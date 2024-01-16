/*
Kruskal's Algorithm for MSTs

 - Kruskal's algorithm is a greedy algorithm that finds a MST for a connected weighted graph

 - First we sort all the edges by increasing weight, and keep picking the edges that dont form a cycle.
   we are done when we have N-1 edges in our MST.

Time: O(E log V)
Mem: O(E)
*/
#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> edges;

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
    edges.clear();

    int N;  // Number of vertices

    /*
    *
    * edges = { {weight, u, v}, ... } for each edge connecting vertices u, v
    * 
    */

    // Kruskal's Algorithm
    sort(edges.begin(), edges.end());       // Sort edges by increasing weight

    long long mst_cost = 0;
    int edges_taken = 0;
    UnionFind UF(N);
    for (auto &[w, u, v] : edges) {
        if (UF.isSameSet(u, v)) continue;   // Already connected
        mst_cost += w;
        UF.unionSet(u, v);
        edges_taken++;
        if (edges_taken == N - 1) break;  // Optimization, MST only has V-1 edges
    }
    cout << mst_cost << endl;
}
