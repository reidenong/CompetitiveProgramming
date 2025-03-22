'''
kattis-amoebas

- Standard dfs flood fill implementation

- We do complete search to detect the presence of a ring "#", then we use
  a flood fill dfs to erase the whole ring from that one point.

Time: O(RC)
Space: O(RC)
'''
import sys
sys.setrecursionlimit(10000000)

# Receiving input
Rows, Cols  = map(int, input().split())
visited = []
for i in range (Rows) :
    visited.append([x for x in input()])

# DFS Flood Fill
dRow = [1, 1, 0, -1, -1, -1, 0, 1]
dCol = [0, 1, 1, 1, 0, -1, -1, -1]
def dfs (row, col) :
    visited[row][col] = '.'

    for i in range (8) :
        R, C = row + dRow[i], col + dCol[i]
        if R < 0 or R >= Rows or C < 0 or C >= Cols :
            continue
        if visited[R][C] == "#" :
            dfs(R, C)
            break
    return

# Complete search for rings with DFS erasing
amoebas = 0
for x in range (Rows) :
    for y in range (Cols) :
        if visited[x][y] == '#' :
            amoebas += 1
            dfs(x, y)

print (amoebas)
