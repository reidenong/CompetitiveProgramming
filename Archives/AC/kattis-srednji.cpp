/*
kattis-srednji

- with N <= 10^5 N^2 comparison is too slow and TLEs

- the actual number is irrelevant, for a sequence of (N=5 B=3) interpret 
  given sequence 1 2 3 4 5 as -1 -1 0 1 1, where all x > B is represented
  by a 1 and all x < B is represented as -1.
- thus to find a sequence where B is median, sequence needs equal numbers 
  of '-1's and '1's.

- with this labelling system, count from B outwards the current sum at 
  that point, ie. the above sequence is represented as -2 -1 0 1 2.
- with this, just need to find pairings on either side of B where the left
  number sums with the right number to get 0 (ie. equal n(>B) and n(<B))

- even faster optimization is that you dont have to have the actual index,
  you just need the parity count. ie. odd index on left and odd index on 
  right will result in a overall odd subsequence length.

*/
#include <bits/stdc++.h>
using namespace std;

int A[100001];
int pos[100001];
// MAPS
map<int, int> leftOdd; 
map<int, int> rightOdd; 
map<int, int> leftEven;
map<int, int> rightEven;

int main(){
   // Receiving input
    int N, B, elem, idx;
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        cin >> elem;
        if (elem > B) {
            A[i] = 1;
        } else if (elem < B) {
            A[i] = -1;
        } else {
            idx = i;
        }
    }

    // Create reference positional array
    // B index
    if (idx % 2 != 0) { // Odd index
        leftOdd.insert({0, 1});
        rightOdd.insert({0, 1});
    } else {    // Even index
        leftEven.insert({0, 1});
        rightEven.insert({0, 1});
    }

    // LEFT
    int counter = 0;
    for (int i = idx-1; i > -1; i--) {
        counter += A[i];
        pos[i] = counter;
        if (i % 2 != 0) {   // Odd index
            if (leftOdd.find(counter) == leftOdd.end()) {
                leftOdd.insert({counter, 0});
            }
            leftOdd[counter]++;
        } else {            // Even index
            if (leftEven.find(counter) == leftEven.end()) {
                leftEven.insert({counter, 0});
            }
            leftEven[counter]++;
        }
    }
    
    // RIGHT
    counter = 0;
    for (int i = idx+1; i < N; i++) {
        counter += A[i];
        pos[i] = counter;
        if (i % 2 != 0) {   // Odd index
            if (rightOdd.find(counter) == rightOdd.end()) {
                rightOdd.insert({counter, 0});
            }
            rightOdd[counter]++;
        } else {            // Even index
            if (rightEven.find(counter) == rightEven.end()) {
                rightEven.insert({counter, 0});
            }
            rightEven[counter]++; 
        }
    }

    /*
    // Code snippet to visualize positional +-
    for(int i = 0; i < N; i++){
        cout << pos[i] << ' ' ;
    }cout << endl;
    */

    // Count possibilities
    long long possibilities = 0;
    
    // Odds
    for (auto i : leftOdd) {
        if (rightOdd.find(-1*i.first) != rightOdd.end()){
            possibilities += i.second * rightOdd[-1*i.first];
            //cout << i.first << "matched" << i.second * rightOdd[-1*i.first] << endl;
        }
    }
    for (auto i : leftEven) {
        if (rightEven.find(-1*i.first) != rightEven.end()){
            possibilities += i.second * rightEven[-1*i.first];
            //cout << i.first << "matched" << i.second * rightEven[-1*i.first] << endl;
        }
    }
    cout << possibilities << endl;
}
