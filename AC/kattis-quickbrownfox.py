import sys

alphabets = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
             'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
             'u', 'v', 'w', 'x', 'y', 'z']

N = int(input())

for i in range(N):
    valid = True
    line = input()
    line = line.lower()
    
    for alphabet in alphabets:
        if not alphabet in line:
            if valid:
                sys.stdout.write("missing ")
            sys.stdout.write(alphabet)
            valid = False
            
    if valid:
        sys.stdout.write("pangram")
    print()
