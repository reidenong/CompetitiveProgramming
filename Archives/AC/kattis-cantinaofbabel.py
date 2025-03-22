'''
kattis - cantinaofbabel

- Step 1 is to create the graph. Much easier to create the graph if we consider 
  the speakers and listeners of each language, and then we create the graph
  as well as its transpose.

- Step 2 is to find the SCCs of the graph. We can do this by kosaraju's algorithm.
  This does DFS once to find the topological order of the graph, and then DFS
  again in the topological order on the transpose of the graph, giving us a new function
  call for each SCC

Time: O(V + E)
Mem: O(V + E)
'''
import sys
sys.setrecursionlimit(1000000000)

# Processing speaking information per language
N = int(input())
languages = {}
for i in range (N) :
    line = input().split()
    name = line[0]
    speaks = line[1]
    understand = line[2:]

    if speaks not in languages :
        languages[speaks] = [[],[]]
    languages[speaks][0].append(name)
    languages[speaks][1].append(name)

    for lang in understand :
        if lang not in languages :
            languages[lang] = [[],[]]
        languages[lang][1].append(name)

# Creating Communication Graph and Transposed Graph
graph = {}
graphT = {}
for language in languages :
    members = languages[language]

    # Creating original graph and transposed graph
    for speaker in members[0] :
        if speaker not in graph :
            graph[speaker] = []
        if speaker not in graphT :
            graphT[speaker] = []

        for indiv in members[1] :
            if indiv not in graph :
                graph[indiv] = []
            if indiv not in graphT :
                graphT[indiv] = []

            if indiv != speaker :
                graph[speaker].append(indiv)
                graphT[indiv].append(speaker)

# DFS to find largest SCC
order = []
visited = {}
currSCC = 0     # Current SCC size
def kosaraju (u, passNum) :
    global currSCC
    currSCC += 1
    visited[u] = True

    if passNum == 1 :
        for neighbour in graph[u] :
            if neighbour not in visited :
                kosaraju(neighbour, 1)
        order.append(u)
    
    else :
        for neighbour in graphT[u] :
            if neighbour not in visited :
                kosaraju(neighbour, 2) 

# Finding SCCs Step 1: Finding topological order
for name in graph :
    if name not in visited :
        kosaraju(name, 1)
order = reversed(order)

# Finding SCCS Step 2: DFS on Transposed graph
visited = {}
maxSCC = 0
for name in order :
    if name not in visited :
        currSCC = 0                     # Resetting SCC size
        kosaraju(name, 2)
        maxSCC = max(maxSCC, currSCC)   # Updating max SCC size

print (N - maxSCC)
