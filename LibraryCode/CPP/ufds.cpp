/*
Union Find Disjoint sets

- Data structure used to model a collection of disjoint sets which can efficiently determine which set an item belongs to
  as well as to unite two sets

- code taken from cp-book github, here for easy reference

Time: O(1) operations
Space: O(N) 
*/
#include <bits/stdc++.h>
using namespace std;

// UFDS
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

    // Creating UFDS
    UnionFind ufds (N);

    // Functions
    ufds.findSet(i);            // returns which set i belongs to
    ufds.isSameSet(i, j);       // returns bool 0/1 if i, j are in same set
    ufds.unionSet(i, j);        // combines set containing i and set containing j
    ufds.numDisjointSets();     // returns int, number of disjoint sets
    
    return 0;
}
