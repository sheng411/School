#include <stdio.h>

int f(int);

void main(){
    int i;
    for(i=1;i<=20;i++){
        printf("f(%2d)=%d\n",i,f(i));       //印出f(數字)=和
    }
}

int f(int n){
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    else if(n==3)
        return 2;
    else
        return f(n-1)+f(n-2)+f(n-3);        //使用遞迴方式把數字相加
}

//13~18行為判斷n是否為1~3，若有責分別回傳0~2