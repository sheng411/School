import urllib.request as req
import bs4
from tkinter import *
import math
import time

#時間
tm=time.localtime()
print(tm)   #查看所有時間

#爬蟲
new=[]
url="https://www.ettoday.net/news/realtime-hot.htm" #ETtoday即時人氣
request=req.Request(url,headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36"
})
with req.urlopen(request) as response:
    aa_data=response.read().decode("utf-8")
root=bs4.BeautifulSoup(aa_data,"html.parser")
titles=root.find_all("div",class_="piece clearfix")
titles_num=len(root.find_all("em",class_="number"))
print(titles_num)


fre=int(input("所需新聞量:"))   #用輸入改掉
if fre>titles_num:             #輸入數大於新聞量則使用新聞最大量
    fre=titles_num

a=1
for tit in titles:
    if tit.h3.a!=None and a<=fre:
        print(a,".",tit.h3.a.string,"---",tit.span.string)
        a+=1
        #new=tit.append
        #print(new)


#tkinter
window=Tk()
window.title("ETtoday熱門新聞")
c=Canvas(window,width=500,height=500,bg="MidnightBlue") #紫色
c.pack()


#window.mainloop()