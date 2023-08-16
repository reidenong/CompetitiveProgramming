/*
kattis-dominos

- We realise that all the nodes in a SCC will topple by definition of a SCC as long as 
  one is pushed. Thus there are at least as many pushes as there are SCCs.

- However, some SCCs may have an incoming edge from other SCCs. These will not require '
  a push to topple, and thus we can ignore them.

- We use kosaraju's algorithm to find the number of SCCs with no incoming edge (for any 
  member in the SCC).

- Using kosaraju we get the members of each SCC. If any member of the SCC has a outgoing
  edge to a node not in the SCC in the tranposed matrix, this implies that the SCC
  does not have any incoming nodes from other SCCs.

Time: O(N + M)
Mem: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100001];
vector<int> transpose[100001];
int visited[100001];
vector<int> order;
vector<int> members;

// DFS Kosaraju to find SCCs
void kosaraju (int u, int passNum) {
    visited[u] = 1;
    vector<int> &v = (passNum == 1) ? adjList[u] : transpose[u];

    for (int i = 0; i < v.size(); i++) {
        if (!visited[v[i]]) 
            kosaraju(v[i], passNum);
    }

    // Topological order for pass 1
    // Add u to members of SCC for pass 2
    if (passNum == 1) order.push_back(u);
    else members.push_back(u);
}

// Check if SCC has any incoming edges
bool hasIncoming () {
    for (auto &mem : members) {
        for (auto &v : transpose[mem]) {
            if (find(members.begin(), members.end(), v) == members.end()) 
                return true;
        }
    }
    return false;
}

int main () {
    int TCs, N, M, X, Y;
    cin >> TCs;

    // For each testcase
    for (int tc = 0; tc < TCs; tc++) {
        // Clearing Data Structures
        for (int i = 0; i < 100001; i++) {
            adjList[i].clear();
            transpose[i].clear();
        }
        order.clear();

        // Receiving input
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &X, &Y);
            X--; Y--;
            adjList[X].push_back(Y);
            transpose[Y].push_back(X);
        }

        // Kosaraju's Algorithm pass 1
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < N; i++) {
            if (!visited[i]) 
                kosaraju(i, 1);
        }

        // Kosaraju's Algorithm pass 2
        memset(visited, 0, sizeof visited);
        int pushes = 0;
        for (int i = N - 1; i >= 0; i--) {
            // For each SCC
            if (!visited[order[i]]) {
                kosaraju(order[i], 2);

                if (!hasIncoming()) pushes++;

                members.clear();
            }
        }
        // Display Answer
        cout << pushes << endl;     
    }
    return 0;
}
