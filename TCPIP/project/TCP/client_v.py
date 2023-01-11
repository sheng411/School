import threading
import socket
import os
import json
import time

BUFFER_SIZE = 4096
remote_addr = ('127.0.0.1',6000) # Remote server address

# 請使用者輸入他的nickname
nickname = input('請輸入你留言時的綽號/別名：')

# 建立TCP socket，連線到Server
sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.connect(remote_addr)
print('Connect server {} successfully'.format(sock.getpeername()))
print('The OS assigned me the address {}'.format(sock.getsockname()))

# 準備Enter Request訊息的dict物件
msgdict = {
    "type": 1,
    "nickname": nickname
}

# 轉成JSON字串，尾端加上換行符號「\n」，再轉成bytes
data = (json.dumps(msgdict)+'\n').encode('utf-8')
print(data)

# 將Enter Request送到Server
sock.sendall(data)

# 建立一個socket對應的檔案物件
f = sock.makefile(encoding='utf-8')

# 等待並接收Server傳回來的訊息，若為Enter Response則繼續下一步，否則繼續等待
try:
    text = f.readline()
    msgdict = json.loads(text)
    if msgdict['type'] == 2:
        print('成功進入伺服器!!!')
    else:
        print('進入伺服器失敗!!!')
        os._exit(0)
except (ConnectionAbortedError, ConnectionResetError):
    print('伺服器斷線，結束程式!!!')
    sock.close()
    os._exit(0)
    
# 執行緒send_message()：取得使用者的輸入訊息字串，傳送到Server
def send_message():
    print('執行緒send_message開始')
    # 執行緒send_message()：取得使用者的輸入訊息字串，傳送到Server
    while(True):
        # 取得使用者輸入的聊天訊息
        msgtext = input('請輸入聊天訊息：')
        if msgtext[:2] == '%%' and msgtext[-2:] == '%%':
            if msgtext[2:7] == 'Leave': # 若為離開聊天室的指令
                # 建立Leave Request訊息的dict物件
                msgdict = {
                    "type": 6,
                    "nickname": nickname
                }
        else:
            # 建立Message Request訊息的dict物件
            msgdict = {
                "type": 3,
                "nickname": nickname,
                "message": msgtext
            }
        # 將訊息dict物件轉成JSON字串，再轉成bytes
        msgdata = (json.dumps(msgdict)+'\n').encode('utf-8')
        #print(msgdata) # 除錯用
        # 將Request訊息送到Server
        sock.sendall(msgdata)
        if (msgdict['type']==6):
            print("Leave") # 除錯用
            os._exit(0)
    
# 執行緒recv_message()：接收來自Server傳來的訊息，
# 依據訊息中的type欄位所代表的訊息型態作對應的處理    
def recv_message():
    print('執行緒recv_messag開始')
    while(True):
        # 接收來自Server傳來的訊息
        text = f.readline()
        msgdict = json.loads(text)
        # 依照type欄位的值做對應的動作
        ## Message Response(4)：這是之前Message Request的回應訊息
        if msgdict['type'] == 4:
            # 不需做任何處理
            #print('Get Message Response from server.') # 除錯用
            pass 
        ## Message Transfer(5)：這是其他Client所發布的訊息
        if msgdict['type'] == 5:
            #print('Get Message Transfer from server.') # 除錯用
            # 以「nickname: message content」的格式印出
            print("\n",msgdict['nickname'] + '--> ' + msgdict['message'])

    
# 建立並啟用傳送訊息與接收訊息執行緒
thread_client = threading.Thread(target=send_message)
thread_server = threading.Thread(target=recv_message)
thread_client.start()
thread_server.start()
thread_server.join()
thread_client.join()
print('Done.')
