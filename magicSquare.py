"""
Daily Programmer from 4/4/2016
https://www.reddit.com/r/dailyprogrammer/comments/4dccix/20160404_challenge_261_easy_verifying_3x3_magic/
"""



def isMagicSquare(grid):
    """
    Precondition: grid is a square so has the same number of rows and columns
    """
    sums = sum(grid[0])
    for i in range(len(grid)):
        if sum(grid[i]) != sums:
            return False
        tmpSum = 0
        for j in range(len(grid)):
            tmpSum += grid[i][j]
        if tmpSum != sums:
            return False
    tmpSum = 0
    for i in range(len(grid)):
        tmpSum += grid[i][i]
    if tmpSum != sums:
        return False

    tmpSum = 0
    for i in range(len(grid)):
        tmpSum += grid[i][len(grid)-i-1]
    if tmpSum != sums:
        return False
    return True








grid1 = [[8, 1, 6], [3, 5, 7], [4, 9, 2]]
print(isMagicSquare(grid1))

grid2 = [[8, 1, 6], [3, 5, 7], [4, 9, 2]]
print(isMagicSquare(grid2))

grid3 = [[3, 5, 7], [8, 1, 6], [4, 9, 2]]
print(isMagicSquare(grid3))