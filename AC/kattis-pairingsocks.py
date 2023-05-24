'''
kattis-pairingsocks

use 2 stacks to simulate the sock stacks. algorithm is as follows:
- add sock
- remove all paired socks
- repeat

- algo ends when both stacks are empty (all socks sorted) or when 
original stack is empty = impossible

Time: O(n)
Space: O(n)

'''
# Using stack to model socks
from collections import deque
ori = deque()
aux = deque()

# Setting up stack structure for socks
N = int(input())
socks = [int(x) for x in input().split()][::-1]
for sock in socks:
    ori.append(sock)
#print(ori)

moves = 0
while(1):
    # Add sock
    if len(ori) != 0:
        aux.append(ori.pop())
        moves += 1

    # Check if socks r matching if both stacks not empty
    # if socks matching, check again
    while((len(ori) != 0) and       
          (len(aux) != 0) and 
          (ori[-1] == aux[-1])):
        moves += 1
        ori.pop()
        aux.pop()

    # End conditions
    # If both stacks empty- end
    if (len(ori) == 0) and (len(aux) == 0):
        print(moves)
        break

    # if original stack empty - impossible
    elif len(ori) == 0:
        print("impossible")
        break





