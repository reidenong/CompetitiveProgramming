/*
kattis-convoy

- can appear to be a very complicated question, but this can be simplified with the right implementation, as
  well as a few key observations

- Observe that the only people who might ever drive are the fastest K people. Apart from them nobody else will ever
  drive as only these people have to either drive to the end or make a return trip. Thus we only ever have to take
  them into consideration. As such, we can just keep track of the total number of people fetched and stop when
  we have fetched >= N people.

- It may seem messy to have to deal with having people at the start and back, but we can simplify this by keeping 2 
  separate priority queues. The key implementation change is that we only ever bring people from the start to the back.
  If we are ferrying people from the start, we consider the time taken to make a trip to the end.
  If we are making a return trip, we consider the time taken to make a trip back to the start and end. This helps
  simplify implementation greatly. Also we only consider the driver going over on a first trip, ie start trips
  fetch 5 people and return trips fetch 4 people.

Time: O(N log N)
Mem: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ll_pair;

priority_queue<ll_pair, vector<ll_pair>, greater<ll_pair>> start, back;
int drivers[20001];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> drivers[i];
    }

    sort(drivers, drivers + N);

    for (int i = 0; i < min(N, K); i++) {
        start.push({drivers[i], i});
    }

    int fetched = 0;
    ll curr_time = 0;
    while (true) {

        // Check if all fetched
        if (fetched >= N) {
            cout << curr_time << endl;
            return 0;
        }

        // Have to use start driver if nobody is at the back
        if (back.empty()) {
            auto [time, driver] = start.top();
            back.push({time + (2 * drivers[driver]), driver});
            start.pop();
            fetched += 5;
            curr_time = max(curr_time, time);
            continue;
        }

        // Have to use back driver is nobody is at the start
        if (start.empty()) {
            auto [time, driver] = back.top();
            back.pop();
            back.push({time + (drivers[driver] * 2), driver});
            
            fetched += 4;
            curr_time = max(curr_time, time);
            continue;
        }

        // If both are available, use the one that will be done earlier
        auto [time_s, driver_s] = start.top();
        auto [time_e, driver_e] = back.top();
        if (time_s < time_e) {
            back.push({time_s + (drivers[driver_s] * 2), driver_s});
            start.pop();
            fetched += 5;
            curr_time = max(curr_time, time_s);
        } else {
            back.pop();
            back.push({time_e + (drivers[driver_e] * 2), driver_e});
            fetched += 4;
            curr_time = max(curr_time, time_e);
        }
    }  
}
