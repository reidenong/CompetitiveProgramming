'''
kattis-sort

- We use a dictionary to track the frequency of each element as the range
  of elements ie. C is too large for a direct frequency list

- We also track the time of the first occurence of each element in the sequence
  as a tiebreaker for a equal number of appearances

Time: O(NlogN) for sorting
Mem: O(N)
'''
N, C = map(int, input().split())
arr = [int(x) for x in input().split()]

# Generating frequency map
freqMap = {}
for i in range (N) :
    elem = arr[i]

    if elem in freqMap :
        freqMap[elem][0] += 1
    else :
        freqMap[elem] = [1, i]

# Generating frequency list
freqList = []
for key in freqMap :
    freqList.append([freqMap[key], key])

# Sort freq list and output
freqList.sort(key = lambda x : x[0][1])
freqList.sort(key = lambda x : x[0][0], reverse = True)
for elem in freqList :
    for i in range(elem[0][0]) :
        print(elem[1], end = ' ')
