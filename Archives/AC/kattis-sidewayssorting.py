import sys

while(1):
    # Exit when 0 detected
    row, col = map(int, input().split())
    if(row == 0):
        sys.exit()

    # Receive input such that words is a list of column strings
    words = [""] * col
    for i in range(row):
        line = input()
        for i, letter in enumerate(line):
            words[i] += letter

    # Sort lexographically, ignoring case
    words.sort(key=lambda x : x.lower())

    # Print column wise
    for i in range(row):
        outputLine = ""
        for word in words:
            outputLine += word[i]
        print(outputLine)
    print(" ")
