#include <bits/stdc++.h>
using namespace std;

//設範圍為10~20
vector<vector<int>> p(4,vector<int>(3)),q(3,vector<int>(4)),R(4,vector<int>(4));
array<array<int,3>,4> ap;  //4*3
array<array<int,4>,3> aq;
array<array<int,4>,4> aR;

int main(){
    srand(time(NULL));
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            p[i][j]=(rand()%90+10);
            ap[i][j]=(rand()%90+10);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            q[i][j]=(rand()%90+10);
            aq[i][j]=(rand()%90+10);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            R[i][j]=0;
            aR[i][j]=0;
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                R[i][j]+=p[i][k]*q[k][j];
                aR[i][j]+=ap[i][k]*aq[k][j];
            }
        }
    }

    //輸出
    cout<<"vector:"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<setw(6)<<R[i][j];
        }
        cout<<endl;
    }

    cout<<"array:"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<setw(6)<<aR[i][j];
        }
        cout<<endl;
    }

    return 0;
}