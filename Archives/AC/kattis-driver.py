'''
kattis-driver

 - The trick of driver is to observe that the only goal is to drive through
   the last gate with minimum cost. 

 - We also observe that we must move constantly, incurring costs.

 - So the optimal strategy is always to camp and move between the lowest cost gates when they are 
   earliest available, as by definition literally any other movement would be more costly. If there are 
   no new lower cost gates, we just wait there for the gates to open

 - Note that there is no extra penalty incurred in moving forward to a new lower cost gate, as 
   we would have to move there eventually.

Implementation details:
 - Note that we will have to travel all of the tolls eventually, and the difference is when we
   have to go back and forth at a certain toll. Thus it helps with reasoning purposes if we just sum 
   the cost of all the gates in the first place, and then add on the extra back-forth during simulation

 - Additionally, it is quite difficult to manage gate position relative to road position. While one way is to 
   use a forward counter to determine the position at the start or the end of the road, a better and more 
   streamlined method is to simply take note only of one's position at the end of the gate. When we record
   a back and forth, we simply increment 2 to the time as well as 2* of the cost, as we would not be able to 
   move forward if we were at the end of the road anyways.

Time: O(opening_time_of_last_gate)
Mem: O(N)
'''
N = int(input())
toll = [int(x) for x in input().split()]
opening = [int(x) for x in input().split()]
last_gate = opening[-1]

# Greedy time simulation
time = 1
gate_pos = 1
latest_open = 0
cost = sum(toll)
minimum_toll = 1000001
while True :

    # Open gates
    while time + (latest_open + 1 - gate_pos) >= opening[latest_open + 1] :
        latest_open += 1
        if latest_open == N - 1 :
            break
        minimum_toll = min(toll[latest_open], minimum_toll) # Update minimum toll
    if latest_open == N - 1 :
        break

    # Not at minimum toll
    if toll[gate_pos - 1] > minimum_toll :
        time += 1
        gate_pos += 1
        
    # At minimum waiting for next gate, back and forth
    else :
        time += 2
        cost += 2 * toll[gate_pos - 1]

print(cost)
