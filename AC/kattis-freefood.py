'''
kattis-freefood
'''
import sys

# Setting Days array
year = [False for _ in range(365)]

# Receiving and sorting input
N = int(input())
for i in range(N):
    start, end = map(int, input().split())
    start -= 1  # 0-indexed
    end -= 1    #     ||

    # Update year
    for j in range(start, end+1):
        #print(j, end=' ')
        year[j] = True
    #print()

# Counting days, output
counter = 0
for day in year:
    if day:
        counter += 1
print(counter)
