#include <bits/stdc++.h>
using namespace std;

int fre=5;

class Mystudent{
    private:
        string myname;
        int math;
        int eng;
        float average;
    public:
    Mystudent(string na,int ma,int en,float ave);
    string getmyname(){return myname;}
    int getmymath(){return math;}
    int getmyeng(){return eng;}
    float getmyave(){return average;}
};

template <class f>
    void myoutput(vector <f> out){
        for(int i=0;i<fre;i++){
            cout<<out[i]<<endl;
        }
    }

template <class f>
    void findmax(vector <f> meam){
        int max=0;
        f maax;
        for(int i=0;i<fre;i++){
            if(meam[i]>meam[max]){
                maax=meam[i];
                max=i;
            }
        }
        cout<<"\ntop-->"<<"index="<<max<<"--"<<maax;
    }

void student(vector <Mystudent>&rw){
    srand(time(NULL));
    for(int i=0;i<fre;i++){
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        int ma=(rand()%(8-4+1))+4;
        int en=(rand()%(8-4+1))+4;
        float ave=(ma+en)/2;
        Mystudent test(na,ma,en,ave);
        rw.push_back(test);
    }
}

Mystudent::Mystudent(string na,int ma,int en,float ave){
    myname=na;
    math=ma;
    eng=en;
    average=ave;
}

int main(){
    vector <Mystudent> rw;
    vector <int> i;
    vector <float> f;
    vector <double> d;
    vector <string> s;
    for(int j=0;j<fre;j++){
        i.push_back(rand()%100);
        f.push_back(rand()%100);
        d.push_back(rand()%100);
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        s.push_back(na);
    }

    student(rw);
    
    myoutput <int>(i);
    findmax <int>(i);


    return 0;
}