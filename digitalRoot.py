"""
https://www.reddit.com/r/dailyprogrammer/comments/1berjh/040113_challenge_122_easy_sum_them_digits/
"""

num = input("Enter a number: ")
while not num.isdigit():
    print("Please enter an integer")
    num = input("Enter a number: ")
num = int(num)


while num // 10 > 0:
    sum = 0
    tensPlace = 1
    digit = (num // tensPlace) % 10
    while digit > 0:
        sum += digit
        tensPlace *= 10
        digit = (num // tensPlace) % 10
    num = sum

print(sum)
