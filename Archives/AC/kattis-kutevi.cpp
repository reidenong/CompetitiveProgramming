/*
kattis-kutevi

- using top down DP, this question is abit similar to coin change
  except that instead of just subtracting coins we can add coins as well
  and there are multiple base cases 

- DP state is (angle), and the transition is to either add or subtract a known angle.

- keep in mind that 360 is a known angle, and to take advantage of this
  we need to be able to go beyond 360 such that we can leverage this tool, ie.
  1 1
  100
  40
  is a edge case that needs 100*4 - 360 to get 40.

Time: O(K*N*720)
Space: O(sizeof memo)
*/
#include <bits/stdc++.h>
using namespace std;
int N, K, query;
int known[11];
int memo[725];

// DP for validity of state (angle) with transitions of adding or subtracting a known angle.
int DP (int angle) {
    if (angle == 0 || angle == 360) return 1;
    if (angle < 0 || angle > 720) return 0;

    int &ans = memo[angle];
    if (ans != -1) return ans;

    for (int i = 0; i < N; i++) {
        ans = max(ans, DP(angle - known[i]));
        ans = max(ans, DP(angle + known[i]));
    }
    return ans;
}

// MAIN
int main () {
    // Receiving input
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> known[i];
    known[N] = 360;
    N++;

    // Initializing memoization array
    memset(memo, -1, sizeof memo);

    // For each query, DP
    for (int i = 0; i < K; i++) {
        cin >> query;
        if (int res = DP(query); res == 1) cout << "YES" << endl;
        else if (int res = DP(query + 360); res == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
