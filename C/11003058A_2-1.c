#include <stdlib.h>

void main(void){
    int a,b,c,e;                        //設a,b,c,e為整數
    printf("輸入四個整數:");
    scanf("%d %d %d %d",&a,&b,&c,&e);
    if(a>b && a>c && a>e){              //判斷a是否為最大值
        printf("%d",a);
    }
    else if(b>a && b>c && b>e){         //判斷b是否為最大值
        printf("%d",b);
    }
    else if (c>a && c>b && c>e){        //判斷c是否為最大值
        printf("%d",c);
    }
    else{                               //若都沒有則e為最大值
        printf("%d",e);
    }
}