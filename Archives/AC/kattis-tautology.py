'''
kattis-tautology

- first we generate all possibilities of variables p-t
- simulate for all variable possibilities

Time: O(N)
Space: O(1)
'''
import sys
import itertools
from copy import deepcopy

# Defining Logic Set for p, q, r, s, t
logicMap = {
    "p" : 0,
    "q" : 1,
    "r" : 2,
    "s" : 3,
    "t" : 4
}
logicSetC = list(itertools.combinations_with_replacement([0,1], 5))
logicSet = set()
for combi in logicSetC :
    for combiset in list(itertools.permutations(combi)) :
        logicSet.add(combiset)

# Processing each WFF
while (1) :
    # Receiving input in form of a stack
    tautology = True
    line = [x for x in input()]
    if line == ['0'] :
        sys.exit()

    # Each distinct case of logic is one permutation of truthvalues
    for logic in logicSet :
        stack = deepcopy(line)
        truthValue = [logic[logicMap[stack.pop()]]]

        # For each operation
        while len(stack) > 0 :
            nextOp = stack.pop()
            
            # Store variable for next operation
            if nextOp in logicMap:
                truthValue.append(logic[logicMap[nextOp]])

            # Perform action
            else:
                # AND function
                if nextOp == 'K' :
                    first = truthValue.pop()
                    second = truthValue.pop()
                    truthValue.append(first and second)

                # OR function
                elif nextOp == 'A' :
                    first = truthValue.pop()
                    second = truthValue.pop()
                    truthValue.append(first or second)
                
                # NOT function
                elif nextOp == 'N' :
                    first = truthValue.pop()
                    truthValue.append(not first)

                # IMPLIES function
                elif nextOp == 'C' :
                    first = truthValue.pop()
                    second = truthValue.pop()
                    if first and (not second) :
                        truthValue.append(0)
                    else :
                        truthValue.append(1)
                
                # EQUALS function
                elif nextOp == 'E' :
                    first = truthValue.pop()
                    second = truthValue.pop()
                    if first == second :
                        truthValue.append(1)
                    else :
                        truthValue.append(0)
        
        if not truthValue.pop() :
            tautology = False
            break

    # Display conclusion
    if tautology :
        print("tautology")
    else :
        print("not")

                

            

