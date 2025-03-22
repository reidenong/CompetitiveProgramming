/*
kattis-caveexploration

- We are given that the whole graph is initially connected, and that we need to find the 
  number of nodes that are still connected to 0 after any edge may be removed.

- Edges that are removed which may cause the graph to be disconnected are bridges. 
  We can use DFS to find bridges in the graph, and remove them.

- Following removal, we can then DFS from 0 to find the number of nodes that are still 
  connected to 0 by DFSing from root 0.

Time: O(N + M)
Mem: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100001];
int dfs_num[100001];
int dfs_low[100001];
int dfs_parent[100001];             // Unnecessary for this problem
int articulation_vertex[100001];    //            || 
enum {UNVISITED = -1};
int dfsNumberCounter, dfsRoot, rootChildren;
vector<pair<int, int>> bridges;     // Bridges to be removed
int safe = 0;

// DFS for Articulation Points and Bridges
void APnB (int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (auto &v : adjList[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;

            APnB(v);

            if (dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1;   // Articulation Point
            if (dfs_low[v] > dfs_num[u]) bridges.push_back(make_pair(u, v));   // Bridge
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }

        else if (v != dfs_parent[u]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

// DFS to find "safe" nodes from 0
void dfs (int u) {
    dfs_num[u] = -1;    // Mark as visited, -1 is visited, !-1 is unvisited as earlier in APnB
    safe++;
    for (auto &v : adjList[u]) {
        if (dfs_num[v] != -1) 
            dfs(v);
    }
}

int main () {
    int N, M, A, B;
    cin >> N >> M;

    // Initializing Data Structures
    memset(dfs_num, UNVISITED, sizeof dfs_num);
    memset(dfs_parent, -1, sizeof dfs_parent);
    dfsNumberCounter = 0;

    // Receiving graph input
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        adjList[A].push_back(B);
        adjList[B].push_back(A);
    }

    // APnB
    // Can start from 0 as graph is guaranteed to be connected
    dfsRoot = 0;
    rootChildren = 0;
    APnB(0);
    articulation_vertex[dfsRoot] = (rootChildren > 1);

    // Erase bridges in adjList
    for (auto &p : bridges) {
        adjList[p.first].erase(find(adjList[p.first].begin(), adjList[p.first].end(), p.second));
        adjList[p.second].erase(find(adjList[p.second].begin(), adjList[p.second].end(), p.first));
    }

    // DFS from 0 to find "safe" nodes, output answer
    dfs(0);
    cout << safe << endl;

    return 0;    
}
