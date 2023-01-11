import socket
import threading
BUFFER_SIZE = 4096
bind_ip = '127.0.0.1'
bind_port = 6000
# 每個連線的執行緒：以無窮迴圈接收從連線進來的訊息並印出
def connection_thread(new_sock, sockname):
    while(True):
        try:
            data = new_sock.recv(BUFFER_SIZE)
            if data == b'':
                print('Remote {} disconnected, close the socket.'.format(sockname))
                new_sock.close()
                break
            text = data.decode('utf-8')
            print('The client at {} says {!r}'.format(sockname, text))    
        except (ConnectionAbortedError, ConnectionResetError):
            print('Remote {} disconnected, close the socket.'.format(sockname))
            new_sock.close()
            break
sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.bind((bind_ip,bind_port))
sock.listen(1)
print('Listening at {}'.format(sock.getsockname()))
while(True):
    print('Waiting to accept a new connection')
    new_sock, sockname = sock.accept()
    print('We have accepted a connection from', sockname)
    print('  Socket name:', new_sock.getsockname())
    print('  Socket peer:', new_sock.getpeername())    
    thread_client = threading.Thread(target=connection_thread, args=(new_sock,sockname))
    thread_client.start()
