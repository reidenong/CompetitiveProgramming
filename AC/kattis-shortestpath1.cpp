/*
kattis-shortestpath1

- SSSP Dijkstra

Time: O((N + M) * log(N))
Space: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<ii> adj[10001];
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
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // SSSP Dijkstra from S
    fill(est, est + N, INT_MAX);
    est[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int w = front.first;
        int u = front.second;

        if (w > est[u]) continue;

        for (auto v : adj[u]) {
            if (est[u] + v.second < est[v.first]) {
                est[v.first] = est[u] + v.second;
                pq.push({est[v.first], v.first});
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
