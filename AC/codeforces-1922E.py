'''
CF-1922E Increasing Subsequences

- Not as hard as it looks

- Key observation: Given any sequence with k increasing subsequences,
    (1) If we add a new smallest element to the sequence, total number of increasing subsequences increases to k+1
        We only increase the number by 1 where the new element is a subsequence by itself

    (2) If we add a new largest element to the sequence, total number of increasing subsequences increases to 2k.
        Every existing subsequence is still a subsequence, and adds to a new subsequence too with the new element added to the back

- So, reverse engineering the given X, we can determine whether we are adding a new smallest or largest element to the sequence

Time: O(log X)
Mem: O(1)
'''
def solve() :
    X = int(input())

    # Reverse engineer X, determine whether we are adding a new smallest or largest element to the sequence
    stk = []
    N = 0
    while X > 1 :
        if X % 2 == 1 :
            stk.append(0)
            X -= 1
        else :
            stk.append(1)
            X //= 2
        N += 1

    # Display sequence
    print(N)
    small, big = -1, 1
    while stk :
        if stk.pop() == 0 :
            print(small, end=' ')
            small -= 1
        else :
            print(big, end=' ')
            big += 1
    
TC = int(input())
for tc in range(TC) :
    solve()
    print()
