#include <bits/stdc++.h>
using namespace std;

int fre=1000;       //quantity of data
long double smfre=100000;     //Use of small data

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
        //return mr;
    }

template <class mes>
    void mergso(mes &ms,int st,int ed){
        if(st<ed){
            int md=(st+ed)/2;
            mergso(ms,st,md);
            mergso(ms,md+1,ed);
            merg(ms,st,md,ed);
        }
        //return ms;
    }


int main(){
    cout<<"start"<<endl;
    
    string *as=new string[fre];
    int *ai=new int[fre],pi;
    long *alo=new long[fre],plo;
    double *ad=new double[fre],pd;
    float *af=new float[fre],pf;
    
    vector <string>vs;
    vector <int>vi;
    vector <long>vlo;
    vector <double>vd;
    vector <float>vf;
    
    
    array <string,1000> aas;
    array <int,1000> aai;
    array <long,1000> aalo;
    array <double,1000> aad;
    array <float,1000> aaf;

    //open file
    fstream myfile;
    myfile.open("count.txt",ios::app);      //改app
    myfile<<"sort\t\t";
    myfile<<"type\t\t";
    myfile<<"time\t\t";
    myfile<<"data num\t";
    myfile<<"rep ti\t\t";   //repeat time
    myfile<<"data str\n\n";
    myfile.close();

    cout<<"file 200OK"<<endl;

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

        pi=rand()%rdm/int(rdn);
        plo=rand()%rdm/long(rdn);
        pd=rand()%rdm/double(rdn);
        pf=rand()%rdm/float(rdn);
        as[i]=na;
        ai[i]=pi;
        alo[i]=plo;
        ad[i]=pd;
        af[i]=pf;

        aas[i]=na;
        aai[i]=rand()%rdm/int(rdn);
        aalo[i]=rand()%rdm/long(rdn);
        aad[i]=rand()%rdm/double(rdn);
        aaf[i]=rand()%rdm/float(rdn);
    }

    cout<<"fre:"<<fre<<",smfre:"<<smfre<<endl;
    cout<<"sort choose--> merge sort"<<endl;
    auto start = chrono::steady_clock::now();


    //run sort


    auto end = chrono::steady_clock::now();
    long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    cout<<"\nAll time-->"<<att<<"ns"<<endl;
    myfile.open("count_merge.txt",ios::app);      //改app
    myfile<<"All time-->"<<att<<"ns\n\n";
    myfile.close();
    return 0;
    }