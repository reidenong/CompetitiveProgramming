/*
kattis-bagoftiles

- knapsack and coinchange crossover. Each item can only be picked once, so
  similar to knapsack in that aspect. DP should return number of ways to get an item.

- important to include number of items picked in the DP state. This is because for 
  different number of items picked, the DP state may not be accurate for that given
  idx/value.

Time: O(NMT)
Space: O(NMT)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int TCs, M, T, N;
int tiles[31];
ll memo[31][10002][31];

// Returns factorial of n
ll nCk( int n, int k ) 
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

// DP to get ways to pick value with maximum N picks
ll ways (int idx, int value, int picked) {
    if (value == 0 && picked == N) return 1;
    if (value <= 0 || picked == N) return 0;
    if (idx == M) return 0;

    ll &ans = memo[idx][value][picked];
    if (ans != -1) return ans;
    return ans = ways(idx + 1, value, picked) + ways(idx + 1, value - tiles[idx], picked + 1);
}

// Main
int main () {
    cin >> TCs;
    for (int testcase = 0;  testcase < TCs; testcase++) {
        memset(memo, -1, sizeof memo);
        cin >> M;
        for (int i = 0; i < M; i++) cin >> tiles[i];
        cin >> N >> T;
        ll totalDraws = nCk(M, N), wins = ways(0, T, 0);
        cout << "Game " << testcase + 1 << " -- ";
        cout << wins << " : " << totalDraws - wins << endl;
    }
    return 0;
}
