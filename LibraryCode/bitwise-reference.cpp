#include <bits/stdc++.h>
using namespace std;

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


// Main Bit operations
int main(){
    int bitmask;
    
    // Basic operations
    bitmask = 4;                //  100
    bitmask = bitmask<<1;        // 1000 (multiply 2)
    bitmask = bitmask>>2;        //   10 (divide by 4)
        
    // Bit specific operations
    bitmask |= (1<<x);       // Turn on xth item
    bitmask &= ~(1<<y);      // Turn off yth item
    bitmask ^= (1<<z);       // Toggle zth item
    
    // Query Bit status
    int check = bitmask & (1<<i);    // Query ith bit on/off
                                     // if off, check == 0
    
    // Least Significant bit (first from right)
    int T = ((bitmask) & -(bitmask));   //if T = 8, 3rd bit is on
    
    // Turn on all bits in set of size N
    bitmask = (1<<N) - 1;
    
    // Enumerate all proper subsets of a bitmask
    int bitmask = 18;   // 10010
    for(int subset = bitmask; 
        subset; 
        subset = (mask & (subset-1))){
        cout << subset << endl;
    }
            // Where proper subsets of 10010 are
            // 10010, 10000, 00010
    
    // Number of bits that are ON in bitmask
    __builtin_popcount(bitmask);    
    
    // Number of trailing zeros in bitmask
    // (zeros from the right)
    __builtin_ctz(bitmask);
    
    // Toggling based on position
    bitmask &= (bitmask - 1);    // Turn off the last one 
                                 // 1110 -> 1100
    
    bitmask |= (bitmask + 1);    // Turn on last zero
                                 // 1001 -> 1011
    
    bitmask &= (bitmask + 1);    // Turn on last consecutive 1s
                                 // 100111 -> 100000
    
    bitmask |= (bitmask - 1);    // Turn off last consecutive 0s
                                 // 100100 -> 100111
    
    return 0;
}
