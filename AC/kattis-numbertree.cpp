/*
kattis-numbertree

- pattern recognition
- if previous branch was right or left with delta d, then the difference 
  of the current branch would be either 2d, 2d+1 or 2d-1

Time: O(steps.length())
Size: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int H;
    string steps;
    cin >> H >> steps;
    
    // Initializing starting conditions and delta
    int number = pow(2, H+1) -1;
    if(steps == ""){    // no steps return top number
        cout << number << endl;
        return 0;
    }
    int delta;
    if(steps[0] == 'L')delta = 1;
    else delta = 2;
    number -= delta;

    // Iterating through all steps
    for(int i = 1; i < steps.length(); i++){
        // If previous step was left
        if(steps[i-1] == 'L'){
            if(steps[i] == 'L')delta *= 2;
            else delta = delta*2 + 1;
        
        // If previous step was right
        }else{
            if(steps[i] == 'L')delta = 2*delta-1;
            else delta = delta*2;
        }
        number -= delta;    // Updating number
    }

    cout << number << endl;
    return 0;
}
