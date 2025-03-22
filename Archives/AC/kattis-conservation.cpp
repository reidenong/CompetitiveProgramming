/*
kattis-conservation

- Implementation of kahn's algorithm. Basically, we want to do BFS, processing
  a node iff all its dependencies have been processed. 

- To get the minimum lab swaps, we greedily process all dependencies in a single lab
  before swapping labs. This ensures that we are able to process the maximum
  number of nodes while at each lab, minimizing the number of total lab swaps.

- Note that there is no simple way to determine which lab we should start from, 
  so we package the code in such a way that it is easy to run twice, starting from
    either lab. We then take the minimum of the two runs.

Time: O(V + E)
Mem: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> adjList[100001];
int lab[100001];                // Shows if item has to be processed in lab 0 or 1
int in_degree[2][100001];       // Shows how many items have to be processed before item i
queue<int> q[2];                // Queue for each lab

// Modified version of kahn's algorithm
// BFS when each node has no nodes going in (satisfied already)
int kahn (int startLab) {
    int labSwaps = 0;

    // Adding items with no dependencies to their respective queue
    for (int i = 0; i < N; i++) {
        if (in_degree[startLab][i] == 0) {
            q[lab[i]].push(i);
        }
    }

    // Kahn's Algorithm
    int processed = 0;
    int currLab = startLab;
    while (processed < N) {
        
        // Check if need to swap lab
        if (q[currLab].empty()) {
            labSwaps++;
            currLab = 1 - currLab;
            continue;
        }

        // Process all in current lab
        while (!q[currLab].empty()) {
            // Processing each node
            int node = q[currLab].front(); q[currLab].pop();
            processed++;

            // Minus one dependency as [node] is removed
            for (auto &v : adjList[node]) {
                in_degree[startLab][v]--;
                if (in_degree[startLab][v] == 0) q[lab[v]].push(v);
            }
        }
    }
    return labSwaps;
}

int main () {
    int Testcases;
    cin >> Testcases;
    for (int tc = 0; tc < Testcases; tc++) {
        memset(in_degree, 0, sizeof in_degree);
        cin >> N >> M;

        // Receiving lab order for each stage
        for (int i = 0; i < N; i++) {
            cin >> lab[i];
            lab[i]--;
        }

        // Receiving dependencies
        int A, B;
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);
            A--; B--;
            adjList[A].push_back(B);
            in_degree[0][B]++;
            in_degree[1][B]++;
        }

        // Kahn algorithm, Try starting from either lab for true minimum
        cout << min(kahn(0), kahn(1)) << endl;
        
        // Clear Vector for next testcase
        for (int i = 0; i < N; i++) {
            adjList[i].clear();
        }
    }    
}
