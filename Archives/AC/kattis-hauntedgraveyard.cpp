/*
kattis-hauntedgraveyard

- Basically bellman ford, and watch out for negative cycles

- Part of the question is to convert a grid graph into a adjList.
  We can then apply bellman ford to this grid graph, and then 

- If we find negative cycles -> Never.
- If we can't reach the end node -> Impossible
- Otherwise, output the distance to the end node.

- Observe that the question wording is that "For each test case,
  if it is possible for Scared John to travel back in time indefinitely 
  without passing by the exit, output Never." This implies that a negative cycle where 
  John has to pass by the exit is not considered as "Never". This can be
  solved by not having any outgoing edges from the exit node, such that all of such negative cycles 
  will become invalid. 

Time: O(V*E)
Mem: O(N + E)
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

int INF = 1e9;
ii dydx[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

vector<ii> adj[901];
int tombstone[901];
int dist[901];
bool modified;
int W, H, N;

int convert(int x, int y){
    return y*W + x;
}

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

void solve() {
    // Clear Data Structures
    for (int i = 0; i < 901; i++){
        adj[i].clear();
        dist[i] = INF;
        tombstone[i] = 0;
    }

    // Check end of input
    cin >> W >> H;
    if (W == 0 && H == 0) exit(0);
    N = W*H;

    // Find tombstone
    int G;
    cin >> G;
    for (int i = 0; i < G; i++) {
        int r, c;
        cin >> r >> c;
        tombstone[convert(r, c)] = 1;
    }

    // Create rest of graph
    for (int u = 0; u < N; u++) {
        if (tombstone[u]) continue;
        if (u == N - 1) continue;

        int c = u / W;
        int r = u % W;

        for (int i = 0; i < 4; i++) {
            int nr = r + dydx[i].first;
            int nc = c + dydx[i].second;

            if (nr < 0 || nc < 0 || nr >= W || nc >= H) continue;
            if (tombstone[convert(nr, nc)]) continue;

            adj[u].push_back({convert(nr, nc), 1});
        }
    }

    // Create portals
    int E;
    cin >> E;
    for (int i = 0; i < E; i++) {
        int r1, c1, r2, c2, w;
        cin >> r1 >> c1 >> r2 >> c2 >> w;
        adj[convert(r1, c1)].clear();
        adj[convert(r1, c1)].push_back({convert(r2, c2), w});
    }

    // Run Bellman Ford
    dist[0] = 0;
    bellman_ford();

    // Output
    if (modified) {
        cout << "Never" << endl;
    } else if (dist[N - 1] == INF) {
        cout << "Impossible" << endl;
    } else{
        cout << dist[N - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) solve();
    return 0;
}
