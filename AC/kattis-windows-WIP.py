import sys
from copy import deepcopy
# Receiving input
xmax, ymax = map(int, input().split())
windows = []    # [[UpperBound_0, LowerBound_1, LeftBound_2, RightBound_3]...]
resizing_id = "False"

# Set side box limits
def OPEN(xywh):
    x, y, w, h = xywh
    upper_bound = y
    lower_bound = y+h - 1
    left_bound = x
    right_bound = x+w - 1

    global resizing_id
    global command, command_ctr
    openwindow = True

    # Limit Testing
    if ((upper_bound < 0 or upper_bound > ymax-1) or
        (lower_bound < 0 or lower_bound > ymax-1) or
        (left_bound < 0 or left_bound > xmax-1) or
        (right_bound < 0 or right_bound > xmax-1)):
        openwindow = False

    # Iterate through each window to test for interference
    global windows
    for window in windows:
        # Fails to clear Laterally
        # If right bound fail OR left bound fail
        if (window[2] <= right_bound and window[3] >= right_bound) or (window[2] <= left_bound and window[3] >= left_bound):
            # Fails to clear vertically
            if(window[0] <= upper_bound and window[1] >= upper_bound) or (window[0] <= lower_bound and window[1] >= lower_bound):
                openwindow = False
                break
        
        # SUS?
        # One box contains the other
        if (window[2] >= left_bound and window[3] <= right_bound) or (window[2] <= left_bound and window[3] >= right_bound):
            if (window[0] <= upper_bound and window[1] >= lower_bound) or (window[0] >= upper_bound and window[1] <= lower_bound):
                openwindow = False
                break
        


    if openwindow:
        if resizing_id != "False":
            windows.insert(resizing_id,[upper_bound, lower_bound, left_bound, right_bound])
            resizing_id = "False"
        else:
            windows += [[upper_bound, lower_bound, left_bound, right_bound]]
    else:
        print("Command " + str(command_ctr) + ": " + command + " - window does not fit")

    return openwindow


# Resize function, worry about > vs >= ?
# Basically find the top-left of the window with that pixel, then OPEN
def RESIZE(xywh):
    x, y, w, h = xywh
    global resizing_id
    nowindow = True
    global windows
    global command, command_ctr
    container = deepcopy(windows)
    for i,window in enumerate(windows):
        if (window[2] <= x and window[3] >= x) or (window[2] <= x and window[3] >= x):
            if(window[0] <= y and window[1] >= y) or (window[0] <= y and window[1] >= y):
                nowindow = False
                resizing_id = i
                windows.pop(i)  # Remove old window first
                openwindow = OPEN([window[0], window[2], w, h])
                if not openwindow:
                    windows = deepcopy(container)                    
                    break
    if nowindow:
        print("Command " + str(command_ctr) + ": " + command + " - no window at given position")


def CLOSE(xy):
    x, y = xy
    global windows
    global command, command_ctr
    nowindow = True
    for i,window in enumerate(windows):
        if (window[2] <= x and window[3] >= x) or (window[2] <= x and window[3] >= x):
            if(window[0] <= y and window[1] >= y) or (window[0] <= y and window[1] >= y):
                #print("del?",windows[i])
                del windows[i]
                nowindow = False
    if nowindow:
        print("Command " + str(command_ctr) + ": " + command + " - no window at given position")

# MOVE
# All windows will only move in 1 direction. 
# Everytime a box hits another box, add it to the moving list until it 
# hits the end (ie. "False") or it finishes moving

# Checks if window can move 1 move in that direction.
# Returns "True", "False" if limits, window_id if hit window
def NoWindowDir(windowX, dx, dy):
    #print("NWD", windowX)
    global windows
    global move_group
    if isinstance(windowX, int):
        windowX = windows[windowX]
    
    upper_bound, lower_bound, left_bound, right_bound = windowX
    upper_bound += dy
    lower_bound += dy
    left_bound += dx
    right_bound += dx

    # Check if hits Out of Bounds
    if (upper_bound < 0 or upper_bound >= ymax or
        lower_bound < 0 or lower_bound >= ymax or
        left_bound < 0 or left_bound >= xmax or
        right_bound < 0 or right_bound >= xmax):
        return "False"

    # Check if hits another window, return window id if it does
    
    for i,window in enumerate(windows):
        if window == windowX:
            continue
        # Fails to clear Laterally
        # If right bound fail OR left bound fail
        if (window[2] <= right_bound and window[3] >= right_bound) or (window[2] <= left_bound and window[3] >= left_bound):
            # Fails to clear vertically
            if(window[0] <= upper_bound and window[1] >= upper_bound) or (window[0] <= lower_bound and window[1] >= lower_bound):
                # Hits a window, return window id
                if not i in move_group:
                    move_group += [i]
                return NoWindowDir(i, dx, dy)
    return "True"   # str "True" to avoid conflict with windowid=0/1


def WindowIdAtPos(xy):
    x,y = xy
    for i,window in enumerate(windows):
        if (window[2] <= x and window[3] >= x) or (window[2] <= x and window[3] >= x):
            if(window[0] <= y and window[1] >= y) or (window[0] <= y and window[1] >= y):
                return i
    return "False"

def MOVEid(IDdd):
    idx, dx, dy = IDdd
    global windows
    upper_bound, lower_bound, left_bound, right_bound = windows[idx]
    upper_bound += dy
    lower_bound += dy
    left_bound += dx
    right_bound += dx
    windows[idx] = [upper_bound, lower_bound, left_bound, right_bound]


command_ctr = 0
while(True):
    line = sys.stdin.readline()
    if line == "": break
    
    command = line.split(' ')[0]
    specs = (line.rstrip('\r\n')).split(' ')[1:]
    for i in enumerate(specs):
        specs[i[0]] = int(specs[i[0]])
    #print("DOING-", command, specs)

    command_ctr += 1
    if command == 'OPEN':
        OPEN(specs)
    if command == 'RESIZE':
        RESIZE(specs)
    if command == 'CLOSE':
        CLOSE(specs)
    if command == 'NWAP':
        print("NWAP, ",NoWindowDir(specs, 0, 0))
    if command == 'MOVE':
        # List of all windows which need to move.
        # Once u start moving, you wont stop again
        move_group = [WindowIdAtPos([specs[0],specs[1]])]
        #moving_window = WindowIdAtPos([specs[0],specs[1]])
        if move_group[0] == "False":
            print("Command " + str(command_ctr) + ": " + command + " - no window at given position")
            continue
        units_moved = max(abs(specs[2]), abs(specs[3]))
        direction = 1 if(max(specs[2],specs[3]) > 0 ) else -1

        if specs[2] != 0:   # Moving in X-axis
            # Can we assume all in move_group wont hit others? ie branch moving
            for i in range(units_moved):
                movecheck = NoWindowDir(move_group[0], direction, 0)
                #print(i, movecheck)
                #print("move_group", move_group)
                
                if movecheck == "True":
                    for idx in move_group:
                        MOVEid([idx,direction,0])
                    #print(windows)
                    #print("")   
                else:
                    units_moved = i
                    #print(windows, "false")
                    #print("")
                    break
        else:
            for i in range(units_moved):
                movecheck = NoWindowDir(move_group[0], 0, direction)
                #print(i, movecheck)
                #print("move_group", move_group)
                
                if movecheck == "True":
                    for idx in move_group:
                        MOVEid([idx,0,direction])
                    #print(windows)
                    #print("")   
                else:
                    units_moved = i
                    #print(windows, "false")
                    #print("")
                    break
        if units_moved != max(abs(specs[2]), abs(specs[3])):
            print("Command " + str(command_ctr) + ": " + command + " - moved " + str(units_moved) + " instead of " + str(max(abs(specs[2]), abs(specs[3]))))

    #print(windows)
    #print("\n\n")

print(len(windows), "window(s):")
for window in windows:
    print(window[2], window[0], window[1] - window[0] + 1, window[3] - window[2] + 1)

        

