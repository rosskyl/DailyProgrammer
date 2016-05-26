import socket

def printCards(cards):
    print("Your cards are: ", end="")
    for card in cards:
        print(card, end=" ")
    print()


s = socket.socket()


host = "192.168.88.129"
port = 2100

s.connect((host, port))

username = input("Enter you username: ")
username = username.encode(encoding="UTF-8")
s.send(username)

cards = []
cards.append(s.recv(1024).decode(encoding="UTF-8"))
cards.append(s.recv(1024).decode(encoding="UTF-8"))

printCards(cards)

command = s.recv(1024).decode(encoding="UTF-8")
while command == "TAKE or PASS":
    response = input(command + ": ")
    while response != "TAKE" or response != "PASS":
        response = input("Please enter TAKE or PASS: ")
    s.send(response.encode(encoding="UTF-8"))
    if response == "TAKE":
        cards.append(s.recv(1024).decode(encoding="UTF-8"))
        printCards(cards)
    command = s.recv(1024).decode(encoding="UTF-8")



s.close()