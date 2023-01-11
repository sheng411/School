import socket
import threading
import json

BUFFER_SIZE = 4096
bind_ip = '127.0.0.1'
bind_port = 6000
client_list = [] # 存放每個Client資訊的清單

# 每個連線的執行緒：以無窮迴圈接收從連線進來的訊息並印出
def connection_thread(new_sock, sockname):
  global client_list
  nickname = ''
  while(True):
    # 建立一個對應到socket的檔案物件，
    # 這樣就可以使用操作檔案的函數來處理socket的讀寫
    f = new_sock.makefile(encoding='utf-8')
    try:
      # 從socket讀取一行
      # (即連續讀取直到換行符號出現為止)
      text = f.readline()
      # 若得到的是空字串，表示Client連線已經中斷，
      # 把此Client從清單中移除，並結束執行緒
      if text == '': 
        if nickname != '':
          new_client = {
            'nickname': nickname,
            'socket': new_sock
          }
          # 若這個Client dict物件存在於client_list清單中，
          # 則將之從client_list中移除
          if new_client in client_list:
            client_list.remove(new_client)
            print('{} at {} 已離線'.format(nickname, sockname)) #除錯用
        new_sock.close()
        break
      # 將訊息內容由JSON字串轉成dict物件
      print('The client at {} says {!r}'.format(sockname, text))
      message = json.loads(text)
      # 依照type欄位的值做對應的動作
      ## Enter Request (1)：有一個新的Client加入
      if message['type'] == 1:
        # 新建一個Client的dict物件來存放它的資訊
        nickname = message['nickname']
        new_client = {
          'nickname': nickname,
          'socket': new_sock
        }
        print('Enter Request: ', new_client) # 除錯用
        # 將新Client的dict物件加入list中
        client_list.append(new_client)
        # 送回Request Response訊息
        msgdict = {
          "type": 2
        }
        # 將訊息從dict轉成字串後在尾端加上換行符號，
        # 然後再轉成bytes物件送出
        data = (json.dumps(msgdict)+'\n').encode('utf-8')
        new_sock.sendall(data)
        print('Send back Enter Response to {} at {}'.format(nickname, sockname)) # 除錯用
      elif message['type'] == 3:
        # 建立一個Message Response (4) 訊息，送回給來源Client
        msgdict = {
            "type": 4
        }
        data = (json.dumps(msgdict)+'\n').encode('utf-8')
        new_sock.sendall(data)
        print('Send back Message Response to', sockname) # 除錯用
        # 建立一個Message Transfer (5)訊息
        msgdict = {
            "type": 5,
            "nickname": message['nickname'], # 來源Client的綽號
            "message": message['message']    # 來源Client的聊天內容
        }
        data = (json.dumps(msgdict)+'\n').encode('utf-8')
        # 針對每一個在client_list中的每一個Client，
        # 轉送Message Transfer訊息給他們 (來源Client除外)
        for client in client_list:
            if client['socket'] != new_sock:
                client['socket'].sendall(data) 
                print('Transfer message to', client['nickname'] ) # 除錯用
    except (ConnectionAbortedError, ConnectionResetError):
      # 把此Client從清單中移除，並結束執行緒
      if nickname != '':
        new_client = {
            'nickname': nickname,
            'socket': new_sock
        }
        ## Message Request (3)：有一個Client送來聊天訊息
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
    print(' Socket name:', new_sock.getsockname())
    print(' Socket peer:', new_sock.getpeername())  
    thread_client = threading.Thread(target=connection_thread, args=(new_sock,sockname))
    thread_client.start()
