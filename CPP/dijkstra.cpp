/*
 * SSSP Dijkstra
 *
 * Time: O(E log V)
 * Status: tested (https://judge.yosupo.jp/submission/276965)
 */
const ll INF = 1e18;
vll dijkstra(int src, vector<vii>& adj) {
    int n = adj.size();
    vll dist(n, INF);
    min_heap<pair<ll, int>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}