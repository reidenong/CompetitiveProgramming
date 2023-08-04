/*
kattis-builddeps

- Topological sort, print answer

- Honestly the crux of this problem is dealing with the string input in c++

- must be done in c++ or it will hit recusrion limit in python, as toposort calls
  > 100000000.

Time: O(V + E)
Space: O(V + E)
*/
#include <bits/stdc++.h>
using namespace std;
int N;
map<string, vector<string>> adjList;
map<string, bool> visited;
vector<string> order;

// DFS topological sort
void toposort(string u) {
    visited[u] = true;

    for (auto node : adjList[u]) {
        if (!visited[node]) toposort(node);
    }
    order.emplace_back(u);
}

int main () {
    // Processing string input
    scanf("%d", &N); 
    cin.ignore();
    string s, line;
    
    // For each line of input
    for (int i = 0; i < N; i++) {
        vector<string> v;
        getline(cin, line);
        istringstream ss(line);
        while (ss >> s) v.emplace_back(s);

        // Processing vector input   
        for (auto str : v) {

            // Parent node
            if (str.find(":") != string::npos) {
                if (adjList.find(str) == adjList.end()) {
                    vector<string> temp;
                    adjList[str] = temp;
                    visited[str] = false;
                }
                v[0] = v[0].erase(v[0].size()-1);
            }

            // Dependency
            else {
                if (adjList.find(str) == adjList.end()) {
                    vector<string> temp;
                    temp.emplace_back(v[0]);
                    adjList[str] = temp;
                    visited[str] = false;
                }
                else {
                    adjList[str].emplace_back(v[0]);
                }
            }
        }
    }

    // Receiving target, toposort, print order
    string target;
    cin >> target;

    toposort(target);

    reverse(order.begin(), order.end());
    for (auto str : order) {
        cout << str << endl;
    }
}
