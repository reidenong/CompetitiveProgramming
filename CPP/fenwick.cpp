/*
 * Fenwick Tree (0-indexed) with range update
 * 
 * Time: O(log n) with low constant factor
 * Status: stress tested (https://judge.yosupo.jp/submission/275173)
 */
class FenwickTree {
   public:
    int N;
    vector<ll> fw, fw2;

    FenwickTree(ll size) : N(size + 1), fw(N, 0), fw2(N, 0) {}

    void update(int x, int y, ll v) {  // inclusive
        x++, y++;                      // Shift to 1-based indexing internally
        for (int tx = x; tx < N; tx += tx & (-tx)) {
            fw[tx] += v;
            fw2[tx] -= v * (x - 1);
        }
        for (int ty = y + 1; ty < N; ty += ty & (-ty)) {
            fw[ty] -= v;
            fw2[ty] += v * y;
        }
    }

    ll sum(int x) {
        x++;  // Shift to 1-based indexing internally
        ll res = 0;
        for (int tx = x; tx; tx -= tx & (-tx)) res += fw[tx] * x + fw2[tx];
        return res;
    }

    ll range_sum(int x, int y) {  // inclusive
        return sum(y) - sum(x - 1);
    }
};
// FenwickTree ft(n);               // Init a Fenwick Tree (0-indexed)
// ll rs = ft.range_sum(p, q);      // Do a range_sum from [p, q] inclusive
// ft.update(a, b, c)               // Add c to every element in [a, b] inclusive