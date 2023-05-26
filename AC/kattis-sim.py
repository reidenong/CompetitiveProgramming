'''
kattis-sim

- just do as question says.
- deque as u have to add stuff at both sides
- stack to hold the items when cursor is at front as the items still have to 
maintain forward order

Time: O(n)
Space: O(n)
'''
import sys
from collections import deque

N = int(input())

for _ in range(N):
    line = input()
    pointerEnd = True
    output = deque()    # Use a deque to hold the overall sentence
    homeStack = []           # Use a stack to hold words when pointer is at the end

    # Iterate through all commands
    for ch in line:
        if ch == ']':
            pointerEnd = True
            while(homeStack):
                output.appendleft(homeStack.pop())
        elif ch == '[':
            pointerEnd = False
            while(homeStack):
                output.appendleft(homeStack.pop())
        elif ch == '<' and pointerEnd:
            if len(output) != 0:
                output.pop()
        elif ch == '<' and not pointerEnd:
            if len(homeStack) != 0:
                homeStack.pop()
        elif pointerEnd:
            output.append(ch)
        else:
            homeStack.append(ch)
    
    if not pointerEnd:
         while(homeStack):
            output.appendleft(homeStack.pop())
    print(''.join(output))


