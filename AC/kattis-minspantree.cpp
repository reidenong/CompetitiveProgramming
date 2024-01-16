/*
kattis-minspantree

 - Standard MST problem. We can use Kruskal's algorithm to solve this problem.

Time: O(E log V)
Mem: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> mst;

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
    int N, M;
    while (true) {
        edges.clear();
        mst.clear();

        cin >> N >> M;
        if (N == 0 && M == 0) break;

        int u, v, w;
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back(make_tuple(w, u, v));
        }

        // Kruskal's algorithm
        sort(edges.begin(), edges.end());
        int mst_cost = 0;
        int edges_taken = 0;
        UnionFind UF(N);
        for (auto &[w, u, v] : edges) {
            if (UF.isSameSet(u, v)) continue;   // Already connected
            mst_cost += w;
            mst.push_back(make_pair(min(u, v), max(u, v)));
            UF.unionSet(u, v);
            edges_taken++;
            if (edges_taken == N - 1) break;  // Optimization, MST only has V-1 edges
        }

        // Check if MST is possible
        if (edges_taken != N - 1) {
            printf("Impossible\n");
            continue;
        }

        // Print MST in lexographical order
        printf("%d\n", mst_cost);
        sort(mst.begin(), mst.end());
        for (auto [u, v] : mst) {
            printf("%d %d\n", u, v);
        }
    }
}
