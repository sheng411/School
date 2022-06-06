from tkinter import *
import time
import math

from matplotlib.pyplot import step

def setup():
    coord[0]=loc[0]-r,loc[1]-r,loc[0]+r,loc[1]+r
    pacman[0]=c.create_arc9coord[0],start=0,extent=359,
    return

def draw():
    global sw,step
    sw=~sw
    print(abs(sw))
    coord[0]=loc[0]-r,loc[1]-r,loc[0]+r,loc[1]+r
    c.coords(pacman[0],coord[0])
    if sw==0:
        c.itemconfig(pacman[0],start=180+30,extent=300)
    else:
        c.itemconfig(pacman[0],start=180,extent=359)
    
    if loc[0]+30>=400:
        step*=-1
    if loc[0]<30:
        step*=-1
    loc[0]=loc[0]+5*step

    root.after(250,draw)

root=Tk()

r=30;loc[30,30];sw=0;step=1
coord=[0]*3
pacman=[0]*3
c=Canvas(root,width=400,height=400,bg="green")
c.pack()

setup()
draw()

root.mainioop()