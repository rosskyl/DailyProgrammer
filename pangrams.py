"""
https://www.reddit.com/r/dailyprogrammer/comments/1pwl73/11413_challenge_139_easy_pangrams/
"""
from string import ascii_lowercase as AtoZ

#numLines = int(input("Enter the number of lines: "))

#for i in range(numLines):
##TODO need to make it do it for more than one line

line = input("Enter the sentence: ")
charDict = {}
for char in AtoZ:
    charDict[char] = 0

line = line.lower()
for char in line:
    if char in AtoZ:
        charDict[char] += 1

isPangram = True
for value in charDict.values():
    if not value > 0:
        isPangram = False

print(isPangram)
