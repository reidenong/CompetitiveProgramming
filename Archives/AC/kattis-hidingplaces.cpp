/*
kattis-hidingplaces

- Use BFS to find out all the locations the knight can go to.

- We use frontier to easily keep track of the number of steps we have taken
  to get to all the places in the same location.

- when next_frontier is empty, frontier contains the furthest points from the start 
  location, and all we need to do is to sort and output.

Time: O(Board_Space)
Space: O(Board_Space)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<int, int> moves[] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
int visited[8][8];
vector<pair<int, int>> frontier;
vector<pair<int, int>> next_frontier;

void solve() {
    // Resetting DSes
    memset(visited, 0, sizeof visited);
    frontier.clear();
    next_frontier.clear();

    // Receiving input
    char r_char, c_char; int r, c;
    cin >> c_char >> r_char;
    r = r_char - '1';
    c = c_char - 'a';

    // Frontier BFS
    int steps = 0;
    frontier.push_back({r, c});
    visited[r][c] = 1;
    while (!frontier.empty()) {
        next_frontier.clear();

        for (auto p : frontier) {
            int r = p.first, c = p.second;

            for (auto m : moves) {              // For everywhere we can move from current loc
                int new_r = r + m.first;
                int new_c = c + m.second;

                if (new_r < 0 || new_r >= 8 || new_c < 0 || new_c >= 8) continue;   // OOB
                if (visited[new_r][new_c]) continue;                                // Visited

                visited[new_r][new_c] = 1;
                next_frontier.push_back({new_r, new_c});
            }
        }
        if (next_frontier.empty()) break;   // No more moves
        frontier = next_frontier;
        steps++;
    }

    // Sort frontier top to bottom (8 - 1) then left to right (a - h)
    for (auto &p : frontier)                    // Negate row to sort top to bottom
        p.first *= -1;     
    sort(frontier.begin(), frontier.end());     // Built in pair sorting

    // Output result
    cout << steps;
    for (auto p : frontier) 
        cout << " " << (char)('a' + p.second) << (char)('1' + (p.first*-1));
    cout << endl;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }    
}
