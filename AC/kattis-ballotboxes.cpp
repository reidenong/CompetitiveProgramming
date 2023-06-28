/*
kattis-ballotboxes

- frustrating question

- initial naive solution was to use python custom lambda sort to sort a list of 
  (population, boxes) by popn/box and then give a extra box to the current largest entry
  result: TLE, Time: O(B * N log N) cuz quicksort.

- Next attempt was to use same thing in C++. TLE.

- Next attempt used the observation that we dont need whole sorted array, only largest
  popn/box so we can replace O(N log N) STL sort with O(N) linear pass to find largest elem.
  result: TLE, Time: O(B * N).

- AC solution was to use STL priority queue. With O(log N) complexity for operations, we
  have N insertions, and B queries and updates.
  result: AC, Time: O(B * log N)

- double is used to maintain accuracy for small numbers. unsure if necessary but
  good to consider ig

Time: O(B * log N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
// Store ballot information as pair(popn/ballot, current number of assigned boxes),
// such that PQ returns current largest ballot per box size and it has the relevant
// information to update +1 boxes with the current number of assigned boxes
priority_queue<pair<double, int>> ballots;

// MAIN
int main () {
    // For each testcase
    while (true) {

        // Receiving input
        int N, B, popn;
        cin >> N >> B;

        // End of testcase
        if (N == -1 && B == -1) {
            break;
        }

        // Receiving ballot input
        while (!ballots.empty()) ballots.pop(); // Clearing DS from previous TC
        for (int i = 0; i < N; i++) {
            scanf("%d", &popn);
            ballots.push(make_pair((double)popn, 1));
        }

        // Assigning extra ballot boxes to current max
        int extras = B - N;
        pair<double, int> ballot;
        for (int i = 0; i < extras; i++) {
            ballot = ballots.top();
            ballots.pop();
            ballots.push(make_pair((ballot.first * (double)ballot.second / ((double)ballot.second + 1)), ballot.second+1));
                // IMPT: use (double)/(double) to get a double back.
        }

        // Output answer
        cout << ceil(ballots.top().first) << endl;
    }
    return 0;
}
