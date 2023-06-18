'''
kattis-golombrulers

- easy question. just use set and check for existing enttries in 
  measurements as there is only 1 way to have a given measurement

Time: O(N^2)
Space: O(N^2)
'''
import sys

while (1) :
    try :
        ruler = [int(x) for x in input().split()]
    except EOFError :
        sys.exit()

    # Defining variables
    measurements = set([])
    isARuler = True
    N = max(ruler)

    # Getting each possible measurement with N^2 differences
    while (len(ruler) > 0) :
        mark1 = ruler.pop()
        for mark2 in ruler :
            if not abs(mark2 - mark1) in measurements :
                measurements.add(abs(mark2 - mark1))
            else :
                isARuler = False
                break
        
        if not isARuler :
            break

    # Displaying output
    if not isARuler :
        print ("not a ruler", end="")
    else :
        perfect = set(range(1,N+1)) 
        if measurements == perfect :
            print ("perfect", end="")
        else :
            print ("missing ", end="")
            for mark in perfect :
                if not mark in measurements :
                    print (mark, end=" ")
    print ()
