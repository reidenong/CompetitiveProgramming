'''
kattis-increasingsubsequence

- personally i find O(N log K) Greedy/D&C LIS much more intuitive than the O(N^2) DP
  alternative

- concept is to do a linear pass through the array, where every next element is either
  bigger and increases the LIS, or is able to replace some element in the seq such that
  it sets up the opportunity to build a longer LIS down the road

- This is much faster given that it uses O(log N) Binary search (bisect)

- In reconstructing the LIS, given that the last element in seq is guaranteed to be
  the smallest possible LIS terminal, by backtracking its predecessors with the 
  predecessor map we can easily reconstruct the lexographically smallest LIS

Time: O(N log K) with binary search
Space: O(N)
'''
from bisect import bisect_left

while (True) :
    # Receiving input
    arr = [int(x) for x in input().split()]
    N = arr[0]
    arr = arr[1:]

    # Exit criterion
    if N == 0 :
        break

    # O(N log k) Greedy + Divide & Conquer LIS
    # ==========================================
    seq = [-1]            # -1 to prevent valueErrors when settling predecessors 
    predecessor = {}      # Map of each element to their predecessor
    for i, elem in enumerate (arr) :

        # Start of sequence
        if i == 0 :
            seq.append(elem)
            predecessor[elem] = seq[0]
            continue

        # Try to find insertion point
        pos = bisect_left(seq, elem)
        if pos == len(seq) :
            seq.append(elem)
            predecessor[elem] = seq[-2]
        else :
            seq[pos] = elem
            predecessor[elem] = seq[pos-1]
    
    # Reconstruction of smallest LIS
    LIS = []
    largest = seq[-1]
    def backtrack (X) :
        LIS.append(X)
        prev = predecessor[X]
        if prev != -1 :
            backtrack(prev)
    backtrack(largest)

    # Printing Output
    length = len(seq) - 1
    print(length, ' '.join([str(x) for x in reversed(LIS)]))
