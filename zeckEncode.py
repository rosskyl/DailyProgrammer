"""
https://www.reddit.com/r/dailyprogrammer/comments/55zdxx/20161005_challenge_286_intermediate_zeckendorf/
"""

def zeckEncode(num):
    solution = []
    while num > zeckEncode.fibs[-1]:
        zeckEncode.fibs.append(zeckEncode.fibs[-1] + zeckEncode.fibs[-2])
    index = -1
    while num > 0:
        if num >= zeckEncode.fibs[index]:
            num -= zeckEncode.fibs[index]
            solution.append(zeckEncode.fibs[index])
        index -= 1
    return solution

zeckEncode.fibs = [1, 1] # static function variable


print(zeckEncode(3))
print(zeckEncode(4))
print(zeckEncode(100))
print(zeckEncode(30))

print(zeckEncode(5))
print(zeckEncode(120))
print(zeckEncode(34))
print(zeckEncode(88))
print(zeckEncode(90))
print(zeckEncode(320))