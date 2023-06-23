'''
kattis-dobra

- naively backtracking with alphabet permutations is too slow
- for each _, 3 actions can be done ->  add a vowel
                                        add a consonant that is not L
                                        add a L

- all words are masked as V (vowel), C (consonant not L), L

Time: O(3^N)
Space: O(N)
'''
# Defining alphabet structure
vowels = 'AEIOU'
consonants = 'BCDFGHJKMNPQRSTVWXYZ'
combiMap = {'V' : 5, 'C' : 20, 'L' : 1}

# Receiving input, applying masks
word = [x for x in input()]
maskedWord = []
blanks = []
for i, letter in enumerate(word) :
    if letter in vowels :
        maskedWord += ['V']
    elif letter in consonants :
        maskedWord += ['C']
    else :
        maskedWord += [letter]
        if letter == '_' :
            blanks += [i]
N = len(word)

# Recursive backtrack on building word
def backtrack (prev) :
    # End of word
    if len(prev) == N :
        if 'L' in prev :
            # Using PnC to determine total combinations
            # (Chain Rule of independent choices)
            combinations = 1
            for pos in blanks :
                combinations *= combiMap[prev[pos]]
            
            # Update global answer
            global ans
            ans += combinations
        return

    # Adding new letters
    idx = len(prev)

    # Given letter
    if maskedWord[idx] != '_' :
        nextLetter = maskedWord[idx]
        if ((nextLetter == 'C' or nextLetter == 'L') and
            len(prev) >= 2 and
            (prev[-1] == 'C' or prev[-1] == 'L') and
            (prev[-2] == 'C' or prev[-2] == 'L')) :
            return
        elif (nextLetter == 'V' and
            len(prev) >= 2 and
            prev[-1] == 'V' and
            prev[-2] == 'V') :
            return
        else :
            prev += nextLetter
            backtrack(prev)
        
    
    # Try adding letter
    else :
        # Adding 'C'
        if not (len(prev) >= 2 and
            (prev[-1] == 'C' or prev[-1] == 'L') and
            (prev[-2] == 'C' or prev[-2] == 'L') ) :
            prev += 'C'
            backtrack(prev)
            prev = prev[:-1]

        # Adding 'L'
        if not (len(prev) >= 2 and
            (prev[-1] == 'C' or prev[-1] == 'L') and
            (prev[-2] == 'C' or prev[-2] == 'L') ) :
            prev += 'L'
            backtrack(prev)
            prev = prev[:-1]

        # Adding 'V'
        if not (len(prev) >= 2 and
            prev[-1] == 'V' and
            prev[-2] == 'V') :
            prev += 'V'
            backtrack(prev)
            prev = prev[:-1]

# Display answer
ans = 0
backtrack('')
print (ans)
