/*
kattis-molekule

- The molecule has N vertices and N-1 edges. We start with a single vertice.
  after that, every time we add a vertice, we add an edge. This means that the
  graph will not have any cycles, and will be a tree.

- We want there to be no "chains" of vertices, so we want to make sure that each 
  vertex either has all bonds directed in, or all bonds directed out. This
  can be modeled by a bipartite graph, where one color represents vertices with
  all bonds directed in, and the other color represents vertices with all bonds
  directed out, where no two vertices of the same color are neighbours (by definition)

- As such, we use a bipartite graph to model the molecule, and use dfs to determine
  the color of each molecule. Then depending on the color of each molecule, we output
  1 or 0 where we want all red vertices to be directed to blue vertices without loss
  of generality.

Time: O(V+E) dfs for bipartite coloring
Space: O(V+E) adjList
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100001];
int color[100001];              // (for bipartite) 0 = unvisited, 1 = red, 2 = blue
int edges[100001][2];           // (for bipartite) Stores edges

// DFS to check if bipartite
void bipartite (int u) {
    for (auto &v : adjList[u]) {
        // Visiting new node, coloring it
        if (color[v] == 0) {
            color[v] = 3 - color[u];
            bipartite(v);
        }
    }
}

int main () {
    int N, A, B;
    cin >> N ;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &A, &B);
        A--; B--;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
        edges[i][0] = A;
        edges[i][1] = B;
    }

    // Colouring the graph (bipartite)
    // We can start with any node as graph is connected
    color[0] = 1;
    bipartite(0);

    // Showing bond directions all 1 to 2
    for (int i = 0; i < N-1; i++) {
        if (color[edges[i][0]] == 1) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}
