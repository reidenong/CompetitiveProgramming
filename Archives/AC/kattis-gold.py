'''
kattis-gold

- classic DFS implementation with the exception not to go further when in 
  range of a trap

- remember to use visited array to not visit the same place twice

Time: O(RC)
Space: O(RC)
'''
import sys
sys.setrecursionlimit(10000000)

# Receiving input
Cols, Rows  = map(int, input().split())
map = []
visited = []
for i in range (Rows) :
    line = input()
    map.append([x for x in line])
    visited.append([0 for _ in line])

# Finding start point
startR, startC = 0, 0
for row in range (Rows) :
    for col in range (Cols) :
        if map[row][col] == "P" :
            startR, startC = row, col
            map[row][col] = '.'
            break
    if startR != 0 :
        break

# DFS Flood Fill 
dRow = [1, -1, 0, 0]
dCol = [0, 0, 1, -1]
def dfs (row, col) :
    visited[row][col] = 1
    if map[row][col] == "G" :
        map[row][col] == "."
        global gold
        gold += 1

    # Check if "draft" is felt (cannot go further, can only go back)
    for i in range (4) :
        R, C = row + dRow[i], col + dCol[i]
        if map[R][C] == "T" :
            map[row][col] = '#'     # Remember that this square is pointless
            return 

    # No traps here, explore nearby
    for i in range (4) :
        R, C = row + dRow[i], col + dCol[i]
        if map[R][C] != "#" and not visited[R][C]:
            dfs(R, C)
    return

# Search from startpoint
gold = 0
dfs(startR, startC)
print (gold)
