#include <stdio.h>

int gcd(int,int);                       //宣告gcd
int lcm(int,int);                       //宣告lcm

void main(){
    int a,b,m,n;
    int gcd(a,b);
    int lcm(a,b);
    printf("請輸入兩個整數:");
    scanf("%d %d",&a,&b);
    m=gcd(a,b);
    n=lcm(a,b);
    printf("\ngcd:%d lcm:%d\n",m,n);    //印出gcd及lcm
}

int gcd(int a,int b){                   //gcd函式
    while (b!=0){                       //用輾轉相除法求最大公因數
        int g;  
        g=a%b;
        a=b;
        b=g;
    }
    return a;
}

int lcm(int a,int b){                   //lcm函式
    int l;
    l=a*b/gcd(a,b);                     //把輸入值相乘並除以最大公因數可得最小公倍數
    return l;
}