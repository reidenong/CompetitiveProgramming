/*
kattis-stringmatching

- We can use the rabin karp algorithm with rolling hash to find all matches of a pattern P in a
  text T 

Time: O(N + M)
Space: O(N + M)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

// Computes the modulo of a by n, even if a is negative
ll mod(ll a, ll b) { return (a % b + b) % b; }

// Implements extended Euclidean algorithm
// Returns gcd(a, b) and finds x, y such that ax + by = gcd(a, b)
int extended_euclid(int a, int b, int &x, int &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        tie(a, b) = tuple(b, a % b);
        tie(x, xx) = tuple(xx, x - q * xx);
        tie(y, yy) = tuple(yy, y - q * yy);
    }
    return a;
}

// mod_inverse(a, m) returns the modular multiplicative inverse of a modulo m
int mod_inverse(int a, int m) {
    int x, y;
    int d = extended_euclid(a, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}

// Initializes the Rolling Hash
class RollingHash {
    public:
        vector<int> P, H;   // P stores the powers of the base, H stores the hash values
        vector<int> P_inv;  // Stores the modular inverses of the powers of the base

        const int N;        // Length of the string
        string s;           // The string
        const ll p, M;      // Base and the modulo (now properly declared as class members)

    RollingHash(string s, ll p = 131, ll M = (ll) 1e9 + 7) 
        : s(s), N(s.size()), p(p), M(M) {
        preprocess();
        compute_rolling_hash();
    }

    void preprocess() {
        // Precomputes the powers of the base
        P.assign(N, 0);
        P[0] = 1;
        for (int i = 1; i < N; i++) 
            P[i] = (P[i - 1] * p) % M;
        
        // Precomputes the modular inverses of the powers of the base
        P_inv.assign(N, 0);
        P_inv[N - 1] = mod_inverse(P[N - 1], M);
        for (int i = N - 2; i >= 0; i--) 
            P_inv[i] = (P_inv[i + 1] * p) % M;
    }

    // Computes the rolling hash of the string
    void compute_rolling_hash() {
        H.assign(N, 0);
        for (int i = 0; i < N; i++) {  // Use N, not 'n'
            if (i != 0) H[i] = H[i - 1];
            H[i] = (H[i] + ((ll)s[i] * P[i]) % M) % M;  // Make sure 'll' is defined
        }
    }

    // Returns the hash of the substring s[l, r]
    int get_hash(int l, int r) {
        if (l == 0) return H[r];
        int ans = ((H[r] - H[l - 1]) % M + M) % M;
        ans = ((ll) ans * P_inv[l]) % M;  // Ensure 'll' is used properly here
        return ans;
    }
};   

// Function to find matches of pattern P in text T
void rabin_karp(string P, string T) {
    RollingHash p_rh(P), t_rh(T);
    int N = T.size(), M = P.size();

    for (int i = 0; i + M - 1 < N; i++) {
        if (p_rh.get_hash(0, M - 1) == t_rh.get_hash(i, i + M - 1)) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main() {
    string P, T;
    while (getline(cin, P)) {
        getline(cin, T);
        rabin_karp(P, T);
    }
    return 0;
}
