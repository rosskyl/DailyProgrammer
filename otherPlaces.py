"""
https://www.reddit.com/r/dailyprogrammer/comments/4jom3a/20160516_challenge_267_easy_all_the_places_your/
"""

def outputOtherPlaces(place, end=100):
    strPlace = str(place)
    for i in range(1, end+1):
        i = str(i)
        if i != strPlace:
            if i[0] == '1' and len(i) == 2:
                print(i + "th")
            elif i[-1] == '1':
                print(i + "st")
            elif i[-1] == '2':
                print(i + "nd")
            elif i[-1] == '3':
                print(i + "rd")
            else:
                print(i + "th")


outputOtherPlaces(4, 30)