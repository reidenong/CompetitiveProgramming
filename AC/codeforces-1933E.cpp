/*
codeforces-1933E Turtle vs. Rabbit Race: Optimal Trainings

- Initially i did a iterative approach. So given each l, we start from arr[l] and subsequently reduce U
  until the point where 2*U is smaller than the next track sequence. It is precisely this point where further
  training is detrimental.

- This is a O(QN) solution, which is too slow given Q, N have bounds of 1e5.

- The optimal solution is to use a prefix sum array to find the upper bound of the training sequence where further
  trainings result in -ve returns. However, there were several issues presumably with how i handled the tipping point,
  and i had to swap back to the 2*U < arr[idx] approach, though i suspect this is unnecessary. With O(log N) upper bound,
  we are able to pass the test cases.

Time: O(Q log N)
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[100005];
int prefix[100005];

void solve() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        prefix[i] = prefix[i - 1] + arr[i];
    }
    arr[N + 1] = prefix[N + 1] = INT_MAX;

    int Q;
    cin >> Q;
    while (Q--) {
        int L, U;
        scanf("%d %d", &L, &U);

        int V = U + prefix[L - 1];      // As we start from L, we need to add the prefix sum of the previous elements.

        int idx = upper_bound(prefix + 1, prefix + N + 1, V) - prefix;      // Find upper bound

        int leftover = V - prefix[idx - 1];                                 // Find leftover after training to idx - 1
        if (2 * leftover < arr[idx]) {                                      // Choose between idx and idx - 1
            idx--;
        }
        cout << max(L, idx) << " ";
    }
    cout << endl;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }    
}
