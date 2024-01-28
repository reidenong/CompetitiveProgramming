/*
codeforces-1925C

- Finding if a sequence is valid or not is straightforward. as an extension of qn A, for a 
  sequence to be valid it must contain N complete sets of a contiguous subsequence containing K letters, ie.
  (abc)...(abc) for N terms. 

- We maintain a counter for the sequence checker while building our counter argument. This counter argument can
  be built optimally by always picking the last unique letter in the current set we are building. This is because
  we are maximising the difficulty of forming that particular pattern.

- For the last letter of our counter, all we need to do is to add any letter missing from the last complete set
  until our counter is of length N.

Time: O(N)
Mem: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K, M;
    cin >> N >> K >> M;
    string s;
    cin >> s;

    // Check if sequence is valid by iterating through the whole string and
    // forming complete sets of K letters
    set<char> letters;
    int complete_sets = 0;
    string missing = "";
    for (char &c : s) {
        // Last letter to be added to our counter argument
        if (letters.find(c) == letters.end() && letters.size() == K - 1) {
            missing += c;
        }

        // Add letter to current set
        letters.insert(c);

        // Complete set formed, clear set
        if (letters.size() == K) {
            letters.clear();
            complete_sets++;
        }
    }

    // Output result, or counter argument if wrong
    if (complete_sets >= N) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        // Check if missing is complete
        if (missing.size() < N) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (letters.find(c) == letters.end()) {
                    while (missing.size() < N) {
                        missing += c;
                    }
                    break;
                }
            }
        }
        cout << missing << endl;
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }    
}
