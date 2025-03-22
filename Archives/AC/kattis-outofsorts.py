'''
kattis-outofsorts

- careful with lo, mid, hi manipulation to make sure you are getting the
  correct ranges every iteration
- straightforward implementation of binary search

Time: O(Q log N) where Q is number of queries
Space: O(N)
'''
# Receiving input
N, M, A, C, X0 = map(int, input().split())

# Generating sequence
seq = [X0]
for i in range (N) :
    seq.append((A * seq[-1] + C) % M)
seq = seq[1:]

# Binary Search
def binarySearch (X, arr) :
    N = len(arr)
    lo, hi = 0, N - 1

    while (lo <= hi) :
        mid = (lo + hi) // 2
        
        # Found X
        if arr[mid] == X :
            return True
        
        # X in upper half
        elif arr[mid] < X :
            lo = mid + 1
        
        # X in lower half
        else :
            hi = mid - 1
    
    return False

# Binary Search on unsorted seq
ans = 0
for elem in seq :
    if binarySearch(elem, seq) :
        ans += 1

print (ans)
