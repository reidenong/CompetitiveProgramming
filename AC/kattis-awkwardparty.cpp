/*
kattis-awkwardparty

- reading comprehension more than anything zzz
- you want the MINIMUM distance between 2 people speaking the language
  for all languages
- manage indices for each language with a unordered map of vectors

*/
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> uoMap;

int main(){
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // Receive input, add each language and position to map
    int language;
    for( int i = 0; i < N; i++){
        cin >> language;

        // Not in map
        if (uoMap.find(language) == uoMap.end()){
            vector<int> v;
            uoMap[language] = v;
        }

        // Add index to map
        uoMap[language].push_back(i);
    }

    // Calculate awkwardness
    int awk = INT_MAX-1;
    for (auto &it : uoMap){
        if (it.second.size() > 1){
            
            vector<int> v = it.second;
            sort(v.begin(), v.end());

            for (int i = 1; i < v.size(); i++){
                awk = min(awk, v[i] - v[i-1]);
            }
        }
    }
    if (awk != INT_MAX-1) cout << awk << endl;
    else cout << N << endl;
    return 0;
}
