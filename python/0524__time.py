import math
from tkinter import *
import time

def clock():
    global sec
    x=200+100*math.sin(sec*3.14159/180)
    y=200-100*math.cos(sec*3.14159/180)
    x1=200+30*math.sin((sec+180)*3.14159/180)
    y1=200-30*math.cos((sec+180)*3.14159/180)
    c.coords(secpoint,200,200,x,y)
    c.coords(secpoint2,200,200,x1,y1)
    c.coords(point1,x-r1,y-r1,x+r1,y+r1)
    sec+=6
    root.after(1000,clock)

    now=time.ctime()        #時間函式
    print("now time:",now)

sw=1
root=Tk()
c=Canvas(root,width=400,height=400,bg="green")
c.pack()
r=5;r1=10;r2=100;sec=0

#c.create_oval(200-5,200-5,200+5,200+5,outline="blue",width=205)
secpoint=c.create_line(200,200,200,100,fill="white",width=3)
secpoint2=c.create_line(200,200,100,100,fill="red",width=5)
point=c.create_oval(200-5,200-5,200+5,200+5,fill="white",width=5)
point1=c.create_oval(200-5,200-5,200+5,200+5,fill="yellow",width=1)


clock()
root.mainloop()
