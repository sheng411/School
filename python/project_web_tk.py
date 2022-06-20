from tkinter import *

titles_num=50
fre=0
cont=''

#tkinter

window=Tk()
window.title("ETtoday熱門新聞")
c=Canvas(window,width=500,height=500,bg="MidnightBlue")

def bt_brk():
    global fre
    if int(infre.get())>titles_num:
        fre=titles_num

#fre
myfrebel=Label(window,text="所需新聞量:")
infre=StringVar()
myfre=Entry(window,textvariable=infre)

#cont
mycontbel=Label(window,text="是否顯示部分內文(y/n):")
incont=str(StringVar())
mycont=Entry(window,textvariable=incont)


#contt=Checkbutton(text="是否顯示部分內文",state="normal")   #disabled 禁用
gobtn=Button(window,width=10,height=1,text="GO",command=bt_brk)



myfrebel.grid(row=0, column=0)
myfre.grid(row=0, column=1)
mycont.grid(row=1, column=0)

#contt.pack()
gobtn.pack()
c.pack()
window.mainloop()
