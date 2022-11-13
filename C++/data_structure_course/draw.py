import matplotlib
import matplotlib.pyplot as plt
import numpy as np

#讀檔案

path = 'D:/code/School/C++/data_structure_course/read.txt'
f = open(path, 'r')
text = [[""]*15]
j=0
for i in range(15):
    j==0
    for line in f:
        text[i][j]=line.split(" ")
        print(text[i][j],"\n")  #line,
        j+=1

f.close()



sn=int(input("start:"))
en=int(input("end:"))
print('hi',sn,en)
'''
data=[]
for i in range(sn):
    data.append(int(input()))


x = np.array([1, 5])
y = np.array([20,40])
x1 = np.array([-10,0])
y1 = np.array([0, 80])

p1n='test1'
p2n='test2'

plt.plot(x, y)
plt.plot(x, y, 'o-',label=p1n)

plt.plot(x1, y1)
plt.plot(x1, y1, 'o-',label=p2n)


#plt.bar(x,y)    #長條圖
plt.grid(True)  #網格
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Sort')
plt.legend(title = "Four animals:") #線條標籤
plt.show()
'''