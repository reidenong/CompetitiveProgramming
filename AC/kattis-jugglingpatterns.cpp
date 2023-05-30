/*
kattis-jugglingpatterns

- essentially using a priority queue (min-heap) to log times where ball will
  fall down to a catch, then iterating through the priority queue to clear
  out the catches and to make sure that there r no more than 2 catches ( for
  2 hands)
- worth noting that no ball should be thrown (and thus caught) on a '0' beat
- C++ solution taken from brandontang89, original solution (less elegant) is
  in py3 at CompetitiveProgramming/AC/kattis-jugglingpatterns.py using
  pure simulation

  Time: O(tc 100 n log 9) 
  Space: O(9) as u can only throw the ball maximum 9 steps ahead
*/

#include <bits/stdc++.h>
using namespace std;
priority_queue <int, vector<int>, greater<int> > pq;  // Min-Heap PQ

int main(){
    string pattern;
    while(cin >> pattern){
        // Empty priority queue
        while(!pq.empty())pq.pop();

        // Check for integer number
        int sum = 0;
        for(auto &ch : pattern)sum += ch - '0';
        int patternLength = pattern.size();
        int N = sum / patternLength;
        if(sum % pattern.length() != 0){
            cout << pattern + ": invalid # of balls" << endl;
            continue;
        }

        // Check for 100*N in pattern
        bool valid = true;
        for(int i = 0; i < 100*patternLength; i++){
            int counter = 0;
            if(pattern[i % patternLength] != '0'){
                while(pq.size() > 0 && pq.top() == i){
                    pq.pop();
                    counter++;
                }
                if(counter > 1){    // Pop max twice for left and right
                    valid = false;
                    break;
                }
                pq.push(i + pattern[i % patternLength] - '0');
            } else {
                if(pq.size() > 0 && pq.top()==i){ // not supposed to catch and throw on 0 beat
                    valid = false;
                    break;
                }
            }
        }

        if (valid)cout << pattern + ": valid with " << N << " balls" << endl;
        else cout << pattern + ": invalid pattern" << endl;
    }

    return 0;
}
