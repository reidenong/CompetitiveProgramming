/*
kattis-mallmania

- standard multi-source BFS, we start of with all of mall 1 in frontier, then
  we mark all of mall 2 as an end point, and then BFS.

- Note: Similar approach is too slow in python

Time: O(search_space) est (2000^2)
Mem: O(search_space) est (2000^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int visited[2001][2001];
vector<pair<int, int>> frontier;
vector<pair<int, int>> next_frontier;

int main() {
    while (true) {
        // Resetting DSes
        frontier.clear();
        memset(visited, 0, sizeof(visited));

        // Receiving input
        int N;
        cin >> N;
        if (N == 0) break;
        int x, y;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);
            frontier.push_back({x, y});
        }
        cin >> N;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);
            visited[x][y] = 2;
        }

        // Multi Source BFS
        int dist = 0;
        bool finished = false;
        while (!frontier.empty()) {
            next_frontier.clear();

            for (auto p : frontier) {
                x = p.first; y = p.second;

                if (x < 0 || x > 2000 || y < 0 || y > 2000) continue;

                if (visited[x][y] == 1) continue;

                if (visited[x][y] == 2) {
                    cout << dist << endl;
                    finished = true;
                    break;
                }

                visited[x][y] = 1;
                next_frontier.push_back({x + 1, y});
                next_frontier.push_back({x - 1, y});
                next_frontier.push_back({x, y + 1});
                next_frontier.push_back({x, y - 1});
            }

            frontier = next_frontier;
            dist++;

            if (finished) break;
        }
    }
}
