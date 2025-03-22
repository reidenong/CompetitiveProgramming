/*
kattis-greetingcard

- first thing to consider is N <= 10^5, so N^2 comparison will 
  probably TLE.
- next thing is that euclidean distance is in play, so we cannot
  just do a linear pass with 4 xy parallel neighbours
- However, an observation is that the number chosen 2018 is oddly
  specific. by using a small script in python,

  for i in range(1,2019):
    for j in range(1,2019):
        if(i**2 + j**2 == 2018**2):
            print(i, j)

  we realise that there are only 1 possible i,j combination of
  1680 and 1118 to give a distance of 2018, hence linear pass is
  possible with 12 total neighbours

Time: O(N log N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> S;
set<pair<int, int>>::iterator itrS;
vector<pair<int,int>> checks;

int main(){
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // Receiving pair input
    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        S.insert(make_pair(x, y));
    }

    // Setting up neighbour pair checker
    x = 1680, y = 1118;
    checks.push_back(make_pair(x, y));
    checks.push_back(make_pair(-1*x, y));
    checks.push_back(make_pair(x, -1*y));
    checks.push_back(make_pair(-1*x, -1*y));
    checks.push_back(make_pair(0,2018));
    checks.push_back(make_pair(0,-2018));
    for(int i = 0; i < 6; i++){
        x = checks[i].first, y = checks[i].second;
        checks.push_back(make_pair(y, x));
    }

    // Iterate through set, finding pairs and removing given element
    int pairCounter = 0;
    while(S.size() > 1){
        itrS = S.begin();

        // Check for each of 12 combinations
        for( const pair<int, int> &element : checks){
            x = itrS->first + element.first;
            y = itrS->second + element.second;
            if(S.find(make_pair(x,y)) != S.end())pairCounter++;
        }
                // Possible speedup to check x, y in range first?

        // Remove element after checking to avoid doublecount
        S.erase(itrS);
    }
    // Output
    cout << pairCounter << endl;
    return 0;
}
