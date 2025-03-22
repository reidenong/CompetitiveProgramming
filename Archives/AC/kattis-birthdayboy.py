# Initialising Months
months = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
for i in range(1, len(months)):
    months[i] += months[i-1]

# Yearday to Date
def yeardaytodate(birthday):
    #print(birthday)
    for i in range(len(months)):
        if(birthday <= months[i+1]):
            ans_month = i+1
            if ans_month < 10: ans_month = "0" + str(ans_month)
            else: ans_month = str(ans_month)
            ans_day = birthday - months[i]
            if ans_day < 10: ans_day = "0" + str(ans_day)
            else: ans_day = str(ans_day)

            if ans_month + '-' + ans_day == "01-00": return "12-31"
            return(ans_month + '-' + ans_day)

cal = [0]*365

n = int(input())
for i in range(n):
    [name, date] = input().split()
    month, day = map(int, date.split("-"))
    yearday = months[month-1] + day -1 # Indexed-1
    #print(yearday)
    cal[yearday] = 1
#print(" ")
#cal[300] = 1    # Set Today as a birthday
#print(cal)

curr_max = 0
curr_ctr = 0
birthday = 299
for day in range(1,1200):
    realday = day
    day = (day + 300)%365
    #print(yeardaytodate(day))
    
    # Not someone's birthday
    if not cal[day]:
        curr_ctr += 1

    # Someone's birthday
    else:
        #print(curr_max, day ,yeardaytodate(day))
        if curr_ctr > curr_max and realday < 750:
            birthday = day
            curr_max = curr_ctr
        elif curr_ctr >= curr_max and realday >= 750:
            if((day-301)%365 < (birthday-301)%365):
                birthday = day
                curr_max = curr_ctr
            
        curr_ctr = 0

#birthday -= 1   # Before someone elses's birthday

print(yeardaytodate(birthday))

    


    

