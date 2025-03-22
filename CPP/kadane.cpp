/*
O(N) Kadane's Algorithm

- 1D range maxsum

Time: O(N)
Space: O(N)
*/
#include <bits/stdc++.h>
using namespace std;
int arr[100001];

long long kadane (int N, int arr[]) {
    long long currSum = 0, maxSum = 0;
    for (int i = 0; i < N; i++) {
        currSum += arr[i];

        if (currSum < 0) currSum = 0;
        else maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main () {
    int N, P;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << kadane(N, arr) << endl;
}
