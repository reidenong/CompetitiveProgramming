'''
kattis-suspensionbridges

- remember to pick a initial value of high such that upperbound of BSTA 
  is high enough for all values of D, S
- i did trial and error with hi = 1e5 * D and it passed, although im 
  sure lower values is fine. Large range in BSTA is likely not a issue
  for TLE given BSTA's logarithmic time
- remember to pick a sufficient number of iterations for BSTA such that
  sufficient precision is achieved.

Time: O(1)
Space: O(1) 

'''
from math import exp

# Helper math functions
def sinh (x) :
    return (exp(x) - exp(-1*x))/2

def cosh (x) :
    return (exp(x) + exp(-1*x))/2

# Receive input
D, S = map(int, input().split())

# BSTA
lo = 0
hi = 10000*D
for i in range (100) :
    mid = (lo + hi)/2

    if S  == mid*(cosh(D/(2*mid)) - 1) :
        break

    if S < mid*(cosh(D/(2*mid)) - 1) :
        lo = mid

    else :
        hi = mid

print (2 * mid * sinh(D/(2*mid)))

