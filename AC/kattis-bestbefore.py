import itertools
import calendar

def leapyear(year):
    if(year%4 == 0 and year%100 != 0): return 1
    elif(year%400 == 0): return 1
    else: return 0

def legitdate(XYZ):
    [X, Y, Z] = XYZ
    if(X < 1000): X += 2000
    try:
        calendar.weekday(X, Y, Z)
    except:
        return 0
    return [X, Y, Z]

# Receiving input, processing it into int
line = input()
ABC = [int(x) for x in line.split('/')]
for i in range(len(ABC)):
    if ABC[i] == 0: ABC[i] = 2000

# Derive all permutations of list python
permABC = list(itertools.permutations(ABC))

# Removing all useless dates
dates = []
for perm in permABC:
    if legitdate(perm) != 0:
        dates += [legitdate(perm)]
# print(dates)


# Sorting dates
if len(dates) == 0:
    print(line + " is illegal")
else:
    dates.sort()
    dates = dates[0]
    dates = [str(x) for x in dates]
    for i in range(3):
        if int(dates[i]) < 9:
            dates[i] = "0" + dates[i]
    
    print('-'.join(dates))
