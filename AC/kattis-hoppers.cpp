/*
kattis-hoppers

- In simulating how a hopper spreads, one can imagine the process of labelling
  a bi-partite graph: mark a single node, and all of the nodes of a marked neighbour
  are unmarked, and all the nodes of a unmarked neighbour are marked. This is 
  the same as the hopper's spread of skipping every "node layer".

- From this we can conclude that in a bipartite graph, the hopper will never be
  able to spread fully through the graph - just like how every other node is marked.
  In contrast, in a non-bipartite graph, the hopper will always be able to spread 
  through every node. Thus for a bipartite graph a extra linkage is needed to make
  it non-bipartite for full infection

- With a bit of thinking, we also realise as we need to link different CCs (connected components)
  together, we need to evaluate the addition of types of graphs. eventually we come
  to the conclusion that <bipartite + bipartite = bipartite graph>, and
  <non-bipartite + bipartite = non-bipartite graph>.

- As such, we need CCs - 1 linkages to link each CC together. if the resulting graph
  is bipartite (ie. all CCs are bipartite), we need +1 linkage to make it non-bipartite.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[500001];
int visited[500001];            // (for CCs) 0 = unvisited, 1 = visited
int color[500001];              // (for bipartite) 0 = unvisited, 1 = red, 2 = blue
bool bipartite = true;
int CCs = 0;

// DFS to check if bipartite
void bipartiteCheck (int u) {
    for (auto &v : adjList[u]) {
        // Visiting new node, coloring it
        if (color[v] == 0) {
            color[v] = 3 - color[u];
            bipartiteCheck(v);
        }

        // Visiting old node, not bipartite
        else if (color[v] == color[u]) {
            bipartite = false;
            return;
        }

        if (!bipartite) return;     // Early termination
    }
}

// DFS to find connected components
void dfs (int u) {
    visited[u] = 1;

    for (auto &v : adjList[u]) 
        if (visited[v] == 0) 
            dfs(v);
}

int main () {
    int N, M, A, B;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        A--; B--;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }

    for (int i = 0; i < N; i++) {
        // Counting CCs
        if (visited[i] == 0) {
            dfs(i);
            CCs++;

            // Everytime we come to a new CC we check bipartite
            if (bipartite) {        // Dont need to check if already not bipartite
                color[i] = 1;
                bipartiteCheck(i);
            }
        }
    }

    // Output
    if (bipartite) cout << CCs << endl;        // +1 to make it non-bipartite
    else cout << CCs - 1 << endl;
}
