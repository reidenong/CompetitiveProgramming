/*
kattis-texassummers

- SSSP Dijkstra with a twist

- Basically we have to find the shortest path from the start to the end. Since shady 
  spots are here, we are guaranteed that the best path either passes through some number 
  of shady spots or is a direct line from start to finish.

- We can build a adjlist. For every 2 shady spots/start/end, we can calculate the distance 
  between them and store in the edgelist. Since dist by pythagoras is root(x^2 + y^2), we just
  find the sum of squared manhattan distances.

- from here on is classic dijkstra. Note that we start from end position. This is so that when
  tracing predecessors we can report in linear order, which is fine because each edge is symmetric

Time: O((N + M) * log(N))
Space: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> pq;
vector<ii> adj[2502];
ii points[2502];
int pred[2502];
ll est[2502];

int get_dist(ii a, ii b) {
    return (a.first - b.first) * (a.first - b.first) 
        + (a.second - b.second) * (a.second - b.second);
}

int main() {
    int N;
    cin >> N;

    // Receive points
    for (int i = 0; i < N; i++) {                           // 0-indexed shady spots 
        int u, v;
        cin >> u >> v;
        points[i] = {u, v}; 
    }
    N += 2;
    cin >> points[N - 2].first >> points[N - 2].second;     // Start position
    cin >> points[N - 1].first >> points[N - 1].second;     // End position

    // Build the graph
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int d = get_dist(points[i], points[j]);
            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }

    // SSSP Dijkstra from S
    fill(est, est + N, INT_MAX);
    est[N - 1] = 0;                                     // Start at the end position, trace to start 
    pq.push({0, N - 1});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int dist = front.first, u = front.second;

        if (dist > est[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (est[u] + w < est[v]) {      // Relax step
                pred[v] = u;
                est[v] = est[u] + w;
                pq.push({est[v], v});
            }
        }
    }

    // Best path is a direct line from start to finish
    if (est[N - 2] == get_dist(points[N - 2], points[N - 1])) {
        cout << "-" << endl;
        return 0;
    }

    // Print the path
    int x = pred[N - 2];
    while (x != N - 1) {        // we take pred order as we are tracing from end to start
        cout << x << endl;
        x = pred[x];
    }
}   
