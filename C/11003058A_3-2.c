#include <stdlib.h>

void main (){
    int a,b,c,i;                //定義四個數
    for (i=100;i<=999;i++){     //(設i=100;若i<=999;則i+=1)
        a=i/100;                //取百位數字
        b=(i%100)/10;           //取十位數字
        c=i%10;                 //取個位數字
        a*=a*a;                 //將百位數立方
        b*=b*b;                 //將十位數立方
        c*=c*c;                 //將個位數立方
        if(i==(a+b+c)){         //若i==a、b、c立方後的和
        printf("%d\n",i);       //則印出
        }
    }
}