/*
Topological Sort
=================

- Aim is to find a linear ordering of vertices in a given graph s.t. vertex a comes before vertex b if a directed 
  edge a -> b exists in the given graph.

- Useful for modeling stuff like dependencies - helps us visit all dependent vertices before we visit parent cells 
  and so on and so forth.

- Two main ways of doing it, (1) DFS (see kattis-builddeps)
                             (2) Kahn's Algorithm (Modified BFS) (see kattis-conservation)

For both: 
    Time: O(V + E)
    Mem : O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100];  // We consider graph in the form of an adjacency list

// DFS 
// ======================================================================
vector<string> order;     // Linear ordering of vertices from toposort
bool visited[100];        // Boolean array showing if node i has been visited

void dfs (int u) {                    // To visit node [u]
    visited[u] = true;

    for (auto node : adjList[u]) {    // Visit all unvisited nodes connected to [u]
        if (!visited[node]) {
            dfs(node);
        }
    }
    order.emplace_back(u);            // Remember node AFTER visiting parent nodes
}

int dfs_main () {
    int N;        // Assume nodes are stored 0, 1, ... , N-1
    for (int node = 0; node < N; node++) {
        if (!visited[node]) {
            dfs(node);
        }
    }

    reverse(order.begin(), order.end()); // We remembered node after visiting parent nodes, reverse for true order
    // we now have desired linear ordering in vector "order"
}



// Kahn's Algorithm (Modified BFS)
// ==================================================================
int in_degree[100];      // Number of dependencies each node has
queue<int> q;            // BFS Queue of nodes to visit

int kahn_main () {
    int N;        // Assume nodes are stored 0, 1, ... , N-1

    // Add all starter nodes to BFS queue (nodes with no dependencies)
    for (int node = 0; node < N; node++) {
        if (in_degree[node] == 0) {
            q.push(node);
        }
    }

    // BFS on all nodes until all are visited
    while (!q.empty()) {
        int u = q.front(); q.pop();

        /*
            Process node u here
        */

        // Visit v (parent nodes of u)
        for (auto &v : adjList[node]) {    
            in_degree[v]--;    // Remove one dependency of parent v as u has been visited               
            
            if (in_degree[v] == 0) {       // If in_degree [v] == 0
                q.push(v);                 //     => No more dependencies for v
            }                              //     => Add v to queue to be processed
        }
    }

    // End of kahn
}

// EOF

