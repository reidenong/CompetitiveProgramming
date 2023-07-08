/*
Coin Change

- given a list of coin sizings and a value V, determine the minimum
  number of coins needed to form said value V

- This algorithm assumes that it is guaranteed to be able to form V with
  the given coin sizings

Time: O(NV)
Space: O(NV)
*/
#include <bits/stdc++.h>  
using namespace std;
int N;               // Number of coin sizings  
int coins[101];      // Array of coin sizings
int memo[2000001];
// Remember to memset(memo, -1, sizeof memo);

// DP coinchange (True minimum)
// DP( x ) gives the minimum number of coins needed to form X
int DP (int price) {
    // Base Cases
    if (price == 0) return 0;
    if (price < 0) return 2e9;

    // Check if computed before
    int &ans = memo[price];
    if (ans != -1) return ans;

    // Find minimum number of coins by trying each coin, memoize state
    int minCoin = 2e9;
    for (int i = 0; i < N; i++) {
        minCoin = min(minCoin, 1 + DP(price - coins[i]));
    }
    return ans = minCoin;
}
