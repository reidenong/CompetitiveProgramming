'''
kattis-airconditioned

- greedy interval scheduling problem

- Initial attempt tried to greedily pick the temperature 
  which satisfied the highest number of intervals. However,
  one should note that this does not always result in the
  globally optimal solution as the intervals left behind may
  not be close together to be grouped by such a method

- Instead, sort the intervals by its lower bound. then for
  the interval with the higest lower bound, place a room at
  its lower bound as it provides the best chance for other 
  intervals to share the lower bound with it. whenever a room 
  is not fulfilled by this lower bound, set a new room at its 
  lower bound such that the process repeats

Time: O(N log N)
Space: O(N)
'''
# Receiving input
N = int(input())
intervals = []
for i in range (N) :
    interval = [int(x) for x in input().split()]
    intervals.append(interval)

# Sorting
intervals.sort()
intervals.sort(key=lambda x : x[0])

# Greedily selecting minion with highest lower bound
rooms = set()
temperature = 0
while len(intervals) > 0 :
    interval = intervals.pop()

    # Current minion cannot take this temperature
    if interval[1] < temperature or interval[0] > temperature :
        temperature = interval[0]
        rooms.add(temperature)

print (len(rooms))
