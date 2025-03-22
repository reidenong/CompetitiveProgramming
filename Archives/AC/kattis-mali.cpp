/*
Kattis-mali

Given 2 lists of numbers keep finding pairs such that the largest 
sum of a pair is minimised

STL Sort O(n log n) receives TLE due to large number of input (1e5)

Observe that A and B both < 100. 
Counting sort O(n+k) is likely to be solution given small k=100

Counting sort operation can also be done on the fly by maintaining 
a frequency list to be updated with each new pair

>> Optimise with finding the maximum number of pairings for any
2 given indexes, suspected to contain many edge cases with high 
number frequency of idxA-idxB pairings that this helps to avoid

time: O(n+100) = O(n)
space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int freqA[101];
int freqB[101];
int freqA2[101];    // Ascending
int freqB2[101];    // Descending

int main(){
    int N, A, B, currMax, idxA, idxB;
    cin >> N;

    for(int i = 0; i < N; i++){
        // Update frequency for count sort
        cin >> A >> B;
        freqA[A]++;
        freqB[B]++;

        // Duplicating Arrays
        //copy(freqA, freqA+(101), freqA2);
        //copy(freqB, freqB+(101), freqB2);
        for(int p = 1; p < 101; p++){
            freqA2[p] = freqA[p];
            freqB2[p] = freqB[p];
        }

        // Counting sort, track pair max on the fly
        // For every number, find smallest A biggest B
        idxA = 0; idxB = 100; currMax = 0;
        int pairings = 0;
        while(pairings < i+1){
            // Find smallest A, idxA
            while((freqA2[idxA] == 0) && (idxA < 100))idxA++;
            
            // Find biggest B, idxB
            while((freqB2[idxB] == 0) && (idxB > 0))idxB--;

            // Match highest number for both indices
            int matches = min(freqA2[idxA], freqB2[idxB]);
            freqA2[idxA] -= matches;
            freqB2[idxB] -= matches;
            pairings += matches;

            // Update currMax
            currMax = max(currMax, idxA + idxB);
        }
        cout << currMax << endl;

    }

}
