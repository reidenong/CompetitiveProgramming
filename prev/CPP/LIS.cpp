/*
O(N log K) LIS

- Uses greedy and divide & conquer to give LIS in O(N log k) 
  time instead of usual O(N^2) Time
  
- With a linear pass through the given arr for elem, it creates a empty list 'seq'
  and chooses between 1 of 2 options: 
      (1) If seq is empty or elem is new largest element, it appends elem to the end
          of seq
      (2) Else it finds the lower bound of elem in seq and replaces that element

- This greedily chooses following "smaller" elements in the LIS to replace current 
  elements in the constructed LIS, thus increasing the ability to create a longer
  LIS later on

- It also tracks the predecessors of each element, thus being able to reconstruct the
  lexographically smallest LIS by just seeing the last element of the LIS and backtracking
  its predecessors

- To get LDS, can use this with negative numbers or find the LIS of the reversed array

Time: O(N log K)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
int arr[100001];
map<int, int> predecessors;
vector<int> seq;

// Greedy + D&C Binary search LIS
int LIS (int N, int arr[]) {
    for (int i = 0; i < N; i++) {
        if (seq.empty()) {
            seq.push_back(arr[i]);
            predecessors[arr[i]] = -1;
            continue;
        }

        auto itr = lower_bound(seq.begin(), seq.end(), arr[i]);

        // Expand seq
        if (itr == seq.end()) {
            predecessors[arr[i]] = seq.back();
            seq.push_back(arr[i]);
        }

        // Replace element in seq
        else {
            int pos = itr - seq.begin();
            seq[pos] = arr[i];
            if (pos != 0) predecessors[arr[i]] = seq[pos - 1];
            else predecessors[arr[i]] = -1;
        }
    }
    return seq.size();
}

int main () {
    int N;
    cin >> N;
    
    // Clearing data structures
    memset(arr, 0, sizeof arr);
    seq.clear();
    predecessors.clear();

    // Receiving input
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // LIS
    int length = LIS(N, arr);
    cout << length << endl;

    // Backtracking to find elements
    vector<int> elements;
    int curr = seq.back();
    while (curr != -1) {
        elements.push_back(curr);
        curr = predecessors[curr];
    }
    reverse(elements.begin(), elements.end());

    // Displaying elements
    for (int elem : elements) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
