/*
kattis-shortestpath3

- classic bellman ford question

- we do bellman ford once to relax all edges, then we do it again
  to check for negative cycles

- Note that nodes themselves not in negative cycles may still be reachable 
  from negative cycles, so there is a need to do dfs to mark all nodes

Time: O(VE)
Space: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int INF = (int) 1e9;

vector<int> dist, dist_capture;
vector<ii> adj[1001];
int N, M, Q, S;
bool modified;

void bellman_ford(){
    for (int i = 0; i < N; i++){
        modified = false;
        for (int u = 0; u < N; u++){
            if (dist[u] != INF){
                for (auto [v, w]: adj[u]){
                    if (dist[u] + w >= dist[v])continue;
                    dist[v] = dist[u] + w;
                    modified = true;
                }
            }
        }
        if (!modified) break;
    }
}

void dfs(int u) {
    if (dist[u] == -INF) return;

    dist[u] = -INF;
    for (auto [v, w]: adj[u]){
        dfs(v);
    }
}

void solve() {
    // Check end of input
    cin >> N >> M >> Q >> S;
    if (N == 0 && M == 0 && Q == 0 && S == 0) exit(0);

    // Clear Data Structures
    dist.assign(N, INF);
    for (int i = 0; i < N; i++){
        adj[i].clear();
    }

    // Create Graph
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Run Bellman Ford
    dist[S] = 0;
    bellman_ford();

    // Check for negative cycles
    vector<int> neg_cycle;
    dist_capture = dist;
    bellman_ford();
    for (int i = 0; i < N; i++){
        if (dist[i] != dist_capture[i]){
            neg_cycle.push_back(i);
        }
    }

    // Check for nodes connected to negative cycles
    for (auto u: neg_cycle){
        dfs(u);
    }

    // Answer queries
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        if (dist[x] == -INF) cout << "-Infinity" << endl;
        else if (dist[x] == INF) cout << "Impossible" << endl;
        else cout << dist[x] << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) solve();
    return 0;
}
