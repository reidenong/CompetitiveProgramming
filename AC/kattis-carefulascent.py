'''
kattis-carefulascent

- set of answers is very big, with -1e7 < x < 1e7 and answers required to
  a precision of 1e-6, overall answer space is 2e13.
- However, with Binary Search logarithmic complexity, we can thus calculate
  log2(2e13) ~= 44.2 
- This means with minimum 45 iterations, BSTA will yield a answer at greater
  precision than 1e-6, although we use 50 iterations because 50 is a nice
  number

Time: O(N * 50) = O(N)
Space: O(N)
'''
# Receiving input
X, Y = map(int, input().split())
N = int(input())
shields = []    # lower boundary, upper boundary, horizontal factor
for i in range (N) :
    shield = [float(x) for x in input().split()]
    shields.append(shield)
shields.sort()

# Identifying periods in movements
# No shields
if N == 0 :
    movement = [[Y, 1]]

# Using each shield to generate periods of movement
else :
    movement = []
    for i, shield in enumerate(shields) :

        # Adding takeoff to first shield AND first shield
        if movement == [] :
            movement.append([shield[0], 1])
            movement.append([shield[1]-shield[0], shield[2]])
        
        else :
            # No gap between shields
            if shields[i][0] == shields[i-1][1] :
                movement.append([shield[1]-shield[0], shield[2]])
            
            # Gap between shields
            else :
                movement.append([shield[0] - shields[i-1][1], 1])
                movement.append([shield[1]-shield[0], shield[2]])
    if movement[0][0] == 0 :
        movement = movement[1:]
    if Y != shields[-1][1] :
        movement.append([Y - shields[-1][1], 1])

# Function to give endpoint for given value of speed thru movement periods
def endpoint (speed) :
    pos = 0
    for period in movement :
        pos += period[0] * period[1] * speed
    return pos

# Using BSTA to figure out if we hit the correct X distance
lo, hi = -100000, 100000
for i in range (50) :
    mid = (lo + hi)/2
    endPos = endpoint(mid)

    # Binary Search adjustments
    if endPos == X :
        break
    elif endPos < X :
        lo = mid
    else :
        hi = mid

# Display Answer
print (mid)

