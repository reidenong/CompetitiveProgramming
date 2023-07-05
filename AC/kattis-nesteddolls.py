'''
kattis-nesteddolls

- Tough question, requires a basic understanding of order theory (see below)
  as well as familiarity with the LIS algo

- see https://www.youtube.com/watch?v=7TpBLqvqeaA&t=500s&ab_channel=VivekGupta

- From there, we establish that the minimal chain cover is equal to the
  length of the antichain. ie. to find minimal number of LISes, we need
  to find the length of LDS, and vice versa. Dilworth's theorem.

- Firstly, we sort width of dolls in descending order. so now we want
  to find the minimum number of LDSes in the heights, as each LDS will
  give us 1 nested doll. From dilworth's theorem, all we have to do now is
  to find the LIS.

- The crux is actually in dealing with duplicates. consider test case
    2
    3
    2 3 4 5 5 5
    3
    3 2 5 4 5 5

    Naive sort-LIS will not work. This is because we for similar widths and
    different heights, the arr in LIS is height agnostic and may nest dolls
    with diff height but same width. The opposite is true as well.

- To deal with similar widths and diff heights, the trick is to do a presort
  of heights such that for all dolls of same heights they cannot form a LDS
  to form a nested doll. ie. sorted in ascending order

- To deal with the different widths and same height problem is slightly different,
  this is achieved by modifying LIS code. we modify it to take the upper_bound 
  instead of the lower bound. This results in duplicates being able to show up
  in the LIS ie. {3, 5, 5, 6, 7}. This is important as now the increased addition
  to the LIS reflects the increase in minimal chain cover in the set.

Time: O(N log K)
Space: O(N)
'''
from bisect import bisect_right

# For each testcase
TCs = int(input())
for testcase in range (TCs) :
    N = int(input())
    arr = [int(x) for x in input().split()]
    dolls = []
    for i in range (N) :
        dolls.append([arr.pop(), arr.pop()])
    
    # Presort to ensure dolls of similar width cannot be nested based on height
    dolls.sort(key=lambda x : x[0])

    # Main sort to sort by descending width
    dolls.sort(key=lambda x : x[1], reverse=True)

    # Extract height here. Each LDS here represents a nested doll
    arr = [x[0] for x in dolls]

    # LIS, returns n(LIS), also the minimal number of LDSes by dilworth's theorem
    def LIS (arr) :
        seq = []
        for i, elem in enumerate (arr) :
            if i == 0 :
                seq.append(elem)
                continue
            pos = bisect_right(seq, elem)   # USE UPPER_BOUND !
            if pos == len(seq) :
                seq.append(elem)
            else :
                seq[pos] = elem
        return len(seq)
    print (LIS(arr))
