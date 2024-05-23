/*
kattis-shortestpath2

- SSSP Dijkstra with a modified relax function, we now have a additional bottleneck of waiting
  time at each node.

- given the earliest estimate to reach a node, we can calculate the earliest time to reach the
  next node by taking the waiting time at each node into account

Time: O((N + M) * log(N))
Space: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> iiii;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<iiii> adj[10001];
ll est[10001];

void solve() {
    int N, M, Q, S;
    cin >> N >> M >> Q >> S;

    if (N == 0 && M == 0 && Q == 0 && S == 0) exit(0);

    // Clearing DSes
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        est[i] = INT_MAX;
    }
    while (!pq.empty()) pq.pop();

    // Building the Graph
    for (int i = 0; i < M; i++) {
        int u, v, t, p, d;
        cin >> u >> v >> t >> p >> d;
        adj[u].push_back({v, t, p, d});
    }

    // SSSP Dijkstra from S
    fill(est, est + N, INT_MAX);
    est[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int curr = front.first, u = front.second;

        if (curr > est[u]) continue;

        // Find earliest time where we can move off from u
        for (auto [v, t, p, d] : adj[u]) {      
            int earliest;
            
            // Earliest move off time is t 
            if (est[u] <= t) earliest = t;          
            
            // We cant move off from this node, we past t and p == 0
            else if (p == 0) continue;          
            
            // We have to wait at this node for some number of cycles
            else {                              
                int wait_cycles = ceil((float)(est[u] - t) / (float) p);
                earliest = t + wait_cycles * p;
            }

            // Relaxation
            if (earliest + d < est[v]) {
                est[v] = earliest + d;
                pq.push({est[v], v});
            }
        }
    }

    // Answering each Query
    for (int q = 0; q < Q; q++) {
        int x;
        cin >> x;
        if (est[x] == INT_MAX) cout << "Impossible" << endl;
        else cout << est[x] << endl;
    }
    cout << endl;
}   

int main() {
    while (true) {
        solve();
    }
}
