#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int arr2[1001];
int N;


void Oshuffle(){
    copy(arr, arr+N, arr2);

    if(N%2 == 0){
        // For N is Even
        for(int i = 0; i < N/2; i++){
            // cout << arr[i] <<" " << arr[N/2] + i << " ";
            arr2[2*i] = arr[i];
            arr2[2*i + 1] = arr[N/2 + i]; 
        }
    }else{
        // For N is ODD
        for(int i = 0; i < N/2; i++){
            // cout << arr[i] <<" " << arr[N/2] + i << " ";
            arr2[2*i] = arr[i];
            arr2[2*i + 1] = arr[N/2 + 1 + i];
            arr2[N-1] = arr[int(N/2)]; 
        }
    }

    // To show array
    /*
    for(int i = 0; i < N; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    */

    copy(arr2, arr2+N, arr);
}

void Ishuffle(){
    copy(arr, arr+N, arr2);

    if(N%2 == 0){
        // For N is Even
        for(int i = 0; i < N/2; i++){
            // cout << arr[i] <<" " << arr[N/2] + i << " ";
            arr2[2*i + 1] = arr[i];
            arr2[2*i] = arr[N/2 + i]; 
        }
    }else{
        // For N is ODD
        for(int i = 0; i < N/2; i++){
            // cout << arr[i] <<" " << arr[N/2] + i << " ";
            arr2[2*i + 1] = arr[i];
            arr2[2*i] = arr[N/2 + i];
            arr2[N-1] = arr[N-1]; 
        }
    }

    // To show array
    /*
    for(int i = 0; i < N; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    */
   
    copy(arr2, arr2+N, arr);
}

bool shuffled(int deck[], int N){
    for(int i = 0; i < N-1; i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;
}

int main(){
    int shuffles = 0; string command;
    cin >> N >> command;

    // Initializing deck of cards
    for(int i = 0; i < N; i++){
        arr[i] = i;
    }

    do{
        if(command == "out"){
            Oshuffle();
            shuffles++;
        }else{
            Ishuffle();
            shuffles++;
        }
    }while(!shuffled(arr, N));

    cout << shuffles;
    return 0;
}