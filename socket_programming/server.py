# This is the code for the server
# Import the important libraries
import socket, cv2, pickle, struct, imutils

#Create our socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host_name = socket.gethostname()
host_ip = socket.gethostbyname(host_name)
print('Host IP:', host_ip)

port = 1234
socket_address = (host_ip, port)

# Then we bind the socket
server_socket.bind(socket_address)

# Now we listen to the socket
server_socket.listen(5)
print("Listening at:", socket_address)

# Then we accept the socket
while True:
    client_socket, addr = server_socket.accept()
    print('Got Connection from:', addr)
    if client_socket:
        vid = cv2.VideoCapture(0)
        while(vid.isOpened()):
            img, frame = vid.read()
            a = pickle.dumps(frame)
            message = struct.pack("Q",len(a))+a
            client_socket.sendall(message)
        #    cv2.imshow('TRANSMITTING VIDEO',frame)
        #    if cv2.waitKey(1) & 0xFF == ord('q'):
        #            vid.release()
        #            client_socket.close()
        #            break
