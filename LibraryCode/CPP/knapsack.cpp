/* 
0-1 Knapsack, O(N*S)

- with backtracking for printing optimal solution

Time: O(N*S)
Space: O(N*S)
*/
#include <bits/stdc++.h>
using namespace std;
int N, C;
int value[2002], cost[2002];    // Value, Cost arrays for each item[idx]
long long memo[2002][2002];     // Memoization array for DP states

// O(N*C) Knapsack
long long DP (int idx, int capacity) {
    // Base case
    if (idx == N || capacity == 0) return 0;

    long long &ans = memo[idx][capacity];

    // Computed before
    if (ans != -1) return ans;

    // Cannot take idx, not enough capacity
    if (cost[idx] > capacity) return DP(idx + 1, capacity);

    // Compare taking item and not taking item, store state
    return ans = max(DP(idx + 1, capacity), DP(idx + 1, capacity - cost[idx]) + value[idx]);
}

int main () {
    // Receiving input
    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        cin >> value[i] >> cost[i];
    }

    // 0-1 Knapsack
    memset(memo, -1, sizeof memo);
    DP(0, C);

    // Backtracking through memoization
    set<int> taken;
    for(int idx = 0; idx < N; idx++) {
        if (DP(idx, C) != DP(idx+1, C)) {   // Item was taken
            taken.insert(idx);
            C -= cost[idx];
        }
    }

    // Output items
    cout << taken.size() << endl;
    for (auto elem : taken) {
        cout << elem << " ";
    }
    cout << endl;
}
