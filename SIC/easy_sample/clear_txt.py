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
    hash_txt = open('D:/code/School/SIC/easy_sample/hash.txt', 'w')
    output1_txt = open('D:/code/School/SIC/easy_sample/pass1_output.txt', 'w')
    output2_txt = open('D:/code/School/SIC/easy_sample/pass2_output.txt', 'w')
    program_txt = open('D:/code/School/SIC/easy_sample/program.txt', 'w')
    tree_txt = open('D:/code/School/SIC/easy_sample/tree.txt', 'w')

    hash_txt.write("")
    output1_txt.write("")
    output2_txt.write("")
    program_txt.write("")
    tree_txt.write("")

except Exception as e:
    print(f"Error{e}")

finally:
    hash_txt.close()
    output1_txt.close()
    output2_txt.close()
    program_txt.close()
    tree_txt.close()
    print("\n* Clear all txt file !!")
    t_ime(time())
