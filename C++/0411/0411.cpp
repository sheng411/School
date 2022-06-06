//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class MyClass {
    private:
        string name;
        int score;
    public:
        MyClass(string n,int s):name(n),score(s){     //建構元
            cout<<"MyClass open..."<<endl;
        }
        
        ~MyClass(){                         //解構元
            cout<<"unt hi"<<this->name<<"GG..."<<endl;
            system("pause");
        }
        void member(){
            cout<<"name:"<<name<<":"
            <<"score="<<score<<endl;
        }
};
MyClass::MyClass(string n1,int s1){
    name=n1;
    score=s1;
    cout << "MyClass test!!" <<endl;
}
// 建構元(constructor)請定義於下:
int main(){
    vector<MyClass> test;

    MyClass test1("abcdef",80);
    MyClass test2("jkjljl",70);
    MyClass test3("dfscvv",95);

    test.push_back(test1);
    test.push_back(test2);
    test.push_back(test3);

    test[0].member();
    test[1].member();
    test[2].member();
    return 0;
}