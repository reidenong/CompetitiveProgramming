#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// N!, O(N)
ll factorial (int N) {
    if (N == 2) return 2;
    return N * factorial(N - 1);
}

// N choose K, O(N)
ll nCk (int n, int k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

// N permutate K, O(N)
ll nPk (int n, int k) {
    return nCk(n, k) * factorial(k);
}
  
