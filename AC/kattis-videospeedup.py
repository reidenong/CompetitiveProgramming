'''
kattis-videospeedup

- simple simulation

Time: O(N)
Space: O(1)
'''
import math
N, P, K = map(int, input().split())
events = [0] + [int(x) for x in input().split()] + [K]

# Reverse engineer time for each event occurence
speed = 1
totalTime = 0
for i in range (1, N + 2) :
    eventTime = events[i] - events[i-1]
    speed = 1 + (i-1)*P/100
    totalTime += eventTime*speed

print (totalTime)
