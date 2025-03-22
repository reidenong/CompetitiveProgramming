'''
kattis-lost

- We need to find the shortest path interms of hops to each node

- but we want the lowest cost of translation among all paths of the
  same length, so in BFS sort frontier by cost

Time: O(M)
Space: O(M)
'''
N, M = map(int, input().split())

# Mapping languages to indices
languages = ['English'] + [x for x in input().split()]
lang_index = {}
for i, lang in enumerate(languages):
    lang_index[lang] = i

# Constructing adjacency list
adjList = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)] 
for _ in range(M):
    a, b, w = input().split()
    a, b, w = lang_index[a], lang_index[b], int(w)
    adjList[a].append((b, w))
    adjList[b].append((a, w))

# BFS to minimise translation distance (hops)
total_cost = 0
frontier = [(0, 0)]
while frontier :
    nextFrontier = []
    frontier.sort(key=lambda x: x[1])   # Get lowest translation cost
    for node, cost in frontier :
        if visited[node] :
            continue

        visited[node] = True
        total_cost += cost
        for elem in adjList[node] :
            if not visited[elem[0]] :
                nextFrontier.append(elem)
        
    frontier = nextFrontier

# Output answer
if all(visited) :
    print(total_cost)
else :
    print('Impossible')
