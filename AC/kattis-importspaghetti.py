'''
kattis-importspaghetti

- we want to find the shortest cycle in the graph

- we can use Floyd-Warshall to find the shortest path between all pairs of nodes. The critical
  step is to not initiate each node to itself as 0, but instead to INF. This way, the shortest cycle
  will be revealed as the shortest path from each node to itself.

- once we find the shortest cycle, we can backtrack the path from the node to itself to find the
  shortest cycle.

Time: O(N^3)
Space: O(N^2)
'''
INF = 10**9

N = int(input())
files = input().split()
file_map = {}
for i, file in enumerate(files) :
    file_map[file] = i

adjmat = [[INF for i in range(500)] for j in range(500)]

for i in range(N) :
    name, edges = input().split()
    edges = int(edges)

    for j in range(edges) :
        line = input()
        links = line[7:].split(', ')
        for link in links :
            adjmat[i][file_map[link]] = 1

pred = [[i for _ in range(500)] for i in range(500)]
def floyd_backtrack() :
    for k in range(N) :
        for i in range(N) :
            for j in range(N) :
                if adjmat[i][j] > adjmat[i][k] + adjmat[k][j] :
                    adjmat[i][j] = adjmat[i][k] + adjmat[k][j]
                    pred[i][j] = pred[k][j]
floyd_backtrack()

# Find shortest cycle
shortest, idx = INF, -1
for i in range(N) :
    if adjmat[i][i] < shortest :
        shortest, idx = adjmat[i][i], i

def print_path(i, j) :
    if i != j :
        print_path(i, pred[i][j])
    print(files[j], end=' ')

if shortest == INF :
    print('SHIP IT')
else :
    print_path(idx, pred[idx][idx])

