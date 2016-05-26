import socket
import threading
"""
def connection(conn, address):
    command = conn.recv(1024)
    while command != b'exit':
        command = command.decode(encoding="UTF-8")
        print(address[0],command)
        conn.send(b"Command successfully recieved")
        command = conn.recv(1024)
    conn.close()
    print("Connection closed from", address)
"""

class Deck:
    def __init__(self):
        self.__newCards = []
        self.__usedCards = []
        for suit in ["Diamonds", "Clubs", "Spades", "Hearts"]:
            for i in range(2,11):
                self.__newCards.append(str(i) + " " + suit)
            for otherCard in ["Ace", "Jack", "Queen", "King"]:
                self.__newCards.append(otherCard + " of " + suit)
    def dealCard(self):
        card = self.__newCards[0]
        del self.__newCards[0]
        self.__usedCards.append(card)
        return card
    def reshuffle(self):
        for card in self.__usedCards:
            self.__newCards.append(card)
        self.__usedCards = []

class Game:
    def __init__(self):
        self.s = socket.socket()
        self.connections = []
        self.currGameConn = []
        self.deck = Deck()

    def startServer(self):
        print("Starting server")
        host = ""
        port = 2100
        s.bind((host, port))

    def stopServer(self):
        for conn in self.connections:
            conn[0].close()
        s.close()

    def listen(self):
        self.s.listen(5)
        while True:
            conn, address = s.accept()
            username = conn.recv(1024).decode(encoding="UTF-8")
            self.connections.append([conn, username, address])

    def dealPlayer(self, player):
        conn = player[0]
        cards = [self.deck.dealCard(), self.deck.dealCard()]
        conn.send(cards[0].encode(encoding="UTF-8"))
        conn.send(cards[1].encode(encoding="UTF-8"))
        #TODO need check for 21 or bust and take cards
        conn.send(b"TAKE or PASS")


    def is21(self, hand):
        pass
    def isBust(self, hand):
        pass


"""
print("Starting server")


s = socket.socket()

host = ""
port = 2100

s.bind((host, port))


s.listen(2)
while True:
    conn, address = s.accept()
    print("Connection from", address)
    connThread = threading.Thread(target=connection, args=(conn, address))
    connThread.start()
"""



"""
connThread = threading.Thread(target=game.listen, args=())
connThread.start()
"""