"""
From 4/29/2015
https://www.reddit.com/r/dailyprogrammer/comments/34asls/20150429_challenge_212_intermediate_animal_guess/
"""

class Animal:
    def __init__(self, tmpName, tmpQuestions):
        self.__name = tmpName
        self.__questions = tmpQuestions
    def getName(self):
        return self.__name
    def getQuestions(self):
        return self.__questions
    def __str__(self):
        return self.__name

class Game:
    def __init__(self):
        self.__animals = []
        self.__questions = []
    def readFile(self):
        try:
            file = open("animal.txt","r")
            lines = file.readlines()
            file.close()
            lineNum = 0
            while lineNum < len(lines):
                if lines[lineNum] == "\n":
                    lineNum += 1
                    continue
                lines[lineNum] = lines[lineNum].rstrip().split(": ")
                if lines[lineNum][0] == "animal":
                    name = lines[lineNum][1]
                    lineNum += 1
                    lines[lineNum] = lines[lineNum].rstrip().split(": ")
                    questions = lines[lineNum][1].split(", ")
                    self.__animals.append(Animal(name, questions))
                elif lines[lineNum][0] == "question":
                    self.__questions.append(lines[lineNum][1])
                lineNum += 1
        except Exception as e:
            print("Error opening the file")
            print(e)
    def writeFile(self):
        file = open("animal.txt", "w")
        for animal in self.__animals:
            file.write("animal: " + str(animal) + "\n")
            yes = ""
            for num in animal.getQuestions():
                yes = yes + ", " + str(num)
            yes = yes[2:]
            file.write("yesQuestions: " + yes + "\n\n")
        for question in self.__questions:
            file.write("question: " + question + "\n\n")

        file.close()
    def saveFile(self):
        pass
    def askQuestion(self, questionNum):
        pass
    def checkAnimal(self, yesQuestions):
        for animal in self.__animals:
            if yesQuestions == animal.getQuestions():
                return True
        return False
    def addAnimal(self, yesQuestions):
        pass
    def startGame(self):
        pass


game = Game()
game.readFile()
game.writeFile()