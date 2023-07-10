/*
kattis-spiderman

- DP qn. State is (distance [idx], current pos) and transition is to climb up or down

- we dont actually need a third state variable in maxHeight as we can just calculate the max Height at
  every given state.

- for backtracking accept every solution that satisfies climbing height <= maxHeight

Time: O(N*dist/2)
Space: O(N*dist/2)
*/
#include <bits/stdc++.h>
using namespace std;
int N;
int heights[41];        // max height
int memo[42][501];      // memoize array, pos < 500 to fulfil max 1k travel limit

// DP that returns minimum building height to go from distance [idx] to distance [N]
int DP (int idx, int pos) {
    // Base Cases
    if (pos < 0 || pos > 500) return 1e5;           // Invalid action, too high / too low
    if (idx == N && pos == 0) return 0;             // End of simulation
    if (idx == N) return 1e5;                       // Ended climbs but still not at ground

    int &ans = memo[idx][pos];
    if (ans != -1) return ans;

    // Choose to climb up or down
    int up = DP(idx + 1, pos + heights[idx]);
    int down = DP(idx + 1, pos - heights[idx]);
    return ans = max(pos, min(up, down));
}

// Main
int main () {
    int TCs;
    cin >> TCs;
    for (int tc = 0; tc < TCs; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> heights[i]; 

        // Initialize memoize array, DP
        memset(memo, -1, sizeof memo);
        int maxHeight = DP(0, 0);

        // Impossible criterion
        if (maxHeight > 1000) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        // Visualize DP states, for debug
        /*
        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < 15; j++) {
                if (DP(i, j) < 1001)
                    cout << DP(i, j) << " ";
                else cout << "_ ";
            }
            cout << endl;
        }
        */
        
        // Backtrack to find steps
        int pos = 0;
        for (int i = 0; i < N; i++) {
            // Accept any way as long as it gives us a solution to get from
            // idx i to idx N equal to or smaller than maxHeight
            if (pos != 0 && DP(i + 1, pos - heights[i]) <= maxHeight) {
                cout << "D";
                pos -= heights[i];
            }
            else {
                cout << "U";
                pos += heights[i];
            }
        }
        cout << endl;
    }
  return 0;
}
