'''
kattis-kastenlauf

- Max distance they can travel is 1000. So when creating graph, we only allow edges between nodes that are
  within 1000 distance from each other. Then APSP to find shortest path between all nodes.

Time: O(N^3)
Mem: O(N^2)
'''
INF = int(10**9)

def get_dist(a, b) :
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def floyd(adjmat, N) :
    for k in range(N) :
        for i in range(N) :
            for j in range(N) :
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j])
    return adjmat

def solve() :
    # Receiving input
    N = int(input())
    nodes = []
    x, y = map(int, input().split())
    nodes.append((x, y))    
    for i in range(N) :
        x, y = map(int, input().split())
        nodes.append((x, y))
    x, y = map(int, input().split())
    nodes.append((x, y))

    # Create adjacency matrix, weights matrix
    adjmat = [[INF for x in range(N+2)] for y in range(N+2)]
    for i in range(N+2) :
        adjmat[i][i] = 0
    for i, node in enumerate(nodes) :
        for j, other_node in enumerate(nodes) :
            distance = get_dist(node, other_node)
            if distance <= 1000 :
                adjmat[i][j] = adjmat[j][i] = distance

    # Floyd Warshall
    adjmat = floyd(adjmat, N+2)

    if adjmat[0][N+1] == INF :
        print("sad")
    else :
        print("happy")

TC = int(input())
for tc in range(TC) :
    solve()
