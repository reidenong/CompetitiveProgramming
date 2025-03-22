/*
kattis-beepers

- Classic TSP with bitmask dp

Time: O(N^2 * 2^N)
Space: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int INF = 2e9;

int adjmat[11][11];
int memo[11][2048];
ii beepers[11];

int LSOne(int x) {
    return x & (-x);
}

int get_dist(ii a, ii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

/*
 * Returns the minimum cost if we are at vertex u and have visited vertices
 * represented by the bitmask.
 */
int dp(int u, int bitmask) {
    if (bitmask == 0) return adjmat[u][0];                          // visited all; close tour
    int &ans = memo[u][bitmask];
    if (ans != -1) return ans;                                      // computed before
    ans = INF;
    int m = bitmask;
    while (m) {
        int two_pow_v = LSOne(m);                                   // the rightmost bit
        int v = __builtin_ctz(two_pow_v) + 1;                       // offset v by +1
        ans = min(ans, adjmat[u][v] + dp(v, bitmask ^ two_pow_v));
        m -= two_pow_v;
    }
    return ans;
}

void solve() {
    // Receiving input
    int X, Y;
    cin >> X >> Y;
    cin >> beepers[0].first >> beepers[0].second;
    int N;
    cin >> N;
    N++;
    for (int i = 1; i < N; i++)
        cin >> beepers[i].first >> beepers[i].second;

    // Create distance matrix
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int dist = get_dist(beepers[i], beepers[j]);
            adjmat[i][j] = dist;
            adjmat[j][i] = dist;
        }
    }

    // Output answer
    memset(memo, -1, sizeof memo);
    cout << dp(0, (1 << (N - 1)) - 1) << endl;
}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
        solve();
}
