#include <stdio.h>

int f(int);

void main(){
    int i;
    for(i=3;i<=20;i++){
        printf("f(%2d)=%d\n",i,f(i));
    }
}

int f(int n){
    
}