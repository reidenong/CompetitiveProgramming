'''
kattis-monk

- careful with rest times, even if they are at the same position at time
  X still binary search lower half for a earlier timing just in case they
  are both resting at time X => they reached that elevation earlier
- in calculating number of iterations for BSTA, with time=1000 and the
  desired precision being 1e-5, log2(1e8) ~= 27 so 30 iterations is more
  than sufficient

Time: O(A+D)
Space: O(A+D)
'''
# Function to query elevation for a given timing
def elevation (hours, boolAscent) :
    dist = 0
    # Ascending elev
    if boolAscent :
        global ascent
        for period in ascent :
            # End of time
            if hours == 0 :
                break
            
            # Monk finishes whole period
            if hours >= period[1] :
                dist += period[0]
                hours -= period[1]
            else :
                dist += period[0] * (hours/period[1])
                break
        return dist

    # Descending elev (same as Ascending)
    else :
        global descent
        for period in descent :
            if hours == 0 :
                break
            if hours >= period[1] :
                dist += period[0]
                hours -= period[1]
            else :
                dist += period[0] * (hours/period[1])
                break
        global totalDistance
        return totalDistance - dist

# Receiving input
A, D = map(int, input().split())
ascent, descent = [], []
ascentTime, descentTime, totalDistance = 0, 0, 0
for i in range (A) :
    H, T = map(int, input().split())
    ascent.append([H,T])
    ascentTime += T
    totalDistance += H
for i in range (D) :
    H, T = map(int, input().split())
    descent.append([H,T])
    descentTime += T


# BSTA for time
lo = 0
hi = max(ascentTime, descentTime)
for i in range (30) :
    mid = (lo + hi)/2

    ascentDist = elevation(mid, True)
    descentDist = elevation(mid, False)

    # Too early
    # Strict inequality so that even reaching the same distance the 
    # binary search will look for earlier timings such that resting is 
    # not of concern
    if ascentDist < descentDist :  
        lo = mid

    # Too late / at the same time
    else :
        hi = mid
    
print (mid)
    



