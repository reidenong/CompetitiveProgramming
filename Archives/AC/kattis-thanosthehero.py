'''
kattis-thanosthehero

- linear pass, impossible criterion is whenever a world has negative ppl

Time: O(N)
Space: O(N)
'''
import sys

N = int(input())
worlds = [int(x) for x in input().split()]

worlds.reverse()

killed = 0
for i in range (N - 1) :
    if worlds[i] <= worlds[i+1] :
        killed += worlds[i+1] - worlds[i] + 1
        worlds[i+1] = worlds[i] - 1

        # Impossible criterion
        if worlds[i+1] < 0 :
            print (1)
            sys.exit()

print (killed)
