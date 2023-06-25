/*
kattis-roompainting

- use log N lower bound

Time: O(M log N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
set<int> cans;

int main () {
    int N, M, size;
    cin >> N >> M;

    // Receiving cans input
    for (int i = 0; i < N; i++) {
        cin >> size;
        cans.insert(size);
    }

    // Receiving paint input, finding can size
    long long wasted = 0;
    for (int i = 0; i < M; i++) {
        cin >> size;

        // Calculating difference between smallest can >= size
        wasted += *cans.lower_bound(size) - size;
    }

    cout << wasted << endl;
}

