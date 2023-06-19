'''
kattis-zagrade

- firstly, obtain pairings of 'proper' brackets using stack, by keeping
  track of currently open and close bracket tabs
- after that permutate all combinations of choosing brackets using
  itertools to decide which brackets to keep and remove
- important to use set to store expressions to tackle edge cases of
  ((1+1)) as without set, (~1+1~) and ~(1+1)~ are duplicated and both
  are shown in the output
'''
import itertools
line = input()

# Obtain 'proper' bracket pairings
pairs = []
stack = []
for i, c in enumerate(line) :
    if c == '(' :
        stack.append(i)
    if c == ')' :
        pairs += [[stack.pop(), i]]

# Generate expressions w no brackets 
expressions = set()
permIdx = [x for x in range (len(pairs))]
for r in range (1, len(pairs) + 1) :
    combis = list(itertools.combinations(permIdx, r))
    for combi in combis :
        expression = list(line)
        for idx in combi :
            for pos in pairs[idx] :
                # Use a magic character that we remove later so as to
                # not disturb the order of the other characters
                expression[pos] = '~'
        expression = [x for x in expression if x != '~']
        expressions.add(''.join(expression))

# Output expressions
expressions = list(expressions)
expressions.sort()
for expression in expressions :
    print (expression)
        

