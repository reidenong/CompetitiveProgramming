'''
kattis-grasshopper

- Bounds are small enough such that we can simulate a fresh BFS each time we need to find the cost of a path

Time: O(R * C)
Space: O(R * C)
'''
dir = [(1, 2), (2, 1), (-1, 2), (-2, 1), (1, -2), (2, -1), (-1, -2), (-2, -1)]

def solve() :
    R, C, sr, sc, er, ec = [int(x) for x in input().split()]
    sr -= 1; sc -= 1; er -= 1; ec -= 1

    cost = [[-1 for c in range(C)] for r in range(R)]

    # BFS from origin to the rest of the map
    frontier = [(sr, sc)]
    cost[sr][sc] = 0
    while frontier :
        next_frontier = []

        for (r, c) in frontier :
            for (dr, dc) in dir :
                if r + dr >= 0 and r + dr < R and c + dc >= 0 and c + dc < C and cost[r + dr][c + dc] == -1 :
                    next_frontier.append((r + dr, c + dc))
                    cost[r + dr][c + dc] = cost[r][c] + 1

        frontier = next_frontier

    if cost[er][ec] == -1 :
        print("impossible")
    else :
        print(cost[er][ec])
    
while True : 
    try : 
        solve()
    except EOFError : 
        break
