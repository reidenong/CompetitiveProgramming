'''
kattis-virus

- a string sequence may be added to the before. At the same spot, a string seq
  may or may not have been removed.

- Key observation is that the removal and addition happens at the same spot
  in the string. Meaning that the string is still identical at all other parts

- With only one spot, we can check from the front until we come across our 
  first difference. we then check from the back until we find our last (first
  from the back) difference. Everything in between is thus the difference
  between both strings

- In this case, from the front and back, we remove each element if they are
  identical in before and after. what is left of before is the string section
  removed, and what is left of after is the string section added

- Since they only want the min length added just output length of "after"

Time: O(N)
Space: O(N)
'''
# Receiving input
before = list(input())
after = list(input())

# Find last location where virus hit
# Removing back elements if they are equal
while before and after and before[-1] == after[-1] :
    before.pop()
    after.pop()

# Find first location where virus hit
before = before[::-1]   # Reversing string to pop from front
after = after[::-1]
# Removing front elements if they are equal
while before and after and before[-1] == after[-1] :
    before.pop()
    after.pop()

print (len(after))
