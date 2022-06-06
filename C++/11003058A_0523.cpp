#include <bits/stdc++.h>
using namespace std;

template <class A>A add(A,A);

int main(void){
    int a=10,b=20;
    double x=2.3456,y=3.5678;
    float q=2.3,w=10.4;
    string s1="hello",s2="teacher";
    long double ld1=-1.7E+308,ld2=-1.7E-308;
    long long ll1=123456789000,ll2=9876543210000;
    cout << a << "+" << b << "=" << add(a,b) << endl;
    cout << x << "+" << y << "=" << add(x,y) << endl;
    cout << q << "+" << w << "=" << add(q,w) << endl;
    cout << s1 << "+" << s2 << "=" << add(s1,s2) << endl;
    cout << ld1 << "+" << ld2 << "=" << add(ld1,ld2) << endl;
    cout << ll1 << "+" << ll2 << "=" << add(ll1,ll2) << endl;
    system("pause");
    return 0;
}

template <class A>
    A add(A i,A j){ 		   
        return i+j;
    }


//設m=math
for(int i=0;i<fre;i++){
    int max;
    if(m[i]>max){
        max=m[i]
    }
}