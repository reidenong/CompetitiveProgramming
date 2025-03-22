/*
kattis-ticketpricing

- Maximise revenue given options to pick the optimal price-seat deal.

- DP state is (week, remaining quota) on the total revenue to week 0.

- To get first sale value just calculate which option is the one that gives the
  correct transition from DP (W, N)

Time: O(N*W)
Space: O(N*W)
*/
#include <bits/stdc++.h>
using namespace std;
int N, W;                   // Number of tickets, Weeks to sell
int choices[53];            // Number of choices available for each week
int prices[53][101];        // prices for [week][choice]
int demand[53][101];        // demand for prices for [week][choice]
int memo[53][301];          // DP memoization table for [week][quota]

// DP to return maximum sale of (week, remaining quota)
int DP (int week, int quota) {
    // Base cases
    if (week == -1) return 0;
    if (quota == 0) return 0;

    // Check if computed before
    int &ans = memo[week][quota];
    if (ans != -1) return ans;

    // Choose each option
    int revenue = 0, option, sales;
    for (int i = 0; i < choices[week]; i++) {
        sales = min(demand[week][i], quota);
        option = DP(week - 1, quota - sales) + prices[week][i] * sales;
        revenue = max(revenue, option);
    }
    return ans = revenue;
}

// MAIN
int main () {
    // Receiving input
    cin >> N >> W;
    for (int i = W; i > -1; i--) {
        cin >> choices[i];
        for (int j = 0; j < choices[i]; j++) cin >> prices[i][j];
        for (int j = 0; j < choices[i]; j++) cin >> demand[i][j];
    }

    // Initialize memoization table
    memset(memo, -1, sizeof memo);

    // DP 
    int maxRevenue = DP(W, N);
    cout << maxRevenue << endl;

    // Test all week W options for correct transition
    for (int i = 0; i < choices[W]; i++) {
        int sales = min(demand[W][i], N);
        if (DP(W, N) - DP(W-1, N - sales) == prices[W][i] * sales) {
            cout << prices[W][i] << endl;
            break;
        }
    }
    return 0;
}
