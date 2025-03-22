'''
O(N*C) 0-1 Knapsack

- keep in mind python is really slow and this solution might
  not be appropriate (ie. kattis-knapsack)

Time: O(NC)
Space: O(NC)
'''
import sys
from functools import lru_cache
sys.setrecursionlimit(100000)

# 0-1 Knapsack with LRU cacheing
@lru_cache(maxsize=None)
def DP (idx, remainingCapacity) :
    # Base case
    if idx == N or remainingCapacity == 0 :
        return 0
    
    # No capacity to take
    if weights[idx] > remainingCapacity :
        return DP(idx + 1, remainingCapacity)
    
    # Compare taking and not taking item [idx]
    skip = DP(idx + 1, remainingCapacity)
    take = DP(idx + 1, remainingCapacity - weights[idx]) + values[idx]
    return max(skip, take)

# MAIN
C, N = map(int, input().split())
values = []
weights = []
for i in range (N) :
    value, weight = map(int, input().split())
    values.append(value)
    weights.append(weight)

# O(N*C) Knapsack
DP.cache_clear()
DP(0, C)

# O(N) Backtracking to find items taken from memo
taken = set()
for idx in range (N) :
    if DP(idx, C) != DP(idx + 1, C) :
        taken.add(idx)
        C -= weights[idx]
print (len(taken))
print (' '.join([str(x) for x in taken]))
