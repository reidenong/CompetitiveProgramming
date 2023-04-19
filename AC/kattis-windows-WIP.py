import sys
# Receiving input
xmax, ymax = map(int, input().split())
windows = []    # [[UpperBound_0, LowerBound_1, LeftBound_2, RightBound_3]...]

# Set side box limits
def OPEN(xywh):
    x, y, w, h = xywh
    upper_bound = y
    lower_bound = y+h
    left_bound = x
    right_bound = x+w

    openwindow = True
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

    if openwindow:
        windows += [[upper_bound, lower_bound, left_bound, right_bound]]
    else:
        print("window does not fit")

    return openwindow


# Resize function, worry about > vs >= ?
# Basically find the top-left of the window with that pixel, then OPEN
def RESIZE(xywh):
    x, y, w, h = xywh
    nowindow = True
    global windows
    for i,window in enumerate(windows):
        if (window[2] <= x and window[3] >= x) or (window[2] <= x and window[3] >= x):
            if(window[0] <= y and window[1] >= y) or (window[0] <= y and window[1] >= y):
                nowindow = False
                del windows[i]  # Remove old window first
                openwindow = OPEN([window[0], window[2], w, h])
                if not openwindow:
                    windows += [window]
                break
    if nowindow:
        print("no window at given position")


def CLOSE(xy):
    x, y = xy
    global windows
    nowindow = True
    for i,window in enumerate(windows):
        if (window[2] <= x and window[3] >= x) or (window[2] <= x and window[3] >= x):
            if(window[0] <= y and window[1] >= y) or (window[0] <= y and window[1] >= y):
                print("del?",windows[i])
                del windows[i]
                nowindow = False
    if nowindow:
        print("no window at given position")

# MOVE
# All windows will only move in 1 direction. 
# Everytime a box hits another box, add it to the moving list until it 
# hits the end (ie. "False") or it finishes moving

# Checks if window can move 1 move in that direction.
# Returns "True", "False" if limits, window_id if hit window
def NoWindowDir(windowX, dx, dy):
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
    global windows
    for i,window in enumerate(windows):
        if window == windowX:
            continue
        # Fails to clear Laterally
        # If right bound fail OR left bound fail
        if (window[2] <= right_bound and window[3] >= right_bound) or (window[2] <= left_bound and window[3] >= left_bound):
            # Fails to clear vertically
            if(window[0] <= upper_bound and window[1] >= upper_bound) or (window[0] <= lower_bound and window[1] >= lower_bound):
                # Hits a window, return window id
                return i
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

'''
def MOVE(xydd):
    x, y, dx, dy = xydd
    global windows
    upper_bound, lower_bound, left_bound, right_bound = windows[WindowIdAtPos([x,y])]
    upper_bound += dy
    lower_bound += dy
    left_bound += dx
    right_bound += dx
    windows[WindowIdAtPos([x,y])] = [upper_bound, lower_bound, left_bound, right_bound]
'''

while(True):
    line = sys.stdin.readline()
    if line == "": break

    command = line.split(' ')[0]
    specs = (line.rstrip('\r\n')).split(' ')[1:]
    for i in enumerate(specs):
        specs[i[0]] = int(specs[i[0]])
    print("DOING-", command, specs)

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
            print("no window at given position")
            continue
        units_moved = abs(max(specs[2],specs[3]))
        direction = 1 if(max(specs[2],specs[3]) > 0 ) else 0
        '''
        # Slowly move 1 by 1 and check
        for i in range(units_moved):
            # Make sure all windows can move, with last window moving first
            for move_group_id in reversed(range(len(move_group))):
                if(abs(specs[2]) > 0):   # move along x axis
                    movecheck = NoWindowDir(windows[move_group[0]], direction, 0)
                    if movecheck == "False":            # OOB
                        units_moved = i
                        break
                    elif movecheck != "True":           # Depends on another window
                        while isinstance(movecheck, int):
                            move_group += [movecheck]   # Add window id to move_group
                            movecheck = NoWindowDir(movecheck)
                        if movecheck == "False":            # OOB
                            units_moved = i
                            break

            if movecheck == "False":            # OOB
                        units_moved = i
                        break
            else:
                for move_group_id in move_group
        '''
        for i in range(units_moved):
            while(1):
                for idx in reversed(move_group):
                    movecheck = NoWindowDir(windows[idx], direction, 0)
                    print(movecheck)
                    if(movecheck == "False"):
                        break
                    elif(movecheck != "True"):  # Window blocking
                        move_group += [movecheck]
                        print(move_group)
                        break
                if movecheck == "True" or movecheck == "False": # Moved 1 block
                    break

            if movecheck == "True":
                units_moved = i
                for idx in move_group:
                    MOVEid([idx, direction, 0])
            if movecheck == "False":
                units_moved = i
                break
                

            

        units_moved += 1

        print("MOVED BY", units_moved)
        

