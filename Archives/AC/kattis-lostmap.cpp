/*
kattis-lostmap

 - standard mst problem, except we don't care about the weight and we just
   want to recreate the MST

 - We can use Kruskal with UFDS

Time: O(E log N)
Mem: O(E)
*/
#include <bits/stdc++.h>
using namespace std;
vector<tuple<float, int, int>> edges;
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
    int N;
    cin >> N;

    int weight;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> weight;
            if (i < j) {
                edges.push_back(make_tuple(weight, i, j));
            }
        }
    }

    sort(edges.begin(), edges.end());
    int edges_taken = 0;
    UnionFind UF(N);
    for (auto &[w, u, v] : edges) {
        if (UF.isSameSet(u, v)) continue;   // Already connected
        mst.push_back(make_pair(u, v));
        UF.unionSet(u, v);
        edges_taken++;
        if (edges_taken == N - 1) break;  // Optimization, MST only has V-1 edges
    }

    for (auto &[u, v] : mst) {
        cout << u + 1 << " " << v + 1 << endl;
    }
}
