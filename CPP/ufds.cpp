/*
Union Find Disjoint sets

- Data structure used to model a collection of disjoint sets which can efficiently determine which set an item belongs to
  as well as to unite two sets

- code taken from cp-book github, here for easy reference

Time: ~O(1) operations
Space: O(N) 
*/
#include <bits/stdc++.h>
using namespace std;

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

    int find_set(int i) { return (p[i] == i) ? i : (p[i] = find_set(p[i])); }
    bool is_same_set(int i, int j) { return find_set(i) == find_set(j); }

    int num_disjoint() { return numSets; }      // optional
    int size_of_set(int i) { return setSize[find_set(i)]; } // optional

    void union_set(int i, int j) {
        if (is_same_set(i, j)) return;                 // i and j are in same set
        int x = find_set(i), y = find_set(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
};

// UnionFind ufds (N);          // Create a UFDS with [0..N-1] items
// ufds.find_set(i);            // returns which set i belongs to
// ufds.is_same_set(i, j);      // returns bool 0/1 if i, j are in same set
// ufds.union_set(i, j);        // combines set containing i and set containing j
// ufds.num_disjoint();         // returns int, number of disjoint sets
