'''
kattis-walls

Attempt 1:
- record which cranes can reach which walls
- prune all cranes which are not in reach of walls
- check if there are any walls not in reach of any 
  crane (Impossible criterion)
- determine if answer is 1/2/3, else it is 4

- considering combination of cranes is only possible
  due to small N, for 1/2/3 is 30C1 + 30C2 + 30C3 < 
  10^5 so does not TLE.

Time: O(N + 30C1 + 30C2 + 30C3) for PnC = O(N)
Space: O(N)
'''
import sys
import itertools

L, W, N, R = map(int, input().split())

# Initializing center of walls, center cranes
centers = [[-1*L/2, 0],
           [L/2, 0],
           [0, -1*W/2],
           [0, W/2]]
craneReach = [set() for _ in range (N)]
impossibleTest = set()

# Receiving crane input
for crane_i in range (N) :
    X, Y = map(int, input().split())

    # Testing if crane can reach points
    for center_idx, point in enumerate(centers) :
        dist = ((Y - point[1])**2 + (X - point[0])**2)**0.5
        if dist <= R :
            impossibleTest.add(center_idx)
            craneReach[crane_i].add(center_idx)

# Impossible test
if len(impossibleTest) < 4 :
    print ("Impossible")
    sys.exit()

# Determining if answer is 1/2/3/4
full = set([0, 1, 2, 3])
for r in range (1, 4) :
    combis = list(itertools.combinations(range(N), r))
    for combi in combis :
        # Test if answer is 1
        if len(combi) == 1 :
            if craneReach[combi[0]] == full :
                print (r)
                sys.exit()
        # Test is answer is 2/3
        else:
            reach = set()
            for elem in combi:
                reach = reach.union(craneReach[elem])
            if reach == full :
                print (r)
                sys.exit()

# Remaining alternative
print(4)
