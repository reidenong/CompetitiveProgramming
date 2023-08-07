/*
Bipartite Checks / Cycle Checks

Attached bellow is some sample code that does basic bipartite checking / color checking using DFS on
an adjList. Any competitive programming question will probably need a modified version, but this snippet 
may come in useful to those new to either algorithms.

Bipartite Checking :
    In essence, a bipartite graph is one where all vertices in the graph are one of two colors, and only 
    different coloured vertices share a edge.

    To check, we can do either BFS or DFS. BFS is probably more intuitive and can be implemented with a 
    queue, but this solution uses DFS instead. Solution assumes graph form of an adjList.

    In our DFS, as we come to a node, we assign it a colour red (value = 1). For all neighbours, if it is
    uncoloured, we assign it a different colour blue (value = 2) and continue DFS. If the neighbour is already
    coloured of a similar color, we conclude that this component of the graph is non-bipartite.

Cycle Checking :
    Cycles in the graph can occur in two manners: trivial and non trivial cycles.

    A trivial cycle is basically a bi-directional edge (a cycle between 2 nodes).

    A non-trivial cycle is a cycle between 3 or more nodes.

    In cycle checking, we can use DFS with 3 states: unvisited, visiting, and completed. We begin with a node
    and DFS to its neighbours, marking them as visiting as we go along. If we come across another visiting node,
    it means that somewhere in the graph there is a cycle that has led us back to this visiting node. Once we 
    done with the DFS we then mark all nodes as completed to prevent re-checking these nodes.

    To differentiate trivial from non-trivial cycles we can use a parent array to keep track of parents of each
    connected node. For trivial cycles the nodes are each other's parents and can thus be ignored.
*/
#include <bits/stdc++.h>
using namespace std;

// WIP!
