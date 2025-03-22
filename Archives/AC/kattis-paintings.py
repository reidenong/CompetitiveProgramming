'''
kattis-paintings

- naive permutations is too slow given 5 x 12! = ~2B
- used a recursive backtrack solution to generate colour by colour
- similar to DFS, recursive backtrack tries to generate by using the first
  color available to form a full painting, before it 

Time: O(N!)
Mem: O(N)
'''
T = int(input())
for testcases in range (T) :
    # Receiving colors input, mapping to char
    N = int(input())
    colors = [x for x in input().split()]
    colorMask = {x : 1 for x in colors}
    
    # Updating hideous pairs
    M = int(input())
    hideousPairs = {}
    for i in range (M) :
        color1, color2 = map(str, input().split())
        if color1 in hideousPairs :
            hideousPairs[color1].add(color2)
        else :
            hideousPairs[color1] = {color2}
        if color2 in hideousPairs :
            hideousPairs[color2].add(color1)
        else :
            hideousPairs[color2] = {color1}

    # Backtracking
    paintings = 0
    painting = []
    solution = ''
    def backtrack (prev) :
        # Used up all colors, found a answer
        if sum(colorMask.values()) == 0 :
            global paintings
            paintings += 1
            if paintings == 1 :
                global solution
                solution =  ' '.join(painting)
        
        # Choose next color    
        for color in colors :
            # Color not available
            if colorMask[color] == 0 :
                continue

            # Color not compatible with previous
            if prev in hideousPairs and color in hideousPairs[prev] :
                continue

            # Add colour to list, backtrack
            painting.append(color)
            colorMask[color] = 0
            backtrack(color)
            painting.pop()
            colorMask[color] = 1
    
    # Display output
    backtrack('')
    print (paintings)
    print (solution)
