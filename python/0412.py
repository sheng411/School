import matplotlib.pyplot as plt
def fun(x):
    y2=(x*x*x+x+1)%p
    return y2

#def y2(x,p):
#    y2=(x*x*x+x+1)%p
#    return y2


p=17
xt=[]
yt=[]

for x in range(0,p):
    for y in range(0,p):
        if (y*y)%p==fun(x):
            xt.append(x)
            yt.append(y)


plt.plot(xt,yt,'r.')
plt.ylabel('Mod '+str(p)+' ECC')
plt.show()