/*
kattis-presidentialelections

- 0/1 Knapsack variant. The way I see it, knapsack is a way of 
  picking items to maximise/minimise A within constraint B. In this case,
  our "capacity" is our score, where we want to continue picking until it
  first goes below 0, our "value" is the min number of voters, which we 
  want to minimise.

- Important to carefully interpret the data too. Difference in winning a 
  state is D*2, as both C wins and F loses D. All undecided voters U 
  must ultimately vote by the end of the election, so U must also be
  factored into account when sorting votes

Time: O(N*C)
Space: O(N*C)
*/
#include <bits/stdc++.h>
using namespace std;
int S;
int MAX_NUM = 1e9 + 1;
vector<int> value;
vector<int> weight;  
int memo[2017][2017];     // Memoization array for DP states

// 0-1 Knapsack to minimise weight until constituents win at score < 0
int DP (int idx, int score) {
    // Base Cases
    if (score < 0) return 0;
    if (idx == value.size()) return MAX_NUM;

    int &ans = memo[idx][score];
    if (ans != 0) return ans;
    return ans = min(DP(idx + 1, score), DP(idx + 1, score - value[idx]) + weight[idx]);
}

// MAIN
int main () {
    cin >> S;
    int D, C, F, U, constituents = 0;
    for (int i = 0; i < S; i++) {
        cin >> D >> C >> F >> U;
        
        // Guaranteed win
        if (C - F - U > 0) constituents += D;

        // Guaranteed loss
        else if (C + U - F <= 0) constituents -= D;

        // Fightable, assume its lost first
        else {
            constituents -= D;
            int minVotes = floor((C + F + U)/2) + 1;
            value.push_back(D*2);
            weight.push_back(minVotes - C);
        }
    }

    // Already winning
    if (constituents > 0) {
        cout << 0 << endl;
        return 0;
    }

    // Impossible
    if (accumulate(value.begin(), value.end(), 0) + constituents <= 0) {
        cout << "impossible" << endl;
        return 0;
    }

    // Find minimum constituents
    cout << DP(0, abs(constituents)) << endl;
    return 0;
}
