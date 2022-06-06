from tkinter import *
import time
import math
import random

def clock():
    global sw, step
    sw=~sw
    print(abs(sw)) 
    for i in range(len(paclocxy)):
        locxy=paclocxy[i]
        pac=pacman[i]
        coord = locxy[0]-r, locxy[1]-r, locxy[0]+r, locxy[1]+r
        if abs(sw)==1:
            c.coords(pac, coord)
            c.itemconfig(pac, start=0, extent=359)
        else:
            c.itemconfig(pac, start=30, extent=300)
            c.coords(pacman, coord)
        if locxy[0]+30 >=400:
            step[i]=step[i]*-1
        if locxy[0] <30:
            step[i]=step[i]*-1 
        n=random.randint(1,7)
        locxy[0]=locxy[0]+n*step[i]
    root.after(250,clock)
    
root = Tk()
c=Canvas(root, width=400, height=400, bg="green")
c.pack()

r=30;sw=0;step=[1,1];x=30;y=30
paclocxy=[[x,y],[x+10,100]]
pacman=[0]*2
locxy=paclocxy[0]
coord=locxy[0]-r, locxy[1]-r, locxy[0]+r, locxy[1]+r
pacman[0]=c.create_arc(coord,start=30,extent=300,fill="yellow",width=1)

locxy=paclocxy[1]
coord=locxy[0]-r, locxy[1]-r, locxy[0]+r, locxy[1]+r
pacman[1]=c.create_arc(coord,start=30,extent=300,fill="yellow",width=1)

clock()
root.mainloop()