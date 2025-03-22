'''
Kosaraju's Algorithm for finding SCCs

 - SCCs are strongly connected components, which are groups of nodes in a graph where
    every node in the group can reach every other node in the group

- Kosaraju's Algorithm is a two-pass algorithm that finds the largest SCC in a graph.
  This does DFS once to find the topological order of the graph, and then DFS
  again in the topological order on the transpose of the graph, giving us a new function
  call for each SCC

- Usage case of kosaraju here is to see the size of each SCC, as well as its constituent nodes

Time: O(V + E)
Mem: O(V + E)
'''
import sys
sys.setrecursionlimit(1000000000)

# We need both the original graph as well as its transpose
# For all directed edges u -> v, we change the tranposed edge v -> u
graph = {}
graphT = {}

# DFS to find largest SCC
order = []
visited = {}
currSCC = 0     # Current SCC size
def kosaraju (u, passNum) :
    if passNum == 2 :
        print (u)

    global currSCC
    currSCC += 1
    visited[u] = True

    if passNum == 1 :
        for neighbour in graph[u] :
            if neighbour not in visited :
                kosaraju(neighbour, 1)
        order.append(u)   # Important to only add order after all neighbours are visited!
    
    else :
        for neighbour in graphT[u] :
            if neighbour not in visited :
                kosaraju(neighbour, 2) 

# Finding SCCs Step 1: Finding topological order
for name in graph :
    if name not in visited :
        kosaraju(name, 1)
order = reversed(order)     # Reversing order to get topological order

# Finding SCCS Step 2: DFS on Transposed graph
visited = {}
for name in order :
    if name not in visited :
        currSCC = 0                     # Resetting SCC size
        kosaraju(name, 2)
        print ("SCC size: " + str(currSCC))
        print ()                        # Newline for each new SCC
