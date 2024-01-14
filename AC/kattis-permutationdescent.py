'''
kattis-permutationdescent

 - Not so much of a DP question than a recurrence relation

 - Our base cases are PDC(2,0) = PDC(2,1) = 1

 - For any N, v, PDC(N, v) can be constructed with PDC(N - 1, v) and PDC (N - 1, v - 1).
   This is because adding number N to the permutation of (N-1) will either add 0 to v or at most
   1 to v.

 - For PDC(N - 1, v - 1), we want to increase v by 1. This is done by (1) adding N to the front of the
   sequence, or (2) adding N to every non-descending pair. eg. [1,2] -> [1,3,2]

 - For PDC(N - 1, v), we want to maintain v. THis is done by (1) adding N to the back of the sequence, or 
   (2) adding N to every descending pair. eg. [2,1] -> [2,3,1]

Time: O(Nv), for max N, v
Mem: O(Nv),       ||
'''
# Memoization and computation of recurrence relation
memo = [[-1 for _ in range(101)] for _ in range(101)]
memo[2][0] = 1
memo[2][1] = 1
def PDC(N, v) :
    # Base Cases
    if N == v : return 0
    if v == 0 : return 1

    # Already computed
    if memo[N][v] != -1 :
        return memo[N][v]
    
    # Compute and memoize
    memo[N][v] = (PDC(N - 1, v - 1) * (1 + N - v - 1) + PDC(N - 1, v) * (1 + v)) % 1001113
    return memo[N][v]

# Main
P = int(input())
for tc in range(P) :
    id, N, v = map(int, input().split())
    print(id, PDC(N, v))
