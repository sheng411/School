#include <stdlib.h>

void main(void){
    int a,b,c;                          //設a,b,c為整數
    printf("輸入三個整數:");             //提示語
    scanf("%d %d %d",&a,&b,&c);
    if (a>b && a>c){                    //判斷a是否為最大值
        if (b>c)                        //已確定a為最大值，在來判斷b和c
        {
            printf("%d,%d,%d",a,b,c);
        }
        else
            printf("%d,%d,%d",a,c,b);
    }
    else if (b>a && b>c){               //判斷b是否為最大值
        if (a>c){                       //已確定b為最大值，在來判斷a和c
            printf("%d,%d,%d",b,a,c);
        }
        else
            printf("%d,%d,%d",b,c,a);
    }
    else{
        if (a>b){                       //已確定c為最大值，在來判斷a和b
            printf("%d,%d,%d",c,a,b);
        }
        else
            printf("%d,%d,%d",c,b,a);
    }
}