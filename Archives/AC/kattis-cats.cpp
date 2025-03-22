/*
kattis-cats

- standard MST question

- Rememeber to account for mst_cost <= M - C as we have to feed each cat 1ml of milk
*/
#include <bits/stdc++.h>
using namespace std;
vector<tuple<float, int, int>> edges;

// UFDS Library code
class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional feature
        numSets = N;                                 // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }      // optional
    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
};

int main() {
    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; tc++) {
        edges.clear();

        int M, C;
        cin >> M >> C;

        int w, u, v;
        for (int i = 0; i < (C * (C - 1)) / 2; i++) {
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back(make_tuple(w, u, v));
        }
        sort(edges.begin(), edges.end());

        int mst_cost = 0;
        int edges_taken = 0;
        UnionFind UF(C);
        for (auto &[w, u, v] : edges) {
            if (UF.isSameSet(u, v)) continue;   // Already connected
            mst_cost += w;
            UF.unionSet(u, v);
            edges_taken++;
            if (edges_taken == C - 1) break;  // Optimization, MST only has V-1 edges
        }

        if (mst_cost + C <= M) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
