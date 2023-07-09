/*
kattis-nikola

- starting from second square with prevjump as 1, use DP to find the minimum cost of moving
  to each new position

- DP state has to be memoized as (pos, prevJump) because of the many different ways to get
  to any given pos, could get there with a forward jump, or a backwards jump which gives
  very different minimums, but with recording the previous jump it removes this difference

Time: O(N^2)
Space: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;
int N;
int fees[1001];
int memo[1005][1005];

// DP to memoize journey of getting from square 1 to square N
int DP (int pos, int prevJump) {
    // Base case
    if (pos > N || pos < 1) return 1e9;     // Not a valid jump seq, return big number 
    if (pos == N) return 0;                 // Endpoint, end program.

    // If calculated before
    int &ans = memo[pos][prevJump];
    if (ans != -1) return ans;

    // Choose to jump either forwards or backwards, add in jump cost
    int forward = DP(pos + prevJump + 1, prevJump + 1) + fees[pos + prevJump + 1];
    int backward = DP(pos - prevJump, prevJump) + fees[pos - prevJump];
    return ans = min(forward, backward);
}

// Main
int main () {
    cin >> N;
    for (int i = 1; i < N + 1; i++) cin >> fees[i]; 

    memset(memo, -1, sizeof memo);

    cout << fees[2] + DP(2, 1);
}
