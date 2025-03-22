/*
kattis-continuousmedian

- need to use long long
- use pair in pbds for duplicate entries

Time: O(n log n)
Mem: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// PBDS
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>,
    rb_tree_tag, tree_order_statistics_node_update> ost;

int main(){
    int totalTC;
    ll N, x;

    // For each testcase
    scanf("%d", &totalTC);
    for (int tc = 0; tc < totalTC; tc++) {
        ost A; // clear tree?
        scanf("%lld", &N);
        
        // Receiving each number, adding median to total
        long long total = 0;
        for (ll i = 0; i < N; i++) {
            scanf("%lld", &x);
            A.insert(make_pair(x, i));

            // Even number of numbers
            if (i%2 != 0) {
                total += (A.find_by_order(i/2)->first + 
                A.find_by_order((i+1)/2)->first) / 2;
            }
            
            // Odd number of numbers
            else {
                total += A.find_by_order(i/2)->first;
            }
        }
        printf("%lld\n", total);
    }
}
