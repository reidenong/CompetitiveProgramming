/*
kattis-visualgo

 - we want to count the number of shortest paths between 2 points in a graph

 - to find shortest paths, first we use dijkstra. We keep track of the predecessors
   of each node to create a shortest path tree

 - then we use dfs to count the number of shortest paths by traversing from target back to source
   node. Note we do not keep track of visited nodes as we are counting the number of paths

 - important to note that we cannot let the initial estimate of the all nodes to be INT_MAX, as we
   may encounter overflow errors when adding weights to the estimate.

Time: O((N + M) log M)
Mem: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<ii> adj[10001], pred[10001];
ll est[10001];
int N, M, s, t;

ll dfs(int u) {
    ll ans = 0;
    if (u == s) return 1;
    if (pred[u].empty()) return 0;
    for (auto [v, w] : pred[u]) {
        ans += dfs(v);
    }   
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;

    // Building the Graph
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    cin >> s >> t;

    // SSSP Dijkstra from S to get pred graph
    fill(est, est + N, 20000000);
    est[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int w = front.first;
        int u = front.second;

        if (w > est[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (est[u] + w < est[v]) {          // If we have new shorter path, destroy all predecessors so far
                pred[v].clear();
                pred[v].push_back({u, w});
                est[v] = est[u] + w;
                pq.push({est[v], v});
            } else if (est[u] + w == est[v]) {  // We want to keep all alternative shortest paths, so just add on
                pred[v].push_back({u, w});
            }
        }
    }

    // Counting the number of shortest paths from S to T
    cout << dfs(t) << endl;
}   
