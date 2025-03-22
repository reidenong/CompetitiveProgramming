#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, s, d, base;
    cin >> N;

    for(int tc = 0; tc < N; tc++){
        cin >> s >> d;

        base = (s - d)/2;

        if(((s-d)%2) || (d>s)){
            cout << "impossible" << endl;
            continue;
        }else if((base+d) >= 0 && base >= 0){
            cout << base+d << " " << base << endl;
        }else cout << "impossible" << endl;

        

        

    }

    return 0;
}
