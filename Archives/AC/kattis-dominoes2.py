'''
kattis-dominoes2

- relatively simple graph question, just use dfs to find which dominoes will fall 
  down. important that edges are not bidirectional

Time: O(V+E)
Space: O(V+E)
'''
import sys
sys.setrecursionlimit(10000000)

TCs = int(input())
for testcase in range (TCs) :
    N, M, L = map(int, input().split())

    # Model dominoes using adjList
    graph = [[] for _ in range(N + 1)]  # 1-indexed
    for i in range (M) :
        A, B = map(int, input().split())
        graph[A].append(B)
    fallen = [0 for _ in range (N+1)]

    # DFS
    def dfs (idx) :
        for house in graph[idx] :
            if not fallen[house] :
                fallen[house] = 1
                dfs(house)
    
    # Receive knocked dominoes
    for i in range (L) :
        knock = int(input())
        fallen[knock] = 1
        dfs(knock)

    # Output answer
    print (sum(fallen))
