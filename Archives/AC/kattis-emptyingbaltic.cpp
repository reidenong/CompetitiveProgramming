/*
kattis-emptyingbaltic

- We want to do dijkstra from the drain (source) to all other cells

- We use a priority queue to store the cells that we need to visit. We always want to visit the
  cells with the smallest estimate first, as that gives us the maximum depth in which we can move to
  the other cells

Time: O(HW log HW), where H is the height of the grid and W is the width of the grid
Space: O(HW)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
priority_queue<iii, vector<iii>, greater<iii>> pq;
ii dydx[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int grid[501][501];
ll est[501][501];
bool visited[501][501];

int main() {
    int h, w;
    cin >> h >> w;

    // Creating the graph
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] >= 0) {
                est[i][j] = 0;
            }
        }
    }

    // Receive drain (source) input
    int d_r, d_c;
    cin >> d_r >> d_c;
    d_r--; d_c--;

    // Dijkstra
    est[d_r][d_c] = grid[d_r][d_c];
    pq.push({grid[d_r][d_c], d_r, d_c});
    while (!pq.empty()) {
        iii curr = pq.top();pq.pop();
        int weight = get<0>(curr);
        int x = get<1>(curr);
        int y = get<2>(curr);

        for (ii d : dydx) {
            int nx = x + d.first;
            int ny = y + d.second;

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;       // OOB

            if (max(grid[nx][ny], weight) < est[nx][ny]) {              // Relax
                est[nx][ny] = max(grid[nx][ny], weight);
                pq.push({est[nx][ny], nx, ny});
            }
        }
    }

    // Print sum of all drainage
    ll ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans -= est[i][j];
        }
    }
    cout << ans << endl;
}   
