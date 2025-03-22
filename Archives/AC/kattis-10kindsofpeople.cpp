/*
kattis-10kindsofpeople

- Determine if two coordinates are connected, with multiple queries

- given large number of queries, we cannot use DFS repeatedly as it will TLE.

- Instead, we first use dfs to obtain groupings, where each group of connected
  coordinates are given a unique group number. Hence, if two coordinates are in 
  the same group, they are connected. This way, we only need to DFS once

Time: O(RC)
Space: O(RC)
*/
#include <bits/stdc++.h>
using namespace std;
int Rows, Cols, queries, group = 1;
char c;
int grid[1001][1001];
int visited[1001][1001];    // Also describes the groupings of each coordinate

// Flood Fill DFS
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
void dfs (int row, int col) {
    visited[row][col] = group; // Mark as visited in the current group

    // Explore neighbours
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < Rows && nc >= 0 && nc < Cols &&     // Check bounds
            visited[nr][nc] == 0 &&                             // Check if visited
            grid[nr][nc] == grid[row][col]) {                   // Check if same color
            dfs(nr, nc);
        }
    }
    return;
}

int main () {
    scanf("%d %d", &Rows, &Cols);

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    // DFS to determine groupings
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (visited[i][j] == 0) {
                dfs(i, j);
                group++;
            }
        }
    }

    // View groupings (Debug)
    /*
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    // For each query
    scanf("%d", &queries);
    int r1, c1, r2, c2;
    for (int q = 0; q < queries; q++) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        // Valid if in same group
        if (visited[r1][c1] != visited[r2][c2]) cout << "neither" << endl;
        else if (grid[r1][c1] == 0) cout << "binary" << endl;
        else cout << "decimal" << endl;
    }
}
