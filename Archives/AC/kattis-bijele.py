correct = [1,1,2,2,2,8]
pieces = [int(x) for x in input().split()]
for i in range(6):
    print(correct[i] - pieces[i], end=' ')
