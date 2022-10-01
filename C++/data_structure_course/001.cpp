#include <bits/stdc++.h>
using namespace std;
int fre=0;  //quantity of data

int ins(int in[],int n){

}


int bub(int b[],int n){     //b is list ,n is list size.
    int i,j,k;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(b[j]>b[j+1]){
                swap(b[j],b[j+1]);
            }
        }
    }
    cout<<"list-->"<<b<<endl;
    return 0;
}



//sel(int s[],int)

int main(){
    srand(time(NULL));
    int len;
    
    len=a.size();
    cout<<"len-->"<<len<<endl;
    
    return 0;
}