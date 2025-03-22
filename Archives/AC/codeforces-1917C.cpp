/*
codeforces-1917C Watering an Array

- A key observation is that after every watering it is always optimal to collect to get a +1.
  This is because when watering we can water up to K elements, but since K is only from the left, if we
  start from fresh [0,0...,0] we will only ever have 1 element with value = i. Since every water is at least 1,
  from a fresh [0,0,...,0] optimal is to always water-collect to get a +1.

- Now in figuring out when to collect our first time, there is no choice but to simulate and collect constantly.
  However, day bounds are up to 1e9, which will TLE if we simulate every day.

- However, observe that the maximum that we can collect from the start after watering is N (ie. best case scenario
  where each i = k). However, also observe that this can be achieved in 2*D + 1 days. This means we need to simulate
  at most 4001 days, which is easily within bounds.

Time: O(N * min(N, D))
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, D;
    cin >> N >> K >> D;

    int arr[2001], B[100001];
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < K; i++) cin >> B[i];
    
    // Simulate every day, attempting to collect every day.
    int ans = 0;
    for (int day = 0; day < min(2*N + 1, D); day++) {

        // Find curr_val if we collect TODAY, update ans if max
        int curr_val = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == i + 1) 
                curr_val++;
        }
        curr_val += (D - day - 1)/2;
        ans = max(ans, curr_val);

        // Update the array if we dont collect today
        for (int i = 0; i < B[day % K]; i++) {
            arr[i]++;
        }
    }

    cout << ans << endl;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }    
}
