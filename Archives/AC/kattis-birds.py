'''
kattis-birds

- remember to sort birds!!!!

Time: O(N)
Space: O(N)
'''
# Receiving input
L, D, N = map(int, input().split())
birds = []
for i in range (N) :
    bird = int(input())
    birds.append(bird)

# Fake birds to attempt to fit birds at the ends if possible
birds = [6-D] + birds + [L - 6 + D]
birds.sort()

# Add birds in the gaps between existing birds
extras = 0
for i in range (len(birds) - 1) :
    dist = birds[i+1] - birds[i]
    
    # No space for birds
    if dist < D*2 :
        continue

    # Fit extra birds
    else :
        extras += dist//D - 1

print (extras)
