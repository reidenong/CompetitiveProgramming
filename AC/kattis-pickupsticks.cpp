/*
kattis-pickupsticks

- This qn has 2 parts, both of which are fairly straightforward

- (1) Checking for cycles can be done with DFS

- (2) Topological sort can be used to settle vertices in a linear order such that
      all dependencies are settled before the parent node.

Time: O(V + E)
Mem: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[100001];
int visited[100001];
enum {UNVISITED, VISITED, PROCESSED};
bool cyclic = false;
vector<int> order;

// DFS for finding cycles
void cyclecheck (int u) {
    visited[u] = VISITED;
    for (auto &v : adjList[u]) {
        if (visited[v] == UNVISITED) 
            cyclecheck(v);

        if (visited[v] == VISITED)
            cyclic = true;

        if (cyclic) break;  // save unnecessary computation
    }
    visited[u] = PROCESSED;
}

// DFS for topological sorting
void toposort (int u) {
    visited[u] = VISITED;
    for (auto v : adjList[u]) {
        if (visited[v] == UNVISITED)
            toposort(v);
    }
    order.push_back(u);
}

int main () {
    // Receiving graph input in adjList
    int N, M, A, B;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        scanf ("%d %d", &A, &B);
        A--; B--;
        adjList[A].push_back(B);
    }

    // Test for cycles (IMPOSSIBLE test)
    for (int i = 0; i < N; i++)
        if (visited[i] == UNVISITED && !cyclic)
            cyclecheck(i);
    if (cyclic) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Give linear stick order by Toposort
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < N; i++)
        if (visited[i] == 0)
            toposort(i);
    reverse(order.begin(), order.end());
    for (auto elem : order) 
        cout << elem + 1 << endl;
}
