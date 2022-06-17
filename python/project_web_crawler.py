import urllib.request as req
import bs4
from tkinter import *
import time
import os

#優化四

#時間
tm=time.localtime()
print(tm)   #查看所有時間

#爬蟲
#new=[]
url="https://www.ettoday.net/news/realtime-hot.htm" #ETtoday即時人氣
print("ETtoday新聞網址:",url)
request=req.Request(url,headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36"
})
with req.urlopen(request) as response:
    aa_data=response.read().decode("utf-8")
root=bs4.BeautifulSoup(aa_data,"html.parser")
titles=root.find_all("div",class_="piece clearfix")
titles_num=len(root.find_all("em",class_="number"))
print("總報導數:",titles_num,"\n")

fre=int(input("所需新聞量:"))
if fre>titles_num:             #輸入數大於新聞量則使用新聞最大量
    fre=titles_num

ok=0
while(ok==0):
    cont=str(input("是否顯示部分內文(y/n):"))
    if cont=='y' or cont=='Y' or cont=='n' or cont=='N':
        ok+=1
    else:
        print("不符合規定，請重新輸入！\n")

print("*******************")

a=1
for tit in titles:
    if tit.h3.a!=None and a<=fre:
        if(a<10):
            print(" "+str(a),".",tit.h3.a.string+"---"+tit.span.string)
        else:
            print(a,".",tit.h3.a.string,"---",tit.span.string)
        if cont=='y' or cont=='Y':
            print(tit.p.string,"\n")
        a+=1
        #new=tit.append
        #print(new)
print("*******************")
print(str(tm.tm_mon)+"/"+str(tm.tm_mday)+"---"+str(tm.tm_hour)+":"+str(tm.tm_min)+":"+str(tm.tm_sec))

#tkinter
'''
window=Tk()
window.title("ETtoday熱門新聞")
c=Canvas(window,width=500,height=500,bg="MidnightBlue")
c.pack()


window.mainloop()
'''
os.system("pause")  #執行完等待