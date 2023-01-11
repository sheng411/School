import threading
import socket
import os
BUFFER_SIZE = 4096
remote_addr = ('127.0.0.1',6000)  # Remote server address
 # Create TCP socket and connect to remote server
sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.connect(remote_addr)
print('Connect server {} successfully'.format(sock.getpeername()))
print('The OS assigned me the address {}'.format(sock.getsockname()))
# 傳送訊息(Client)執行緒
def tcp_client():
    while(True):
        text = input('input message: ')  # 使用者輸入訊息字串
        text += '\n'  # 加上換行符號
        data = text.encode('utf-8')
        sock.sendall(data)
        print('Sent data: {}'.format(data))
# 接收訊息(Server)執行緒
def tcp_server():
    while(True):
        try:
            data = sock.recv(BUFFER_SIZE)
            # 檢查是否收到空的bytes物件，
            # 若為真表示該TCP連結已被中斷，結束程式
            if data == b'':
                pass
                print('遠端已中斷連結，程式結束')
                sock.close()
                os._exit(0)
            # 否則，將收到的bytes物件轉為string並印出
            else:
                text = data.decode('utf-8')
                print('Remote server says {!r}'.format(text))
        except (ConnectionAbortedError, ConnectionResetError): 
            # 在做sendall()傳送資料時，遠端就已經把連線中斷
            # 會在呼叫recv()時發生ConenctionAbortedError或ConnectionResetError例外事件
            # 結束程式
            print('遠端已中斷連結，程式結束')
            sock.close()
            os._exit(0)
# 建立並啟用傳送訊息與接收訊息執行緒
thread_client = threading.Thread(target=tcp_client)
thread_server = threading.Thread(target=tcp_server)
thread_client.start()
thread_server.start()
thread_server.join()
thread_client.join()
print('Done.')
