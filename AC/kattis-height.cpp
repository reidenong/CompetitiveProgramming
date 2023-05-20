#include <bits/stdc++.h>
using namespace std;
int arr[21];

int main(){
    int P, stepbacks;
    cin >> P;
    
    // For each testcase
    for(int testCase = 0; testCase < P; testCase++){
        stepbacks = 0;
        int K, currHeight;
        cin >> K;

        // Counting steps student by student
        for(int i = 0; i < 20; i++){
            cin >> currHeight;

            // Add first student
            if(i == 0){
                arr[0] = currHeight;
                continue;
            }

            // Add student to back, count number of steps
            // Stepback operations
            int j = i;
            // while currHeight smaller, stepback++
            while(currHeight < arr[j-1]){
                arr[j] = arr[j-1];
                j--;
                stepbacks++;
            }
            arr[j] = currHeight;
        }
        cout << testCase+1 << " " <<stepbacks << endl;
    }
    return 0;
}
