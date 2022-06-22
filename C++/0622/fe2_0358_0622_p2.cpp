#include <bits/stdc++.h>
using namespace std;

int fre=20;

class MySores{
    private:
    string name;    //size==6 (eng)
    int math;       //4~9
    int english;    //3~10
    public:
    MySores(string na,int ma,int en){
        na=name;
        ma=math;
        en=english;
        cout<<"MySores open"<<endl;
    }
    copy_MySores(const MySores &rw){
        cout<<"copy Mysores open"<<endl;
        name=rw.name;
        math=rw.math;
        english=rw.english;
    }
    ~MySores(){
        cout<<"~MySores open";
    }
    void output_data(string n,int m,int e){
        for(int i=0;i<fre;i++){
            cout<<"name:"<<endl;
            cout<<n[i]<<endl;
        }
        for(int i=0;i<fre;i++){
            cout<<"math:"<<endl;
            cout<<m<<endl;
        }
        for(int i=0;i<fre;i++){
            cout<<"english:"<<endl;
            cout<<e<<endl;
        }
    }
    string get_name(){return name;}
    int get_math(){return math;}
    int get_english(){return english;}
};

int find_small_3058(string na,int ma,int eng){
    int min;
    for(int i=0;i<fre;i++){
        if(ma[i]<ma[min]){
            min=i;
        }
    }
    
}

int main(){
    srand(time(NULL));
    vector <MySores> rw;
    vector <string> n;
    vector <int> ma;
    vector <int> eng;
    for(int i=0;i<fre;i++){
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        n.push_back(na);
        ma.push_back(rand()%6+4);
        eng.push_back(rand()%8+3);
    }
    output_data(n,ma,eng);
    find_small_3058();
    return 0;
}