'''
CF-1920A Satisfying Constraints

- Straightforward question

Time: O(N)
Mem: O(1)
'''
TC = int(input())
for tc in range(TC) :
    N = int(input())
    
    upper_bound = int(1e9) + 1
    lower_bound = 1
    unequal = []
    for i in range(N) :
        a, b = map(int, input().split())
        if a == 1 :
            lower_bound = max(lower_bound, b)
        elif a == 2 :
            upper_bound = min(upper_bound, b)
        else :
            unequal.append(b)
    
    if upper_bound < lower_bound :
        print(0)
        continue

    unequal_ctr = 0
    for elem in unequal :
        if lower_bound <= elem <= upper_bound :
            unequal_ctr += 1
    
    print(upper_bound - lower_bound - unequal_ctr + 1)
