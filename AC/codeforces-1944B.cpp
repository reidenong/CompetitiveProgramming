/*
codeforces-1944B Equal XOR

- Observe that x XOR x = 0, and XOR is commutative and associative

- A key method to solving this is to consider the construction of the given array. Firstly we note that
  all elements will appear exactly twice, either in the first half or the second half.

- This gives us several key observations:

        (1) If an element appears twice in one half, it will appear 0 times in the other half.
            Additionally, it also means that some other element will appear twice in the other half.

        (2) If an element appears once in one half, it has another appearance in the other half.
            Thus we can always use this element for the XOR operation on both sides.

- Thus a strategy is first to use all elements that appear twice in one half, as the XOR operation will
  result in a 0 (x XOR x). Then we can use the remaining elements that appear once in each half, as adding these elements will 
  always result in a x XOR current_result on both halves and be equal.

Time: O(N log N) for sorting
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int arr[50002];
int freq[50002];

void solve() {
    int N, K;
    cin >> N >> K;

    memset(freq, 0, sizeof(freq));                  // Clearing frequency array

    K *= 2;
    for (int i = 0; i < N; i++) cin >> arr[i];      // Reading in left array (unecessary)
    for (int i = 0; i < N; i++) cin >> arr[i];      // Overwriting with right array
    sort(arr, arr + N);

    // Develop frequency array
    for (int i = 0; i < N; i++) {           
        freq[arr[i]]++;
    }

    // Add all duplicates first
    int dups = 0;
    string l_ans = "", r_ans = "";
    for (int i = 1; i <= N; i++) {              // Adding all duplicates from right array
        if (K == 0) break;
        if (freq[i] == 2) {
            dups++;
            r_ans += to_string(i) + " " + to_string(i) + " ";
            K -= 2;
        }
    }
    if (dups > 0) {                             // Adding all duplicates from left array
        for (int i = 1; i <= N; i++) {
            if (dups == 0) break;
            if (freq[i] == 0) {
                l_ans += to_string(i) + " " + to_string(i) + " ";
                dups--;
            }
        }
    }

    // Touch up leftovers
    if (K > 0) {
        for (int i = 1; i <= N ; i++) {
            if (K == 0) break;
            if (freq[i] == 1) {
                l_ans += to_string(i) + " ";
                r_ans += to_string(i) + " ";
                K--;
            }
        }
    }
    
    cout << l_ans << endl;
    cout << r_ans << endl;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }    
}
