/*
kattis-cookieselection

- dynamic ranking problem, use OST Policy based DS
- need to use long long
- large amount of input (600k) implies use of scanf/printf

Time: O(n log n)
Mem: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// PBDS
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>,
    rb_tree_tag, tree_order_statistics_node_update> ost;
    // impt less_equal for duplicates in ost

int main(){
    // Declaring DSes
    char input[10];
    ll diameter, N = 0;
    ost cookies;

    // Receiving input, cookie OR query
    while (scanf("%s", input) > 0) {

        // Add cookie to OST
        if (input[0] != '#') {
            N++;
            diameter = atoll(input);
            cookies.insert(diameter);
        }

        // Query median, remove cookie
        else {
            printf("%lld\n", *cookies.find_by_order(N/2));
            cookies.erase(cookies.find_by_order(N/2));
            N--;
        }
    }
}
