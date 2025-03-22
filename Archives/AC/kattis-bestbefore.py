import itertools
import calendar
import datetime

def legitdate(XYZ):
    [X, Y, Z] = XYZ
    if(X < 100): X += 2000
    elif(X >= 100 and X <2000): return 0
    elif(X >2999): return 0
    try:
        #calendar.weekday(X, Y, Z)
        dateF = datetime.date(year=X, month=Y, day=Z)
    except:
        return 0
    return dateF

# Receiving input, processing it into int
line = input()
ABC = [int(x) for x in line.split('/')]
for i in range(len(ABC)):
    if ABC[i] == 0: ABC[i] = 2000

# Derive all permutations of list python
permABC = list(itertools.permutations(ABC))

# Removing all useless dates
max_date = datetime.date(3000,1,1)
curr_date = max_date
for perm in permABC:
    if legitdate(perm) != 0:
        if legitdate(perm) < curr_date:
            curr_date = legitdate(perm)

# print(dates)


# Sorting dates
if curr_date > datetime.date(2999,12,31):
    print(line + " is illegal")
else:
    print(curr_date)
    
