'''
kattis-dreamer

- we can use itertools to easily obtain all permutations and then 
  datetime to compare if the date is legit or not, much more robust
  than having to program the leapyear stuff
- use set to prevent duplicate dates which itertools permutation might
  give 

Time: O(N*8!)
Space: O(N*8!)
'''
import itertools
import datetime

date_format = "%Y-%m-%d"
def dateChecker (dateString) :
    try : 
        dateObject = datetime.datetime.strptime(dateString,date_format)
        return True
    except :
        return False

# Receiving input
N = int(input())
for testcase in range (N) :
    line = [x for x in input() if x != " "]
    
    # Permutating for all possible dates
    realDates = set() # Easy duplicate prevention
    permutations = list(itertools.permutations(line))
    for instance in permutations :
        currDate = ''.join(instance)

        # Pruning step to reject dates before 2000
        if int(currDate[:4]) < 2000 :
            continue

        # Formatting date, checking if real
        currDate = currDate[:4] + '-' + currDate[4:6] + '-' + currDate[-2:]
        if dateChecker(currDate) :
            realDates.add(currDate)
    
    # Formatting Output
    print (len(realDates), end=" ")
    if len(realDates) > 0 :
        earliestDate = sorted(realDates)[0]
        print (' '.join(earliestDate.split('-')[::-1]))
    else :
        print ()
