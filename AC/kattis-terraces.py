'''
kattis-terraces

- if ALL UDLR (up down left right) of a point are bigger, then a point is valid

- if any UDLR of a point is smaller, then a point is invalid

- (observation 1) if ALL UDLR of a point are bigger than or equal, then a point is unknown,
  then a point is valid iff all other neighbouring points are valid

- First we do point checking to determine if each point is valid, invalid, or unknown

- Next we create a floodFill algo that explores each each connected area and
  merges all areas. This allows us to expand all invalid connected areas and 
  then eliminate unknown terraces.

- what is left behind is valid terraces by (observation 1) as all invalid terraces
  have been floodfilled by a invalid point. so we do flood fill on the remaining valid 
  land to get our answer

Time: O(N^2)
Space: O(N^2)
'''
import sys
sys.setrecursionlimit(10000000)

X, Y = map(int, input().split())

# Receiving garden input
garden = []
for i in range (Y) :
    row = [int(x) for x in input().split()]
    garden.append(row)

# Setting data structures
valid = [[-1 for _ in range (X)] for _ in range (Y)]
density = [[1 for _ in range (X)] for _ in range (Y)]

# Checking each point to see if its valid 1, invalid 0, or unknown 2
for row in range (Y) :
    for col in range (X) :
        UDLR = [[row + 1, col],
                [row - 1, col],
                [row, col + 1],
                [row, col - 1]]
    
        for i in range (4) :
            R, C = UDLR[i]
            if R < 0 or R >= Y or C < 0 or C >= X :     # OOBs, valid
                UDLR[i] = 1
            elif garden[R][C] < garden[row][col] :      # Downhill, invalid
                valid[row][col] = 0
                break
            elif garden[R][C] > garden[row][col] :      # Uphill, valid
                UDLR[i] = 1
            elif garden[R][C] == garden[row][col] :     # Same height, unknown
                UDLR[i] = 2
        
        if valid[row][col] == 0 :
            continue
        if 2 in UDLR :
            valid[row][col] = 2
        else :
            valid[row][col] = 1

# DFS Flood fill to identify density map
def densityDFS (row, col) :
    if density[row][col] == 0 :
        return 0

    currHeight = garden[row][col]
    density[row][col] = 0
    
    if valid[row][col] == 2 :
        valid[row][col] = 3

    totalCount = 1

    UDLR = [[row + 1, col],
            [row - 1, col],
            [row, col + 1],
            [row, col - 1]]

    for i in range (4) :
        R, C = UDLR[i]
        if R < 0 or R >= Y or C < 0 or C >= X :
            continue
        if garden[R][C] == currHeight and density[R][C] == 1 :
            totalCount += densityDFS(R, C)
    
    return totalCount

# First round of flood fill to eliminate all known valid/invalid terraces
ans = 0
for row in range (Y) :
    for col in range (X) :
        if valid[row][col] == 1 :
            ans += densityDFS(row, col)
        elif valid[row][col] == 0 :
            densityDFS(row, col)    # DFS on invalids still to remove unknowns with floodfill

# Second round of flood fill to elimnate all remaining terraces (previously unknown)
for row in range (Y) :
    for col in range (X) :
        if density[row][col] == 1 :
            ans += densityDFS(row, col)

print (ans)
