/*
codeforces-1920C Partitioning the Array

- I feel it's a hard problem, which also requires a strong understanding of math for 
  the crux of the problem.

- The first issue is how to find M such that x % M == y % M. This can be simplified to
  (x - y) % M == 0, ie. M is a factor of (x - y). 

- The next issue is how to find for M for all N//k tuples of (i + k, i + 2k, ... , i + (N//k)k).
  Combined with the first issue, we want to find an M such that M is a factor of (i + k), ... , (i + (N//k)k).
  This can be done by finding the GCD of (A[j+k] - A[j]) for all j in range(0, N - k). This allows us to
  test for all (N-k) possible subarray pairings at once, because they all need the same M.

Time: O((n + log N) * max divisors of n)
Mem: O(N)
*/
#include <bits/stdc++.h>  
using namespace std;
int arr[200001];

void solve() {
    int N;
    cin >> N;

    // Receiving input
    for (int i = 0; i < N; i++) cin >> arr[i];

    int ans = 0;
    for (int k = 1; k <= N; k++) {
        if (N % k == 0) {                                   // If k is a factor of N
            int g = 0;
            for (int i = 0; i + k < N; i++) {               // Test all possible subarray pairings
                g = __gcd(g, abs(arr[i + k] - arr[i]));
            }
            ans += (g != 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
}
