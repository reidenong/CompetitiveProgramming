line = input()
line = list(line.upper())
name = ["P","E","R"]

ans = 0
for i in range(len(line)):
    if(line[i] != name[i%3]):
        ans += 1
        line[i] = name[i%3]
    #print(line)

print(ans)
