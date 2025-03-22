'''
kattis-addingwords

- not a hard problem, just use 2 maps to store front and back 
  mappings
- careful that when you re-define existing terms, u have to clear
  the back definitions as those are one way and will not be 
  overwritten by default

Time: O(N)
Space: O(N)
'''
import sys

# Mappings
frontMap = {}   # string : int
backMap = {}    # int : string

while(1):
    try:
        line = input().split()
    except EOFError:
        sys.exit()

    # Def variable
    if line[0] == 'def':
        # Re-def
        if line[1] in frontMap:
            backMap.pop(frontMap[line[1]])
    
        # Def 
        frontMap[line[1]] = int(line[2])
        backMap[int(line[2])] = line[1]

    # Process Calculation
    elif line[0] == 'calc':
        line = line[1:]
        unknown = False
        pos = 0
        while(1):
            if pos == 0:
                if line[0] in frontMap:
                    answer = frontMap[line[0]]
                    pos += 1
                else:
                    unknown = True
            
            if line[pos] == '+' and not unknown:
                pos += 2
                if line[pos-1] in frontMap:
                    answer += frontMap[line[pos-1]]
                else:
                    unknown = True
            
            if line[pos] == '-' and not unknown:
                pos += 2
                if line[pos-1] in frontMap:
                    answer -= frontMap[line[pos-1]]
                else:
                    unknown = True

            if line[pos] == '=' and not unknown:
                if answer in backMap:
                    print(' '.join(line), backMap[answer])
                    break
                else:
                    unknown = True
            
            if unknown:
                print(' '.join(line), "unknown")
                break
    
    # Clear operation
    elif line[0] == 'clear':
        frontMap = {}
        backMap = {}
