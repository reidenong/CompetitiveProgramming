T = int(input())

for tc in range(T):
    D, M = map(int, input().split())
    days = [int(x) for x in input().split()]
    ans = 0
    month, month_day = 0, 1
    for day in range(sum(days)):
        if(month_day > days[month]):
            month_day = 1 
            month += 1
        if(month_day == 13 and day%7 == 5):
            ans += 1

        #print(month_day, day%7)
        month_day += 1
        
    print(ans)




