#include <bits/stdc++.h>
using namespace std;

template <typename T>
    void find_second_3058(array <a>out){
        
    }

int main(){
    srand(time(NULL));
    array<int,20> a;
    array<float,20> f;
    array<double,20> d;
    array<string,20> s;

    for(int i=0;i<20;i++){
        a[i]=(rand()%6+11);
        f[i]=float(a[i])/3;
        d[i]=double(a[i])/3;
        string na="aa";
        for(int k=0;k<2;k++){
            na[k]+=(rand()%3+1);
        }
        s[i]=na;
        cout<<i<<"--"<<s[i]<<endl;   //test
    }


    return 0;
}