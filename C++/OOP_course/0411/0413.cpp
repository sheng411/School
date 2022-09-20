//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class MyClass {
    private:
        string name;
        int score;
    public:
        MyClass(string ,int);//建構元
        MyClass(const MyClass &num);//複製建構元
        ~MyClass();//解構元
        void output_data();
};
MyClass::MyClass(string n1,int s1){     //建構元code
    name=n1;
    score=s1;
    cout << "MyClass test!!" <<endl;
}
MyClass::MyClass(const MyClass &num){   //解構元code
    cout<<"copy myclass open..."<<endl;
    name=num.name;
    score=num.score;
}
MyClass::~MyClass(){                    //解構元code
    cout<<"delete hi -->"<<this->name<<" GG..."<<endl;
    system("pause");
}
void MyClass::output_data(){
    cout<<"name:"<<name<<":"
    <<"score="<<score<<endl;
}

int main(){
    vector<MyClass> test;
    for(int i=0;i<20;i++){
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        int num=rand()%100;
        MyClass tmp(na,num);
        test.push_back(tmp);
    }
    for(int j=0;j<20;j++){
        test[j].output_data();
    }
    system("pause");
    return 0;
}