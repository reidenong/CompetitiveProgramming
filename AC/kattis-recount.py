'''
kattis-recount
'''
import sys
votes = {}
N = 0

while(1):
    name = input()
    if name == '***':
        break
    else:
        N += 1

    if not name in votes:
        votes[name] = 1
    else:
        votes[name] += 1

currMax = 0
for name in votes:
    if votes[name] > currMax:
        candidate = name
        currMax = votes[name]
    elif votes[name] == currMax:
        candidate = "Runoff!"

print(candidate)
        
