'''
kattis-compoundwords
'''
# Receiving input
wordset = set()
while (1) :
    try :
        line = set(input().split())
    except EOFError:
        break
    wordset |= line

# Create pairings
outputset = set()
while (len(wordset) > 0) :
    term = wordset.pop()
    for remaining in wordset:
        outputset.add(term + remaining)
        outputset.add(remaining + term)

# Sorting terms
outputset = list(outputset)
outputset.sort(key=lambda x : len(x))
outputset.sort()
for element in outputset:
    print (element)
