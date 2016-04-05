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

def findMagicSquare(grid):
    """
    Precondition: grid is a rectangle with the number of columns 1 more than the number of rows
    """
    row = []
    sums = sum(grid[0])
    for i in range(len(grid[0])):
        tmpSum = 0
        for j in range(len(grid)):
            tmpSum += grid[j][i]
        row.append(sums - tmpSum)
    tmpGrid = grid[:]
    tmpGrid.append(row)
    return isMagicSquare(tmpGrid)








grid1 = [[8, 1, 6], [3, 5, 7], [4, 9, 2]]
print(isMagicSquare(grid1))

grid2 = [[8, 1, 6], [3, 5, 7], [4, 9, 2]]
print(isMagicSquare(grid2))

grid3 = [[3, 5, 7], [8, 1, 6], [4, 9, 2]]
print(isMagicSquare(grid3))

grid4 = [[8, 1, 6], [3, 5, 7]]
print(findMagicSquare(grid4))

grid5 = [[3, 5, 7], [8, 1, 6]]
print(findMagicSquare(grid5))