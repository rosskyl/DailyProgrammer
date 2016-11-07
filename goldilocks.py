"""
https://www.reddit.com/r/dailyprogrammer/comments/5bn0b7/20161107_challenge_291_easy_goldilocks_bear/
"""

def checkAllSeats(inputs):
    seats = inputs.split("\n")

    for i in range(len(seats)):
        seats[i] = seats[i].split()
        for j in range(len(seats[i])):
            seats[i][j] = int(seats[i][j])

    gl = seats.pop(0)

    validSeats = []
    for i in range(len(seats)):
        if gl[0] <= seats[i][0] and gl[1] >= seats[i][1]:
            validSeats.append(i+1)

    return validSeats

sample = """100 80
30 50
130 75
90 60
150 85
120 70
200 200
110 100"""

print("Sample output:",checkAllSeats(sample))

challenge = """100 120
297 90
66 110
257 113
276 191
280 129
219 163
254 193
86 153
206 147
71 137
104 40
238 127
52 146
129 197
144 59
157 124
210 59
11 54
268 119
261 121
12 189
186 108
174 21
77 18
54 90
174 52
16 129
59 181
290 123
248 132"""

print("Challenge output:",checkAllSeats(challenge))