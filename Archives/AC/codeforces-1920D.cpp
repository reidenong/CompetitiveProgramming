/*
codeforces-1920D Array Repetition

- Hard problem for me.

- It should be fairly obvious that constructing the array is not possible, since the array size can be up to 1e18. 
  My first attempt was to use a backtracking solution through retracing the number of steps. This was clearly too 
  slow in hindsight, with O(NQ) time complexity, where N, Q can go up to 5e4.

- We can track the growth of the array, where after each new move, we record the size of the array and the last number there.
  While backtracking, at some point the number at index i was added, making it the last number, so as long as we backtrack to the
  point where the array size is equal to the index that we want, we can find the number we want at the last index.

- The solution is to use binary search. We can see that the array size is monotonically increasing, so we can
  use lower bound to find the largest array size that is smaller or equal to the number we want. If the largest array size is 
  equal to k, we can just recall the last number. If not, we can just find the remainder of k divided by the next largest 
  array size, and then repeat the process until it has been reduced to the last number.

- To store the array sizes we use a set so we can do binary search, and to store the last number we use a map because we\
  have relatively sparse representation of the index to the last number.

Time Complexity: O(Q N log N)
Space Complexity: O(N)
*/
#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const ll MAX_LEN = 2e18;
set<ll> arr_size;
map<ll, int> idx;

void solve() {
    int N, Q;
    cin >> N >> Q;

    arr_size.clear();
    idx.clear();

    int b, x, latestNum;
    ll curr_size = 0;
    for (int i = 0; i < N; i++) {
        cin >> b >> x;

        // Add Integer
        if (b == 1) {
            curr_size++;
            latestNum = x;

        // Multiply array
        } else {
            if (curr_size < MAX_LEN/(x + 1)) {
                curr_size *= (x + 1);
            } else {
                // Array extends beyond 1e18, ignore remaining inputs
                for (int j = 0; j < N - i - 1; j++) 
                    cin >> b >> x;
                break;
            }
        }
        arr_size.insert(curr_size);
        idx[curr_size] = latestNum;
    }

    // For each query
    for (int q = 0; q < Q; q++) {
        ll k;
        cin >> k;

        // Find lower bound of k in arr_size
        while (true) {
            auto it = arr_size.lower_bound(k);
            if (k == *it) {         // k is at the end of a move
                cout << idx[k] << " ";
                break;
            } else {                // k is in the middle of a move, find remainder
                k %= *(--it);
                if (k == 0) {
                    cout << idx[*it] << " ";
                    break;
                }
            }
        }
    }
    cout << "\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc; 
    cin >> tc;
    while (tc--) {
        solve();
    }
}
