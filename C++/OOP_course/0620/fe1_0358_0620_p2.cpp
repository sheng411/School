#include <bits/stdc++.h>
using namespace std;

template <class T>
    int find_second_3058(array <T,20> out){
        int len=out.size();
        for(int i=0;i<len-1;i++){
            for (int j=0;j<len-1-i;j++){
                if (out[j]>out[j+1])
                    swap(out[j],out[j+1]);
            }
            cout<<out[i]<<endl;
        }
        T min1=out[19];
        int ok=0;
        for(int j=19;j>=0;j--){
            if(ok==0){
                if(out[j]<min1){
                    min1=oct[j];
                    ok+=1;
                }
            }
            else
                break;
        }
        cout<<"top2:"<<min1;
    return min1;
    }

int main(){
    srand(time(NULL));
    array<int,20> a;
    array<float,20> f;
    array<double,20> d;
    array<string,20> s;
    int aa;
    float ff;
    double dd;
    string ss;
    for(int i=0;i<20;i++){
        a[i]=(rand()%6+11);
        f[i]=float(a[i])/3;
        d[i]=double(a[i])/3;
        string na="aa";
        for(int k=0;k<2;k++){
            na[k]+=(rand()%3+1);
        }
        s[i]=na;
        //cout<<i<<"--"<<s[i]<<endl;   //test
    }

    aa=find_second_3058(a);
    ff=find_second_3058(f);
    dd=find_second_3058(d);
    ss=find_second_3058(s);
    for(int i=0;i<20;i++){
        cout<<i<<"."
        <<a[i]<<endl;
    }
    cout<<aa<<endl;

    int fi=0;
    while(fi<20){
        cout<<fi<<"."
        <<f[fi]<<endl;
        fi+=1;
    }
    cout<<ff<<endl;

    for(int i=0;i<20;i++){
        cout<<i<<"."
        <<d[i]<<endl;
    }
    cout<<dd<<endl;

    int si=0;
    while(fi<20){
        cout<<si<<"."
        <<s[si]<<endl;
        si+=1;
    }
    cout<<ss<<endl;
    return 0;
}