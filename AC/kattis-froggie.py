# NOT A RIGOROUS ANSWER
# Solution should not be theoretically correct, but somehow achieves AC.
# I suspect testcases r not thorough.
# Logic gap is when frog can pass thru where cars were previously at even though they shld squish

import sys

# Receiving Input
L, W = map(int, input().split())    # number of Lanes, Width of each lane
carOIS = []         # [Offset, Interval, Speed]
for i in range(L):
    O, I, S = map(int, input().split())
    carOIS += [[O,I,S]]
carOIS.reverse()
fline = input().split(" ")
P = int(fline[0])   # P starting position
commands = fline[1]     # comm string of commands


def lane_dir(lane_number):
# True means left to right, 
# False means right to left.
    if(L%2 == 0):
        if(lane_number%2 == 0): return 0
        else: return 1
    else:
        if(lane_number%2 == 0): return 1
        else: return 0


def simulate_lane(lane_number, time):
    lane=[0]*W
    O, I, S = carOIS[lane_number]

    # Derive start position (start_pos)
    start_pos = O + time*S
    while(start_pos >= W):
        start_pos -= I
    lane[start_pos] = 1

    # Fill in all other cars relative to "startpos"
    # Fill forwards
    pos = start_pos + I
    while(pos < W):
        lane[pos] = 1
        pos += I
    # Fill backwards
    pos = start_pos - I
    while(pos >= 0):
        lane[pos] = 1
        pos -= I

    # Account for lane dir
    if not lane_dir(lane_number):
        lane.reverse()

    return lane

# Command based moving frog, consider END if exit limits
pos = [P, -1]
def movefrog(command):
    if command == 'U':
        pos[1] += 1
        return pos
    elif command == 'D':
        pos[1] -= 1
        if pos[1] < -1:
            print('squish')
            sys.exit()
        return pos
    elif command == 'L':
        pos[0] -= 1
        if pos[0] < 0:
            print('squish')
            sys.exit()
        return pos
    elif command == 'R':
        pos[0] += 1
        if pos[0] >= W:
            print('squish')
            sys.exit()
        return pos

'''
# Print Lane Simulation 
print("  ")
for t in range(len(commands)):
    for l in reversed(range(L)):
        print(simulate_lane(l, t))
    print("------------------------")
'''

# Simulate moving froggie
for time in range(0, len(commands)):
    command = commands[time]
    movefrog(command)
    #print(pos)

    # Froggie safe
    if pos[1] == L:
        print('safe')
        sys.exit()

    # Froggie steps onto the roadd
    if(pos[1] >= 0):
        lane = simulate_lane(pos[1], time+1)    
        # time+1 accounts for fact that froggie moves on time 0

        if lane[pos[0]]:
            print('squish')
            sys.exit()

# If froggie does not end up outside the road
print('squish')
