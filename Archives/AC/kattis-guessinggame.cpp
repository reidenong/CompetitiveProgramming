#include <bits/stdc++.h>
using namespace std;

int main(){
    int number; string line;
    
    while(1){
        int ub = 11, lb = 0;
        bool ans = 1;
        while(1){
            cin >> number;
            if(number == 0)return 0;    // end of problem
            cin.ignore();
            getline(cin, line);
            if(ub < lb)ans = 0;

            if(line == "too high"){
                // number too high, change upper bound to be lower
                ub = min(ub, number-1);
            }else if(line == "too low"){
                // number too low, change lower bound to be higher
                lb = max(lb, number+1);
            }else{
                // right on
                if(ub < number || lb > number)ans=0;
                if(ans) cout << "Stan may be honest" <<endl;
                else cout << "Stan is dishonest" << endl;
                break;
            }
            if(ub < lb)ans = 0;
            // cout << lb << ' ' << ub << endl;

        }  
    }


    return 0;
}
