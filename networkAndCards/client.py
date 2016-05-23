import socket


s = socket.socket()


host = "192.168.88.129"
port = 2100

s.connect((host, port))

command = input()
while command != "exit":
    command = command.encode(encoding="UTF-8")
    s.send(command)
    print(s.recv(1024).decode(encoding="UTF-8"))
    command = input()

s.send(b"exit")

s.close()