/*
kattis-kattissquest

- iterating 1by1 is too slow, use lower bound in a descending order map
  to 'jump' to the next suitable energy level (lower bound works here to
  give same or next lower E because map is in deescending order)

*/
#include <bits/stdc++.h>
using namespace std;

map<int, priority_queue<int>, greater<int>> quests;

int main(){
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Receiving input
    int N;
    cin >> N;
    string command; int E, G;
    for (int comm = 0; comm < N; comm++) {
        cin >> command;
        
        // Add quests to map of PQs
        if (command == "add") {
            cin >> E >> G;
            if (quests.find(E) == quests.end()) {
                priority_queue<int> pq;
                quests.insert({ E, pq });
            }
            quests[E].push(G);

        } else {
            cin >> E;
            long long gold = 0;

            // No available quests
            if (quests.empty()) {
                cout << 0 << endl;
                continue;
            }
            
            // Iterate through quests
            while (true) {
                auto itr = quests.lower_bound(E);
                
                // No energy left || No suitable quests left
                if (E == 0 || itr == quests.end()) {
                    break;
                }

                // Suitable quest found, while loop to clear all quests
                // ie. E=10, while loop for 2 5E quests 
                while (!itr->second.empty() && E >= itr->first) {
                    gold += itr->second.top() ;
                    E -= itr->first;
                    itr->second.pop();
                }

                // Clear empty keys
                if (itr->second.empty()){
                    quests.erase(itr->first);
                }
            }
            cout << gold << endl;
        }
    }
}
