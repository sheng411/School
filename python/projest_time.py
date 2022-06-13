from tkinter import *
import math
import time

def points():
    for i in range(1,13):
        x=250+130*math.sin(2*math.pi*i/12)
        y=250-130*math.cos(2*math.pi*i/12)
        canvas.create_text(x,y,text=i,width=0)      #顯示1~12


def createline(radius,line_width,rad):
    global llist,i,o
    llist=[]
    x=250+radius*math.sin(rad)
    y=250-radius*math.cos(rad)
    print("x",x,"y",y)
    i=canvas.create_line(250,250,x,y,width=line_width)
    o=canvas.create_oval(245,245,255,255,fill="white",width=2)
    llist.append(i)


root = Tk()
root.title("派去ㄟ時鐘")    #標題名稱
root.resizable(0,0)
canvas = Canvas(root,width=500,height=600,bg="BlueViolet")  #底色

canvas.pack()
canvas.create_oval(105,105,395,395,fill="Aqua",width=3)   #圓


points()
while 1:
    tm=time.localtime()#    取得本機時間
    t=time.asctime(tm)#     將時間轉換
    t_hour=0
    if tm.tm_hour<=12:
        t_hour=tm.tm_hour
    else:
        t_hour=tm.tm_hour-12
    radh=2*math.pi*(t_hour+tm.tm_min/60)/12     #時計算
    radm=2*math.pi*(tm.tm_min+tm.tm_sec/60)/60  #分計算
    rads=2*math.pi*tm.tm_sec/60                 #秒計算
    print("tm:",tm," t:",t)
    createline(40,5,radh)   #長度,粗度,計算值
    createline(80,3,radm)
    createline(120,1,rads)
    print(radh," ",radm," ",rads)   #test
    l=canvas.create_text(250,450,text=t,fill="white")   #下方顯示字
    root.update()   #若有重複則忽略
    time.sleep(1)   #休1s
    for item in llist:
        canvas.delete(item)
        canvas.delete(l)
        print("*****",item," ",l)
        root.update()

mainloop()