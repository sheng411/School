import socket,requests  #pip install requests

def get_lanip():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(("8.8.8.8", 80))
    ip = s.getsockname()[0]
    s.close()
    return ip
print("內部IP-->",get_lanip())
#print("-->",socket.gethostbyname(socket.gethostname()))    #另一種寫法


def get_wanip():
    ip = requests.get('https://api.ipify.org').text
    return ip
print("外部IP-->",get_wanip())