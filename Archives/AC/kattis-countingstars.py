'''
kattis-countingstars

- Standard dfs flood fill implementation

- We do complete search to detect the presence of a star "#", then we use
  a flood fill dfs to erase the whole star from that one point.

Time: O(RC)
Space: O(RC)
'''
import sys
sys.setrecursionlimit(10000000)

testcase = 1
while (True) :
    # Receiving input
    try :
        Rows, Cols  = map(int, input().split())
    except EOFError :
        break
    visited = []
    for i in range (Rows) :
        visited.append([x for x in input()])

    # DFS Flood Fill to erase a whole star from one point
    dRow = [1, -1, 0, 0]
    dCol = [0, 0, 1, -1]
    def dfs (row, col) :
        visited[row][col] = '#'

        for i in range (4) :
            R, C = row + dRow[i], col + dCol[i]
            if R < 0 or R >= Rows or C < 0 or C >= Cols :
                continue
            if visited[R][C] == "-" :
                dfs(R, C)
        return

    # Complete search for stars with DFS erasing
    stars = 0
    for x in range (Rows) :
        for y in range (Cols) :
            if visited[x][y] == '-' :
                stars += 1
                dfs(x, y)

    print ("Case " + str(testcase) + ":", stars)
    testcase += 1
