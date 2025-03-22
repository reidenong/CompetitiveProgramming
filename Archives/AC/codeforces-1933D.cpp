/*
codeforces-1933D Turtle Tenacity: Continual Mods

- If we can sort all elements in ascending order, it is clear that the modulo of the arr[0] % arr[i] will
  remain the same iterating through all i.

- The problem arises when the first elements are the same, in which case the modulo will be 0 for all i

- We can solve this by the fact that if there exists some element arr[k] that is not divisible by arr[0], then the order 
  becomes arr[k] % arr[0] % arr[i] % ... % arr[N] for all i, as arr[0] is the smallest number and all numbers after are
  increasing, the modulo will be nonzero.

Time: O(N log N) for sorting
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[100001];

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    if (arr[0] != arr[1]) {             // Sorted sequence is already valid.
        cout << "YES" << endl;
        return;
    }

    for (int i = 1; i < N; i++) {       // Look for the first element that is not divisible by arr[0].
        if (arr[i] % arr[0] != 0) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }    
}
