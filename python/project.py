from logging import root
from tkinter import *
import time
import math
import random


#Tkinter code
root=Tk()
root.title("welcome to my project")    #標題名稱
c=Canvas(root, width=800, height=600, bg="white")
b1=Button(root,text='click me')
b1.pack()

c.pack()
root.mainloop()
print (time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
