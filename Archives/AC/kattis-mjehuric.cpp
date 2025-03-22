#include <bits/stdc++.h>
using namespace std;
int arr[6];

int main(){
    // Receiving input
    for(int i = 0; i < 5; i++)cin >> arr[i];

    // Bubble Sort
    int container;  // Holding integer for swapping
    while(1){
        // Check if sorted
        bool sorted = 1;
        for(int i = 0; i < 4; i++){
            if(arr[i+1] < arr[i])sorted = 0;
        }
        if(sorted)break;

        // Swap operation
        for(int i = 0; i < 4; i++){
            if(arr[i+1] < arr[i]){
                container = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = container;

                // Display Swap
                for(int j = 0; j < 5; j++)cout << arr[j] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
