/*
kattis-unionfind

- classic UFDS question

- use scanf/printf instead cuz of high IO volume

Time: O(Q) (all UFDS operations are O(1))
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

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
    int N, Q;
    cin >> N >> Q;

    UnionFind ufds (N);

    char action; int first, second;
    for (int i = 0; i < Q; i++) {
        scanf(" %c%d%d", &action, &first, &second);

        if (action == '?') {
            if (first == second) {
                printf("yes\n");
                continue;
            }
            if (ufds.isSameSet(first, second)) printf("yes\n");
            else printf("no\n");
        }
        
        else {
            ufds.unionSet(first, second);
        }
    }
    return 0;
}
