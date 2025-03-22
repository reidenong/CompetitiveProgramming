'''
kattis-torn2pieces

- Simple DFS with backtracking for solution

- irritating edge case is when start or end not in graph, will get RTE if not handled

Time: O(V + E)
Mem: O(V + E)
'''
import sys
sys.setrecursionlimit(1000000000)
graph = {}          # adjList
visited = {}        # visited nodes
found = False
order = []          # order of nodes visited (answer path)

# Build adjList
N = int(input())
for i in range(N):
    line = input().split()
    u = line[0]
    v = line[1:]
    for node in v :
        if node not in graph :
            graph[node] = []
        if u not in graph :
            graph[u] = []
        if u not in graph[node] :
            graph[node].append(u)
        if node not in graph[u] :
            graph[u].append(node)

# Receiving start/end, handling edge case of start/end not in graph
start, end = input().split()
if start not in graph or end not in graph :
    print ('no route found')
    sys.exit()

# DFS to build path from start to end
def dfs (u) :
    visited[u] = True

    if u == end :           # Endpoint found, declare found and start saving path order
        global found
        found = True
        order.append(u)
        return

    for v in graph[u]:
        if v not in visited:
            dfs(v)

        if found :          # Important to prevent backtracking to other nodes
            break

    if found :              # Save path order    
        order.append(u)
dfs(start)

# Print answer
if found :
    print (' '.join(reversed(order)))
else :
    print ('no route found')
