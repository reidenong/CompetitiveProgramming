'''
kattis-veci
'''
import itertools

# Receiving input
digits = [x for x in input()]
N = int(''.join(digits))
permutations = list(itertools.permutations(digits))

# Obtain all possible permutations
# Only add permutation to the set if its bigger than the original number
# Easy to find smallest (bigger) number --> smallest number in set
possibleNumbers = set()
for instance in permutations :
    num = int(''.join(instance))
    if num > N :
        possibleNumbers.add(num)

# Display output
if len(possibleNumbers) > 0 :
    print (sorted(possibleNumbers)[0])
else :
    print (0)

