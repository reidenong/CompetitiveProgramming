/*
kattis-transportationplanning

- NOTE: This problem cannot be done in python due to high I/O requirements

- The problem is to find the minimum distance between all pairs of nodes in a graph, and then to update the 
  distance between 2 nodes to see if the distance can be reduced.

- Observation 1. The graph is guaranteed to be connected. This is very important because it means that the distance
  between any 2 nodes is finite

- We first find the minimum total distance without changing any edge.

- Next for each undefined edge, we update the distance between 2 nodes and find the minimum total distance. Note that
  we have to run floyd warshall again as the distances between each other pair of nodes will change as well.

Time: O(N^4)
Space: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int INF = (int) 1e9;

double coord_dist(ii a, ii b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

vector<vector<double>> floyd(vector<vector<double>> adjmat, int N) {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
            }
        }
    }
    return adjmat;
}

double find_total_dist(const vector<vector<double>>& adjmat, int N) {
    double total_dist = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            total_dist += adjmat[i][j];
        }
    }
    return total_dist;
}

void solve() {
    int N;
    cin >> N;
    if (N == 0) exit(0);

    // Receiving input, building graph
    vector<ii> nodes(N);
    vector<vector<double>> adjmat(N, vector<double>(N, INF));
    for (int i = 0; i < N; ++i) adjmat[i][i] = 0;

    for (int i = 0; i < N; ++i) {
        cin >> nodes[i].first >> nodes[i].second;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        adjmat[x][y] = adjmat[y][x] = coord_dist(nodes[x], nodes[y]);
    }

    vector<ii> undefined_edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (adjmat[i][j] == INF) {
                undefined_edges.push_back(make_pair(i, j));
            }
        }
    }

    // Floyd warshall find all shortest distance first
    adjmat = floyd(adjmat, N);
    double original_dist = find_total_dist(adjmat, N);

    // Try all undefined edges
    double min_dist = INF;
    ii node_reduction;
    for (auto& edge : undefined_edges) {
        int i = edge.first, j = edge.second;
        vector<vector<double>> adjmat2 = adjmat;
        adjmat2[i][j] = adjmat2[j][i] = coord_dist(nodes[i], nodes[j]);

        adjmat2 = floyd(adjmat2, N);
        double curr_min_dist = find_total_dist(adjmat2, N);

        if (curr_min_dist < min_dist) {
            min_dist = curr_min_dist;
            node_reduction = make_pair(i, j);
        }
    }

    // Output answer
    cout << fixed << setprecision(7);
    if (original_dist - min_dist < 0.00005) {
        cout << "no addition reduces " << original_dist << endl;
        return;
    }

    cout << "adding " << node_reduction.first << " " << node_reduction.second;
    cout << " reduces " << original_dist;
    cout << " to " << min_dist << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        solve();
    }
    return 0;
}
