/*
Finding Articulation Points and Bridges
(Undirected Graph)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[101];
int dfs_num[101];                    // Iteration counter when vertex is visited for the first time
int dfs_low[101];                    // Lowest dfs_num reachable by a back edge
int dfs_parent[101];                 // Used to distinguish triviality of cycles (bidirectional edges r trivial)
int articulation_vertex[101];        // Boolean of each vertex's status as an articulation point
enum {UNVISITED = -1};
int dfsNumberCounter, dfsRoot, rootChildren;

// DFS for Articulation Points and Bridges
void APnB (int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (auto &v : adjList[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;

            APnB(v);

            // Found an articulation point
            if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;

            // Found a bridge
            if (dfs_low[v] > dfs_num[u]) cout << "Bridge: " << u << " " << v << endl;

            // Update the subtree
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }

        // Come to a Visited node, update if its a non-trivial cycle
        else if (v != dfs_parent[u])                 
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

// Simulate Receiving input into an undirected unweighted adjList, then 
// searching for articulation points and bridges
int main () {
    int N, C, A, B;
    cin >> N >> C;

    // Initializing Data Structures
    memset(dfs_num, UNVISITED, sizeof dfs_num);
    memset(dfs_low, 0, sizeof dfs_low);
    memset(dfs_parent, -1, sizeof dfs_parent);
    memset(articulation_vertex, 0, sizeof articulation_vertex);
    dfsNumberCounter = 0;

    for (int i = 0; i < C; i++) {
        scanf("%d %d", &A, &B);
        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }

    // DFS all nodes for articulation points
    for (int u = 0; u < P; u++) {
        if (dfs_num[u] == UNVISITED) {
            dfsRoot = u;
            rootChildren = 0;
            APnB(u);
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    }

    // Display articulation Points
    for (int u = 0; u < P; u++) {
        if (articulation_vertex[u]) { 
            cout << "Articulation Point: " << u << endl;
        }
    }
}
