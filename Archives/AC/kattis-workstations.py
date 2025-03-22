'''
kattis-workstations

- similar to the interval scheduling problem
- Firstly, sort workers by time by means of a priority queue, then try 
  to clear workers sequentially
- As each worker finishes his shift, he then opens up workstation for 
  another worker
- As we are trying to match workstation availability to worker, we can 
  use a Priority queue for workstation too so that the earliest available
  workstation is clear to use for the worker
- Remember to remove workstations that expire before the worker can use,
  if workstation has expired for worker i then since worker i comes before
  worker i+1 it has expired for all other workers left

Time: O(N log N) with log N priority queue
Space: O(N)
'''
import heapq

# Data Structures
workers = []            # [time arrived, time stayed]
stations = []           # [time opened, time closed]

# Receiving input
N, M = map(int, input().split())
for i in range (N) :
    worker = [int(x) for x in input().split()]
    heapq.heappush(workers, worker)

# Simulate each worker
saved = 0
while len(workers) > 0 :

    # Consider earliest worker
    worker = heapq.heappop(workers)
    come = worker[0]
    leave = worker[0] + worker[1]

    # Clear useless stations
    while len(stations) > 0 :
        if stations[0][1] < come :
            heapq.heappop(stations)
        else :
            break

    # See if can use open station, saves opening up one station
    if (len(stations) > 0 and 
        (stations[0][0] <= come and
        stations[0][1] >= come)) :
        saved += 1
        heapq.heappop(stations)
        
    # Add station to available stations
    heapq.heappush(stations, [leave, leave + M])

print (saved)




