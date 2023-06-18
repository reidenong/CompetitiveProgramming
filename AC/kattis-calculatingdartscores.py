'''
kattis-calculatingdartscores

- easy solution is to iterate through all permutations, which is at most
  60^3

Time: O(1)
Space: O(1)
'''
def num2word (x) :
    if x == 1 :
        print("single", end=" ")
    elif x == 2 :
        print("double", end=" ")
    else :
        print("triple", end=" ")

import sys
N = int(input())

if N > 180 :
    print ("impossible")
    sys.exit()

# Using formula a*x + b*y + c*z
for a in range (1,4) :
    for b in range (1, 4) :
        for c in range (1, 4) :
            for x in range (21) :
                for y in range (21) :
                    for z in range (21) :
                        if (a*x) + (b*y) + (c*z) == N :
                            if x != 0 :
                                num2word(a)
                                print (x)
                            if y != 0 :
                                num2word (b)
                                print (y)
                            if z != 0 :
                                num2word (c)
                                print (z)
                            sys.exit()

print ("impossible")

