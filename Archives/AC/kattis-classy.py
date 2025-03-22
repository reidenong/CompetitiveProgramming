tc = int(input())
for cases in range(tc):
    peopleClass = []
    N = int(input())
    maxClassNum = 0
    for i in range(N):
        peopleClass += [input().split(': ')]
        # replace the classes with lexographically ordered tags
        # With .sort() A will be infront of B and so on due
        # to lexographical order, thus sorting by class
        peopleClass[-1][1] = peopleClass[-1][1].replace("upper", "A")
        peopleClass[-1][1] = peopleClass[-1][1].replace("middle", "B")
        peopleClass[-1][1] = peopleClass[-1][1].replace("lower", "C")
        maxClassNum = max(maxClassNum, len(peopleClass[-1][1]) )
    
    # Middle Class padding
    for i, person in enumerate(peopleClass):
        while(len(person[1]) < maxClassNum):
            peopleClass[i][1] = "B-" + peopleClass[i][1]

    # Sort by alphabetical order first, followed by class
    # STL sort is stable so for similar
    # class the alphabetical order holds
    peopleClass.sort(key=lambda x : x[0])
    peopleClass.sort(key=lambda x : x[1][::-1])     
    # reverse and sort

    # Output
    for person in peopleClass:
        print(person[0])
    print("="*30)
    #print()
