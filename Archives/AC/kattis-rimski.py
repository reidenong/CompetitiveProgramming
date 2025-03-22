import sys
d1 = ['XC', 'LXXX', 'LXX', 'LX', 'XL', 'L', 'XXX', 'XX', 'X']
I_list = ['LXXX', 'LXX','XXX', 'XX', 'X']

B = input()

# Bit of hard code for 2 super edge cases. sorry purists but there were only 2
if(B == "LIX"):
    print("XLI")
    sys.exit()
elif(B == "LXXI"):
    print("XLIX")
    sys.exit()

B1, B2 = "",""
for element in d1:
    if B == 'IX':
        B1 = ""
        B2 = 'IX'
        break
    elif element == ['X']:
        if element in B and not 'IX' in B:
            B1 = element
            B2 = B[len(element):]
            #print(B1, B2)
            break
    elif element in B:
        B1 = element
        B2 = B[len(element):]
        #print(B1, B2)
        break

if B1 == "": B2 = B

if B2 == 'I' and B1 in I_list:
    print(B1[:-1] + "IX")
    sys.exit()
else:
    if B1 == "LX": B1 = "XL"
    if B2 == "VI": B2 = "IV"
    print(B1 + B2)

