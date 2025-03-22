/*
kattis-grandpabernie

- unordered map of place names mapped to vectors, which are sorted 
  before processing

*/
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<int>> uoMap;


int main(){
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N;

    // Logging trips and years
    string place; int year;
    for(int i = 0; i < N; i++){
        cin >> place >> year;

        // Not the first time
        if(!uoMap.empty() && uoMap.find(place) != uoMap.end()){
            uoMap[place].push_back(year);

        // First log
        } else {
            vector<int> v;
            v.push_back(year);
            uoMap[place] = v;
        }
    }

    // Sorting years of places
    for (auto years : uoMap){
        vector<int> v = years.second;
        sort(v.begin(), v.end());
        uoMap[years.first] = v;
    }

    // Querying place year
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> place >> year;
        cout << uoMap[place][year-1] << endl;
    }
    return 0;
}
