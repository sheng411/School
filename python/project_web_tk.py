from tkinter import *
import urllib.request as req
import bs4
import time

#優化1

#時間
tm=time.localtime()

#爬蟲

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


#tkinter


window=Tk()
var=BooleanVar()
window.title("ETtoday熱門新聞")
c=Canvas(window,width=550,height=550,bg="BlueViolet")   #MidnightBlue


def bt_brk():
    global fre
    if infre.get()=='':
        tt.insert(END,"Now time:"+str(tm.tm_mon)+"/"+str(tm.tm_mday)+"---"+str(tm.tm_hour)+":"+str(tm.tm_min)+":"+str(tm.tm_sec))
        tt.insert(END,"\n404 Error,you did not enter the number!")
        tt.insert(INSERT,"\n\n")
    if int(infre.get())>titles_num:
        fre=titles_num
    else:
        fre=int(infre.get())
    tt.delete("1.0","end")
    tt.insert(END,"Now time:"+str(tm.tm_mon)+"/"+str(tm.tm_mday)+"---"+str(tm.tm_hour)+":"+str(tm.tm_min)+":"+str(tm.tm_sec))
    tt.insert(INSERT,"\n\n")
    a=1
    for tit in titles:
        if tit.h3.a!=None and a<=fre:
            if a<=10:
                #print(fre)
                #print(var.get())
                tt.insert(END," "+str(a)+"."+str(tit.h3.a.string)+"--"+str(tit.span.string))
                tt.insert(INSERT,"\n\n")
            else:
                tt.insert(END,str(a)+"."+str(tit.h3.a.string)+"--"+str(tit.span.string))
                tt.insert(INSERT,"\n\n")
            if var.get()==1:
                tt.insert(END,tit.p.string)
                tt.insert(INSERT,"\n---------------------------------------------------------------\n\n")
            a+=1

def de():
    global tm
    tt.delete("1.0","end")
    tm=time.localtime()

#fre
myfrebel=Label(window,text="所需新聞量:",width=33,font=10)
infre=StringVar()
myfre=Entry(window,width=10,textvariable=infre)

#cont
contt=Checkbutton(text="是否顯示部分內文",variable=var,state="normal",font=10)   #disabled 禁用

#go
gobtn=Button(window,width=10,height=1,text="GO",command=bt_brk,bg="Cyan",fg="black")


#delete
debtn=Button(window,width=10,height=1,text="DELETE",command=de,bg="red")

#output
tt=Text(window,height=33,width=65,font=8)


myfrebel.grid(row=0,column=0,sticky='w')
myfre.grid(row=0,column=0)
contt.grid(row=1,column=0,sticky='we')
gobtn.grid(row=2,column=0)
debtn.grid(row=2,column=0,sticky='e')
tt.grid(row=3,column=0)
c.grid(row=3,column=0,sticky='w')

window.mainloop()