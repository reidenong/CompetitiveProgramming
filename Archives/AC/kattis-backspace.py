'''
kattis-backspace

 - trivial question, use stack to easily manage operations in O(1)

Time: O(N)
Mem: O(N)
'''
line = input()
ans = []
for char in line :
    if char == '<' :
        ans.pop()
    else :
        ans.append(char)
print(''.join(ans))
