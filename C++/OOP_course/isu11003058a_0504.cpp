#include <iostream>
#include <string>
using namespace std;

int a,b,c,d;

int main(){
    cout<<"input A:";
    cin>>a;
    cout<<"input B:";
    cin>>b;
    cout<<"input C:";
    cin>>c;
    cout<<"input D:";
    cin>>d;

    if(a>b && a>c && a>d){
        cout<<"\n"<<"TOP:"<<a;
    }
    else if(b>a && b>c && b>d){
        cout<<"\n"<<"TOP:"<<b;
    }
    else if(c>a && c>b && c>d){
        cout<<"\n"<<"TOP:"<<c;
    }
    else{
        cout<<"\n"<<"TOP:"<<d;
    }
    return 0;
}