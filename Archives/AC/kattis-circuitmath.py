'''
kattis-circuitmath

Key observation:
- For the postcircuit to work, it is guaranteed that there will always
  be 2 working T-F values inside.
- the trick here is to use a stack such that all later steps can
  effectively queue up if they cannot be solved immediately, to be
  resolved later when the stack operations clear up


Time: O(n)
Space: O(1)
'''
import sys

# Lookup tables for easy translation
translation = {"T":True,"F":False}
checker = [True, False]
alphabet = {'a': '1', 'b': '2', 'c': '3', 'd': '4', 'e': '5', 'f': '6', 'g': '7', 'h': '8', 'i': '9', 'j': '10',
            'k': '11', 'l': '12', 'm': '13', 'n': '14', 'o': '15', 'p': '16', 'q': '17', 'r': '18', 's': '19', 't': '20',
            'u': '21', 'v': '22', 'w': '23', 'x': '24', 'y': '25', 'z': '26', 'A': '27', 'B': '28', 'C': '29', 'D': '30',
            'E': '31', 'F': '32', 'G': '33', 'H': '34', 'I': '35', 'J': '36', 'K': '37', 'L': '38', 'M': '39', 'N': '40',
            'O': '41', 'P': '42', 'Q': '43', 'R': '44', 'S': '45', 'T': '46', 'U': '47', 'V': '48', 'W': '49', 'X': '50', 
            'Y': '51', 'Z': '52'}

# Receiving input
N = int(input())
inputValues = [translation[x] for x in input().split()]
sequence = input().split()

# Processing input sequence
stack = []
for move in sequence:
    if move in alphabet:
        stack.append(inputValues[int(alphabet[move])-27])
    
    if move == "*":
        if (stack[-1] in checker) and (stack[-2] in checker):
            first = stack.pop()
            second = stack.pop()
            stack.append(first and second)
    
    elif move == "+":
        if (stack[-1] in checker) and (stack[-2] in checker):
            first = stack.pop()
            second = stack.pop()
            stack.append(first or second)

    elif move == "-":
        if stack[-1] in checker:
            first = stack.pop()
            stack.append(not first)

if stack[0]:
    print("T")
else:
    print("F")

