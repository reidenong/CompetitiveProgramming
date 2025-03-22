/* 
kattis-communication
*/
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> unscramble;

// View binary sequence
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

// Turn off most significant bit
int offMSBit (int bitmask) {
    for (int i = 31; i > 0; i--) {
        int check = bitmask & (1 << i);
        if (check) {
            bitmask &= ~(1 << i);
            return bitmask;
        }
    }
    return bitmask;
}

// MAIN
int main () {
    // Receiving input
    int N, scrambled;
    cin >> N;
    
    // Get the scrambles of all answers
    for (int i = 0; i < 256; i++) {
        scrambled = i ^ (i << 1);
        if (scrambled > 256) {
            scrambled = offMSBit(scrambled);
        }
        unscramble[scrambled] = i;
    }

    // Unscramble
    for (int i = 0; i < N; i++) {
        cin >> scrambled;
        cout << unscramble[scrambled];
        if (i != N-1) {
            cout << " ";
        }
    }
}
