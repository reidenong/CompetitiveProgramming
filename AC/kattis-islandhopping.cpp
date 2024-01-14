/*
kattis-islandhopping
*/
#include <bits/stdc++.h>
using namespace std;
pair<float, float> islands[751];
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
    // For each testcase
    int TC, M;
    float x, y;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++) {
        edges.clear();

        // Receiving island input
        cin >> M;
        for (int i = 0; i < M; i++) {
            scanf("%f %f", &x, &y);
            islands[i] = make_pair(x, y);
        }

        // Calculate bridge length for every possible pair of islands
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                float dist = sqrt(pow(islands[i].first - islands[j].first, 2) + pow(islands[i].second - islands[j].second, 2));
                edges.push_back(make_tuple(dist, i, j));
            }
        }

        // Kruskal's Algorithm
        sort(edges.begin(), edges.end());       // Sort bridges by increasing weight
        float mst_cost = 0;
        int bridges_taken = 0;
        UnionFind UF(M);
        for (auto &[w, u, v] : edges) {
            if (UF.isSameSet(u, v)) continue;   // Already connected
            mst_cost += w;
            UF.unionSet(u, v);
            bridges_taken++;
            if (bridges_taken == M - 1) break;  // Optimization, MST only has V-1 edges
        }
        cout << mst_cost << endl;
    }
}
