'''
kattis-reachableroads

- simple dfs qn

Time: O(V+E)
Space: O(V+E)
'''
import sys
sys.setrecursionlimit(10000000)

TCs = int(input())
for testcase in range (TCs) :
    M = int(input())
    R = int(input())

    # Model places using adjList
    graph = [[] for _ in range(M)]  # 1-indexed
    for i in range (R) :
        A, B = map(int, input().split())
        graph[A].append(B)
        graph[B].append(A)

    # Graph showing reachability for each endpoint
    reachable = [0 for _ in range (M)]
    reachable[0] = 1    # Start searching from endpoint 0

    # DFS
    def dfs (idx) :
        for place in graph[idx] :
            if not reachable[place] :
                reachable[place] = 1
                dfs(place)
    dfs(0)      # Use endpoint 0 as our starting point

    # Add roads linking each endpoint to 0 if it is not reachable
    addedRoads = 0
    for endpoint in range (M) :
        if not reachable[endpoint] :
            addedRoads += 1
            graph[0].append(endpoint)
            graph[endpoint].append(0)
            dfs(endpoint)   # Update new connectivity around the graph

    print (addedRoads)
