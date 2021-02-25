import socket

host = '' #insert target ip address or where server.py is running
port = 9000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))

while True:
    command = input("what is thy bidding: ")
    if command == 'EXIT':
        #send exit signal to other end
        s.send(str.encode(command))
        break
    elif command == 'KILL':
        s.send(str.encode(command))
        break
    s.send(str.encode(command))
    reply = s.recv(1024)
    print(reply.decode('utf-8'))

s.close()