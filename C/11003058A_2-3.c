#include <stdlib.h>

void main(){
    int year,a,b,c;
    printf("請輸入年份:");
    scanf("%d",&year);
    a=year%4;
    b=year%100;
    c=year%400;
    if (a==0 && b!=0 || c==0){
        printf("閏年");
    }
    else
        printf("平年");
}