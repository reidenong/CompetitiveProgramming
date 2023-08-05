'''
kattis-runningmom

- Basically infinite flights means that we need to find a cycle in a directed
  graph

- We can use DFS to do cycle detection; if we are visiting nodes and we come across
  a previous node we have detected a cycle

- However, with 1k queries, naively DFS for each query will result in TLE

- As such, we implement DFS with memoization in a DP style, where we DFS to evaluate
  for each point and we memoize the answer for every node encountered in DFS.  
  Note that we can further save time as all nodes which run into "trapped" nodes are
  guaranteed to be trapped, and all nodes that run into "safe" nodes are also
  guaranteed to be safe. As such, each node has to be visited at most once.

Time: O(V+E)
Mem: O(V + E)
'''
import sys
sys.setrecursionlimit(1000000000)
graph = {}
visited = {}    # 1 = explored, 2 = finished
safe = {}       # -1 = unknown, 0 = unsafe, 1 = safe

# Receiving input, defining adjList, initializing all other data structures
N = int(input())
for i in range (N) :
    line = input().split()
    A, B = line[0], line[1]
    if A not in graph : graph[A] = []
    if B not in graph : graph[B] = []
    if A not in visited : visited[A] = 0
    if B not in visited : visited[B] = 0
    if A not in safe : safe[A] = -1
    if B not in safe : safe[B] = -1
    graph[A].append(B)

# DFS cycle check with memoization (DP style)
def dfs (u) :
    # Base case, node is known
    if safe[u] != -1 :
        return safe[u]
    
    visited[u] = 1
    safe[u] = 0

    # Explore nodes of u
    for v in graph[u] :
        if visited[v] == 0 :
            safe[v] = dfs(v) 

        # Cycle found, return safe
        if visited[v] == 1 :
            safe[u] = 1
            break
            
        safe[u] |= safe[v]  # node is safe if at least one child node is safe
    
    visited[u] = 2
    return safe[u]

# Output answer
answer = ["trapped", "safe"]
while (True) :
    try :
        node = input()
    except EOFError :
        break

    print (node, answer[dfs(node)])
