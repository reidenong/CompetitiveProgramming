'''
kattis-cudoviste

- just iterate through map, count number of crushed cars no buildings

Time: O(R*C)
Space: O(R*C)
'''
import sys
crushCount = [0 for _ in range (5)]

# Receiving 2d map input
R, C = map(int, input().split())
city = []
for i in range (R) :
    line = [x for x in input()]
    city += [line]

# Iterating map, anchor point top left of the car
for i in range (R-1) :
    for j in range (C-1) :
        cars = 0
        crushed = [city[i][j],
                   city[i+1][j],
                   city[i][j+1],
                   city[i+1][j+1]]
        if not '#' in crushed :
            for elem in crushed :
                if elem == 'X' :
                    cars += 1
            crushCount[cars] += 1

# Displaying output
for num in crushCount :
    print (num)

