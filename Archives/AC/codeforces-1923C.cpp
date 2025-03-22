/*
codeforces-1923C Find B

- Observe that no element in the array can be smaller than 1. It is always easy to rearrange
  non-1 elements, but the crux of the matter arises when we do not have enough extra surplus
  from other number to change the ones, and then A[i] == B[i] == 1.

- So all our non-1 elements k give a surplus of (k-1) to help with rearranging the ones

- It then follows a solution is to keep track of the surplus we have, and if the surplus is less
  than the number of ones, then there will be a one in A[i] that will be equal to B[i] and we fail.
  This can be done in O(N) per query as we iterate between arr[l] to arr[r].

- However, notice similarity to the 1D range sum problem, and so this can be sped up by using prefix
  sums of both ones and surplus. This allows us to answer each query in O(1) time.

Time: O(N + Q)
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[300002];
ll ones[300002], surplus[300002];

void solve() {
    int N, Q;
    cin >> N >> Q;

    // Update prefix sums on the fly
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        if (temp == 1) {
            ones[i] = ones[i-1] + 1;
            surplus[i] = surplus[i-1];
        } else {
            ones[i] = ones[i-1];
            surplus[i] = surplus[i-1] + temp - 1;
        }    
    }

    // Answer queries
    int L, R;
    for (int q = 0; q < Q; q++) {
        cin >> L >> R;

        if (L == R) {
            cout << "NO" << endl;
            continue;
        }

        ll one_ctr = ones[R] - ones[L-1];
        ll surplus_ctr = surplus[R] - surplus[L-1];

        if (surplus_ctr >= one_ctr) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }    
}
