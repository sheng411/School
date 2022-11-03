#include <bits/stdc++.h>
using namespace std;

int fre=10;


template <class mer>
    void merg(mer &mr,int sn,int md,int en){
        using elType = typename mer::value_type;
        int L_s=md-sn+1;
        int R_s=en-md;
        elType L[L_s],R[R_s];
        for(int ll=0;ll<L_s;ll++){
            L[ll]=mr[sn+ll];
        }
        for(int rr=0;rr<R_s;rr++){
            R[rr]=mr[md+1+rr];
        }
        int i=0,j=0,k=sn;
        while(i<L_s && j<R_s){
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
        while(i<L_s){
            mr[k]=L[i];
            i++;
            k++;
        }
        while(j<R_s){
            mr[k]=R[j];
            j++;
            k++;
        }
    }

template <class mes>
    void mergso(mes &ms,int st,int ed){
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
    cout<<endl;

    mergso(vi,0,fre-1);

    for(int i=0;i<fre;i++){
        cout<<vi[i]<<"\t";
    }
    return 0;
}






/*
template <class mgo>
    void mergego(int dt,int dsn){  //dt is data type
        fstream myfile;
        myfile.open("count.txt",ios::app);      //改app
        auto gst=chrono::steady_clock::now();
        mergso(as,0,fre-1);
        mergso(ai,0,fre-1);
        mergso(alo,0,fre-1);
        mergso(ad,0,fre-1);
        mergso(af,0,fre-1);
        mergso(vs,0,fre-1);
        mergso(vi,0,fre-1);
        mergso(vlo,0,fre-1);
        mergso(vd,0,fre-1);
        mergso(vf,0,fre-1);
        mergso(aas,0,fre-1);
        mergso(aai,0,fre-1);
        mergso(aalo,0,fre-1);
        mergso(aad,0,fre-1);
        mergso(aaf,0,fre-1);
        auto gend=chrono::steady_clock::now();

        long double ti=chrono::duration_cast<chrono::nanoseconds>(gend-gst).count();

        string dtl[5] {"string","int\t","long","double","float"};
        string ds[3] {"C array","vector","std array"};
        cout<<"Sort: \""<<" \",data type is \" "<<dtl[dt]<<" \""<<"data str"<<ds[dsn]<<endl;
        cout<<"usage time-->"<<ti<<"ns\n"<<endl;
        myfile<<"merge"<<"\t\t"
                <<dtl[dt]<<"\t\t"
                <<ti<<"ns\t\t"
                <<fre<<"\t\t"
                <<smfre<<"\t\t"
                <<ds[dsn]<<"\n"
                <<endl;
        myfile.close();
    }*/