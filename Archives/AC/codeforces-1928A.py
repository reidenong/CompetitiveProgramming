'''
CF1928A - Rectangle Cutting

- we can only cut sides that are even. Note that we have to sort both sides
  so we are comparing small to small.
'''
def solve() :
    rect = [int(x) for x in input().split()]
    rect.sort()
            
    if rect[0] % 2 == 0 :
        temp = [rect[0] // 2, rect[1] * 2]
        temp.sort()
        if temp != rect :
            print("YES")
            return
        
    if rect[1] % 2 == 0 :
        temp = [rect[0] * 2, rect[1] // 2]
        temp.sort()
        if temp != rect :
            print("YES")
            return
    
    print("NO")
    return

TC = int(input())
for tc in range(TC) :
    solve()
