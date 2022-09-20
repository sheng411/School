#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib> 
#include <string>
using namespace std;


struct score{
    string name;
    int math;
    int english;
    int nature;
    int society;
    int chinese;
    int total;
};


int main(){
    int fre=100;              //跑的次數
    vector <score> rw;
    score test;
    srand(time(NULL));
    for(int i=0;i<fre;i++){
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        //cout<<i+1<<". "<<na<<endl;
        test.name=na;
        test.math=rand()%16;
        test.english=rand()%16;
        test.nature=rand()%16;
        test.society=rand()%16;
        test.chinese=rand()%16;
        test.total=test.math+test.english+test.nature+test.society+test.chinese;
        rw.push_back(test);
    }

    //插入排序
    score tmp;
    int k;
    for(int j=0;j<fre;j++){
        tmp=rw[j];
        k=j-1;
        while((k>=0)&&(rw[k].total<tmp.total)){
            rw[k+1]=rw[k];
            k--;
        }
        rw[k+1]=tmp;
        cout<<j+1<<".->"<<rw[j].total<<endl;        //測資用
    }
    cout<<"\n"<<endl;                               //換行(美觀)

    //選特定排名並印出
    for(int z=0;z<=90;z+=10){        
        cout<<z<<"."
        <<"name: "<<rw[z].name<<"\n"
        <<"ch: "<<rw[z].chinese<<"\n"
        <<"eng: "<<rw[z].english<<"\n"
        <<"math: "<<rw[z].math<<"\n"
        <<"nature: "<<rw[z].nature<<"\n"
        <<"society: "<<rw[z].society<<"\n"
        <<"all: "<<rw[z].total<<"\n"<<endl;
    }
}