/*
kattis-walrusweights

- do backtracking with memoization. Since each weight is at most 1000
  and the ideal weight is 1000 as long as it exceeds 2k we can just stop 
  and return as adding additional weights will never be better.thus 
  we can do dp with memo[1k][2k].

- DP state is (idx, prev weight before [idx]), transition is choosing
  to take weight[idx] or not. WHen we hit N, then return total weight
  of the plates

- As we get the total weight of plates, keep choosing the one with the
  closer to 1k.

Time: O(N*W)
Space: O(N*W)
*/
#include <bits/stdc++.h>
using namespace std;
int N;
int weights[10001];
int memo[1010][2010];

int diff (int X) {
    return abs(X - 1000);
}

// DP state (idx, previous weight before [idx]), returns closest
// group of weights to 1000
int DP (int idx, int prevWeight) {
    // Base cases
    if (idx == N) return prevWeight;
    if (prevWeight > 2000) return 2005;

    // Check if calculated before
    int &ans = memo[idx][prevWeight];
    if (ans != -1) return ans;

    // Choose to either take or ignore weight [idx]
    int ignore = DP(idx + 1, prevWeight);
    int take = DP(idx + 1, prevWeight + weights[idx]);

    // Choose to take the closer number to 1000, larger weight if equal 
    if (diff(take) <= diff(ignore)) return ans = take;
    else return ans = ignore;
}

int main () {
    // Receiving input
    cin >> N;
    for (int i = 0; i < N; i++) cin >> weights[i];

    // DP
    memset(memo, -1, sizeof memo);
    cout << DP (0, 0) << endl;
}
