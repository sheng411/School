#include <bits/stdc++.h>
using namespace std;

int fre=10;




template <class mer>
    void merg(mer *mr,int sn,int md,int en){
        int l1=md-sn+1;
        int r1=en-md;
        mer L[l1],R[r1];
        for(int i=0;i<l1;i++){
            L[i]=mr[sn+i];
        }
        for(int j=0;j<r1;j++){
            R[j]=mr[md+1+j];
        }
        int i=0,j=0,k=sn;
        while(i<l1 && j<r1){
            if(L[i] <=R[j]){
                mr[k]=L[i];
                i++;
            }
            else{
                mr[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<l1){
            mr[k]=L[i];
            i++;
            k++;
        }
        while(j<r1){
            mr[k]=R[j];
            j++;
            k++;
        }
    }

template <class mes>
    void mergso(mes *ms,int st,int ed){
        if(st<ed){
            int md=(st+ed)/2;
            mergso(ms,st,md);
            mergso(ms,md+1,ed);
            merg(ms,st,md,ed);
        }
    }

int main(){
    vector <string>vs;
    vector <int>vi;
    vector <long>vlo;
    vector <double>vd;
    vector <float>vf;

    srand(time(NULL));
    int rdn=10,rdm=10000;
    for(int i=0;i<fre;i++){
        vi.push_back(rand()%rdm/int(rdn));
        vlo.push_back(rand()%rdm/long(rdn));
        vd.push_back(rand()%rdm/double(rdn));
        vf.push_back(rand()%rdm/float(rdn));
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        vs.push_back(na);
    }

    for(int i=0;i<fre;i++){
        cout<<vi[i]<<"\t";
    }

    mergso(&vf,0,fre);

    for(int i=0;i<fre;i++){
        cout<<"hello "<<vf[i]<<"\t";
    }
    return 0;
}