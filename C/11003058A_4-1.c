#include <stdio.h>

void main(){
    int i,j;
    for(i=0;i<26;i++){              //從0開始跑至第25個(共26次)
        for(j=97+i;j>=97;j--){      //j預設為97+i(97為a的ASCII code)並進行遞減
            printf("%c",j);
        }
        printf("\n");               //換行
    }
}