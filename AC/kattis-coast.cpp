/*
kattis-coast

- observation is that every border is basically the number of adjacent sea tiles
  to each land tile (not just water tile)

- since all sea tiles have some connection to the outside edge of the grid, we
  can do a DFS on all the edges of the grid to find all the sea tiles.

- once we have all sea tiles, we do a DFS on all land tiles to find the number
  of adjacent sea tiles to each land tile.

Time: O(RC)
Space: O(RC)
*/
#include <bits/stdc++.h>
using namespace std;
int Rows, Cols;
char c;
int grid[1001][1001];       // 0 = water, 1 = land, 2 = sea
int visited[1001][1001];    
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
long long ans = 0;

// Sea DFS
void seaDFS (int row, int col) {
    visited[row][col] = 1;      // mark as visited
    grid[row][col] = 2;         // mark as sea

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < Rows && nc >= 0 && nc < Cols && 
            grid[nr][nc] == 0 && 
            visited[nr][nc] == 0) {
            seaDFS(nr, nc);
        }
    }
}

// Land DFS 
void landDFS (int row, int col) {
    visited[row][col] = 1;      // mark as visited

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        // Add border if adjacent tile is out of bounds or sea
        if (nr < 0 || nr >= Rows || nc < 0 || nc >= Cols ||
            grid[nr][nc] == 2) {
            ans++;
            continue;
        }

        // Land block, continue DFS
        if (nr >= 0 && nr < Rows && nc >= 0 && nc < Cols && 
            grid[nr][nc] == 1 && 
            visited[nr][nc] == 0) {
            landDFS(nr, nc);
        }
    }
}

int main () {
    // Receiving input
    scanf("%d %d", &Rows, &Cols);
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            scanf(" %c", &c);
            grid[i][j] = c - '0';
        }
    }

    // Sea DFS on all edges of the grid
    for (int row = 0; row < Rows; row++) {
        if (grid[row][0] == 0 && visited[row][0] == 0) {
            seaDFS(row, 0);
        }
        if (grid[row][Cols-1] == 0 && visited[row][Cols-1] == 0) {
            seaDFS(row, Cols-1);
        }
    }
    for (int col = 0; col < Cols; col++) {
        if (grid[0][col] == 0 && visited[0][col] == 0) {
            seaDFS(0, col);
        }
        if (grid[Rows-1][col] == 0 && visited[Rows-1][col] == 0) {
            seaDFS(Rows-1, col);
        }
    }

    // View grid with marked sea tiles (debug)
    /*
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    */

    // Land DFS on the whole grid
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                landDFS(i, j);
            }
        }
    }

    cout << ans << endl;
}
