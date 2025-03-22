/* 
kattis-toys

- josephus problem, solution is to use the general case josephus recurrence

Time: O(N)
Mem: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

// General Case josephus recurrence relation
int josephus (ull N, ull K) {
    if (N == 1) {
        return 1;
    } else {
        return (josephus(N-1, K) + K - 1) % N + 1;
    }
}

// MAIN
int main () {
    ull N, K;
    cin >> N >> K;

    // 0-based indexing
    cout << josephus(N, K) - 1 << endl;
}
