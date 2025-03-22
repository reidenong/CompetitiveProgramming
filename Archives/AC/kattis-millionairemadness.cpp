/*
kattis-millionairemadness

- Essentially, this problem is asking us to find a path with the smallest maximum edge to reach the end.
  We can use dijkstra's algorithm to solve this problem.

- est usually stores the minimum cost to reach a certain position, but in this case, we are storing the maximum edge
  that we have encountered so far to reach a certain position.

- our relax function checks if we can reach a certain position with a smaller maximum edge that what we have encountered.
  If we can, we update the maximum edge and push the position to the priority queue.

Time: O(NM log NM)
Mem: O(NM)
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int INF = 1e9;
ii moves[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
int vault[1001][1001];
int est[1001][1001];

int main() {
    // Receiving input
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> vault[i][j];
        }
    }

    // Initialize est to INF
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            est[i][j] = INF;
        }
    }

    // Dijkstra's algorithm (on grid)
    est[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
        auto [dist, pos] = pq.top(); pq.pop();

        if (dist > est[pos.first][pos.second]) continue;

        for (auto m : moves) {
            ii next = {pos.first + m.first, pos.second + m.second};
            if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;

            if (est[next.first][next.second] > max(est[pos.first][pos.second], vault[next.first][next.second] - vault[pos.first][pos.second])) {
                est[next.first][next.second] = max(est[pos.first][pos.second], vault[next.first][next.second] - vault[pos.first][pos.second]);
                pq.push({est[next.first][next.second], next});
            }
        }
    }

    cout << est[N - 1][M - 1] << endl;
}
