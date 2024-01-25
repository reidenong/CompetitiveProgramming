'''
codeforces-1917A Least Product

- Straightforward.

- If there is a 0, the product always 0. no moves
- If there are a odd number of -ves, it is already at its minimum product. no moves
- If all are positive, there is no way to make it -ve, so the minimum product is 0. move the first element to 0

Time: O(N)
Mem: O(N)
'''
def solve() :
    N = int(input())
    arr = [int(x) for x in input().split()]
 
    negatives = sum(1 for x in arr if x < 0)
 
    # Product always 0
    if 0 in arr :
        print(0)
        
    # Already negative
    elif negatives % 2 == 1 :
        print(0)
 
    # All positive
    else:
        print(1)
        print(1, 0)

TC = int(input())
for _ in range(TC) :
    solve()
