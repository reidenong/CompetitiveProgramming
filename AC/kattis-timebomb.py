import sys

#let each string correspond to a certain number
digit_conversion = {
    "**** ** ** ****" : "0",
    "  *  *  *  *  *" : "1",
    "***  *****  ***" : "2",
    "***  ****  ****" : "3",
    "* ** ****  *  *" : "4",
    "****  ***  ****" : "5",
    "****  **** ****" : "6",
    "***  *  *  *  *" : "7",
    "**** ***** ****" : "8",
    "**** ****  ****" : "9"
    }

# Receiving first line, setting up DSes
line = input()
num_digits = int((len(line) + 1)/4)
digits = [""]*num_digits

# Passing first line
for i in range(num_digits):
    #print(">" + line[i*4:(i*4)+3] + "<")
    digits[i] += line[i*4:(i*4)+3]

for iteration in range(4):
    line = input()
    for i in range(num_digits):
        #print(">" + line[i*4:(i*4)+3] + "<")
        digits[i] += line[i*4:(i*4)+3]

ans = ""
for digit in digits:
    if digit in digit_conversion:
        ans += digit_conversion[digit]
    else:
        print("BOOM!!")
        sys.exit()

#print(int(ans))
if (int(ans)%6 == 0): print("BEER!!")
else: print("BOOM!!")
