/* 
kattis-geppetto

- use of bitmasks required for fast bit operations due to the large 
  number of data (2^N)
- TLEs on python
- use set to prevent duplicates in pairings, also important to sort pairs
  before inserting them into set

Time: O(2^N)
Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> wrongPairs;

// MAIN
int main () {
    // Receiving input
    int N, M, bitmask;
    cin >> N >> M;

    // Setup all pairs, make sure no duplicates with STL set
    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        A--;
        B--;
        wrongPairs.insert(make_pair(min(A, B), max(A, B)));
    }

    // Enumerating all possible combinations of bitmask
    long long validPizzas = 0;
    bitmask = (1<<N) - 1;   // Turn on all bits in set of size N
    for(int subset = bitmask; 
        subset; 
        subset = (bitmask & (subset-1))){
        bool valid = true;

        // Iterate through pairs, check for validity
        for (auto wrongPair : wrongPairs) {
            if (subset & (1<<(wrongPair.first)) && 
                subset & (1<<(wrongPair.second))) {
                    valid = false;
                    break;
                }
        }

        // Determine if valid or not
        if (valid) {
            validPizzas++;
        }
    }
    cout << validPizzas + 1 << endl; // +1 for the case of no ingredients
}
