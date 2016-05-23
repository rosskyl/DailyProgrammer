import socket


s = socket.socket()


host = "192.168.88.129"
port = 2100

s.connect((host, port))

command = input()
while command != "exit":
    s.send(command)
    print(s.recv(1024))
    command = input()

s.send(b"exit")

s.close()