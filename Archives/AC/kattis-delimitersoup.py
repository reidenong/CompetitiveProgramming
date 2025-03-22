'''
kattis-delimitersoup

use stack to manage opening/closing

Time: O(n)
Space: O(n)
'''
import sys

# Receiving input
N = int(input())
sequence = [x for x in input()]
openings = ['(', '{', '[']
closings = [')', '}', ']']

# Processing input sequence
stack = []
for i, element in enumerate(sequence):
    # Add opening bracket
    if element in openings:
        stack.append(element)

    # Process closing bracket
    elif element in closings and len(stack) == 0:
        print(element, i)
        sys.exit()
    elif element == ')':
        if stack[-1] == '(':
            stack.pop()
        else:
            print(element, i)
            sys.exit()
    elif element == '}':
        if stack[-1] == '{':
            stack.pop()
        else:
            print(element, i)
            sys.exit()
    elif element == ']':
        if stack[-1] == '[':
            stack.pop()
        else:
            print(element, i)
            sys.exit()
print("ok so far")
