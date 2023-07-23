/*
kattis-ladice

- The rules are all a bit of fluff, dosen't matter

- What is important is as a item is placed in a drawer, its two locations become
  linked together. This can be stacked on top of other items such that all items 
  that are in linked spots can travel around

- We can use UFDS to model the linkages between drawers, such that disjoint sets 
  show the number of spaces available in a set. We then maintain a occupancy counter
  tagged to the parent index of each disjoint set such that we can get a idea of the
  vacancy of given set by (sizeofset - occupancy[parent idx])

Time: O(N)
Space: O(L)
*/
#include <bits/stdc++.h>
using namespace std;
int occupied[300001];

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
    int N, L, A, B;
    cin >> N >> L;

    UnionFind ufds (L);

    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        A--; B--;           // 0 based indexing
        
        // Vacancy given by (size of set - current occupancy)
        // Take the max vacancy of A and B as they may still be disjoint
        int vacancy = max(ufds.sizeOfSet(A) - occupied[ufds.findSet(A)], ufds.sizeOfSet(B) - occupied[ufds.findSet(B)]);

        // Vacancy, LADICA
        if (vacancy > 0) {
            // Merge A, B
            // Also merge their occupancy counts and add one for the incoming item
            int occupancy = occupied[ufds.findSet(A)] + occupied[ufds.findSet(B)] + 1;
            occupied[ufds.findSet(A)] = 0;
            occupied[ufds.findSet(B)] = 0;
            ufds.unionSet(A, B);

            // Update new occupancy count to parent idx of given set
            occupied[ufds.findSet(A)] = occupancy;
            cout << "LADICA" << endl;
        }
        
        // No vacancy, SMECE
        else {
            cout << "SMECE" << endl;
        }
    }
}
