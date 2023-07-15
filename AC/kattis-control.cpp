/*
kattis-control

- use UFDS

- consider all ingredients as distinct sets first. When used for
  a potion, these ingredients are then unionized into the same set

- First for each recipe we find the number of unique sets needed to make
  them. Then with every element accounted for in a set or another, we
  sum up total sizes of all the sets. Any extra means extra ingredients.

- if the potion is successful we need to unionize all items in the same potion.

*/
#include <bits/stdc++.h>
using namespace std;

// UFDS Data Structure
class UnionFind {                                // OOP style
private:
    vector<int> p, rank, setSize;                           // vi p is the key part
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
    int N, recipeSize, ingredient;
    cin >> N;

    // Consider all ingredients as distinct sets
    UnionFind ufds (500005);

    // For each recipe
    int potions = 0;
    for (int i = 0; i < N; i++) {
        set<int> uniqueSets;
        cin >> recipeSize;
        for (int j = 0; j < recipeSize; j++) {
            cin >> ingredient;

            // Find number of unique sets that make up recipe
            uniqueSets.insert(ufds.findSet(ingredient));
        }

        // Find total potion size
        int potionSize = 0;
        for (auto ele : uniqueSets) {
            potionSize += ufds.sizeOfSet(ele);
        }

        // Compare potion size with recipe size
        // potion is guaranteed to have at least all ingredients in recipe
        if (potionSize == recipeSize) {
            potions++;
            for (auto ele : uniqueSets) {
                ufds.unionSet(ele, *uniqueSets.begin());
            }
        }
    }
    cout << potions << endl;
    return 0;
}
