// Kattis-cd
// python too slow
// cpp unordered set usage
#include <bits/stdc++.h>
using namespace std;
unordered_set<int> uoSet;

int main(){
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // For every testcase
    int N, M, cd;
    while(1){
        while(!uoSet.empty())uoSet.clear();
        int counter = 0;

        // Receiving input
        cin >> N >> M;
        if(N == 0 && M == 0){
            break;
        }

        // Jack CDs
        for(int i = 0; i < N; i++){
            cin >> cd;
            uoSet.insert(cd);
        }

        // Jill CDs
        for(int i = 0; i < M; i++){
            cin >> cd;
            if( uoSet.find(cd) != uoSet.end())counter++;
        }

        cout << counter << endl;
    }

    return 0;
}
