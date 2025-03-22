'''
kattis-squaredeal

- very niche question with hard cases, not much room for generalisation
- the square is only formed 2 ways, putting 3 shapes linearly or 2 adj
  with one perpendicular
- just code for those hard cases and itll be fine

'''
import sys
from copy import deepcopy

# Receiving rectangles
shapes = []
for i in range (3) :
    W, H = map(int, input().split())
    shapes += [[W, H]]

# Check for Linear placement(must have 1 common length)
if shapes[0][0] in shapes[1] and shapes[0][0] in shapes[2] :
    length = shapes[0][1]
    shape1 = deepcopy(shapes[1])
    shape1.remove(shapes[0][0])
    length += shape1[0]
    shape2 = deepcopy(shapes[2])
    shape2.remove(shapes[0][0])
    length += shape2[0]
    if length == shapes[0][0] :
        print ("YES")
        sys.exit()
if shapes[0][1] in shapes[1] and shapes[0][0] in shapes[2] :
    length = shapes[0][0]
    shape1 = deepcopy(shapes[1])
    shape1.remove(shapes[0][1])
    length += shape1[0]
    shape2 = deepcopy(shapes[2])
    shape2.remove(shapes[0][1])
    length += shape2[0]
    if length == shapes[0][1] :
        print ("YES")
        sys.exit()

# Check for adjacent placement
# Cases: 0-1, 0-2, 1-2 
# Assume square x, y are adjacent, z is perpendicular
def adjacentR (x, y, z) :
    # Finding the common length between x and y (adj)
    if shapes[x][0] in shapes[y] :
        adj = shapes[x][0]
        y = deepcopy(shapes[y])
        y.remove(adj)
        length = y[0] + shapes[x][1]  
    elif shapes[x][1] in shapes[y] :
        adj = shapes[x][1]
        y = deepcopy(shapes[y])
        y.remove(adj)
        length = y[0] + shapes[x][0]
    else :
        return
    
    z = deepcopy(shapes[z])
    if length in z :
        z.remove(length)
        if length == adj + z[0] :
            print ("YES")
            sys.exit()

adjacentR(0,1,2)
adjacentR(0,2,1)
adjacentR(1,2,0)

# Failed linear and adj checks, no square
print ("NO")
    
