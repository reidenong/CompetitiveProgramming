/* 
kattis-dancerecital

- use of bitmasks so that operations are done quickly given that we are
  checking through R! permutations
- use of bitmasks to represent if a dancer is taking part in a certain
  recital, bit 0 on is A is performing etc.

Time: O(N!)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

// Helper function to visualize the binary form of a decimal number
void dec2bin(long n) {
    long i;
    cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2) {
        if((n & i) != 0) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;
}

// MAIN
int main () {
    int N, nBit, bitmask;
    string S;
    cin >> N;

    // Receiving input routines
    int routines[N];
    for (int i = 0; i < N; i++) {
        cin >> S;
        bitmask = 0;

        // For each character, turn on their specific bit
        // Bitmask represents dancer status in that routine
        for (auto &c : S) {
            nBit = c - 'A';
            bitmask |= (1 << nBit);
        }
        routines[i] = bitmask;

        // Viewing Bitmasks
        //dec2bin(bitmask);
    }

    // Iterating through routine permutations
    long long minSwaps = INT_MAX, currSwaps, temp;
    sort(routines, routines + N);   // NEEDED before permutating
    do {
        // Count all fast swaps
        currSwaps = 0;
        for (int i = 0; i < N-1; i++) {
            temp = routines[i] & routines[i+1];
            currSwaps += __builtin_popcount(temp);
        }

        // Updating global minimum
        minSwaps = min(currSwaps, minSwaps);
    } while (next_permutation(routines, routines + N));

    // Display answer
    cout << minSwaps << endl;
}
