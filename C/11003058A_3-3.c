#include <stdio.h>

void main(){
    int a,b,n,i=0,j,money=0;
    srand(time(0));                     //設定亂數為真的亂數
    while (i<=10000000){                //若i小於等於1千萬次則執行
        i+=1;                           //每跑一次i就+1
        n=rand()%6+1;                   //設n為猜測值(1~6)
        a=money;
        for (j=0;j<3;j++){              //for迴圈跑三次(每次代表一個骰子)
            b=rand()%6+1;               //設b為每次骰子所擲出的數
            if (n==b)                   //若猜測值等於擲出的數
                money+=1;               //則獲得一塊錢
        }
        if (money==a)
            money-=1;
    }
    printf("最後獲得金額為:%d",money);   //印出總共獲得的金額
}