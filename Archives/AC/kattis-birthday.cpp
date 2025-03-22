/*
kattis-birthday

- Determining if there exist any articulation points / bridges in a graph

- Articulation points: Removing this vertex will increase the number of 
  connected components in the graph

- Bridges: Removing this edge will increase the number of connected components

Time: O(V + E) (dfs)
Memory: O(V + E) (adjList)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[101];
int dfs_num[101];
int dfs_low[101];
int dfs_parent[101];
int articulation_vertex[101];
enum {UNVISITED = -1};
int dfsNumberCounter, dfsRoot, rootChildren;
bool ans;

// DFS for Articulation Points and Bridges
void APnB (int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (auto &v : adjList[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;

            APnB(v);

            if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;   // Articulation Point
            if (dfs_low[v] > dfs_num[u]) ans = true;                    // Bridge
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }

        else if (v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main () {
    int P, C, A, B;
    while (true) {
        cin >> P >> C;

        if (P == 0 && C == 0) break;    // End of testcase

        // Initializing Data Structures
        memset(dfs_num, UNVISITED, sizeof dfs_num);
        memset(dfs_low, 0, sizeof dfs_low);
        memset(dfs_parent, -1, sizeof dfs_parent);
        memset(articulation_vertex, 0, sizeof articulation_vertex);
        dfsNumberCounter = 0;
        ans = false;

        // Receiving graph input
        for (int i = 0; i < C; i++) {
            scanf("%d %d", &A, &B);
            adjList[A].push_back(B);
            adjList[B].push_back(A);
        }

        // DFS on graph for articulation points and bridges
        for (int u = 0; u < P; u++) {
            if (dfs_num[u] == UNVISITED) {
                dfsRoot = u;
                rootChildren = 0;
                APnB(u);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        // Printing articulation vertices for debugging
        for (int u = 0; u < P; u++) {
            if (articulation_vertex[u]) { 
                //cout << "Articulation Point: " << u << endl;
                ans = true;
            }
        }

        // Printing answer
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;

        // Clear adjList for next testcase
        for (int i = 0; i < P; i++) adjList[i].clear();
    }
}
