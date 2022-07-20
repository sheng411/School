#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib> 
#include <string>
using namespace std;

int fre=2048;              //跑的次數

struct score{
    string name;
    int math;
    int english;
    int nature;
    int society;
    int chinese;
    int total;
    int application;
    int oral;
};

void student(vector <score>&rw);
void output(vector <score>&rw);

int main(){
    vector <score> rw;
    student(rw);
}


void student(vector <score>& rw){
    int app1=0,ora1=0,eng1=0;
    //vector <score> rw;
    score test;
    srand(time(NULL));
    for(int i=0;i<fre;i++){
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        //cout<<i+1<<". "<<na<<endl;
        test.name=na;
        test.math=(rand()%(8-4+1))+4;
        if(eng1>fre/2){
            test.english=(rand()%(6-3+1))+3;
        }
        else{
            test.english=(rand()%(11-7+1))+7;
        }
        test.nature=(rand()%(11-7+1))+7;
        test.society=(rand()%(11-9+1))+9;
        test.chinese=(rand()%(12-8+1))+8;

        for(int i=70;i<=90;i+=5){
            if(app1==5)
                app1=0;
            i+=app1*5;
            test.application=i;
            app1+=1;
            break;
        }
        for(int i=65;i<=95;i+=5){
            if(ora1==7)
                ora1=0;
            i+=ora1*5;
            test.oral=i;
            ora1+=1;
            break;
        }
        test.total=test.math+test.english+test.nature+test.society+test.chinese;
        rw.push_back(test);
    }
    output(rw);
}

void output(vector <score>& rw){
    for(int z=0;z<fre;z++){
        cout<<z<<"."
        <<"name: "<<rw[z].name<<"\n"
        <<"ch: "<<rw[z].chinese<<"\n"
        <<"eng: "<<rw[z].english<<"\n"
        <<"math: "<<rw[z].math<<"\n"
        <<"nature: "<<rw[z].nature<<"\n"
        <<"society: "<<rw[z].society<<"\n"
        <<"all: "<<rw[z].total<<"\n"
        <<"application: "<<rw[z].application<<"\n"
        <<"oral: "<<rw[z].oral<<"\n"<<endl;
    }
}
