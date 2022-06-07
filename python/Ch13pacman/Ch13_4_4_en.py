from tkinter import *
import threading
import time
import random

def rightKey(event):
    global pacd; pacd=0
def downKey(event):
    global pacd; pacd=1
def leftKey(event):
    global pacd; pacd=2
def upKey(event):
    global pacd; pacd=3

def drawmap(img):
    for my in range(0,12):
        for mx in range(0,20):
            a[my*20+mx] = w.create_image(mx*30,my*30, anchor=NW, image=img[map[my][mx]])

def drawghost(xy,color,gh):
    #-draw ghost
    x=xy[0]*30; y=xy[1]*30
    gh[0]=w.create_arc(x+3,y,x+30-3,y+60, start=0, extent=180, fill=color, width=1) #-body
    gh[1]=w.create_oval(x+6,y+9,x+14,y+17, fill="white", width=1)
    gh[2]=w.create_oval(x+16,y+9,x+24,y+17, fill="white", width=1)
    gh[3]=w.create_oval(x+9, y+12,x+11,y+14, fill="black", width=2) #-eyes
    gh[4]=w.create_oval(x+19,y+12,x+21,y+14, fill="black", width=2)
    gh[5]=w.create_arc(x+13,y+26,x+17,y+34, start=0, extent=180, fill="black", width=1)#-leg
    gh[6]=w.create_arc(x+6, y+26,x+10,y+34, start=0, extent=180, fill="black", width=1)
    gh[7]=w.create_arc(x+20,y+26,x+24,y+34, start=0, extent=180, fill="black", width=1)

def drawpac(xy,color,pac):
        x=xy[0]*30; y=xy[1]*30;
        pac[0]=w.create_arc(x,y,x+30,y+30, start=30, extent=300, fill="yellow", width=3)

def Ghost(xy,di1,gh):
    ex=[1,0,-1,0]; ey=[0,1,0,-1];iv=[2,3,0,1];dl=[0,0,0,0] 
    od1=iv[di1[0]]; global sw
    if map[xy[1]][xy[0]+1]%2==0:  dl[0]=1 
    if map[xy[1]+1][xy[0]]%2==0:  dl[1]=1 
    if map[xy[1]][xy[0]-1]%2==0:  dl[2]=1 
    if map[xy[1]-1][xy[0]]%2==0:  dl[3]=1
    while True:
        count=dl[0]+dl[1]+dl[2]+dl[3];
        if count==1: di1[0]=od1; break;           
        ch=random.randint(0,3)
        if (dl[ch]==1 and ch!=od1): di1[0]=ch; break;           
    if di1[0]==0: xy[0]=xy[0]+1   
    if di1[0]==1: xy[1]=xy[1]+1
    if di1[0]==2: xy[0]=xy[0]-1 
    if di1[0]==3: xy[1]=xy[1]-1
    x=xy[0]*30; y=xy[1]*30
    w.coords(gh[0],x+3,y,x+30-3,y+60)  #body
    w.coords(gh[1],x+6,y+9,x+14,y+17)  #left circle
    w.coords(gh[2],x+16,y+9,x+24,y+17) #right circle  
    w.coords(gh[3],x+9+ex[di1[0]], y+12+ey[di1[0]],x+11+ex[di1[0]],y+14+ey[di1[0]]) #left  eye
    w.coords(gh[4],x+19+ex[di1[0]],y+12+ey[di1[0]],x+21+ex[di1[0]],y+14+ey[di1[0]]) #right eye
    w.coords(gh[5],x+abs(sw*1)+13,y+26,x+abs(sw*1)+17,y+34) #leg
    w.coords(gh[6],x+abs(sw*1)+6, y+26,x+abs(sw*1)+10,y+34) #leg
    w.coords(gh[7],x+abs(sw*1)+20,y+26,x+abs(sw*1)+24,y+34) #leg
        
def pacman(xy,di,pac):
    global sw; pacd;
    global score 
    global flag
    pstart = [30,0,-60,-90,150,180,60,90]; pexten = [300,359,300,359,-300,-359,-300,-359] 
    w.itemconfig(a[xy[1]*20+xy[0]], image=img[map[xy[1]][xy[0]]])
    if pacd==0 and map[xy[1]][xy[0]+1]%2==0: xy[0]=xy[0]+1; di[0]=0;  
    if pacd==1 and map[xy[1]+1][xy[0]]%2==0: xy[1]=xy[1]+1; di[0]=1;  
    if pacd==2 and map[xy[1]][xy[0]-1]%2==0: xy[0]=xy[0]-1; di[0]=2;  
    if pacd==3 and map[xy[1]-1][xy[0]]%2==0: xy[1]=xy[1]-1; di[0]=3;
    if (map[xy[1]][xy[0]]==0):
        map[xy[1]][xy[0]]=2
        score= score+1
        string="分數="+str(score)
        w.itemconfig(score1,text=string)
        if score==121:
            w.create_text(300,180,fill="blue",font="Times 35 italic bold",text="Your winner")
            flag=0        
        
    x=xy[0]*30; y=xy[1]*30;
    w.coords(pac[0],x,y,x+30,y+30)  
    w.itemconfig(pac[0], start=pstart[di[0]*2+abs(sw)], extent=pexten[di[0]*2+abs(sw)])
    sw=~sw  

def draw():
    global score;
    global flag
    #--Pacman positions and directions
    pac = [0]; xy=[1,1];di=[0] 
    #--Ghost red positions and directions
    gh1 = [0]*8; xy1=[1,10];di1=[0]
    #--Ghost blue positions and directions
    gh2 = [0]*8; xy2=[1,10];di2=[0]
    gh3 = [0]*8; xy3=[1,10];di3=[0]   
    drawmap(img)
    drawpac(xy,'yellow',pac)
    drawghost(xy1,'red',gh1)
    drawghost(xy2,'blue',gh2)
    drawghost(xy3,'white',gh3)
    flag = 1
    while flag:
            pacman(xy,di,pac)        
            Ghost(xy1,di1,gh1)
            Ghost(xy2,di2,gh2)
            Ghost(xy3,di3,gh3)
            if (xy[0]==xy1[0] and xy[1]==xy1[1]) or (xy[0]==xy2[0] and xy[1]==xy2[1] or (xy[0]==xy3[0] and xy[1]==xy3[1])) :
                w.create_text(300,180,fill="blue",font="Times 35 italic bold",text="Game Over!"); break;
            time.sleep(0.3)

#main program
sw=0;pacd=4
a = [0]*20*12

map=   [[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],  
        [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1],
        [1,0,1,1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1],
        [1,0,1,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,1],
        [1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1],
        [1,0,1,0,0,0,1,0,1,1,1,1,0,1,1,0,0,0,0,1],
        [1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,0,1],
        [1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1],
        [1,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1],
        [1,0,0,1,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1],
        [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1],
        [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]]

root=Tk()
root.title("PacMan")



score = 0; score1=0; flag=0
w = Canvas(root, width=600, height=390, bg="green")
w.pack()
score1=w.create_text(300,380,fill="white",font="Times 20 italic bold",text="分數="+str(score))
    
img=[]
for i in range(4):
    img.insert(i, PhotoImage(file="map" + str(i) + ".png"))

root.bind('<Left>', leftKey)
root.bind('<Right>', rightKey)
root.bind('<Down>', downKey)
root.bind('<Up>', upKey)

t = threading.Thread(target=draw, args=()).start()

root.mainloop()
