'''
codeforces-1978C

- We can think of starting off with the array [1,2,...,N] and then swapping elements
  to get the final array.

- Whenever we swap two elements, the change in manhattan distance is always a multiple
  of 2. This is a useful thing -> for every odd k we can immediately return no

- Now when we are figuring out what to swap, we can make two observations:

    1. the maximum manhattan distance can be generated when we swap the two elements 
       furtherst apart
    
    2. to generate a manhattan distance of 2*j, we need to swap two elements that are
       j apart

- With observations one and two, we keep trying to swap the furthest two elements apart
  to reduce K, then when K is small enough we can swap two elements that are K//2 apart.
  if K is not zero at the end or we run out of elements to swap, we return no.

Time: O(N)
Mem: O(N)
'''
def swap(arr, a, b) :
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp

def solve() :
    N, K = map(int, input().split())
    arr = [i for i in range(1, N + 1)]

    if K % 2 != 0 :
        print("No")
        return
    
    # Begin swapping furthest two elements
    start = 0                   # First swappable element
    end = N - 1                 # Last swappable element
    while K > 0 :
        # K small enough that we can swap some elements and finish now
        if K // 2 <= end - start :
            swap(arr, start, start + K // 2)
            K = 0
            break

        # K too large, we can only reduce K
        swap(arr, start, end)
        K -= (end - start) * 2
        start += 1
        end -= 1

        # Ran out of elements to swap
        if (start >= end) :
            break
    
    # Print answer
    if K == 0 :
        print("Yes")
        print(" ".join(map(str, arr)))
    else :
        print("No")

TC = int(input())
for _ in range(TC) :
    solve()
