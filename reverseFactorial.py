"""
https://www.reddit.com/r/dailyprogrammer/comments/55nior/20161003_challenge_286_easy_reverse_factorial/
"""


def reverseFactorial(num):
    div = 1
    while num > 1:
        div += 1
        num /= div
    if num == 1:
        return str(div) + "!"
    else:
        return "NONE"


print(reverseFactorial(120))
print(reverseFactorial(150))
print(reverseFactorial(3628800))
print(reverseFactorial(479001600))
print(reverseFactorial(6))
print(reverseFactorial(18))