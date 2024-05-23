/*
kattis-flowerytrails

- First we use Dijkstra to find shortest path from 0 to (N - 1)

- Next we need to find 2*(sum of all edges in shortest paths). We can do this
  by creating a predecessor graph in our first dijkstra graph, where the predecessor graph is 
  Directed and acyclic with (N-1) as the root

- Now DFS on this graph gives us the sum of all edges on the shortest paths from 0 to N-1

Time: O((N + M) * log(N))
Space: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<ii> adj[10001], pred[10001];
ll est[10001];
int visited[10001];
int N, M;

// DFS to backtrack on shortest path graph
ll dfs(int v) {
    if (v == 0 || visited[v]) return 0;
    visited[v] = 1;

    ll ans = 0;
    for (auto [u, w] : pred[v]) {
        ans += dfs(u) + 2 * w;
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
        adj[v].push_back({u, w});
    }

    // SSSP Dijkstra from S to get pred graph
    fill(est, est + N, INT_MAX);
    est[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int w = front.first;
        int u = front.second;

        if (w > est[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (est[u] + w < est[v]) {
                pred[v].clear();
                pred[v].push_back({u, w});
                est[v] = est[u] + w;
                pq.push({est[v], v});
            } else if (est[u] + w == est[v]) {
                pred[v].push_back({u, w});
            }
        }
    }

    // Backtrack predecessors
    cout << dfs(N - 1) << endl;
}   
