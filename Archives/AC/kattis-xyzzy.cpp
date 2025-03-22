/*
kattis-xyzzy

- We want to do SSSP. We use bellman ford due to negative weights and the chance of negative weight cycles.

- First we inverse all the "energy" values, so we can find shortest path.

- Next is building the graph. First we figure out where all the end points are. We then build a 
  adj list with this information as well as the negated energy values.

- We then run bellman ford. We start with dist[0] = -100 because we start with +100 energy. Also
  note the relax function in bellman ford is modified so that we can only relax if the energy does not go below 0
  (above 0 in this case with negative values)

- Also note that even if it seems impossible to reach after one round of bellman ford, if there are
  negative weight cycles, it means in the real graph there is a way to get positively infinite energy, and
  thus we can reach the end if there is a route there.

- This means we check for negative weight cycles. For every node with a negative weight cycle, we run a dfs to search
  if the end node is connected. If it is, we cna reach the end node no matter the cost to get there due to the infinte
    energy we can get from the cycle.

Time: O(VE)
Space: O(V+E) 
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int INF = (int) 1e9;

vector<int> dist, dist_capture;
vector<int> temp[101];
vector<ii> adj[101];
int energy[101];
bool modified;
int N;

void bellman_ford(){
    for (int i = 0; i < N; i++){
        modified = false;
        for (int u = 0; u < N; u++){
            if (dist[u] != INF){
                for (auto [v, w]: adj[u]){
                    if (dist[u] + w >= 0) continue;
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
    cin >> N;
    if (N == -1) exit(0);

    // Clear Data Structures
    dist.assign(N, INF);
    for (int i = 0; i < N; i++){
        adj[i].clear();
        temp[i].clear();
    }

    // Create graph without weights
    for (int i = 0; i < N; i++) {
        int E, edges;
        cin >> E >> edges;
        energy[i] = -1 * E;

        for (int j = 0; j < edges; j++) {
            int u;
            cin >> u;
            temp[i].push_back(u - 1);       // 1-indexed to 0-indexed
        }
    }

    // Finishing graph weights
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < temp[i].size(); j++) {
            adj[i].push_back({temp[i][j], energy[temp[i][j]]});
        }
    }

    // Run Bellman Ford
    dist[0] = -100;
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

    // If negative cycle, check for connectedness to end
    for (auto i : neg_cycle){
        dfs(i);
    }

    if (dist[N-1] == INF) cout << "hopeless" << endl;
    else cout << "winnable" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) solve();
    return 0;
}
