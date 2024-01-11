'''
kattis-applesack

 - most efficient method of moving is to move stepwise. ie. from gate x to gate x+1, bringing 
   as many apples as you can

 - The cost of moving all the apples is always constant at 1 apple per gate, but this is more efficient
   when the bag is full, we can bring over maximum possible apples in ceil(N/K) trips, so for every gate we 
   incur ceil(N/K) cost.

 - when we run out of apples then its over. +1 for 1-based indexing.

Time: O(N/K)
Mem: O(1)
'''
from math import ceil
N, K = map(int, input().split())        # apples, sack

dist = 0
while N > 0 :
    N -= ceil(N/K)
    dist += 1
print(dist + 1)
