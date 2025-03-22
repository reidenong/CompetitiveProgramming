/*
kattis- deathstar

bitwise simultaneous equations,
can be solved with bitwise OR on all the other terms   

Time: O(n^2)
Space: O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];

int main(){
    int N;
    cin >> N;

    // Receiving input
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    // Solving for each index
    int currMax = 0;
    for(int i = 0; i < N; i++){
        int x = 0;
        for(int j = 0; j < N; j++){
            x = x | arr[i][j];
        }
        arr[i][i] = x;
        currMax = max(currMax, x);
    }

    // Displaying array
    for(int i = 0; i < N; i++){
        cout << arr[i][i] << " ";
    }



}
