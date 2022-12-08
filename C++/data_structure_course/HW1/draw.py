import matplotlib
import matplotlib.pyplot as plt
import numpy as np
data=[]

#讀檔案
#blue is C array,red is vector

path = 'D:/code/School/C++/data_structure_course/read.txt'
f = open(path, 'r')
text = [[""]*15]
j=0
for i in range(15):
    j==0
    for line in f:
        text[i][j]=line.split(" ")
        print(text[i][j],"\n")  #line,
        
        data.append(text[i][j][2])
        j+=1
        

f.close()

nptis=str(text[0][0][5])+" "+str(text[0][0][6])+" -->"+str(text[0][0][3])+","+str(text[0][0][4])
print(nptis)
#b_or_t=int(input("b:0,t:1-->"))

#print(*data,type(data[0]))
'''
sn=int(input("start:"))
en=int(input("end:"))
print('hi',sn,en)


for i in range(sn,en):
    data.append(int(input(i)))
'''
data=list(map(int,data))
p1=[]
for i in range(5):
    p1.append(data[i])
print(p1)

p2=[]
for i in range(5,10):
    p2.append(data[i])
print(p2)


p3=[]
for i in range(10,15):
    p3.append(data[i])
print(p3)

pn=['10','20','30','40','50']

k=0
for f in range(5):
    x1=pn[f]
    y1=p1[f]
    p1n="C array"
    x= np.array(x1)
    y= np.array(y1)
    #plt.bar(x,y)
    plt.plot(x, y, '^-r',label=p1n)


for f in range(5):
    x1=pn[f]
    y1=p2[f]
    p2n="std vector"
    x= np.array(x1)
    y= np.array(y1)
    #plt.bar(x,y)
    plt.plot(x, y, 'o-g',label=p2n)


for f in range(5):
    x1=pn[f]
    y1=p3[f]
    p3n="std array"
    x= np.array(x1)
    y= np.array(y1)
    #plt.bar(x,y)
    plt.plot(x, y, '*-b',label=p3n)
    
    #plt.legend(title = "Data type:") #線條標籤


#變直線

'''
p2n='test2'
x1 = np.array([-10,0])
y1 = np.array([0, 80])
plt.plot(x1, y1)
plt.plot(x1, y1, 'o-',label=p2n)
'''

#plt.bar(x,y)    #長條圖
#if b_or_t==0:
plt.grid(True)  #網格
plt.xlabel('Type')
plt.ylabel('Time(ns)')
plt.title(nptis)

plt.show()
