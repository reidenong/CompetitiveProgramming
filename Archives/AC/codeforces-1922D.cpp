/*
CF-1922D Berserk Monsters

- A data structure problem. Once u identify the data structure, the problem is straightforward.

- It should be obvious that the naive solution of a O(N) iteration per round is too slow. With N rounds,
  our O(N^2) solution is way too slow and will not pass the time limit where N ~ 300k.

- The key insight is that not all monsters die each round, more importantly the monsters that dont die this round won't
  die next round (so we can ignore them) UNLESS their neighbors die. So instead of querying all monsters each round,
  we only query the monsters who can die this round.

- We use a set to maintain the monsters who are alive. This allows us to use lower_bound and upper_bound to find the
  neighbors of a monster in O(log N).We also use a set to store the monsters who can die next round to prevent duplicates, ie.
  if a monster has 2 neighbors who can die next round, we only want to add it to the set once.

Time: O(N log N)
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    // Receiving input, initializing data structures
    int N;
    cin >> N;
    vector<int> A(N + 2), D(N + 2);
    for (int i = 1; i < N + 1; i++) scanf("%d", &A[i]);
    for (int i = 1; i < N + 1; i++) scanf("%d", &D[i]);

    set<int> alive;
    for (int i = 0; i <= N + 1; i++) alive.insert(i);

    queue<int> died_this_round;
    set<int> die_next_round;
 
 
    // Simulating N rounds
    for (int rd = 0; rd < N; rd++) {
        // First round, simulate all monsters n see who can die
        if (rd == 0) {
            for (int i = 1; i <= N; i++) {
                if (A[i - 1] + A[i + 1] > D[i]) 
                    died_this_round.push(i);
            }
 
        // Not first round, check all monsters who can die (die_next_round) 
        } else {
            for (auto it = die_next_round.begin(); it != die_next_round.end(); it++) {
                int i = *it;
                int left_neighbor = *(--alive.lower_bound(i));
                int right_neighbor = *alive.upper_bound(i);
                if (A[left_neighbor] + A[right_neighbor] > D[i]) 
                    died_this_round.push(i);
            }
            die_next_round.clear();
        }
 
        // All monsters who can die this round have died
        cout << died_this_round.size() << " ";

        // See who can die next round
        while (!died_this_round.empty()) {
            int i = died_this_round.front();
            died_this_round.pop();
            alive.erase(i);
            die_next_round.erase(i);
 
            // Add neighbors to die_next_round
            int left_neighbor = *(--alive.lower_bound(i));
            int right_neighbor = *alive.upper_bound(i);
            if (left_neighbor != 0) die_next_round.insert(left_neighbor);
            if (right_neighbor != N + 1) die_next_round.insert(right_neighbor);   
        }
    }
    cout << "\n";
}
 
int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
}
