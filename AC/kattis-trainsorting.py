'''
kattis-trainsorting

- Initial method was to naively do LIS and LDS and to take the maximum.
  WA as it is possible to add on trains at both ends.

- AC method is to do a linear pass through array. At each arr[i], consider
  arr[i] the first train used, like an anchor point. From there, LIS starting
  from arr[i] are trains in ascending order from arr[i] and LDS ending
  at arr[i] are trains in descending order after arr[i], and thus these
  represent the trains before and after arr[i].

  Therefore max cars is when max(LIS(i) + LDS(i) - 1) as arr[i] is in both
  sets.

- For easy implementation, simply reverse the order of trains coming in such
  that at any given point the latest train coming in is arr[i] and all trains
  before that are in play. It is possible to do LIS and LDS directly given that
  LIS of a given array is LDS of reversed array by symmetry

- To filter the LIS and LDS to only consider trains after/before arr[i], ie. to 
  consider arr[i] as the anchor point, just ignore all trains smaller/bigger than
  arr[i] when finding LIS/LDS

Time: O(N^2 log K)
Space: O(N)
'''
from bisect import bisect_left

# LIS, LDS functions with anchor points
# ======================================
def LIS (arr) :
    anchor = arr[-1]    # define anchor
    seq = []
    for i, elem in enumerate (arr) :
        # Ignore all elements bigger than anchor
        # Effectively LIS that ends at anchor
        if elem > anchor :
            continue
        if seq == [] :
            seq.append(elem)
            continue
        pos = bisect_left(seq, elem)
        if pos == len(seq) :
            seq.append(elem)
        else :
            seq[pos] = elem
    return len(seq)
def LDS (arr) :
    anchor = arr[-1]    # Define anchor point
    seq = []
    for i, elem in enumerate (arr) :
        # Ignore all elements smaller than anchor
        # Effectively LDS ending at anchor
        if elem < anchor :
            continue
        elem *= -1
        if seq == [] :
            seq.append(elem)
            continue
        pos = bisect_left(seq, elem)
        if pos == len(seq) :
            seq.append(elem)
        else :
            seq[pos] = elem
    return len(seq)

# Reverse train order
N = int(input())
trains = []
for i in range (N) :
    train = int(input())
    trains.append(train)

# Calculate longest possible train
longest = 0
available = []
while trains :
    available.append(trains.pop())
    longest = max (longest, LIS(available) + LDS(available) - 1)

print (longest)
