/*
kattis-canonical

- Straightforward implementation of coinchange

- Remember to memoize Greedy algo as well or it will bottleneck and TLe

Time: O(N*upper_limit)
Space: O(N*upper_limit)
*/
#include <bits/stdc++.h>  
using namespace std;
int coins[101];
int memo[2000001], memoG[2000001];
int N;

// Greedy coinchange
int Greedy (int idx, int price) {
    if (price == 0) return 0;

    int &ans = memoG[price];
    if (ans != -1) return ans;

    while (coins[idx] > price) idx--;
    return ans = 1 + Greedy(idx, price - coins[idx]);
}

// DP coinchange (True minimum)
int DP (int price) {
    // Base Cases
    if (price == 0) return 0;
    if (price < 0) return 2e9;

    // Check if computed before
    int &ans = memo[price];
    if (ans != -1) return ans;

    // Find minimum number of coins by trying each coin
    int minCoin = 2e9;
    for (int i = 0; i < N; i++) {
        minCoin = min(minCoin, 1 + DP(price - coins[i]));
    }
    return ans = minCoin;
}

// MAIN
int main () {
    // Receiving input
    cin >> N;
    for (int i = 0; i < N; i++) cin >> coins[i];

    // -1 Initializing memos
    memset(memo, -1, sizeof memo);
    memset(memoG, -1, sizeof memoG);

    // Complete search on every value in search space
    int upper_limit = coins[N-1] + coins[N-2];
    bool canonical = true;
    for (int i = upper_limit; i >= 0; i--) {
        //cout << i << " " << Greedy(N-1, i) << " " << DP(i) << endl;
        if (Greedy(N-1, i) != DP(i)) {
            canonical = false;
            break;
        }
    }

    // Output answer
    if (canonical) cout << "canonical" << endl;
    else cout << "non-canonical" << endl;

    return 0;
}
