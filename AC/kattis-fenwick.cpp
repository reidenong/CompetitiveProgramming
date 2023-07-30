/*
kattis-fenwick

- Just a classical implementation of a fenwick tree. 

- Remember to use scanf/printf for fast IO given giant input size (5M)

Time: O(Q log N)
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

// Macros
#define LSOne(S)((S) & -(S)) // the key operation
typedef long long ll; // for extra flexibility
typedef vector < ll > vll;
typedef vector < int > vi;

// Fenwick tree
class FenwickTree { // index 0 is not used
    private: vll ft; // internal FT is an array
    public: FenwickTree(int m) {
        ft.assign(m + 1, 0);
    } // create an empty FT

    void build(const vll & f) {
        int m = (int) f.size() - 1; // note f[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) { // O(m)
            ft[i] += f[i]; // add this value
            if (i + LSOne(i) <= m) // i has parent
                ft[i + LSOne(i)] += ft[i]; // add to that parent
        }
    }

    FenwickTree(const vll & f) {
        build(f);
    } // create FT based on f

    FenwickTree(int m, const vi & s) { // create FT based on s
        vll f(m + 1, 0);
        for (int i = 0; i < (int) s.size(); ++i) // do the conversion first
            ++f[s[i]]; // in O(n)
        build(f); // in O(m)
    }

    ll rsq(int j) { // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, ll v) {
        for (; i < (int) ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k) { // O(log m)
        int p = 1;
        while (p * 2 < (int) ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

// MAIN
int main() {
    int N, Q;
    cin >> N >> Q;

    FenwickTree ft(N);

    while (Q--) {
        char op;
        scanf(" %c", & op);

        if (op == '+') {
            int i, v;
            scanf("%d %d", & i, & v);
            ft.update(i + 1, v);
        } else {
            int i;
            scanf("%d", & i);
            printf("%lld\n", ft.rsq(i));
        }
    }
}
