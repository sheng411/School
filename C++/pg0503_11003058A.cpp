#include <bits/stdc++.h>
using namespace std;

int fre=10;

class Mystudent{
    private:
        int i;
        float f;
        double d;
        string s;
        string myname;
        int math;
        int eng;
        float average;
    public:
        void student();
};

template <class f>
    f findmax(f meam){
        for(int i=0;i<fre;i++){
        int max;
        if(m[i]>max){
            max=m[i]
            }
        }
    }


void Mystudent::student(){
    vector <Mystudent> rw;
    Mystudent test;
    srand(time(NULL));
    for(int i=0;i<fre;i++){
        test.i=rand()%100;
        test.f=float(rand()%100);
        test.d=double(rand()%100);
        test.s=char(rand()%26)+1;
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        test.myname=na;
        test.math=(rand()%(8-4+1))+4;
        test.eng=(rand()%(8-4+1))+4;
        test.average=(math+eng)/2;
        rw.push_back(test);
    }
}

int main(){
    
    return 0;
}