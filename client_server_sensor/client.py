import socket

host = '192.168.1.15' #insert target ip address or where server.py is running
port = 8840

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))

while True:
    command = 'GET'
    if command == 'GET':
            command = input("what is thy bidding: ")
            s.send(str.encode(command))
    elif command == 'EXIT':
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