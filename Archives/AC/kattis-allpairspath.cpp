/*
kattis-allpairspath

- First we use floyd warshall to find the shortest path between all pairs of nodes.

- (1) With a path between u, v, if there exists a node in a negative cycle in that path, then
  the path is arbitrarily short. We need to update all such paths to -INF.

- To do this, first we find all nodes in negative cycles. This can be done by checking adjmat[i][i] < 0.
  We also need to update adjmat[i][i] to -INF.

- Next, from (1), observe that we can update all paths between i, j where i is in a negative cycle to -INF.
  This can be done by iterating over all nodes in negative cycles and updating adjmat[i][j] to -INF.
  THis is O(N^3) which is fine since floyd warshall is also O(N^3).

- Common mistakes
    - Graph is not simple, we need to take minimum while taking in edge input
    - Negative weights are in, need to check for existing path in floyd warshall relax step

Time: O(N^3)
Space: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;

const int INF = (int) 1e9;

int adjmat[151][151];

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    if(N == 0 && M == 0 && Q == 0) exit(0);

    // Initialize adjacency matrix
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            adjmat[i][j] = INF;
        }
        adjmat[i][i] = 0;
    }

    // Receive graph input
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjmat[u][v] = (min(adjmat[u][v], w));
    }

    // Floyd Warshall
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if (adjmat[i][k] != INF && adjmat[k][j] != INF) // Since negative weights exist
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
            }
    }

    // Find nodes in negative cycles
    set<int> in_neg_cycles;
    for(int i = 0; i < N; i++) {
        if(adjmat[i][i] < 0) {
            in_neg_cycles.insert(i);
            adjmat[i][i] = -INF;
        }
    }

    // Update adjmat with all arbitrarily short paths
    for (auto k : in_neg_cycles) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (adjmat[i][k] != INF && adjmat[k][j] != INF)
                    adjmat[i][j] = -INF;
    }

    // Answer queries
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        if(adjmat[u][v] == INF) cout << "Impossible" << endl;
        else if(adjmat[u][v] == -INF) cout << "-Infinity" << endl;
        else cout << adjmat[u][v] << endl;
    }
    cout << endl;
}

int main() {
    while(true) solve();
    return 0;
}
