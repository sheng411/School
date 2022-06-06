#include <stdio.h>
#include <math.h>

void main(){
    int i,j,x,y=0;                      //i,j用在for loop x為輸入數 y為開根號
    printf("請輸入一個大於2的正整數:");
    scanf("%d",&x);
    for (j=x;j>0;j--){                  //取x的值並以遞減的方式判斷
        y=sqrt(j);                      //把輸入值開根號
        int isPrime = 1;                //預設為質數
        for(i=2;i<=y;i++){              //從2開始跑到開根號的數
            if(j%i==0){                 //若開根號後取於數=0
                isPrime = 0;            //則把預設為質數的標籤改為0(變成合數)
                break;
            }
        }
        if(isPrime == 1){               //若為質數
            printf("%d", j);            //則把該數印出
            break;
        }
    }
}