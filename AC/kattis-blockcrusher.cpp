/*
kattis-blockcrusher

- We want to do grid SSSP from the top row to the bottom row.

- We can model the grid as a graph, and then attach a auxiliary source and dest node to the top and
  bottom row respectively.

- To model an auxiliary source, we add all items in the top row to the PQ at the start to symbolize a imaginary
  0 edge from source node to the bottom row.

- To model an auxiliary dest node, we do a linear sweep of all items in bottom row and find the minimum

- We then backtrack from the minimum to the source node to find the path.

Time Complexity: O(R * C * log(R * C))
Space Complexity: O(R * C)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii>> pq;
int weight[21][61];
int est[21][61];
int pred[21][61];
int R, C;

// 2d movement vector
ii moves[8] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

ii idxToPos(int i) {
    return {i / C, i % C};
}

int posToIdx(ii p) {
    return p.first * C + p.second;
}

void solve() {
    cin >> R >> C;
    if (R == 0 && C == 0) exit(0);

    // Read in the grid
    char c;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> c;
            weight[i][j] = c - '0';
            est[i][j] = 100000000;
            pred[i][j] = -1;
        }
    }

    // SSSP Dijkstra from S
    for (int i = 0; i < C; i++) {
        pq.push({weight[0][i], posToIdx({0, i})});
        est[0][i] = weight[0][i];
    }

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
                pred[next.first][next.second] = posToIdx(pos);
            }
        }
    }

    // Find the minimum distance to the bottom row
    int minDist = 100000000;
    int minIdx = -1;
    for (int i = 0; i < C; i++) {
        if (est[R - 1][i] < minDist) {
            minDist = est[R - 1][i];
            minIdx = posToIdx({R - 1, i});
        }
    }

    // Blank out the path
    while (minIdx != -1) {
        ii pos = idxToPos(minIdx);
        weight[pos.first][pos.second] = 0;
        minIdx = pred[pos.first][pos.second];
    }

    // Print the grid
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (weight[i][j] == 0) cout << ' ';
            else cout << weight[i][j];
        }
        cout << endl;
    }
    cout << endl;
}   

int main() {
    cin.tie(0);
    while (true) {solve();}
    return 0;
}
