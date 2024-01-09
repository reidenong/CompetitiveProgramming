'''
kattis-hypercube

- Firstly, to understand the pattern, we generate the n-bit gray code sequence to gain intuition

- From observation, we can see that the leftmost bit of the current code determines whether we are in the 
  first half of the sequence or the second half of the sequence.

- As such, we can do a recursive pattern as to whether we are in the first half or second half of the sequence,
  remove the leftmost bit to get the next code.

- It is important whenever the code is a 1, we flip the boolean flip to indicate that we are in the second half
  if the sequence, and as such we process the boolean -arity in an opposite direction.

- This algorithm is efficient as instead of generating the entire sequence and searching in O(2^n), we only
  need to process it bit by bit in O(n) time.

Time: O(N)
Memory: O(1)
'''
# Generating n-bit gray code (code to understand pattern)
def generate_graycode(n) :
    if n == 1:
        return ['0', '1']
    else :
        return ['0' + x for x in generate_graycode(n - 1)] + ['1' + x for x in reversed(generate_graycode(n - 1))]

# Finding position of code in n-bit graycode sequence
def findPos(code) :
    lo, hi = 0, 2**len(code) - 1
    flip = False
    
    while lo != hi :
        if code[0] ==  "0" and not flip :
            hi = (lo + hi)//2
        elif code[0] == "0" and flip :
            lo = (lo + hi)//2 + 1
        elif code[0] == "1" and not flip :
            lo = (lo + hi)//2 + 1
            flip = True
        elif code[0] == "1" and flip :
            hi = (lo + hi)//2
            flip = False
        code = code[1:]

    return lo

# Receiving input, returning answer
inputs = input().split()
print(abs(findPos(inputs[1]) - findPos(inputs[2])) - 1)
