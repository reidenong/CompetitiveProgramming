attributes = input().split()
N = int(input())
Data = []
for i in range(N):
    Data += [input().split()]
M = int(input())
for i in range(M):
    spec = input()
    Data.sort(key=lambda x : x[attributes.index(spec)])

    # Print attributes
    print(" ".join(attributes))
    for datum in Data:
        print(" ".join(datum))
    print()

