#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main (){
    int a;                  //定義a
    srand(time(NULL));      //讓初始值!=0
    a=(rand() % 100) +1;    //設定亂數
    printf("%d\n",a);
}