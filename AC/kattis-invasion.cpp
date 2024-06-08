/*
kattis-invasion

- Dijkstra from multiple sources multiple times.

- We want to preserve the same graph, just keep running dijkstra from different sources.

Time: O(A * (N + M) * log(N))
Space: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<ii> adj[10001];
ll est[10001];

void solve() {
    // Clearing Data Structures
    fill(est, est + 10000, 100000);
    while (!pq.empty()) pq.pop();
    for (int i = 0; i < 10000; i++) adj[i].clear();

    // Receiving input
    int N, M, A, K;
    cin >> N >> M >> A >> K;

    if (N + M + A + K == 0) exit(0);

    // Building graph
    for (int i = 0; i < M; i++) {           
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // For building each base
    for (int i = 0; i < A; i++) {
        int base; 
        cin >> base; base--;
        pq.push({0, base});
        est[base] = 0;

        // Dijkstra
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

        // Counting safe points
        int safe = 0;
        for (int j = 0; j < N; j++) {
            if (est[j] >= K)safe++;
        }
        cout << safe << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) solve();
    return 0;
}
