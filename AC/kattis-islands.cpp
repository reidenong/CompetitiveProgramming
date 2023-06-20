/* 
kattis-islands

- use stack to maintain whether a island bracket is close or not
- important to add island even if it closes other islands, ie for 
  0 2 4 3 after island 3 closes island 4 we need to add it as it builds
  on island 2

Time: O(N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
stack<int> stk;

// MAIN
int main () {
    int P, K, island;
    cin >> P;

    // For each testcase
    for (int tc = 0; tc < P; tc++) {
        cin >> K;
        int N = 0;  // Number of islands

        // Receiving island input
        for (int i = 0; i < 12; i++) {
            cin >> island;

            // Smaller island, close bracket
            while (!stk.empty() && island < stk.top()) {
                N++;
                stk.pop();
            }

            // Empty island OR making island bigger
            if (stk.empty() || island > stk.top()) {
                stk.push(island);
            }
        }

        // Output
        cout << K << " " << N << endl;
    }
}
