/*
kattis-freeweights

- We want to find the smallest weight such that all other dumbbells
  can be arranged by rolling.
- we used a function, queryRack to test if rack is viable for a given 
  weight. If the dumbbell <= weight, we assume it can be moved and ignore
  it. if the dumbbell is larger, now we test if it is paired with the next
  non mobile dumbbell. at any point if false, we deem the rack as unviable
  for the given weight

- given large N = 1e6, O(N) linear pass is probably too slow so we use
  log2(N) binary search.
- Now to find the smallest weight where it is viable, we do BSTA with
  midpoint and midpoint-1, where our answer lies when midpoint is viable
  but midpoint-1 is not.

Time: O(log2(N) log N) ~= O(29 log N) = O(log N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
set<int> weightSet;
vector<int> weights;
const int MAX_N = 1e6 + 1;
int topRow[MAX_N], botRow[MAX_N];
int N;

// Query if rack is legitimate for lifting a given weight
bool queryRack (int weight) {
    int topCurr = 0, botCurr = 0;
    for (int i = 0; i < N; i++) {
        // TOP ROW
        // Weight cant be moved, 
        if (topRow[i] > weight){
            // Current dumbbell we are looking at
            if (topCurr == 0) {
                topCurr = topRow[i];
            }

            // Check if dumbbell pairs
            else {
                if (topCurr != topRow[i]) return false;
                else topCurr = 0;
            }
        }

        // BOTTOM ROW (same as top)
        if (botRow[i] > weight) {
            if (botCurr == 0) {
                botCurr = botRow[i];
            }
            else {
                if (botCurr != botRow[i]) return false;
                else botCurr = 0;
            }
        }
    }
    if (topCurr == 0 and botCurr == 0) return true; // Last element is paired
    else return false;
}

int main () {
    cin >> N;

    // Receiving rack input
    int dumbbell;
    for (int i  = 0; i < N; i++) {  // Top rack
        scanf("%d", &dumbbell);
        weightSet.insert(dumbbell);
        topRow[i] = dumbbell;
    }
    for (int i  = 0; i < N; i++) {  // Bottom rack
        scanf("%d", &dumbbell);
        weightSet.insert(dumbbell);
        botRow[i] = dumbbell;
    }

    // Prepare vector of weights from set
    weights.reserve(weightSet.size());
    copy(weightSet.begin(), weightSet.end(), back_inserter(weights));

    // Code for visualization of BSTA principle
    /*
    for (auto elem : weights) {
        if (queryRack(elem)) cout << elem << " True" << endl;
        else cout << elem << " False" << endl;
    }
    */

    // Test for perfect rack and smallest weight
    if (queryRack(0)) {
        cout << 0 << endl;
        return 0;
    } 
    if (queryRack(weights[0])) {
        cout << weights[0] << endl;
        return 0;
    }

    // BSTA for minimum True queryRack Weight
    int lo = 0, hi = weights.size() - 1;
    bool midTest, preTest;
    while (true) {
        int mid = floor((lo + hi) / 2);

        midTest = queryRack(weights[mid]);
        preTest = queryRack(weights[mid-1]);
        
        // Found min weight
        if (midTest && !(preTest)) {
            cout << weights[mid] << endl;
            break;
        }

        // Need higher weight
        if (!midTest) {
            lo = mid + 1;
        }

        // Need lower weight
        else {
            hi = mid - 1;
        }
    }
}

