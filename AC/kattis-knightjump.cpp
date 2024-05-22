/*
kattis-knightjump

- BFS for each move that a knight can make

- we can set all block cells as already visited so we dont go to those cells

Time: O(N^2)
Space: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> moves[] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
int visited[101][101];
vector<pair<int, int>> frontier;
vector<pair<int, int>> next_frontier;

int main() {
    // Resetting DSes
    memset(visited, 0, sizeof visited);
    frontier.clear();
    next_frontier.clear();

    int N;
    cin >> N;

    // Reading board input
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char ch;
            cin >> ch;
            if (ch == 'K') {
                frontier.push_back({r, c});
                visited[r][c] = 1;
            } else if (ch == '#') 
                visited[r][c] = 1;
        }
    }

    // Frontier BFS
    int steps = 0;
    bool done = false;
    while (!frontier.empty()) {
        next_frontier.clear();

        for (auto p : frontier) {
            int r = p.first, c = p.second;

            if (r == 0 && c == 0) {   // If we reach the top left corner
                done = true;
                break;
            }

            for (auto m : moves) {              // For everywhere we can move from current loc
                int new_r = r + m.first;
                int new_c = c + m.second;

                if (new_r < 0 || new_r >= N || new_c < 0 || new_c >= N) continue;   // OOB
                if (visited[new_r][new_c]) continue;                                // Visited

                visited[new_r][new_c] = 1;
                next_frontier.push_back({new_r, new_c});
            }
        }
        if (done) break;   // No more moves
        frontier = next_frontier;
        steps++;
    }

    if (done)
        cout << steps << endl;
    else
        cout << -1 << endl;
}
