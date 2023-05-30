'''
kattis-jugglingpatterns

- Simulation solution, hands list record ball movement for up to 100 * patternLength
  by showing if ball is in hand or not
- collisions mean that the sequence is not legit
- Additionally extra check at the end as if pattern shows 0, no ball is to be thrown on that
  move so by definition no ball is to be caught either

Time: O(tc 100*patternLength)  
Space: O(100*patternLength)
'''
import sys

while(1):
    valid = True
    try:
        pattern = [int(x) for x in input()]
    except EOFError:
        sys.exit()

    # Check for # of balls
    patternLength = len(pattern)
    N = int(sum(pattern)/patternLength)
    if sum(pattern) % patternLength != 0:
        print(''.join(str(x) for x in pattern) + ": invalid # of balls")
        continue

    # Check for how far for 1 complete repetition
    maxDist = 100*patternLength

    hands = [['-','-'] for _ in range(maxDist+1)]

    # Simulate throws
    for ball in range(N):
        # Find starting point, SP
        for i in range(100*patternLength):
            if hands[i] == ['-','-'] and pattern[i%patternLength] != 0:
                pos = i
                break
        
        # Find starting postion
        # 'right' is both a boolean and positional indicator
        if pos%2 == 0:
            right = 0
        else:
            right = 1

        # Simulate movement of individual ball
        while(pos < maxDist):
            # Check pos for existing ball
            if hands[pos][right] != '-' or pattern[pos%patternLength] == 0:
                hands[pos][right] = 'X'     # Debug tool
                valid = False
                break

            # Update curr hand
            hands[pos][right] = 'O'
        
            # Move marker to next pos, update positional indicator
            if (pattern[pos%patternLength] %2) != 0:
                right ^= 1      # Flip position
            pos += pattern[pos%patternLength]
            if pattern[pos%patternLength] == 0:
                valid = False
                break

        if not valid:
            break

        '''
        # Debug Tool to visualize ball movement
        # Similar to ladder diagrams used for siteswap
        for i, hand in enumerate(hands):
            if i < 20:
                print(i, hand, pattern[i%patternLength])
        '''
    
    # Last check for missing throws on '0'
    if valid:
        for i in range(100*patternLength):
            if hands[i] == ['-','-'] and pattern[i%patternLength] != 0:
                valid = False
                break

    #print(hands)
    if valid:
        print(''.join(str(x) for x in pattern) + ": valid with " + str(N) + " balls")
    else:
        print(''.join(str(x) for x in pattern) + ": invalid pattern")
    
