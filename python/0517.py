def segment(w,x,y,value):
    segnum=['1111110','0110000','1101101','1111001','0110011','1011011','1011111','1110000','1111111','1110011']
    sv=segnum[value]
    color=['gray','red']
    for i in range(0,7):
        w.itemconfig(item[i],fill=color[int(sv[i])])

from itertools import count
from tkinter import *
import time
root=Tk()
w = Canvas(root, width=200, height=200,bg='black')
w.pack()
item=[0]*7
sv='1111110'
color=['gray','red']
x=80
y=30
item[0]=w.create_oval(x   ,     y, x+52, y+10 , fill=color[int(sv[0])])
item[1]=w.create_oval(x+50,  y+ 5, x+60, y+60 , fill=color[int(sv[1])])
item[2]=w.create_oval(x+50, y+ 70, x+60, y+125, fill=color[int(sv[2])])
item[3]=w.create_oval(x   , y+120, x+52, y+130, fill=color[int(sv[3])])
item[4]=w.create_oval(x-10, y+ 70,   x,  y+125, fill=color[int(sv[4])])
item[5]=w.create_oval(x-10, y+  5,   x,  y+60 , fill=color[int(sv[5])])
item[6]=w.create_oval(x   , y+ 60, x+52, y+70 , fill=color[int(sv[6])])

count=0
while True:
    #print(count)
    segment(w,80,30,count)
    count=(count+1)%10
    time.sleep(1)
    root.update()
root.mainloop()