#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// When receiving a line of space separated string inputs of unknown lengths
// ie. "america brunei cameroon denmark"
int stringInput () {
    string s, line;
    getline(cin, line);
    vector<string> v;
    istringstream ss(line);
    while (ss >> s) v.emplace_back(s);

    // print str for debugging
    for (auto str : v) {
        cout << str << " ";
    }
}

int main(){
    fast_cin();

    return 0;
}
