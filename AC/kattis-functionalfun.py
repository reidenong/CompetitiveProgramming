from copy import deepcopy
import sys
# 5 Outcomes
# 1. not a function
# 2. injective
# 3. surjective
# 4. bijective
# 5. neither injective nor surjective
run = True

while(run):
    domain_raw = sys.stdin.readline()
    if domain_raw == "": sys.exit()

    domain = domain_raw.split(" ")[1:]
    codomain = input().split(" ")[1:]
    #print(codomain)
    n = int(input())
    mappings = []
    mappings2 = {}      # To check if it is a function
    isFunction = True
    for i in range(n):
        x, y = input().split(" -> ")
        mappings += [[x,y]]
        if x in mappings2 and mappings2[x] != y:
            isFunction = False
        else:
            mappings2[x] = y

    cmap =  {}

    # Checking for function

    # Checking for injective
    isInjective = True
    for mapping in mappings:
        # Existing mapping, Not injective
        if mapping[1] in cmap:
            isInjective = False
        cmap[mapping[1]] = True

    # Checking for surjective
    isSurjective = True
    for element in codomain:
        if not element in cmap:
            #print(element)
            isSurjective = False

    # Checking for bijective
    if isInjective and isSurjective:
        isBijective = True
    else:
        isBijective = False

    # Output
    '''
    print("function: ", isFunction)
    print("injective: ", isInjective)
    print("surjective: ", isSurjective)
    print("bijective: ", isBijective)
    '''
    if not isFunction:
        print("not a function")
    elif isBijective:
        print("bijective")
    elif isInjective:
        print("injective")
    elif isSurjective:
        print("surjective")
    else:
        print("neither injective nor surjective")
