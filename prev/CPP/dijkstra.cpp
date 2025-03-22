/*
SSSP Dijkstra

- Graph is weighted, no negative weights

Time: O((V + E) log V)
Space: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;

const int INF = (int) 1e9;

priority_queue<ii, vector<ii>, greater<ii>> pq;     // Priority Queue {est, node}
vector<ii> adj[10001];                              // Adjacency List {node, weight}
ll est[10001];                                      // Estimated Distance

/*
 * SSSP Dijkstra (Regular version)
 */
void dijkstra() {
    
    // N: Number of Nodes (0-indexed)
    // S: Source Node

    // SSSP Dijkstra from S
    fill(est, est + N, INF);
    est[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int w = front.first;
        int u = front.second;

        if (w > est[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (est[u] + w < est[v]) {
                est[v] = est[u] + w;
                pq.push({est[v], v});
            }
        }
    }
}   

/*
 * Backtrack Dijkstra
 *
 * - We can backtrack the shortest path(s) from the target node to the source node by creating
 *   a predecessor graph. The predecessor graph is a graph where pred[i] = {j, w} means that j
 *   is a predecessor of i with weight w.
 * 
 * - We can then use a DFS to iterate/count the number of shortest paths from the source node to the target
 *   node.
*/
vector<ii> pred[10001];                         // Predecessor Graph adjacency list

int dfs(int u) {

    // S: Source Node

    int ans = 0;
    if (u == s) return 1;
    if (pred[u].empty()) return 0;
    for (auto [v, w] : pred[u]) {
        ans += dfs(v);
    }   
    return ans;
}

void backtrack_dijkstra() {

    // N: Number of Nodes (0-indexed)
    // S: Source Node
    // T: Target Node
    // pred: predecessor graph, pred[i] = {j, w} means j is a predecessor of i with weight w

    // Dijkstra with backtracking
    fill(est, est + N, INF);
    est[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int w = front.first;
        int u = front.second;

        if (w > est[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (est[u] + w < est[v]) {          // If we have new shorter path, destroy all predecessors so far
                pred[v].clear();
                pred[v].push_back({u, w});
                est[v] = est[u] + w;
                pq.push({est[v], v});
            } else if (est[u] + w == est[v]) {  // We want to keep all alternative shortest paths, so just add on
                pred[v].push_back({u, w});
            }
        }
    }

    // Counting number of shortest paths
    int num_shortest_paths = backtrack_dfs(T);  // Number of shortest paths from s to t
}

/*
 * Grid Dijkstra
 *
 * - We may come across situations where we need to run Dijkstra on a grid. In this case,
 *   each grid cell has a weight associated with it, and we can move in 4 or 8 directions.
 * 
 * - Moving to a grid cell with a weight of w costs w units of time.
 */
ii moves[8] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
ii moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

ii idxToPos(int i) { return {i / C, i % C}; }
int posToIdx(ii p) { return p.first * C + p.second; }

priority_queue<ii, vector<ii>, greater<ii>> pq;
int weight[R][C];
int est[R][C];

void grid_dijkstra() {

    // R: Number of Rows
    // C: Number of Columns
    // S: Source Cell {s_r, s_c}

    // Initialize
    // for all cells (r, c) in grid:
    //      est[r][c] = INF

    pq.push({weight[s_r][s_c], posToIdx({s_r, s_c})});
    est[s_r][s_c] = weight[s_r][s_c];

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int dist = front.first, u = front.second;
        ii pos = idxToPos(u);

        if (dist > est[pos.first][pos.second]) continue;

        for (auto m : moves) {
            ii next = {pos.first + m.first, pos.second + m.second};
            if (next.first < 0 || next.first >= R || next.second < 0 || next.second >= C) continue;

            if (est[next.first][next.second] > est[pos.first][pos.second] + weight[next.first][next.second]) {
                est[next.first][next.second] = est[pos.first][pos.second] + weight[next.first][next.second];
                pq.push({est[next.first][next.second], posToIdx(next)});
            }
        }
    }
}
