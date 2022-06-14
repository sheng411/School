import urllib.request as req
import bs4
from tkinter import *
import math
import time

#爬蟲
new=[]
url="https://www.ettoday.net/news/realtime-hot.htm" #ETtoday即時人氣
request=req.Request(url,headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36"
})
with req.urlopen(request) as response:
    aa_data=response.read().decode("utf-8")
root=bs4.BeautifulSoup(aa_data,"html.parser")

titles=root.find("p",class_="summary")
titles1=root.find_all("div",class_="piece clearfix")
titless=titles.string
a=1
fre=int(input("所需新聞量:"))
for tit in titles1:
    if tit.h3.a!=None and a<=fre:
        print(a,".",tit.h3.a.string)
        a+=1
        new=tit.append
        #print(new)


#tkinter
window=Tk()
window.title("")

