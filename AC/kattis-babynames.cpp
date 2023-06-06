/*
kattis-babynames

- question which needs dynamic ranking of strings
- a policy based data struct (pbds) is thus the best choice for this
  problem with O(log n) insert and O(log n) rank, given the giant Q <= 
  500k
- also given giant Q cin/cout even with fastio is still too slow, gotta
  use scanf/printf and convert to c++ strings to make the time

Time: O(n log n)
Mem: ?
*/
#include <bits/stdc++.h>
using namespace std;

// PBDS
#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<string, null_type, less<string>, rb_tree_tag,
    tree_order_statistics_node_update> ost;
ost maleTree, femaleTree;

int main(){
    int action, k;
    char name_c[40], startStr_c[40], endStr_c[40];

    // For each action
    while (true) {
        scanf("%d", &action);

        // End
        if (action == 0) break;

        // Insert into tree
        else if (action == 1) {
            scanf("%s %d", name_c, &k);
            string name(name_c);
            if (k == 1) maleTree.insert(name);
            else femaleTree.insert(name);
        }

        // Remove element from tree
        else if (action == 2){
            scanf("%s", name_c);
            string name(name_c);
            maleTree.erase(name);
            femaleTree.erase(name);
        }

        // Query
        else {
            scanf("%s %s %d", startStr_c, endStr_c, &k);
            string startStr(startStr_c);
            string endStr(endStr_c);

            int ans = 0;

            // Male Query
            if (k == 1 || k == 0) {
                ans += maleTree.order_of_key(endStr) - 
                maleTree.order_of_key(startStr);
            }

            // Female Query
            if (k == 2 || k == 0) {
                ans +=  femaleTree.order_of_key(endStr) - 
                femaleTree.order_of_key(startStr);
            }

            printf("%d\n", ans);
        }
    }
}
