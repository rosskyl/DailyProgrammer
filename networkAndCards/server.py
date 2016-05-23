import socket
import threading

def connection(conn, address):
    command = conn.recv(1024)
    while command != b'exit':
        command = command.decode(encoding="UTF-8")
        print(address[0],command)
        conn.send(b"Command successfully recieved")
        command = conn.recv(1024)
    conn.close()
    print("Connection closed from", address)




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