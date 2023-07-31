/*
kattis-moviecollection

- We use a fenwick tree for this dynamic rsq problem

- the design is such that we place our movies into a fenwick tree while
  recording their positions. Furthermore, we place R empty placeholders of {0}
  above the movies in the fenwick tree. This is so that we can insert movies
  later on after watching them.

- As we watch a movie, we find their position using the position array, and 
  then we return the relevant RSQ. Following which, we update the FT with a -1
  such that there is a 0 where it used to be, and update the latest relevant placeholder
  with a 1, as well as the positional array to reflect its new position at the top
  of the stack.

Time: O(R log(R+M))
Space: O(R+M)
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

// Data structures
int pos[100005];    // 1-indexed, gives position of movie i

int main () {
    int TCs;
    scanf ("%d", &TCs);

    for (int tc = 0; tc < TCs; tc++) {
        int M, R;
        scanf("%d %d", &M, &R);

        vll movies = {0};   // 1-indexed for Fenwick tree

        // Initialize positions and movies vector
        for (int i = 1; i <= M; i++) {
            pos[i] = M - i + 1;
            movies.push_back(1);
        }

        // Empty placeholders for inserting movies after watching
        for (int i = 0; i <= R; i++) {
            movies.push_back(0);
        }

        FenwickTree ft(movies);

        // Move movies for each query
        for (int query = 0; query < R; query++) {
            int movie;
            scanf("%d", &movie);

            // Return movie output
            printf("%lld ", ft.rsq(pos[movie] + 1, M + R));

            // Update Fenwick tree, positional array
            ft.update(pos[movie], -1);
            ft.update(M + query + 1, 1);
            pos[movie] = M + query + 1;
        }

        printf("\n");
    }
}
