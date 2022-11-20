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

nptis=str(text[0][0][0])+" sort-->"+str(text[0][0][3])+","+str(text[0][0][4])
print(nptis)

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

'''
p3=[]
for i in range(10,15):
    p3.append(data[i])
print(p3)
'''
pn=['str','int','long','double','float']

k=0
for f in range(5):
    p1n=pn[f]
    x = np.array([f+1])
    y = np.array(p1[f])
    plt.plot(x, y, 'o-b',label=p1n)
    
#plt.legend(title = "Data type:") #線條標籤

for f in range(5):
    p2n=pn[f]
    x1= np.array([f+1])
    y1= np.array(p2[f])
    plt.plot(x1, y1, 'o-r',label=p2n)
    
'''
for f in range(5):
    p3n=pn[f]
    x= np.array([f+1])
    y= np.array(p3[f])
    plt.plot(x, y, 'o-g',label=p3n)
'''

#變直線

'''
p2n='test2'
x1 = np.array([-10,0])
y1 = np.array([0, 80])
plt.plot(x1, y1)
plt.plot(x1, y1, 'o-',label=p2n)
'''

#plt.bar(x,y)    #長條圖
plt.grid(True)  #網格
plt.xlabel('Type')
plt.ylabel('Time')
plt.title(nptis)

plt.show()
