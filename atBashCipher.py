"""
https://www.reddit.com/r/dailyprogrammer/comments/45w6ad/20160216_challenge_254_easy_atbash_cipher/
"""

from string import ascii_lowercase as lowerLetters
from string import ascii_uppercase as upperLetters

global revLowerLetters
revLowerLetters = lowerLetters[::-1]

global revUpperLetters
revUpperLetters = upperLetters[::-1]

def encode(text):
    cipher = ""
    for letter in text:
        if letter in lowerLetters:
            cipher = cipher + revLowerLetters[lowerLetters.find(letter)]
        elif letter in upperLetters:
            cipher = cipher + revUpperLetters[upperLetters.find(letter)]
        else:
            cipher = cipher + letter
    return cipher
    
print(encode("gsrh rh zm vcznkov lu gsv zgyzhs xrksvi"))