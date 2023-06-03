'''
kattis-administrativeproblems

- tedious python simulation type problem
- event time is useless here, easier to understand when you look at 
  the individual action log per spy than to process all one 
  by one. 
- not hard 

Time: O(N)
Space: O(N)

'''
import math

# For each Testcase
TC = int(input())
for testcase in range(TC) :
    # Data Structures
    cars = {}   # [catalogPrice, pickupCost, costPerKm]
    spies = {}  # List of activities to happen to said spy

    # Receiving input
    N, M = map(int, input().split())
    for i in range (N) :
        name, P, Q, K = input().split()
        cars[name] =  [int(P), int(Q), int(K)]
    for i in range (M) :
        time, person, action, x = input().split()
        if not person in spies :
            spies[person] = []
        spies[person] += [[time, action, x]]

    # Sorting Spy names
    spyNames = list(spies.keys())
    spyNames.sort()
    spies = {i : spies[i] for i in spyNames}

    # Solving each spy's cost
    for spy in spies :
        #print ()
        #print (spy)
        #for line in spies[spy] :
            #print (line)

        overall_cost = 0
        currCar = False
        inconsistent = False
        for log in spies[spy]:
            # Pick up
            if log[1] == 'p' :  
                if currCar != False :
                    inconsistent = True
                else :
                    currCar = log[2]
                    overall_cost += cars[log[2]][1]

            # Return
            if log[1] == 'r' :
                if currCar == False :
                    inconsistent = True
                else :
                    overall_cost += cars[currCar][2] * int(log[2])
                    currCar = False

            # Accident
            if log[1] == 'a' :
                if currCar == False :
                    inconsistent = True
                else:
                    overall_cost += math.ceil(cars[currCar][0] * int(log[2]) / 100 )

            if inconsistent :
                break
        
        if not inconsistent and currCar == False :
            print (spy, overall_cost)
        else:
            print(spy, 'INCONSISTENT')

