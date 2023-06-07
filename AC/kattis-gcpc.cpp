/*
kattis-gcpc

- Dynamic rank problem, the use of 'points' and 'penalties' is
  trivial when using pbds as greater_equal automatically sorts
  it for you in desc order, using penalties as a negative number
- use unordered map to track all the different points of teams, 
  and use PBDS to check ranking of our team

Time: O(n log n)
Mem: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// PBDS
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, greater_equal<pair<int, int>>,
    rb_tree_tag, tree_order_statistics_node_update> ost;
    // impt less_equal for duplicates in ost
ost rankings;
unordered_map<int, pair<int, int>> teams;

int main(){
    int N, M, t, p;
    cin >> N >> M;

    // For each event
    for (int i = 0; i < M; i++) {
        // Update latest team win
        cin >> t >> p;

        // Team not yet in rankings
        if (teams.find(t) == teams.end()) {
            teams[t] = (make_pair(1, -1*p));
            rankings.insert(make_pair(1, -1*p));
        }

        // Update team ranking
        else {
            pair<int, int> pii = teams[t];

            int idx = rankings.order_of_key(pii);
            rankings.erase(rankings.find_by_order(idx));
                // dumbass way to erase from pbds but somehow
                // the alternative erase(find(pii)) does not work
            teams[t] = make_pair(pii.first + 1, pii.second - p);
            rankings.insert(teams[t]);
        }

        /* 
        // Debug tool to view rankings
        for (auto pairInt : rankings) {
            cout << pairInt.first << " " << pairInt.second << endl;
        }
        */

        // Output our team ranking
        // If team not in rankings
        if (teams.find(1) == teams.end()) {
            cout << teams.size() + 1 << endl;
        }

        // Find team ranking
        else {
            cout << rankings.order_of_key(teams[1]) + 1 << endl;
        }
    }
}
