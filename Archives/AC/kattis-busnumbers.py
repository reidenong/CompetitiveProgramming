'''
kattis-busnumbers

Time: O(N) Linear pass
Space: O(N)
'''
import sys

# Receiving and sorting input
N = int(input())
numbers = [int(x) for x in input().split()]
numbers.sort()

# Linear pass through sorted numbers in ascending order
counter = 0
for i in range(N):
    # No streak ongoing
    if counter == 0:    
        sys.stdout.write(str(numbers[i]))

        # Start of a streak, minimum 3 in a row
        if(i < N-2 and
           numbers[i+1] == numbers[i] +1 and
           numbers[i+2] == numbers[i+1] + 1):   
            counter += 1
            sys.stdout.write('-')
        
        # No streak, print whitespace
        else:
            sys.stdout.write(' ')
    
    # End of a streak
    elif (i < N-1 and
          numbers[i+1] != numbers[i] + 1):
        counter = 0
        sys.stdout.write(str(numbers[i]) + " ")

    # End of the streak AND last number
    elif (i == N-1):
        sys.stdout.write(str(numbers[i]))
