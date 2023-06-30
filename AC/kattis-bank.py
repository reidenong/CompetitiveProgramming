'''
kattis-bank

- greedily picking locally optimum (highest money) option each time does
  not yield the globally optimum solution, consider if $100 expires at t=2
  and $10 expires at t=1, greedy would choose 100 instead of the sequential
  10 and then 100.

- However, this works as long as we go backwards in time, ie. at t=2 we choose
  the greedy highest $100 and then at t=1 we choose the available $10. This
  works as the pool of money is fixed and the options only increase as we
  go backwards in time. Thus the optimal is achieved by picking the highest
  money that is about to expire before going to a previous time to do the same.

- This is easily achieved with a priority queue, which allows us to easily
  update and choose the largest at any given time

- the time at which money expires is probably best stored in a multimap

Time: O(N log N) bottleneck likely at receiving input, given T <= 47
Space: O(N)
'''
import heapq

N, T = map(int, input().split())

# Adding money to expiry, stores which money expires at what time
expiry = {}
for i in range (N) :
    money, time = [int(x) for x in input().split()]
    if not time in expiry :
        expiry[time] = [money]
    else :
        expiry[time].append(money)

# Move backwards in time, starting with time = T
available = []
total = 0
for time in reversed(range(T + 1)) :

    # Introduce available customers
    if time in expiry :
        for money in expiry[time] :
            heapq.heappush(available, -1 * money)  # Ensures largest first
    
    # Choose from latest customer for [time]
    if len(available) != 0 :
        total += -1 * heapq.heappop(available)

print (total)
