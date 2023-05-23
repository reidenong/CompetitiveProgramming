'''
kattis- bitbybit

easy question, just follow instructions

time: O(N)
space: O(1)
'''
import sys

# OR function
def doOR(i, j):
    global bits
    if bits[i] == 1 or bits[j] == 1:
        bits[i] = 1
    elif bits[i] == 0 and bits[j] == 0:
        bits[i] = 0
    elif bits[j] == "?":
        bits[i] = "?"

# AND function
def doAND(i, j):
    global bits
    if bits[i] == 0 or bits[j] == 0:
        bits[i] = 0
    elif bits[i] == 1 and bits[j] == 1:
        bits[i] = 1
    elif bits[j] == "?":
        bits[i] = "?"

# Main
while(1):
    bits = ["?"]*32
    N = int(input())
    if N == 0:
        break

    for i in range(N):
        instruction = input().split()
        #print(instruction)

        if instruction[0] == "CLEAR":
            bits[int(instruction[1])] = 0
        elif instruction[0] == "SET":
            bits[int(instruction[1])] = 1
        elif instruction[0] == "OR":
            doOR(int(instruction[1]), int(instruction[2]))
        elif instruction[0] == "AND":
            doAND(int(instruction[1]), int(instruction[2]))  

    # Display bit sequence (reverse as bits r right to left)
    print(''.join([str(x) for x in reversed(bits)]))
