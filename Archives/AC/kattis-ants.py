'''
kattis-ants

- Earliest is straightforward. Every ant before the midpoint walks left
  and every ant after the midpoint walks right.

- Latest is not so straightforward, jsut by observation at some samples
  we observe that the latest time all ants get off occurs when all ants
  walk in a single direction, ie. the leftmost ant goes right or the 
  rightmost ant goes left. 
- for each collision, speed remains unchanged, and at each collision point
  the rightward ant is jsut swapped with the leftwards ant so it is as if
  the collision does not happen. thus the method above is optimal

Time: O(N)
Space: O(N)
'''
TCs = int(input())
for testcase in range (TCs) :
    L, N = map(int, input().split())
    positions = []
    while len(positions) < N :
        posInput = [int(x) for x in input().split()]
        positions += posInput
    positions.sort()

    # Finding Earliest
    midpoint = L/2
    currMin = 0
    for pos in positions :
        if pos <= midpoint :
            currMin = max(currMin, pos)
        else :
            currMin = max(currMin, L - pos)
    print (currMin, end=" ")

    # Finding Latest
    print (max(positions[-1], L - positions[0]))
