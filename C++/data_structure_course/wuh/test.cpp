#include <bits/stdc++.h>
using namespace std;

constexpr int arnum=10000;
long double smfre=1;     //Use of small data
int fre=arnum;       //quantity of data

//亂數排序
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

            aas[i]=na;
            aai[i]=rand()%rdm/int(rdn);
            aalo[i]=rand()%rdm/long(rdn);
            aad[i]=rand()%rdm/double(rdn);
            aaf[i]=rand()%rdm/float(rdn);
        }
    }



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

    array <string,arnum> aas;
    array <int,arnum> aai;
    array <long,arnum> aalo;
    array <double,arnum> aad;
    array <float,arnum> aaf;
    
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

    //亂數排序
    randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

    for(int i=0;i<fre;i++){
        cout<<vs[i]<<"\t";
    }
	cout << endl;
    mergso(vs,0,fre-1);

    for(int i=0;i<fre;i++){
        cout<<vs[i]<<"\t";
    }
    cout << endl;
    
    for(int i=0;i<fre;i++){
        cout<<vi[i]<<"\t";
    }
	cout << endl;
    mergso(vi,0,fre-1);

    for(int i=0;i<fre;i++){
        cout<<vi[i]<<"\t";
    }
    cout << endl;
    
    for(int i=0;i<fre;i++){
        cout<<vlo[i]<<"\t";
    }
	cout << endl;
    mergso(vlo,0,fre-1);

    for(int i=0;i<fre;i++){
        cout<<vlo[i]<<"\t";
    }
    cout << endl;
    
    for(int i=0;i<fre;i++){
        cout<<vd[i]<<"\t";
    }
	cout << endl;
    mergso(vd,0,fre-1);

    for(int i=0;i<fre;i++){
        cout<<vd[i]<<"\t";
    }
    cout << endl;
    
    for(int i=0;i<fre;i++){
        cout<<vf[i]<<"\t";
    }
	cout << endl;
    mergso(vf,0,fre-1);

    for(int i=0;i<fre;i++){
        cout<<vf[i]<<"\t";
    }
    return 0;
}
