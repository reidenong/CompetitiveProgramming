/*
kattis-closestsums

- given small amount of numbers N, we can just do N^2 summing of all 
  numbers and then check for the nearest number
- use of STL set helps to elimintae dupliocates,
  auto sort the sums, as well as to use upper bound and lower bound 
  so we dont have to search for nearest number

Time: O(N^2)
Space: O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;
int numbers[1001];
set<int> S;
set<int>::iterator higher, lower;

int main() {
    int N, Q, givenNum, caseNumber = 1;
    while (cin >> N) {
        // Receiving numbers
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        // Summing all numbers into S
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    S.insert(numbers[i] + numbers[j]);
                }
            }
        }
        
        // For each query case
        cout << "Case " << caseNumber << ":" << endl;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> givenNum;
            higher = S.lower_bound(givenNum);
            lower = --S.lower_bound(givenNum);

            // Use Higher if its closer to given number or if lower does
            // not exist
            if (*higher == givenNum ||
                lower == S.end() ||
                abs(*higher - givenNum) < abs(*lower - givenNum)) {
                cout << "Closest sum to " << givenNum << " is " << *higher << "." << endl;
            } else {
                cout << "Closest sum to " << givenNum << " is " << *lower << "." << endl;
            }
        }
        S.clear();
        caseNumber++;
    }
}
