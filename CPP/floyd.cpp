/*
O(N^3) Floyd Warshall 

- APSP O(N^3) algorithm, to be used with adjacency matrix of N <= 450

Variants
- Classic APSP
- APSP with backtrack
- APSP with negative cycles finding

Time: O(N^3)
Space: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9;

int adjmat[450][450];

/*
 * Classic Floyd Warshall Algorithm
 */
void floyd() {
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++){
                if (adjmat[i][k] != INF && adjmat[k][j] != INF) // Since negative weights may exist
                    adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
            }
        }
    }
}

/*
 * Floyd Warshall with Backtrack
 * 
 * - pred[i][j] stores the predecessor of j in the shortest path from i to j
 * - a shortest path i -> j => i -> ... -> pred[i][j] -> j
 */
int pred[N][N];
void floyd_backtrack() {
    // Initialize pred matrix
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            pred[i][j] = i;
        }
    }

    // Floyd Warshall Algorithm
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++){
                if (adjmat[i][k] != INF && adjmat[k][j] != INF) {
                    if(adjmat[i][j] > adjmat[i][k] + adjmat[k][j]) {
                        adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
                        pred[i][j] = pred[k][j];
                    }
                }
            }
        }
    }
}

/*
 * Floyd Warshall with Negative Cycles
 * 
 * - Find nodes in negative cycles
 * - Update adjmat with all arbitrarily short paths
 */
void floyd_neg_cycles() {
    // Classic Floyd Warshall
    floyd();

    // Find nodes in negative cycles
    set<int> in_neg_cycles;
    for(int i = 0; i < N; i++) {
        if(adjmat[i][i] < 0) {
            in_neg_cycles.insert(i);
            adjmat[i][i] = -INF;
        }
    }

    // Update adjmat with all arbitrarily short paths
    for (auto k : in_neg_cycles) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (adjmat[i][k] != INF && adjmat[k][j] != INF)
                    adjmat[i][j] = -INF;
            }
        }
    }
}
