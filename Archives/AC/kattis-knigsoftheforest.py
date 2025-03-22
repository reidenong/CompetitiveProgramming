'''
kattis-stockprices

- use heapq PQ to constantly update pool and retrieve strongest moose
- min-heap with negative numbers == max-heap

Time: O(n log n) 
Space: O(n)
'''
import sys
import heapq

K, N = map(int, input().split())
yearStrength = [0]*(N-1)
currPool = []

# Receiving karl input
karlYear, karlStrength = map(int, input().split())
if karlYear == 2011:
    currPool += [-1*karlStrength]
else:
    yearStrength[karlYear - 2012] = karlStrength

# Receivng input for remaining Moose
for _ in range(N+K-2):
    year, strength = map(int, input().split())
    if year == 2011:
        heapq.heappush(currPool, -1*strength)
    else:
        yearStrength[year-2012] = strength

# Determine winner for year 2011
winner = heapq.heappop(currPool)
if winner == -1*karlStrength:
    print("2011")
    sys.exit()

# Determining winner for rest of the years
for i in range(N-1):
    heapq.heappush(currPool, yearStrength[i]*-1)
    winner = heapq.heappop(currPool)
    if winner == -1*karlStrength:
        print(2012+i)
        sys.exit()

# End of all known years info
print("unknown")


        
