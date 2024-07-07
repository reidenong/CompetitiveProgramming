/*
codeforces-1981C

- The condition for a sequence to be valid is that for every 2 elements in a sequence, one of them is the floored 
  half of the other. Notice the main issue is that for x _ _ _ _ y, with 4 missing elements inbetween, we have to
  determine if it is legitimate or not.

- First, address the trivial case of missing array. This can be done by alternating between 1 and 2 for the missing
  elements.

- Next, consider a full binary tree. We notice that we want to find a path between x and y in the binary tree. If the 
  path is valid, we can then fill in the gaps with the values of the path. If the path is longer than the number of missing
  elements, then the sequence is definitely invalid. If the path is shorter, we can fill i the gaps with alternating values
  of the path, but only if the path difference with the missing elements is even.

- My initial method was to consider X, Y, and find the lowest common ancestor (LCA) of the two. This is given
  by the longest common prefix of the binary representation of X and Y. Then we repeatedly divide x by 2 until we reach
  the LCA, and then divide y by 2 until we reach the LCA. This gives us the path between x and y. If there are gaps, we
  can alternate between LCA and LCA*2.

- However, a faster method is to simply track all the biggest elements in the sequence with missing neighbours. We can guarantee
  that the neighbour of the current largest element will be the largest element / 2. We then fill in the gaps this way,
  and check the sequence for validity.

Time: O(N log N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int arr[200001];
priority_queue<ii> pq;

void solve() {
    // Clear the priority queue
    while (!pq.empty()) pq.pop();

    int N;
    cin >> N;

    // Load the array
    for (int i = 0; i < N; i++) cin >> arr[i];

    // Edge case: Array is all missing
    bool missing = true;
    for (int i = 0; i < N; i++) {
        if (arr[i] != -1) {
            missing = false;
            break;
        }
    }
    if (missing) {
        for (int i = 0; i < N; i++) {
            if (i % 2) {
                cout << 1 << " ";
            } else {
                cout << 2 << " ";
            }
        }
        cout << endl;
        return;
    }

    // Add all elements which have missing neighbours
    if (arr[0] != -1 && arr[1] == -1) pq.push({arr[0], 0});
    if (arr[N-1] != -1 && arr[N-2] == -1) pq.push({arr[N-1], N-1});
    for (int i = 1; i < N - 1; i++) {
        if (arr[i] != -1 && (arr[i-1] == -1 || arr[i+1] == -1)) {
            pq.push({arr[i], i});
        }
    }

    // Fill in missing elements
    while (!pq.empty()) {
        ii top = pq.top();
        pq.pop();
        int val = top.first;
        int idx = top.second;

        int child = (val != 1) ? val / 2 : 2;
        
        if (idx > 0 && arr[idx-1] == -1) {
            arr[idx-1] = child;
            if (idx > 1 && arr[idx-2] == -1) pq.push({child, idx-1});
        }

        if (idx < N - 1 && arr[idx+1] == -1) {
            arr[idx+1] = child;
            if (idx < N - 2 && arr[idx+2] == -1) pq.push({child, idx+1});
        }
    }

    // Check sequence legitimacy
    bool valid = true;
    for (int i = 0; i < N; i++) {
        if (i > 0 && !(arr[i] == arr[i-1]/2 || arr[i]/2 == arr[i-1])) {
            valid = false;
            break;
        }
        if (i < N - 1 && !(arr[i] == arr[i+1]/2 || arr[i]/2 == arr[i+1])) {
            valid = false;
            break;
        }
    }

    // Output the answer
    if (valid) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
