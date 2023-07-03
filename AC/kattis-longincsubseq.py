'''
kattis-increasingsubsequence

- see https://github.com/reidenong/CompetitiveProgramming/blob/main/AC/kattis-increasingsubsequence.py

Time: O(N log K) with binary search
Space: O(N)
'''
from bisect import bisect_left
import sys

while (True) :
    # Receiving input
    try :
        N = int(input())
        arr = [int(x) for x in input().split()]
    except EOFError:
        sys.exit()
    
    # O(N log k) Greedy + Divide & Conquer LIS
    # ==========================================
    neg = -1*(2 ** 32)
    seq = [neg]            # -1 to prevent valueErrors when settling predecessors 
    predecessor = {}                 # Map of each element to their predecessor
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

    # Reconstruction of LIS
    LIS = []
    largest = seq[-1]
    prev = predecessor[largest]
    LIS.append(largest)
    while prev != neg :
        LIS.append(prev)
        prev = predecessor[prev]

    # Retrieving index from LIS
    num = LIS.pop()
    print (len(seq) - 1)
    indexes = []
    for i, elem in enumerate (arr) :
        if elem == num :
            indexes.append(i)
            if len(LIS) != 0 :
                num = LIS.pop()
            else :
                break

    print (' '.join([str(x) for x in indexes]))

