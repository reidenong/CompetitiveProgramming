/*
 * Lazy Segment Tree
 *
 * Time: O(log n) per operation
 * Status: tested on kattis-hringvegurinn
 */
struct node {
    int s, e;
    bool lset;
    ll mn, mx, sum, xr, add_val, set_val;
    node *l, *r;
    node(int _s, int _e, const vector<int> &A = {})
        : s(_s),
          e(_e),
          mn(0),
          mx(0),
          sum(0),
          xr(0),
          lset(0),
          add_val(0),
          set_val(0),
          l(NULL),
          r(NULL) {
        if (A.empty()) return;
        if (s == e)
            mn = mx = sum = xr = A[s];
        else {
            l = new node(s, (s + e) >> 1, A),
            r = new node((s + e + 2) >> 1, e, A);
            combine();
        }
    }
    void create_children() {
        if (s == e) return;
        if (l != NULL) return;
        int m = (s + e) >> 1;
        l = new node(s, m);
        r = new node(m + 1, e);
    }
    void self_set(ll v) {
        lset = 1;
        mn = mx = set_val = v;
        sum = v * (e - s + 1);
        xr = v * (e - s + 1);
        add_val = 0;
    }
    void self_add(ll v) {
        if (lset) {
            self_set(v + set_val);
            return;
        }
        mn += v, mx += v, add_val += v;
        sum += v * (e - s + 1);
        xr ^= v * (e - s + 1);
    }
    void lazy_propagate() {
        if (s == e) return;
        if (lset) {
            l->self_set(set_val), r->self_set(set_val);
            lset = set_val = 0;
        }
        if (add_val != 0) {
            l->self_add(add_val), r->self_add(add_val);
            add_val = 0;
        }
    }
    void combine() {
        if (l == NULL) return;
        sum = l->sum + r->sum;
        mn = min(l->mn, r->mn);
        mx = max(l->mx, r->mx);
        xr = l->xr ^ r->xr;
    }
    void add(int x, int y, ll v) {
        if (s == x && e == y) {
            self_add(v);
            return;
        }
        int m = (s + e) >> 1;
        create_children();
        lazy_propagate();
        if (x <= m) l->add(x, min(y, m), v);
        if (y > m) r->add(max(x, m + 1), y, v);
        combine();
    }
    void set(int x, int y, ll v) {
        if (s == x && e == y) {
            self_set(v);
            return;
        }
        int m = (s + e) >> 1;
        create_children();
        lazy_propagate();
        if (x <= m) l->set(x, min(y, m), v);
        if (y > m) r->set(max(x, m + 1), y, v);
        combine();
    }
    ll range_sum(int x, int y) {
        if (s == x && e == y) return sum;
        if (l == NULL || lset) return (sum / (e - s + 1)) * (y - x + 1);
        int m = (s + e) >> 1;
        lazy_propagate();
        if (y <= m) return l->range_sum(x, y);
        if (x > m) return r->range_sum(x, y);
        return l->range_sum(x, m) + r->range_sum(m + 1, y);
    }
    ll range_min(int x, int y) {
        if (s == x && e == y) return mn;
        if (l == NULL || lset) return mn;
        int m = (s + e) >> 1;
        lazy_propagate();
        if (y <= m) return l->range_min(x, y);
        if (x > m) return r->range_min(x, y);
        return min(l->range_min(x, m), r->range_min(m + 1, y));
    }
    ll range_max(int x, int y) {
        if (s == x && e == y) return mx;
        if (l == NULL || lset) return mx;
        int m = (s + e) >> 1;
        lazy_propagate();
        if (y <= m) return l->range_max(x, y);
        if (x > m) return r->range_max(x, y);
        return max(l->range_max(x, m), r->range_max(m + 1, y));
    }
    ll range_xor(int x, int y) {
        if (s == x && e == y) return xr;
        if (l == NULL || lset) return xr;
        int m = (s + e) >> 1;
        lazy_propagate();
        if (y <= m) return l->range_xor(x, y);
        if (x > m) return r->range_xor(x, y);
        return l->range_xor(x, m) ^ r->range_xor(m + 1, y);
    }
    ~node() {
        if (l != NULL) delete l;
        if (r != NULL) delete r;
    }
} *root;
// root = new node(0, n - 1, A);       // Creates segment tree with range [0,
// n-1] wiht A root = new node(0, 10000000000);    // Creates segment tree with
// range [0, 10000000000] root->add(0, 3, 5);                 // Adds 5 to all
// elements in range [0, 3] root->set(0, 3, 5);                 // Sets all
// elements in range [0, 3] to 5 root->range_sum(0, 3);               // Returns
// sum of elements in range [0, 3]