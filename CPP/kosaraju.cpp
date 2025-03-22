/*
Kosaraju's Algorithm for finding SCCs

- SCCs are strongly connected components, which are groups of nodes in a graph where
    every node in the group can reach every other node in the group

- Kosaraju's Algorithm is a two-pass algorithm that finds the largest SCC in a graph.
  This does DFS once to find the topological order of the graph, and then DFS
  again in the topological order on the transpose of the graph, giving us a new function
  call for each SCC

- Usage case of kosaraju here is to see the size of each SCC, as well as its constituent nodes

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

int main () {
    int N, M, X, Y;

    // Receiving input, creating graph and its tranpose
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &X, &Y);
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
    int numOfSCCs = 0;
    cout << "SCCs:" << endl;
    for (int i = N - 1; i >= 0; i--) {          // Important to reverse for topological order
        // For each SCC
        if (!visited[order[i]]) {
            numOfSCCs++;
            kosaraju(order[i], 2);

            // Print members
            for (int j = 0; j < members.size(); j++) {
                printf("%d ", members[j]);
            }
            cout << endl;

            members.clear();
        }
    }
    cout << endl << "number of SCCs: " << numOfSCCs << endl;     
    return 0;
}
