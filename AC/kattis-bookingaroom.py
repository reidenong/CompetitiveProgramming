import sys
N, K = map(int, input().split())

rooms = [True for _ in range(N)]

if N == K:
    print("too late")
    sys.exit()
    
for i in range(K):
    bookRoom = int(input())
    rooms[bookRoom-1] = False
    
for i, room in enumerate(rooms):
    if room:
        print(i+1)
        sys.exit()
