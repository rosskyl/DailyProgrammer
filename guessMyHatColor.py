"""
https://www.reddit.com/r/dailyprogrammer/comments/48l3u9/20160302_challenge_256_intermediate_guess_my_hat/
"""


inFile = open("guessMyHatColor.txt", "r")
hatColors = inFile.readlines()
inFile.close()

#create the list of people's hat colors and the number of blacks they can see
people = []
for i in range(len(hatColors)):
    hatColors[i] = hatColors[i].rstrip()
    blacks = hatColors[i+1:].count("Black\n")
    people.append(blacks)
    
#For first person, a
#Black guess is odd number of black and a
#White guess is even number of black
evenBlacks = (people[0] % 2 == 0)

if evenBlacks:
    print("White")
else:
    print("Black")
    
for i in range(1, len(people)):
    if (people[i] % 2 == 0) and evenBlacks:#person can see an even number and there is an even number previously
        guess = "White"
    elif (people[i] % 2 == 0) and not evenBlacks:#person can see an even number and there is an odd number previously
        guess = "Black"
        evenBlacks = True
    elif (people[i] % 2 != 0) and evenBlacks:#person can see an odd number and there is an even number previously
        guess = "Black"
        evenBlacks = False
    elif (people[i] % 2 != 0) and not evenBlacks:#person can see an odd number and there is an odd number previously
        guess = "White"
    if hatColors[i] != guess:
        print("Failed")
        print(hatColors[i], guess)
        break
    else:
        print(guess)