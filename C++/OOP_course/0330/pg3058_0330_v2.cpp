#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib> 
#include <string>
using namespace std;

int fre=10;              //跑的次數

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
void mymath(vector <score>&rw);
void myeng(vector <score>&rw);
void myappli(vector <score>&rw);
void myoral(vector <score>&rw);
void bdw(vector <score>&rw);
//void output(vector <score>&rw);

int main(){
    vector <score> rw;
    student(rw);
    mymath(rw);
    myeng(rw);
    myappli(rw);
    myoral(rw);
    bdw(rw);
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
}


void mymath(vector <score>& rw){
    score tmp;
    for(int j=0;j<fre;j++){
        int min=j;
        for(int k=j+1;k<fre;k++){
            if(rw[k].math>rw[min].math){
                min=k;
                }
            }
        if(min!=j){
                tmp=rw[min];
                rw[min]=rw[j];
                rw[j]=tmp;
        }
        //cout<<j+1<<".->"<<rw[j].total<<endl;        //測資用
    }
    cout<<"\n"<<"math Top:";
    
    for(int z=0;z<1;z++){
        cout//<<z<<"."
        <<rw[z].math<<endl;
    }
}


void myeng(vector <score>& rw){
    score tmp;
    for(int j=0;j<fre;j++){
        int min=j;
        for(int k=j+1;k<fre;k++){
            if(rw[k].english>rw[min].english){
                min=k;
                }
            }
        if(min!=j){
                tmp=rw[min];
                rw[min]=rw[j];
                rw[j]=tmp;
        }
        //cout<<j+1<<".->"<<rw[j].total<<endl;        //測資用
    }
    cout<<"\n"<<"english Top:";
    
    for(int z=0;z<1;z++){
        cout//<<z<<"."
        <<rw[z].english<<endl;
    }
}


void myappli(vector <score>& rw){
    score tmp;
    for(int j=0;j<fre;j++){
        int min=j;
        for(int k=j+1;k<fre;k++){
            if(rw[k].application>rw[min].application){
                min=k;
                }
            }
        if(min!=j){
                tmp=rw[min];
                rw[min]=rw[j];
                rw[j]=tmp;
        }
        //cout<<j+1<<".->"<<rw[j].total<<endl;        //測資用
    }
    cout<<"\n"<<"application Top:";
    
    for(int z=0;z<1;z++){
        cout//<<z<<"."
        <<rw[z].application<<endl;
    }
}


void myoral(vector <score>& rw){
    score tmp;
    for(int j=0;j<fre;j++){
        int min=j;
        for(int k=j+1;k<fre;k++){
            if(rw[k].oral>rw[min].oral){
                min=k;
                }
            }
        if(min!=j){
                tmp=rw[min];
                rw[min]=rw[j];
                rw[j]=tmp;
        }
        //cout<<j+1<<".->"<<rw[j].total<<endl;        //測資用
    }
    cout<<"\n"<<"oral Top:";
    
    for(int z=0;z<1;z++){
        cout//<<z<<"."
        <<rw[z].oral<<endl;
    }
}


void bdw(vector <score>& rw){
    score tmp;
    cout<<"\n\n"<<"*bdw ranking:";
    mymath(rw);
    myappli(rw);
    myoral(rw);
    myeng(rw);
}


//void output(vector <score>& rw){
//    for(int z=0;z<fre;z++){
//        cout<<z<<"."
//        <<"name: "<<rw[z].name<<"\n"
//        <<"ch: "<<rw[z].chinese<<"\n"
//        <<"eng: "<<rw[z].english<<"\n"
//        <<"math: "<<rw[z].math<<"\n"
//        <<"nature: "<<rw[z].nature<<"\n"
//        <<"society: "<<rw[z].society<<"\n"
//        <<"all: "<<rw[z].total<<"\n"
//        <<"application: "<<rw[z].application<<"\n"
//        <<"oral: "<<rw[z].oral<<"\n"<<endl;
//    }
//}
