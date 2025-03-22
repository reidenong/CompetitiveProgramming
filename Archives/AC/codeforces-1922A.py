'''
CF-1922A Tricky Template

- Took me way longer than it should have because brain wasn't working. We can process each letter on the fly, where
  first we check if its definitely uppercase. 

- We operate with the assumption that a and b can match, and then we try to search for a situation where c dosent match.

Time: O(N)
Mem: O(1)
'''
TC = int(input())
for testcase in range(TC) :
    N = int(input())
    a = input()
    b = input()
    c = input()

    # Check and iterate through each letter
    c_follows = True
    for i in range (N) :

        # Confirmed to be template uppercase, 
        # If c[i] is not the same letter as a[i] or b[i] then c has the chance to not match
        if a[i] != b[i] :
            if c[i].lower() != a[i].lower() and c[i].lower() != b[i].lower() :
                c_follows = False

        # May or may not be template lowercase
        # If c[i] is not the same letter as a[i] or b[i] then c has the chance to not match
        else :
            if c[i] != a[i] :
                c_follows = False

    if not c_follows :
        print("YES")
    else :
        print("NO")
