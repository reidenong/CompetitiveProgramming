/*
  kattis-exactchange2

  - Essentially single-use coin change, use memo[idx][change] to track minimum number of coins.
  - Try with actual bill before increasing up to get minimum payable value

Time: O(N*max_bill)
Space: O(N*max_bill)
*/
#include <bits/stdc++.h>
using namespace std;
int N, bill;
int cash[101];
int memo[101][10002];

// DP for coin change
int DP (int idx, int price) {
    if (price == 0) return 0;
    if (idx == N || price < 0) return 101;
    
    int &ans = memo[idx][price];
    if (ans != -1) return ans;

    return ans = min(DP(idx + 1, price), 1 + DP(idx + 1, price - cash[idx]));
}

int main () {
    int TCs;
    cin >> TCs;
    for (int tc = 0; tc < TCs; tc++) {
        cin >> bill >> N;
        for (int i = 0; i < N; i++) cin >> cash[i];

        // Initialize memoize array
        memset(memo, -1, sizeof memo);

        // Try minimum price, work your way up
        for (int pay = bill; pay < 10001; pay++) {
            if (int x = DP(0, pay); x < 101) {
                cout << pay << " " << x << endl;
                break;
            }
        }

    }
    return 0;
}
