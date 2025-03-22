import sys

# Receiving input
N = input()
M = input()
decSpaces = len(M)-1
head = N[:-decSpaces]
tail = N[-decSpaces:]

# Accounting for N/M < 1
if decSpaces > len(N):
    tail = "0" * (decSpaces-len(N)) + tail

# Remove trailing zeros in tail
tailLength = len(tail)
chopcounter = 0
for i in range(1, tailLength+1):
    #print("endtail:", -i, tail[-i])
    if tail[-i] == "0":
        chopcounter += 1
    elif tail[-i] != "0":
        break
if chopcounter != 0:
    tail = tail[:-chopcounter]

# Printing Output
if head == "":
    print("0." + tail)
elif tail != "":
    print(head + "." + tail)
else:
    print(head)

