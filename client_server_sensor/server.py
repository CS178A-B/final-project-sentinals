import socket

host = ''
port = 8840

storedValue = "hello there"

def setupServer():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("sever socket has been made")
    
    try:
        s.bind((host, port))
    except socket.error as msg:
        print(msg)
    print("socket bind complete")
    return s

def setupConnection():
    s.listen(1) #allow one conn at a time
    conn, address = s.accept()
    print("connected to: " + address[0] + ":" + str(address[1]))

s = setupServer()

def GET():
    reply = storedValue
    return reply

def REPEAT(dataMessage):
    reply = dataMessage[1]
    return reply

def dataTransfer(conn):
    #loop that sends/recvs sata until told not to
    while True:
        #recv data
        data = conn.recv(1024) #1024 = buffer size
        data = data.decode('utf-8') #deal with strings
        dataMessage = data.split(' ', 1) #split data st you sep command from args
        command = dataMessage[0]
        if command == 'GET':
            reply = GET()
        elif command == 'REPEAT':
            reply = REPEAT(dataMessage)
        elif command == 'EXIT':
            print("sayonara")
            break
        elif command == 'KILL':
            print("sever has been terminated. hasta la vista")
            s.close()
            break
        else:
            reply = 'unknown cmd'

        #send reply back to client
        conn.sendall(str.encode(reply))
        print("data has been sent")
    conn.close()

while True:
    try:
        conn = setupConnection()
        dataTransfer(conn)
    except:
        break