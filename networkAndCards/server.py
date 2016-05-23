import socket

print("Starting server")


s = socket.socket()

host = socket.gethostname()
port = 2100

s.bind((host, port))


s.listen(2)
while True:
    conn, address = s.accept()
    print("Connection from", address)
    conn.send("Hello")
    conn.close()