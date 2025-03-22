'''
codeforces-1923A Moving Chips

- Observe that the cost of moving a contiguous sequence of chips by 1 is 1, as the last chip will 
  always jump to the first available spot.

- Cost of moving all chips to the nearest left position is the number of 0s between the first and last chip.

Time: O(N)
Space: O(N)
'''
def solve() :
    N = int(input())
    arr = [int(x) for x in input().split()]
    arr.reverse()           # reverse the array so we are moving right.

    # Find first element that is not 0
    start, end = -1, -1
    for i in range(N) :
        if arr[i] != 0 and start == -1 :
            start = i

        if arr[i] != 0 :
            end = i

    # Sum all numbers between start and end
    sum = 0
    for i in range(start, end+1) :
        sum += 1 - arr[i]
    
    print(sum)

TC = int(input())
for _ in range(TC) :
    solve()
