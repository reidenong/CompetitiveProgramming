/*
kattis-brexit

- We realise that BFS is needed instead of BFS as the leaving works layer by layer

- We can use a queue to store the nodes that are leaving, and then process them 
  in the correct order

- We can use an array to store the number of initial and final trading partners, 
  everytime a node leaves, we minus 1 from the number of trading partners and 
  compare to the initial number of partners. if less than half, we leave

Time: O(P + C)
Mem: O(P + C)
*/
#include <bits/stdc++.h>
using namespace std;
int C, P, X, L;
vector<int> adjList[200001];
int present[200001];    // Whether or not a node is present in the graph
int initial[200001];    // Number of initial trading parters for each node
int final[200001];      // Number of final trading parters for each node
queue<int> q;

// BFS to leave a node
void leave(int node) {
    if (present[node] == 0) return; // Node has already left (been processed

    present[node] = 0;

    // For each connected node, evaluate if it is leaving or not
    for (int i = 0; i < adjList[node].size(); i++){
        if (present[adjList[node][i]] == 0) continue;

        final[adjList[node][i]]--;

        // See if node leaves
        if (final[adjList[node][i]] <= initial[adjList[node][i]]/2) {
            q.push(adjList[node][i]);
        }
    }
}

int main () {
    // Receiving input
    cin >> C >> P >> X >> L;
    X--; L--;
    int A, B;
    for (int i = 0; i < P; i++){
        scanf("%d %d", &A, &B);
        A--; B--;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
        initial[A]++; initial[B]++;
        final[A]++; final[B]++;
    }

    // Leave L, begin chain reaction
    memset(present, 1, sizeof(present));
    q.push(L);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        leave(node);
    }

    // Output answer
    if (present[X] == 0) cout << "leave" << endl;
    else cout << "stay" << endl;
}
