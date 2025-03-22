/*
kattis-equivalences

- Basically we want to know the number of additional edges we need to make the graph
  strongly connected. 

- We can do this by first identifying the SCCs in the graph. We realise that to create 
  a SCC graph, all we need to do is to strongly connect all the SCCs. However, we note
  that some SCCs may already have incoming/outgoing edges exisiting, and we do not
  need to add incoming / outgoing edges to these SCCs.

- Thus we identify each SCC, then we track the existence of incoming / outgoing edges 
  into the SCC. The answer is the maximum of (noIncoming, noOutgoing). This is because
  by adding a edge, we fulfil the incoming edge of one SCC and the outgoing edge of
  another SCC, thus we only need to cater to the maximum of the two.

- Note that an edge case exists at n(SCCs) = 1. while noIncoming, noOutgoing = 1,1
  the graph is alr strongly connected so no extra edge is needed.

Time: O(V + E)
Mem: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[20001];
vector<int> transpose[20001];
vector<int> order;
vector<int> members;
int visited[20001];

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

// Check if SCC has any incoming edges / Outgoing edges
bool hasIncoming () {
    for (auto &mem : members)
        for (auto &v : transpose[mem])
            if (find(members.begin(), members.end(), v) == members.end()) 
                return true;
    return false;
}
bool hasOutgoing () {
    for (auto &mem : members)
        for (auto &v : adjList[mem])
            if (find(members.begin(), members.end(), v) == members.end()) 
                return true;
    return false;
}

int main () {
    int TCs, N, M, X, Y;
    cin >> TCs;

    // For each testcase
    for (int tc = 0; tc < TCs; tc++) {

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
        int SCCs = 0, noIncoming = 0, noOutgoing = 0;
        memset(visited, 0, sizeof visited);
        for (int i = N - 1; i >= 0; i--) {
            // For each SCC
            if (!visited[order[i]]) {
                SCCs++;
                kosaraju(order[i], 2);

                if (!hasIncoming()) noIncoming++;
                if (!hasOutgoing()) noOutgoing++;

                members.clear();
            }
        }
        if (SCCs == 1) cout << 0 << endl;                   // Already strongly connected
        else cout << max(noIncoming, noOutgoing) << endl;

        // Clearing Data Structures
        order.clear();
        for (int i = 0; i < N; i++) {
            adjList[i].clear();
            transpose[i].clear();
        }
    }
    return 0;
}
