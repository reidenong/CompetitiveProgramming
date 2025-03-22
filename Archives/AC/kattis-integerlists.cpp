/*
kattis- integerlists

- input formatting irritating
- literally reversing the string for ever R is computationally expensive
  just keep track of reversed status and delete from the front or the 
  back by using deque O(1) pop_front/back().
- if reversed print and pop from the back, else print and pop from front

Time: O(n)
Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
deque<int> intDeq;

int main(){
    // For each testcase
    int tcN;
    cin >> tcN;
    int n, element;
    string p;
    for(int tc = 0; tc < tcN; tc++){

        // Formatting input
        cin >> p >> n;
        string inputStr, container;
        cin >> inputStr;
        stringstream ss(inputStr);
        for(int i = 0; i < n; i++){
            while(getline(ss, container, ',')){
                if(container.front() == '[')container.erase(0,1);
                if(container.back() == ']')container.pop_back();
                intDeq.push_back(stoi(container));
            }
        }

        // For each action
        bool errorend = false;
        bool reversed = false;
        for(auto &ch : p){
            if(ch == 'R')reversed = !reversed;
            else if(intDeq.empty()){
                errorend = true;
                break;
            }else if(ch == 'D' && !reversed)intDeq.pop_front();
            else intDeq.pop_back();
        }

        // Displaying final list
        if(errorend){   // display error
            cout << "error" << endl;
        }else if(!reversed){ // display deque from front
            cout << '[';
            int finalN = intDeq.size();
            for(int i = 0; i < finalN; i++){
                cout << intDeq.front();
                intDeq.pop_front();
                if(i != finalN-1)cout << ",";
            }
            cout << "]" << endl;
        }else{  // reversed, display deque from back
            cout << '[';
            int finalN = intDeq.size();
            for(int i = 0; i < finalN; i++){
                cout << intDeq.back();
                intDeq.pop_back();
                if(i != finalN-1)cout << ",";
            }
            cout << "]" << endl;
        }
    }
}
