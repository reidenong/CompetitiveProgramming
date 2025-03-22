/*
kattis-oceancurrents

- 0-1 BFS with deque

Time: O(TC * R * C)
Mem: O(R * C)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> dir[8] = {{-1, 0},{-1, 1},{0, 1},{1, 1},{1, 0},{1, -1},{0, -1},{-1, -1}};
int visited[1001][1001];
int grid[1001][1001];
deque<tuple<int, int, int>> deq;

void reset() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            visited[i][j] = 0;
        }
    }
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    string s;
    char c;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    int TC;
    scanf("%d", &TC);
    for (int tc = 0; tc < TC; tc++) {
        // Reset DSes
        reset();
        deq.clear();

        // Read Query input
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--; c1--; r2--; c2--;
        visited[r1][c1] = 1;
        deq.push_back({r1, c1, 0});

        // 0-1 BFS with deque
        while (!deq.empty()) {
            tuple<int, int, int> p = deq.front(); deq.pop_front();
            int r = get<0>(p), c = get<1>(p), cost = get<2>(p);
            visited[r][c] = 1;

            if (r == r2 && c == c2) {
                printf("%d\n", cost);
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nr = r + dir[i].first;
                int nc = c + dir[i].second;
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (visited[nr][nc]) continue;

                if (grid[r][c] == i) {
                    deq.push_front({nr, nc, cost});
                } else {
                    deq.push_back({nr, nc, cost + 1});
                }
            }
        }
    }
}
