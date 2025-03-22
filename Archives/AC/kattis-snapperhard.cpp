/*
kattis- snapperhard

maintaining a series of bits as each snapper's on/off

method 1: simulate snaps up until light turns on for each bulb (up
to 30). after that for each testcase find the corresponding N 
value and use modulo functions to find the point where the sequence
restarts

End result: After seeing the pattern for bulbs up to N=5, we quickly
realise that the pattern repeats at 2**N. This implies that we can
get the correct answer only using mathematical logic with N and K,
and that any answer using simulation will fail with 2**N operations 
needed overall.

While this code in cpp was not used for submission, it is probably more
valuable in solving this problem than the actual AC code in python
which is attached below.

<BEGIN CODE>

# Kattis- snapperhard / snappereasy in Python 3
testCases = int(input())
for tc in range(1, testCases+1):
    N, K = map(int, input().split())
    if(K%(2**N) == 2**N-1):
        print("Case #" + str(tc) + ": ON")
    else:
        print("Case #" + str(tc) + ": OFF")

<END CODE>
*/
#include <bits/stdc++.h>
using namespace std;
int snapNum[31]; // Records the number of snaps needed for i snappers

int main(){
    // For each testcase
    int testCase;
    cin >> testCase;

    // Simulate snapping
    // At the beginning of each action, electricity probes to see how
    // far it can go. A snap is conducted, then all resultant
    // snappers are updated
    int bitmask = 0, snapCount = 0, currMax = 0;
    int loopctr = 0;
    cout << bitset<32>(bitmask) << endl;
    while(1){
        if(loopctr == 100)break;
        loopctr++;
        snapCount++;

        // Electricity probe to see how far it goes
        int curr = 0;
        while((bitmask&(1<<curr)))curr++; // curr move while snapper is on
        curr++; //  for curr to travel 1 extra after last ON snapper

        // Conduct snap, flip everything with electricity
        for(int i = 0; i < curr; i++){
            bitmask ^= (1<<i); // XOR to toggle bit
        }

        // Update snapNum if it reaches a new number
        cout << snapCount << " " << bitset<32>(bitmask) << endl;

        if(curr > currMax){
            snapNum[curr] = snapCount;
            currMax = curr;
        }
        if(curr == 31)break;
    }

    for(int i = 1; i < 31; i++)cout << snapNum[i] << " ";
}
