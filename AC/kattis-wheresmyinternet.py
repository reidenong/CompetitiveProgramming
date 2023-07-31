'''
kattis-wheresmyinternet

- simple graph problem. can use dfs to visit all the edges to find all
  connected houses

Time: O(V + E)
Space: O(V + E)
'''
import sys
sys.setrecursionlimit(10000000)

N, M = map(int, input().split())

# Model houses using adjList
graph = [[] for _ in range(N + 1)]  # 1-indexed
for i in range (M) :
    A, B = map(int, input().split())
    graph[A].append(B)
    graph[B].append(A)
connected = [0 for _ in range (N+1)]
connected[1] = 1

# DFS
def dfs (idx) :
    for house in graph[idx] :
        if not connected[house] :
            connected[house] = 1
            dfs(house)
dfs(1)

# Output answer
if sum(connected) == N :
    print ("Connected")
else :
    for i, house in enumerate(connected[1:]) :
        if not house :
            print (i + 1)
