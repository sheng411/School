from time import *

#time
def t_ime(a):
    t=localtime(a)
    Y=t.tm_year
    M=t.tm_mon
    D=t.tm_mday
    h=t.tm_hour
    m=t.tm_min
    s=t.tm_sec
    print(Y,"/",M,"/",D,"  ",h,":",m,":",s,"\n")

try:
    hash_txt = open('School/SIC/hash.txt', 'w')
    output_txt = open('School/SIC/output.txt', 'w')
    tree_txt = open('School/SIC/tree.txt', 'w')

    hash_txt.write("")
    output_txt.write("")
    tree_txt.write("")

except Exception as e:
    print(f"Error{e}")

finally:
    hash_txt.close()
    output_txt.close()
    tree_txt.close()
    print("\n* Clear all txt file !!")
    t_ime(time())
