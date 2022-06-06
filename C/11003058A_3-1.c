#include <stdlib.h>

void main(void){
    int i,num=1;                        //定義兩數(num=計算和)
    for(i=1;i<=12;i++){                 //(設i值;若i<=12;則i++)
        num*=i;                         //num=num*i
        printf("%d!=%d\n",i,num);       //印出計算值
    }
}