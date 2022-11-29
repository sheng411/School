#include <bits/stdc++.h>
using namespace std;

constexpr int arnum=1000;
long double smfre=10000;     //Use of small data
int fre=arnum;       //quantity of data

template <class rds,class rdi,class rdlo,class rdd,class rdf,class rdas,class rdai,class rdalo,class rdad,class rdaf,class rdaas,class rdaai,class rdaalo,class rdaad,class rdaaf>
    void randd(rds &vs,rdi &vi,rdlo &vlo,rdd &vd,rdf &vf,rdas &as,rdai &ai,rdalo &alo,rdad &ad,rdaf &af,rdaas &aas,rdaai &aai,rdaalo &aalo,rdaad &aad,rdaaf &aaf){
        int pi;long plo;double pd;float pf;
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
    }

template <class mer>
    int merg(mer &mr,int sn,int md,int en){
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
        return 0;
    }

template <class mes>
    int mergso(mes &ms,int st,int ed){
        if(st<ed){
            int md=(st+ed)/2;
            mergso(ms,st,md);
            mergso(ms,md+1,ed);
            merg(ms,st,md,ed);
        }
        return 0;
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
    
    
    static array <string,arnum> aas;
    static array <int,arnum> aai;
    static array <long,arnum> aalo;
    static array <double,arnum> aad;
    static array <float,arnum> aaf;

    //open file
    fstream myfile;
    myfile.open("count_merge.txt",ios::out);      //改app
    myfile<<"sort\t\t";
    myfile<<"type\t\t";
    myfile<<"time\t\t";
    myfile<<"data num\t";
    myfile<<"rep ti\t\t";   //repeat time
    myfile<<"data str\n\n";
    myfile.close();

    cout<<"file 200OK"<<endl;

    /*
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
    }*/

    randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

    int sc;
    cout<<"fre:"<<fre<<",smfre:"<<smfre<<endl;
    cout<<"sort choose-->";
    cin>>sc;
    auto start = chrono::steady_clock::now();

    for(int i=0;i<smfre;i++){
        mergso(as,0,fre-1);
        mergso(ai,0,fre-1);
        mergso(alo,0,fre-1);
        mergso(ad,0,fre-1);
        mergso(af,0,fre-1);
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    }

    /*for(int i=0;i<smfre;i++){
        mergso(vs,0,fre-1);
        mergso(vi,0,fre-1);
        mergso(vlo,0,fre-1);
        mergso(vd,0,fre-1);
        mergso(vf,0,fre-1);
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    }*/

    /*for(int i=0;i<smfre;i++){
        mergso(aas,0,fre-1);
        mergso(aai,0,fre-1);
        mergso(aalo,0,fre-1);
        mergso(aad,0,fre-1);
        mergso(aaf,0,fre-1);
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    }*/

    auto end = chrono::steady_clock::now();
    long long att=chrono::duration_cast<chrono::nanoseconds>((end-start)/smfre).count();    //秒 seconds
    double ats=att*0.000000001;
    cout<<"\nAll time-->"<<att<<"ns"<<endl;
    myfile.open("count_merge.txt",ios::app);      //改app
    myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n\n";
    myfile.close();
    return 0;
    }



/*
switch (sc){
    case 1:
        for(int i=0;i<smfre;i++){
            mergso(vs,0,fre-1);
            mergso(vi,0,fre-1);
            mergso(vlo,0,fre-1);
            mergso(vd,0,fre-1);
            mergso(vf,0,fre-1);
            randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
        }
        break;
    case 2:
        for(int i=0;i<smfre;i++){
            mergso(as,0,fre-1);
            mergso(ai,0,fre-1);
            mergso(alo,0,fre-1);
            mergso(ad,0,fre-1);
            mergso(af,0,fre-1);
            randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
        }
        break;
    case 3:
        for(int i=0;i<smfre;i++){
            mergso(aas,0,fre-1);
            mergso(aai,0,fre-1);
            mergso(aalo,0,fre-1);
            mergso(aad,0,fre-1);
            mergso(aaf,0,fre-1);
            randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
        }
        break;
    default:
        cout<<"404 error"<<endl;
        break;
    }

*/