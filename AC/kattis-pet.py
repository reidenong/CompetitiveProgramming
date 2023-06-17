# kattis-pet
winner = 1
maxScore = 0
for i in range (5) :
    grades = [int(x) for x in input().split()]
    grades = sum(grades)
    
    if grades > maxScore :
        winner = i+1
        maxScore = grades

print (winner, maxScore)
