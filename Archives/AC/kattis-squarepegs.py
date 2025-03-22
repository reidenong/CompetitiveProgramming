'''
kattis-squarepegs

- since one house only one plot, we can greedily choose the biggest available
  house that fits into the biggest available plot
- converting square to circle, just use pythagoras to get the diagonal of the
  square as the diameter of the circle
- read question carefully -> house cannot touch the circle of the plot

Time: O(N)
Space: O(N)
'''
import math

# Receiving input
N, M, K = map(int, input().split())

# Transforming all to diameter based reference
plots = [(2 * int(x)) for x in input().split()]
diameters = [(2 * int(x)) for x in input().split()]
root2 = math.sqrt(2)
lengths = [(root2 * int(x)) for x in input().split()]
diameters += lengths

# Sorting
diameters.sort()
plots.sort()

# Greedily choose biggest house for biggest plot
usedPlots = 0
while len(plots) > 0 and len(diameters) > 0 :
    # Diameter too big for any plot, throw away
    if diameters[-1] >= plots[-1] :
        diameters.pop()
    
    # Diameter suitable for plot, use
    else :
        diameters.pop()
        plots.pop()
        usedPlots += 1

print (usedPlots)

