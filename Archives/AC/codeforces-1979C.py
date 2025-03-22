'''
codeforces-1979C Earning on Bets

- for each i, we have the condition k_i * x_i > total_cost.

    => x_i > total_cost / k_i

- SUM_(0 -> N) (total_cost / k_i) < total_cost

    => SUM_(0 -> N) (1 / k_i) < 1  

- we can get a answer with the highest precision by dealing with everything in integers.
  first we find the denominator of the LCM of all k_i, then we find the total_cost by adding the LCM / k_i for all i.

- if the total_cost is greater than the denominator, it is impossible to find a solution.

Time: O(N)
Space: O(N)
'''
import math

def solve() :
    N = int(input())
    arr = [int(x) for x in input().split()]

    # Find the LCM of all elements in the array, use as a denominator
    denom = 1
    for elem in arr :
        denom = math.lcm(denom, elem)

    # Find total cost spent
    total_cost = 0
    for elem in arr :
        total_cost += denom//elem
    
    # If total cost is greater than denom, impossible
    if total_cost >= denom :
        print(-1)
        return
    
    # Print the answer
    for elem in arr :
        print(denom//elem, end=' ')
    print()

tc = int(input())
for t in range(tc) :
    solve()
