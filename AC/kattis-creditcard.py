N = int(input())
for tc in range(N):
    R, B, M = map(float, input().split())
    R /= 100
    B *= 100
    B = round(B)
    M *= 100
    M = round(M)

    counter = 0
    while(counter < 1200 and B > 0):
        B = round(B*(1+R))
        B -= M
        counter += 1

    if(counter <= 1200 and B <= 0): print(counter)
    else: print("impossible")
