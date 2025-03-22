'''
kattis-bungeebuilder

key observations
- N limit at 10^6, probably too slow to use O(n^2) or worse for 
  comparing every 2 given mountains. AC code needs to be > O(n^2)

use a stack to keep track of all mountains inbetween 2 big ones
1 - at the start, add a base mountain (leftmost)

2 - if a mountain is shorter, add it to the stack

3 - if a mountain is taller than the base mountain
--> iterate through stack, recording the jump height for each mountain 
    as it passes through the stack as all mountains inbetween are
    guaranteed to have maximum jump depth inbetween the base mountain
    and the new tallest mountain
--> when the stack is empty, add the new tallest mountain into the 
    empty stack to become the new base moutain

4 - at the end of this algorithm, any mountains leftover in the stack 
    could still be legit (eg. 10 5 1 5), no bigger mountain than 10 to 
    close it out but 5-1-5 is still a jump height of 4
--> iterate through the remaining stack, using the last mountain as the
    effective "tallest" mountain. all depths are wrt to the effective
    "tallest" mountain as the "tallest" mountain is guaranteed to be
    shorter than the base mountain by definition

Time: O(n)
Space: O(n)
'''
import sys

# Receiving input
N = int(input())
mountains = [int(x) for x in input().split()]

# Declaring Variables
maxJump = 0
stack = []

# Linear pass through mountains
for i, height in enumerate(mountains):
    # Stack empty, add mountain
    if len(stack) == 0:
        stack.append([height,i])

    # Current mountain shorter than stack base, add mountain
    elif height < stack[0][0]:
        stack.append([height, i])
    
    # Current mountain taller than stack base
    # Clear stack, measure heights, add new base
    elif height >= stack[0][0]:
        #print(stack, height)
        while(len(stack) != 1): # Dont consider height diff w base
            maxJump = max(min(height, stack[0][0]) - stack.pop()[0], maxJump)
        stack.pop()
        stack.append([height,i])

# If last mountain dosen't finish things up (ie. shorter than base)
if len(stack) != 1:
    #print(stack)
    while(len(stack) > 1):
        heightIndex = stack.pop()
        height = heightIndex[0]

        # last stack item can form a bridge with base
        while(len(stack) != 0 and height > stack[-1][0]):
            maxJump = max(heightIndex[0]-stack[-1][0], maxJump)
            stack.pop()

print(maxJump)
