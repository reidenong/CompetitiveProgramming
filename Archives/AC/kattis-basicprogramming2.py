import sys

N, t = map(int, input().split())
Arr = [int(x) for x in input().split()]

if t == 1:      # O(N)
    Arr = set(Arr)  
    # Set remove all duplicates, 
    # and *in* works much faster in set thatn in list
    for num in Arr: 
        if 7777-num in Arr:
            print("Yes")
            sys.exit()
    print("No")


elif t == 2:    # O(1)
    if N != len(set(Arr)):
        print("Contains duplicate")
    else:
        print("Unique")


elif t == 3:    # O(N)
    freqDict = {}
    for num in Arr:
        if str(num) not in freqDict:
            freqDict[str(num)] = 0
        else:
            freqDict[str(num)] += 1
    for key in freqDict:
        if freqDict[key] >= int(N/2):
            print(key)
            sys.exit()
    print("-1")


elif t == 4:    # O(n log n)
    Arr.sort()
    if N % 2 == 0:
        if(Arr[int(N/2)-1] == Arr[int(N/2)]):
            print(Arr[int(N/2)])
        else:
            print(Arr[int(N/2)-1], Arr[int(N/2)])
    else:
        print(Arr[int(N/2)])


elif t == 5:    # O(n log n)
    inRange = []
    for elem in Arr:
        if elem >= 100 and elem <1000:
            inRange += [elem]
    inRange.sort()
    for elem in inRange:
        sys.stdout.write(str(elem) + " ")
    

