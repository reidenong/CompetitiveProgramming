'''
kattis-chocolates

- First we generate all possibilities of 0's and 1's in a grid of size R x C

- For each grid, there are two conditions that must be satisfied for polygons:
    1. All 1's must be connected (4 directionally)
    2. All 0's must be connected to the boundary (48 directionally)

- We use itertools to generate all possible grids first. then we check if the grid satisfies the two conditions
  above. if it does we add the grid to the count

Time complexity: O(2^(R*C) * (R+C))
Space complexity: O(R * C)
'''
import sys
sys.setrecursionlimit(int(10**8))
from collections import deque
from itertools import product

moves_4 = [(0, 1), (1, 0), (0, -1), (-1, 0)]
moves_8 = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]

def grid_hash(grid) :
    return tuple([tuple(row) for row in grid])

def no_holes(grid, R, C) :
    q = deque()
    for i in range(R) :
        if grid[i][0] == 0 :
            q.append((i, 0))
        if grid[i][C - 1] == 0 :
            q.append((i, C - 1))
    for j in range(C) :
        if grid[0][j] == 0 :
            q.append((0, j))
        if grid[R - 1][j] == 0 :
            q.append((R - 1, j))
    
    visited = [[False for _ in range(C)] for _ in range(R)]
    while q :
        r, c = q.popleft()
        visited[r][c] = True

        for dr, dc in moves_8 :
            nr, nc = r + dr, c + dc
            if 0 <= nr < R and 0 <= nc < C and not visited[nr][nc] and grid[nr][nc] == 0 :
                q.append((nr, nc))

    for i in range(R) :
        for j in range(C) :
            if grid[i][j] == 0 and not visited[i][j] :
                return False
            
    return True

def is_one(grid, R, C) :
    # Find graph source
    source = -1
    for i in range(R) :
        for j in range(C) :
            if grid[i][j] == 1 :
                source = (i, j)
                break
        if source != -1 :
            break
    
    if source == -1 :
        return False
    
    # BFS to see if all 1's are connected
    q = deque()
    q.append(source)
    visited = [[False for _ in range(C)] for _ in range(R)]
    visited[source[0]][source[1]] = True
    while q :
        r, c = q.popleft()

        for dr, dc in moves_4 :
            nr, nc = r + dr, c + dc
            if 0 <= nr < R and 0 <= nc < C and not visited[nr][nc] and grid[nr][nc] == 1 :
                visited[nr][nc] = True
                q.append((nr, nc))
    
    for i in range(R) :
        for j in range(C) :
            if grid[i][j] == 1 and not visited[i][j] :
                return False
    
    return True

def generate_permutations(rows, cols):
    # Generate all possible combinations of 0s and 1s for a grid of given dimensions
    total_cells = rows * cols
    all_combinations = product([0, 1], repeat=total_cells)
    
    # Convert each combination into a 2D grid
    all_grids = []
    for combination in all_combinations:
        grid = [list(combination[i * cols:(i + 1) * cols]) for i in range(rows)]
        all_grids.append(grid)
    
    return all_grids


def solve() :
    R, C = map(int, input().split())

    ans = 0
    all_grids = generate_permutations(R, C)
    for grid in all_grids:
        if is_one(grid, R, C) and no_holes(grid, R, C):
            ans += 1

    print(ans)

solve()
