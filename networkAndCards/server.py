import socket

def connection(conn, address):
    command = conn.recv(1024)
    while command != b'exit':
        print(address,command)
        conn.send(b"Command successfully recieved")
        command = conn.recv(1024)
    conn.close()




print("Starting server")


s = socket.socket()

host = socket.gethostname()
port = 2100

s.bind((host, port))


s.listen(2)
while True:
    conn, address = s.accept()
    print("Connection from", address)
    connection(conn, address)