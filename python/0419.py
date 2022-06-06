from tkinter import *
import math
import time

n=20000
dx=3.14159/n
sum=0
for i in range(0,n):
    sum+=math.sin(i*dx+dx)*dx
print(sum)

root=Tk()
#root.geometry("400X400")   跟下一行一樣
Ca=Canvas(root,width=400,height=400,bg="green")
Ca.pack()

Ca.create_line(0,200,400,200,fill="black",width=3)
Ca.create_line(20,0,20,400,fill="black",width=3)
print(sum)

y=200-3
dx=math.pi/(400-23)
th=0
for x in range(23,400):
    th+=dx
    y1=y-100*math.sin(th)
    Ca.create_line(x,y,x,y1,fill="yellow",width=3)
    time.sleep(0.1) #數字越小越快
    root.update()

root.mainloop()
