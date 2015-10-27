"""
https://www.reddit.com/r/dailyprogrammer/comments/3q9vpn/20151026_challenge_238_easy_consonants_and_vowels/
"""
from random import randrange

vowels = "aeiouy"
consonants = "bcdfghjklmnpqrstvwxz"

print("press enter when done")
line = input("Enter Cs and Vs: ")
while line != "":
    word = ""
    for char in line:
        if char.lower() == "c":
            letter = consonants[randrange(0,len(consonants))]
            if char == "C":
                letter = letter.upper()
        elif char.lower() == "v":
            letter = vowels[randrange(0,len(vowels))]
            if char == "V":
                letter = letter.upper()
        else:
            print("must only contain C,V,c,v")
            exit(1)
        word += letter
    print(word)
    line = input("Enter Cs and Vs: ")
