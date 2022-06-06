from tkinter import *
from random import *
import threading
import time
import winsound

table=[261,293,329,349,392,440,494,548,602]

def job():
    global go; global right; global error;
    while True:
         if go==-1:
                i=randint(0,8)
                texta[i].place(x=i*w/9+10,y=y[i])
                y[i]=y[i]+30
                if y[i]>=650:
                      y[i]=50
                      texta[i].place(x=i*w/9+10,y=y[i])
                      nu=randint(0,25)
                      texta[i].config(text=alpha[nu])
                      error=error+1
                      string="Err="+str(error)
                      errnum.config(text=string)
                #time.sleep(0.2)  
                winsound.Beep(table[i], 200)
                if right>=30:
                   go=0   

def buttonpress():
    global go; global right; global error
    go=~go
    right=0
    error=0
    string="Err="+str(error)
    errnum.config(text=string)
    string1="Hit="+str(right)
    num1.config(text=string1)
    for i in range(0,9):
        y[i] = 50

def keypress(event):          #輸入
     if go==-1:
      global error; global right
      print(event.char)
      sw=0
      lo=0
      for i in range(0,9):
        if texta[i].cget("text")==event.char:
            if sw==0:
               lo=i
               sw=1
            if y[lo] <= y[i]:
                lo=i
      if sw==0:
            error=error+1
            string="Err="+str(error)
            errnum.config(text=string)
      else:
            right=right+1
            winsound.Beep(ord(event.char)*10+1000, 35)
            string1="Hit="+str(right)
            num1.config(text=string1)
            y[lo]=50
            texta[lo].place(x=lo*w/9+10,y=y[lo])
            texta[lo].config(text=alpha[randint(0,25)])

def d(event):
    global w, h
    w1 = root.winfo_width()
    h1 = root.winfo_height()
    can.config(width=w1, height=h1)
    can.coords(line, 0, h1-70, w1, h1-70)
    button.place(x=w1 / 2 - 50, y=0)
    num1.place(x=w1 - 100, y=10)
    w = w1; h = h1

root = Tk()
root.title('Python TypeWriter Game')
root.geometry("800x800")

root.update()
w = root.winfo_width()
h = root.winfo_height()

can = Canvas(root, width=w, height=h, bg='green')
can.pack()

line=can.create_line(0, h-70, w, h-70, fill="red", width=10)


button = Button(can, text='Click Go', command=buttonpress)
button.place(x=w/2-50, y=0)

errnum=Label(can,font=('times', 20, 'bold'),bg='green', fg='black', text="Err=0")
errnum.pack()
errnum.place(x=10,y=10)

num1=Label(can,font=('times', 20, 'bold'),bg='green', fg='black', text="Hit=0")
num1.pack()
num1.place(x=w-100, y=10)

error=0; right=0; go=0

root.bind("<Key>", keypress)
root.bind('<Configure>', d)

alpha="abcdefghijklmnopqrstuvwxyz"

texta=[0]*9; y=[0]*9

for i in range(0,9):
      texta[i]=Label(can, font=('times', 50, 'bold'), bg='green', fg='black', text=alpha[i])

for i in range(0,9):
      y[i]=50

t = threading.Thread(target = job)
t.start()
      
root.mainloop()
