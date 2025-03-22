'''
kattis-grid

- Observe that we can just use BFS to find the shortest path, and grid number only dictates how many steps we can take up down left right

- Frontier based BFS so its easier to count steps

Time: O(N*M)
Space: O(N*M)
'''
import sys
N, M = map(int, input().split())

grid = []
visited = []
for i in range(N) :
    line = [int(x) for x in input()]
    grid.append(line)
    visited.append([False]*M)

# BFS to find shortest path
frontier = []
frontier.append((0, 0))
steps = 0
while frontier :
    nextFrontier = []
    for r, c in frontier :
        # OOB
        if 0 > r or r >= N or 0 > c or c >= M :
            continue

        # Already visited
        if visited[r][c] :
            continue

        # Target Hit
        if r == N-1 and c == M-1 :
            print(steps)
            sys.exit()

        visited[r][c] = True
        nextFrontier.append((r + grid[r][c], c))
        nextFrontier.append((r - grid[r][c], c))
        nextFrontier.append((r, c + grid[r][c]))
        nextFrontier.append((r, c - grid[r][c]))
    
    frontier = nextFrontier
    steps += 1

print(-1)
