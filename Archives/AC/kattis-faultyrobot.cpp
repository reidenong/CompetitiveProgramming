/*
kattis-faultyrobot

- Simulate a robot moving in a predetermined pattern, with the tendency to make a
  singular error somewhere which will result in a different outcome.

- We first simulate the robot moving in the forced pattern. At every new node, we
  explore the robot making a faulty move and see where the robot goes. We constantly 
  update the faultyExplored nodes to prevent recomputation if the robot has gone down
  a particular path before.

- We dont have to care about cycles, as long as the robot comes to a visited node we
  just cut short the DFS traversal

- Note that we need to use separate visited arrays for the faulty and forced paths,
  as the faulty path may be a subset of the forced path, and we dont want to cut short
  the forced path traversal. because on the forced path the robot may make a faulty move
  later on

*/
#include <bits/stdc++.h>
using namespace std;
vector<int> faulty[1001];
vector<int> forced[1001];
int visited[1001];  // Careful of cycles
int faultyVisited[1001];
int ending[1001];

// DFS for faulty move exploration
void dfs (int u) {
    faultyVisited[u] = 1;

    if (forced[u].size() == 0) {
        ending[u] = 1;
        return;
    }

    for (auto v : forced[u]) {
        if (faultyVisited[v] == 0 && visited[v] == 0) {
            dfs(v);
        }
    }
}

int main () {
    int N, M, A, B;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        if (A > 0) {
            A--; B--;
            faulty[A].push_back(B);
        } else {
            A *= -1;
            A--; B--;
            forced[A].push_back(B);
        }
    }

    // Robot following path (Linear, can be done w a loop)
    int currNode = 0;
    while (true) {
        visited[currNode] = 1;

        // Try to take faulty path
        for (auto v : faulty[currNode]) {
            if (visited[v] == 0) {
                dfs(v);
            }
        }

        // End of forced normal path
        if (forced[currNode].size() == 0) {
            ending[currNode] = 1;
            break;
        }

        // Meet a cycle, break
        if (visited[forced[currNode][0]] == 1) {
            break;
        }

        // Move on to next node
        currNode = forced[currNode][0];
    }

    // Record number of endings
    int endings = 0;
    for (int i = 0; i < N; i++) {
        //printf("%d ", ending[i]);
        endings += ending[i];
    }
    cout << endings << endl;
    return 0;
}
