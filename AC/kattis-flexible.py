'''
kattis-flexible

- permutating partitions and then checking alll widths is too slow due
  to n! possible permutations, too slow for N <= 100
- getting the smallest widths (building blocks) for the room and then
  getting N^2 comparisons by merging adjacent partitions

Time: O(N^2)
Space: O(N)
'''
import itertools
from copy import deepcopy
W, P = map(int, input().split())
partitions = [int(x) for x in input().split()]

# Finding all smallest widths
partitions2 = [0] + deepcopy(partitions) + [W]
smallW = []
while len(partitions2) > 1 :
    smallW += [partitions2.pop() - partitions2[-1]]

# Finding all possible widths by merging adjacent widths
widths = set()
for i in range(len(smallW)) :
    length = 0
    for j in range (i, len(smallW)) :
        length += smallW[j]
        widths.add(length)

# Sort and display widths
widths = sorted(list(widths))
print (' '.join([str(x) for x in widths]))
