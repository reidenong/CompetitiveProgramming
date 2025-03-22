/*
kattis-evenup

use of stack to easily query top of current pile of cards

Time: O(n)
Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;
stack<int> stk;


int main(){
    int N, x;
    cin >> N;

    // for every incoming integer
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;

        // Stack empty, add to stack
        if(stk.empty()){
            stk.push(x);

        // Even sum, remove from stack and check
        }else if((stk.top() + x)%2 == 0){
            stk.pop();
        
        // Non even sum, add to stack and continue
        }else{
            stk.push(x);
        }
    }

    // Displaying remaining cards
    cout << stk.size() << endl;
    return 0;
}
