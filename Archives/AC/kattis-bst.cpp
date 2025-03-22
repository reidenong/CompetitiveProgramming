/*
kattis-bst

- simulating actual bst is too slow... tried n TLEd
- faster to use set to keep track of items in bst and use hashmap
  to get depth of items before the new node
- answer needs to be a long long else overflow and WA

Time: O(n log n)
Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

set<int> bbst;
unordered_map<int, int> depth;

int main(){
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Receiving input
    int N, node;
    long long C = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> node;

        // Starting node
        if (bbst.empty()) {
            depth[node] = 0;

        // Non-starting node
        } else {
            // New smallest
            if (bbst.lower_bound(node) == bbst.begin()) {
                depth[node] = depth[*bbst.begin()] + 1;
            
            // New largest element
            } else if (bbst.upper_bound(node) == bbst.end()) {
                depth[node] = depth[*--bbst.end()] + 1;

            // New element in the middle
            } else {
                depth[node] = max(depth[*--bbst.upper_bound(node)],
                                  depth[*bbst.upper_bound(node)]) + 1;
            }
        }
        bbst.insert(node);
        C += depth[node];
        cout << C << endl;
    }
}
