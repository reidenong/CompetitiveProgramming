/*
kattis-orders

- coin change variant, we do classic coin change with backtracking at the end to find unique solutions.

- Instead of number of coins, we want to find number of ways. As such, our DP func returns number of 
  ways to finish an order, instead of the number of coins it needs. we memoize number of ways for 
  fulfilling each order

- To find the unique solution, by definition there is only one way to get that order. This means that
  there is also only one way to get that order - each individual item. As such, we just need to backtrack
  on the memo array by iterating through each coin and checking if it has one way after removing a
  certain order.

Time: O(NC)
Space: O(NC)
*/
#include <bits/stdc++.h>
using namespace std;
int memo[101][30005];
int coins[101];
int N, M, order;

// Returns ways to fulfil a given order
int ways (int idx, int money) {
    if (money == 0) return 1;     // Valid way, and every point reached to get here is also valid
    if (money < 0) return 0;      // Not a valid way

    int &ans = memo[idx][money];

    if (ans != -1) 
        return ans;
    if (idx == N-1) 
        return ans = ways(idx, money - coins[idx]);
    return ans = ways(idx + 1, money) + ways(idx, money - coins[idx]);
}

// MAIN
int main () {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> coins[i];
    cin >> M;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < M; i++) {
        cin >> order;
        int nWays = ways(0, order);
        if (nWays == 0) cout << "Impossible" << endl;
        else if (nWays != 1) cout << "Ambiguous" << endl;
        else {
            // Unique solution, backtrack to get the coin makeup
            vector<int> elements;
            int idx = 0;
            while (order > 0) {
                while (order == coins[idx] || ways(idx, order - coins[idx]) == 1) {
                    elements.push_back(idx);
                    order -= coins[idx];
                    if (order == 0) break;
                }
                idx++;
            }
            for (auto ele : elements) cout << ele + 1 << " ";
            cout << endl;
        }
    }
}
