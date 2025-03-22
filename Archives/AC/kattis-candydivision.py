'''
kattis-candydivision

- complete search probably too slow, we can do complete search from
  0 to root(N), then output all the complements
- stack is used as FILO structure helps to maintain order
- important to tackle perfect square edge case

Time: O(root(N))
Space: O(root(N))
'''

N = int(input())

# Find all divisors smaller than root(N)
stk = []
for i in range(0, int(N**0.5)):
    if (N % (i+1) == 0) :
        print (i, end=' ')
        stk.append(i+1)

# Tackles edge case where perfect square will print twice
squareTest = stk.pop()
if squareTest != N**0.5:
    print( int(N/squareTest) - 1, end=' ')

# Output complements
while(len(stk) != 0):
    print( int(N/stk.pop()) - 1, end=' ')
