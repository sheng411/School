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
    int fre=1000;              //跑的次數
    vector <score> rw;
    score test;
    srand(time(NULL));
    for(int i=0;i<fre;i++){                      //10次
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

    //選擇排序
    score tmp;
    for(int j=0;j<fre;j++){
        int min=j;
        for(int k=j+1;k<fre;k++){
            if(rw[k].total<rw[min].total){
                min=k;
                }
            }
        if(min!=j){
                tmp=rw[min];
                rw[min]=rw[j];
                rw[j]=tmp;
        }
        cout<<j+1<<".->"<<rw[j].total<<endl;        //測資用
    }

    //選特定排名並印出
    for(int z=0;z<fre;z++){
        if(z==0 or z==100 or z==200)
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