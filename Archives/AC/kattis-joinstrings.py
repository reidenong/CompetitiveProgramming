'''
kattis-joinstrings

use stack for O(1) operations
did with help from @brandontang89

'''
import sys
from collections import deque

N = int(input())
strings = [input() for _ in range(N)]
children = [[] for _ in range(N)]
alive = [True]*N

for _ in range(N-1):
    start, end = map(int, input().split())
    start -= 1
    end -= 1
    children[start].append(end)
    alive[end] = False

alive = [i for i in range(N) if alive[i]]

def iterative_dfs(x):
    stack = x
    while stack:
        y = stack.pop()
        sys.stdout.write(strings[y])
        for z in children[y][::-1]:
            stack.append(z)
iterative_dfs(alive)
