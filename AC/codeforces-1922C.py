'''
CF-1922C Closest Cities

- Initial idea was to use DP to store the cost of moving from pos[a] to pos[b]

- However, observe that whenever we move in a given direction, since all the cities are in a line,
  the only time that we cut costs is when we greedily use a cost 1 movement. Any other time, we are
  better off moving to the nearest city in the direction (it does not save cost to jump as the positions are
  in a straight line)

- Implementation is also not straightforward, we cannot keep querying the cost of moving from pos[a] to pos[b]
  given relatively large input sizes N, M ~1e5 we will get TLE with O(NM).

- We can create a cumulative cost map for forwards and backwards, and then query the cost of moving from pos[a] to pos[b]
  by taking the difference of the cumulative cost map at pos[a] and pos[b].

- Note that we need different forwards and backwards maps as for the 1st and last city the closest city to x may not be 
  closest[closest[x]] (i.e. the closest city to the closest city to x may not be x)

Time: O(N)
Space: O(N)
'''
TC = int(input())
for tc in range(TC) :
    N = int(input())
    pos = [int(x) for x in input().split()]

    # Make map of closest cities
    closest_city = []
    for i in range(N) :
        if i == 0 :
            closest_city.append(1)
        elif i == N - 1 :
            closest_city.append(N - 2)
        else :
            if abs(pos[i] - pos[i - 1]) < abs(pos[i] - pos[i + 1]) :
                closest_city.append(i - 1)
            else :
                closest_city.append(i + 1)

    # Cost map from 0 to i (forwards)
    forward_map = [0]
    cost = 0
    for i in range(1, N) :
        if closest_city[i - 1] == i :
            cost += 1
        else :
            cost += abs(pos[i - 1] - pos[i])
        forward_map.append(cost)

    # Cost map from N - 1 to i (backwards)
    backward_map = [0]
    cost = 0
    for i in range(N - 2, -1, -1) :
        if closest_city[i + 1] == i :
            cost += 1
        else :
            cost += abs(pos[i + 1] - pos[i])
        backward_map.append(cost)
    backward_map.reverse()
    
    # For each query
    M = int(input())
    for query in range(M) :
        x, y = map(int, input().split())
        x -= 1
        y -= 1

        if x < y :
            print(forward_map[y] - forward_map[x])
        else :
            print(backward_map[y] - backward_map[x])
