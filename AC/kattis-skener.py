R, C, ZR, ZC = map(int, input().split())
# print(R, C, ZR, ZC)

for row in range(R):
    line = input()
    
    for i in range(ZR):
        for char in line:
            for j in range(ZC):
                print(char,end = '')
        print(" ")











