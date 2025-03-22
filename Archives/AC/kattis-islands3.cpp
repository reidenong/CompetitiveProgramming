/*
kattis-islands3

- Basically DFS to visit all connected land tiles to count them as one island

- We do not assume that all clouds are island tiles, but what we can do is to
  consider all clouds are islands during DFS, and mark them as visited. This 
  helps us to achieve the minimum number of islands as clouds can help to merge
  islands together.

- As we only DFS on explicitly land tiles, we do not accidentally consider
  cloud only tiles as islands.

Time: O(RC)
Space: O(RC)
*/
#include <bits/stdc++.h>
using namespace std;
int Rows, Cols;
char c;
char grid[51][51];       // 0 = water, 1 = land, 2 = sea
int visited[51][51];    

// DFS to visit non water tiles
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
void dfs (int row, int col) {
    visited[row][col] = 1;      // mark as visited

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < Rows && nc >= 0 && nc < Cols && 
            grid[nr][nc] != 'W' && 
            visited[nr][nc] == 0) {
            dfs(nr, nc);
        }
    }
}

int main () {
    // Receiving input
    scanf("%d %d", &Rows, &Cols);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    // DFS on all land tiles
    int ans = 0;
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (grid[i][j] == 'L' && visited[i][j] == 0) {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
