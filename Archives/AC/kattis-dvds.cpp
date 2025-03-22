/*
kattis-dvds

- Observe that DVDs must be in order 1,2,3..., N. Any disruption to this 
  order, such as 1, 2, 5, 3, 4 means that an action must be taken to
  remove the 5. But as the 5 is placed on top, it means that the smallest
  disruption to the order must be done first.

- As such, we just maintain an imaginary order 1,2,3.. and count the 
  disruptions that occur. Each disruption to the order counts as 1 action
  whereas any elements following the order will fall into place as the
  disruptions are removed.

Time: O(N)
Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    // For each testcase
    int TCs, N, dvd, moves, order;
    cin >> TCs;
    for (int testcase = 0; testcase < TCs; testcase++) {
        cin >>  N;
        moves = 0;
        order = 1; 

        // Iterating through given DVD order
        for(int i = 0; i < N; i++) {
            scanf("%d", &dvd);      // scanf to deal with heavy IO
            
            // DVD [i] following order, move up to next in order
            if (dvd == order) order++;

            // DVD [i] not following order, must be moved (sooner or later)
            else moves += 1;
        }

        // Display answer
        printf("%d\n", moves);
    }
}
