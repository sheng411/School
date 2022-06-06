#include <bits/stdc++.h>
using namespace std;

int fre=5;              //跑的次數

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

void student(vector <score>&rw){
    int app1=0,ora1=0,eng1=0;
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

void myoutput(vector <score>&rw){
    for(int i=0;i<fre;i++){
        cout<<"\n"<<i<<"."
        <<"\nname:"<<rw[i].name
        <<"\nmath:"<<rw[i].math
        <<"\nenglish:"<<rw[i].english
        <<"\nnature:"<<rw[i].nature
        <<"\nsociety"<<rw[i].society
        <<"\nchinese"<<rw[i].chinese
        <<"\ntotal"<<rw[i].total
        <<"\napplication"<<rw[i].application
        <<"\noral:"<<rw[i].oral<<endl;
    }
}

void math_data(vector <score>&rw){
    int max=0;
    for(int i=0;i<fre;i++){
        if(rw[i].math>rw[max].math){
            max=i;
        }
    }
    cout<<"\ntop math-->"<<"index="<<max<<", score="<<rw[max].math;
}

void english_data(vector <score>&rw){
    int max=0;
    for(int i=0;i<fre;i++){
        if(rw[i].english>rw[max].english){
            max=i;
        }
    }
    cout<<"\ntop english-->"<<"index="<<max<<", score="<<rw[max].english;
}

void application_data(vector <score>&rw){
    int max=0;
    for(int i=0;i<fre;i++){
        if(rw[i].application>rw[max].application){
            max=i;
        }
    }
    cout<<"\ntop application-->"<<"index="<<max<<", score="<<rw[max].application;
}

void oral_data(vector <score>&rw){
    int max=0;
    for(int i=0;i<fre;i++){
        if(rw[i].oral>rw[max].oral){
            max=i;
        }
    }
    cout<<"\ntop oral-->"<<"index="<<max<<", score="<<rw[max].oral;
}

int main(){
    vector <score> rw;
    student(rw);
    myoutput(rw);
    math_data(rw);
    english_data(rw);
    application_data(rw);
    oral_data(rw);
    return 0;
    //hello
}