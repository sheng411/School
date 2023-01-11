import socket
server_ip = '127.0.0.1'
server_port = 8787
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.connect((server_ip, server_port))
print('Connect server {} successfully'.format(sock.getpeername()))
print('The OS assigned me the address {}'.format(sock.getsockname()))
while(True):
    text = input()  # 使用者輸入訊息字串
    text += '\n'  # 加上換行符號
    data = text.encode('utf-8')
    sock.sendall(data)
    print('Sent data: {}'.format(data))
