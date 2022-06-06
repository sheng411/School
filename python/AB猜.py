import random

def num(listt):
    for i in range(0,10):
        for j in range(0,10):
            for k in range(0,10):
                if i!=j and j!=k and k!=i:
                    str1=str(i)+str(j)+str(k)
                    listt.append(str1)

def AB(str1,str2):
    B=0;A=0
    for i in range(0,3):
        for j in range(0,3):
            if str1[i]==str2[j]:  
                if i==j:
                    A=A+1
                else:
                    B=B+1
    return A, B                 

def AI(listt,str2,A,B):
    listTB=[]
    for i in listt:
        A1, B1 = AB(i,str2)
        if A==A1 and B==B1:
            listTB.append(i)
    return listTB       

listt = []
num(listt)
cnum=listt[random.randint(0,len(listt)-1)]
print("*",cnum)                                  #測資用
while True:
    strx=input("輸入一個三位數:")
    A,B=AB(cnum,strx)
    print(strx,"->",A,"A",B,"B")
    n=random.randint(0, len(listt)-1)
    guessnum=listt[n]
    print("my guess number=",guessnum) 
    A1,B1=input("please input A B:").split()
    listTB=AI(listt,guessnum,int(A1),int(B1))
    print("\n*",len(listTB),"\n")                #測資用
    if A==3 or A1==3:
        if A==3:
            print("\n你贏了\n")
            break
        elif A==3 and int(A1)==3:
            print("\n平手\n")
            break
        elif int(A1)==3:
            print("\n電腦贏了\n")
            break