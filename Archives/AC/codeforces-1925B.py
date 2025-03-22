'''
codeforces-B

- If the answer is G, then what we want is G(a_1 + a_2 + ... + a_N) = X where G is a maximum

- We can use the factorization of G to find the answer. We want to find the largest G such that
  it's complement X/G is >= N.

Time: O(sqrt(X))
Mem: O(1)
'''
from math import sqrt

def solve() :
    X, N = map(int, input().split())
 
    ans = 0
    for i in range(1, int(sqrt(X)) + 1) :
        if X % i != 0 :
            continue
 
        if (X / i) >= N :
            ans = max(ans, i)

        if (i >= N) :
            ans = max(ans, X // i)
        
        if (X / i) < N :
            break
 
    print(ans)
 
TC = int(input())
for test in range(TC) :
    solve()
