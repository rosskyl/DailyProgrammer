"""
https://www.reddit.com/r/dailyprogrammer/comments/3r7wxz/20151102_challenge_239_easy_a_game_of_threes/
"""

num = input("Enter the starting number: ")

while not num.isdigit():
    print("Enter an integer")
    num = input("Enter the starting number: ")

num = int(num)
while num > 1:
    remainder = num % 3
    if remainder == 0:
        print(num, 0)
        num = num // 3
    elif remainder == 1:
        print(num, -1)
        num = (num - 1) // 3
    elif remainder == 2:
        print(num, 1)
        num = (num + 1) //3
print(num)
