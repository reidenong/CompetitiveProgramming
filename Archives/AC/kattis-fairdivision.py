'''
kattis-fairdivision

 - Greedy algorithm. Sort people by contribution, while maintaining original order stability. Then
   successively allow each person to contribute one cent while they are able to do so. So difference is minimized
   while allowing richer people to contribute more, as well as people earlier in the list.

Time: O(P/N)
Mem: O(N)
'''
testcases = int(input())

for tc in range(testcases) :
    P, N = map(int, input().split())

    people = [int(x) for x in input().split()]

    if sum(people) < P :
        print ("IMPOSSIBLE")
        continue

    original = [[elem, i] for i, elem in enumerate(people)]
    people = [[elem, i] for i, elem in enumerate(people)]
    
    people.sort(key = lambda x : x[0], reverse = True)

    # Assume everybody contributes minimum first
    total = 0
    while total < P :
        for i in range(N) :
            if people[i][0] == 0 :
                break       # All others after this person will also be 0

            if total == P :
                break

            total += 1
            people[i][0] -= 1

    # Print answer
    people.sort(key = lambda x : x[1])
    for i in range(N) :
        print (original[i][0] - people[i][0], end = " ")
    print ()
