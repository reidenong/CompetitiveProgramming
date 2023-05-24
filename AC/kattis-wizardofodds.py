'''
kattis-wizardofodds

Fastest way to query a number from a range is probably with binary
search, which has a complexity of log2N. Thus if k >= log2N it is possible.

'''
import math

N, K = map(int, input().split())

if(K >= math.log2(N)):
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")


