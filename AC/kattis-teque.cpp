/*
kattis- teque

- Did this question first in python, but it was too slow (TLE)
- Coding the exact same thing in cpp works tho

- Important that all update functions are O(1), which is achieved by using 
  deque's push, pop, front/back, and size functions.
- This is possible by using 2 deques to simulate a "triple" ended deque, where
  deque is constantly being rebalanced such that the two ends are always 
  equal +- 1 for odd sizing
- with this method push_middle is pushing back on the first deque

Time: O(n)
Size: O(n insertions)
*/
#include <bits/stdc++.h>
using namespace std;

deque<int> one;
deque<int> two;

int main(){
    int N;
    cin >> N;

    // For each action
    int number;
    string action;
    for(int i = 0; i < N; i++){
        cin >> action >> number;

        if(action == "push_back"){
            two.push_back(number);
            if(two.size() > one.size()){
                one.push_back(two.front());
                two.pop_front();
            }
        }else if(action == "push_front"){
            one.push_front(number);
            if(one.size()-two.size() > 1){
                two.push_front(one.back());
                one.pop_back();
            }
        }else if(action == "push_middle"){
            two.push_front(number);
            if(two.size() > one.size()){
                one.push_back(two.front());
                two.pop_front();
            }
        }else{
            // Get function
            if(number >= one.size())cout << two[number-one.size()] << endl;
            else cout << one[number] << endl;
        }

    }
}
