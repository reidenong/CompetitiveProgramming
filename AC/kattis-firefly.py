'''
kattis-firefly

- use bisect module to quickly determine if firefly will hit a given
  obstacle since we sort them before
- since we are only interested in the number of hits, we can sort the 
  obstacles by height so we can use Binary search (bisect) to efficiently
  determine if fly will hit a obstacle or not

Time: O(H log N)
Space: O(N)
'''
import bisect

# Receiving input
N, H = map(int, input().split())
floor = []
ceil = []
for i in range (N) :
    height = int(input())
    if i%2 == 0 :
        floor.append(height)
    else :
        ceil.append(height)
floor.sort()
ceil.sort()

# Number of obstacles hit flying at height X
def obstaclesHit (X) :
    floorHits = len(floor) - bisect.bisect_left(floor, X)
    ceilHits = len(ceil) - bisect.bisect_left(ceil, H - X + 1)
    #print (X, H-X+1, "|", floorHits, ceilHits, "| total =", floorHits + ceilHits)
    return floorHits + ceilHits

# Simulate flying at each height
currMin = N
levels = 0 
for i in range (1, H+1) :
    hits = obstaclesHit(i)

    # Check if new minimum exists
    if hits < currMin :
        currMin = hits
        levels = 1

    # Count new distinct level
    elif hits == currMin :
        levels += 1

# Display answer
print (currMin, levels)

