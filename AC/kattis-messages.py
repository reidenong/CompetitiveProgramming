'''
kattis-messages

- initial idea to sort by keyword length and remove from string did not work, as keyword 
  may cut into 2 keywords. eg. abcabc with keywords [ca, abc]. creds to @brandontang89

- repeatedly cut of pieces off the front of the string. When any keyword is formed, we can just take
  in one of those keywords and add to a counter.

Time: O(string_length * num_of_keywords) per testcase  
Mem: O(num_of_keywords)
'''
words = []
while True :
    new_word = input()
    if new_word == '#':
        break
    words.append(new_word)

# For each testcase
while True :
    line = ''
    while not line.endswith("|"):
        line += input()
        if line == '#': exit()
    line = line[:-1]

    idx = 0
    counter = 0
    for i in range(len(line) + 1) :
        for word in words :
            if line[idx:i].endswith(word) :
                counter += 1
                idx = i

    print (counter)
