#include <bits/stdc++.h>
using namespace std;

fstream  tt; 
vector <int> vec_0358(50);

int num;
int fre=30;     //截圖以10筆測試

int main(){
    tt.open("f_3058.txt",ios::out);
    for(int i=0;i<fre;i++){
        cout<<"\n"<<i<<"."<<"cin:";
        cin>>num;
        vec_0358[i]=num;
        tt<<num+'0'<<"\n";
    }

    for(int i=0;i<fre-1;i++){
        for (int j=0;j<fre-1-i;j++){
            if (vec_0358[j]<vec_0358[j+1])
                swap(vec_0358[j+1],vec_0358[j]);
        }
    }

    for(int j=0;j<fre;j++){
        cout<<vec_0358[j]<<endl;
    }
    tt.close();

    return 0;
} 