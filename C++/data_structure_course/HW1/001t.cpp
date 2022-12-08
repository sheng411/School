#include <bits/stdc++.h>
#include <ctime>
using namespace std;


constexpr int arnum=100000;
long smfre=1;     //Use of small data
int fre=arnum;       //quantity of data

/*
input 1--> ins sel bub merg 


*/


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

template <class ins>
    int is(ins &in,int n){
        //ins temp;
        int j=0;
        for(int i=1;i<n;i++){
            auto temp=in[i];
            j=i-1;
            while(j>=0 && temp<in[j]){
                in[j+1]=in[j];
                j--;
            }
            in[j+1]=temp;
        }
        return 0;
    }

template <class se>
    int sel(se &s,int n){
        for(int i=0;i<n-1;i++){
            int mins=i;
            for(int j=i+1;j<n;j++){
                if(s[j]<s[mins]){
                    mins=j;
                }
            }
            if(mins!=i){
                swap(s[i],s[mins]);
            }
        }
        return 0;
    }

template <class bu>
    int bub(bu &b,int n){     //b is list ,n is list size.
        int i,j,k;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(b[j]>b[j+1]){
                    swap(b[j],b[j+1]);
                }
            }
        }
        return 0;
    }


template <class out>
    void output(out st){
        double sta,end,ti;
        sta=clock();        //timing start
        for(int c=0;c<fre;c++){
            cout<<st[c]<<"\t";
        if(c>=10 && c%10==0){
            cout<<endl;
            }
        }
    }

template <class go,class rds,class rdi,class rdlo,class rdd,class rdf,class rdas,class rdai,class rdalo,class rdad,class rdaf,class rdaas,class rdaai,class rdaalo,class rdaad,class rdaaf>
    int gogo(go fun,int stn,int dt,int dsn,rds &vs,rdi &vi,rdlo &vlo,rdd &vd,rdf &vf,rdas &as,rdai &ai,rdalo &alo,rdad &ad,rdaf &af,rdaas &aas,rdaai &aai,rdaalo &aalo,rdaad &aad,rdaaf &aaf){  //dt is data type
        fstream myfile,read;
        myfile.open("count.txt",ios::app);      //改app
        auto gst=chrono::steady_clock::now();
        if(smfre>=2){
            for(int i=0;i<smfre;i++){
                fun;
                randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            }
        }
        else{
            fun;
        }
        auto gend=chrono::steady_clock::now();
        long long ti=chrono::duration_cast<chrono::nanoseconds>((gend-gst)/smfre).count();
        string dtl[5] {"string","int\t","long","double","float"};
        string st[4] {"insertion","selection","bubble","merge"};
        string ds[3] {"C array","vector","std array"};
        cout<<"Sort: \""<<st[stn]<<" \",data type is \" "<<dtl[dt]<<" \""<<"data str"<<ds[dsn]<<endl;
        cout<<"usage time-->"<<ti<<"ns\n"<<endl;
        myfile<<dtl[dt]<<"\t\t"
                <<st[stn]<<"\t\t"
                <<ti<<"ns\t\t"
                <<fre<<"\t\t"
                <<smfre<<"\t\t"
                <<ds[dsn]<<"\n"
                <<endl;
        myfile.close();

        //input read
        read.open("read.txt",ios::app);     //app
        read<<st[stn]<<" "
            <<dtl[dt]<<" "
            <<ti<<" "
            <<fre<<" "
            <<smfre<<" "
            <<ds[dsn]<<" "
            <<endl;
            read.close();
        return 0;
    }


/*
template <class cls,class cli,class cllo,class cld,class clf,class clas,class clai,class clalo,class clad,class claf,class claas,class claai,class claalo,class claad,class claaf>
    void clearr(){
        cls vs.clear();
        cli vi.clear();
        vlo.clear();
        vd.clear();
        as.clear();
        ai.clear();
        alo.clear();
        ad.clear();
        af.clear();
        aas.clear();
        aai.clear();
        aalo.clear();
        aad.clear();
        aaf.clear();
    }
*/
template <class T>
    int timE(int s,int d,T f){
        fstream myfile;
        auto start = chrono::steady_clock::now();
        f;
        auto end = chrono::steady_clock::now();
        long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
        double ats=att*0.000000001;
        string st[4] {"insertion","selection","bubble","merge"};
        string ds[3] {"C array","vector","std array"};
        myfile.open("count.txt",ios::app);      //改app
        myfile<<"sort-->"<<st[s]<<" type-->"<<ds[d]<<"\ntime-->"<<att<<"ns-->"<<ats<<"s\n";
        myfile<<"------------------------------------------------------------------------------------\n\n";
        myfile.close();
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
    
    fstream read;
    read.open("read.txt",ios::out);
    read.close();
    
    // open file
    fstream myfile;
    myfile.open("count.txt",ios::app);      //改app /out
    myfile<<"type\t\t";
    myfile<<"sort\t\t";
    myfile<<"time\t\t";
    myfile<<"data num\t";
    myfile<<"rep ti\t\t";   //repeat time
    myfile<<"data str\n\n";
    
    
    cout<<"file 200OK"<<endl;

    
    srand(time(NULL));
    int rdn=10,rdm=10000;

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


    //sort choose
    int sc;
    cout<<"fre:"<<fre<<",smfre:"<<smfre<<endl;
    cout<<"type choose-->";
    cin>>sc;
    string st[] {"C array","std vector","std array"};
    myfile<<"fre:"<<fre<<" , smfre:"<<smfre<<" , type-->"<<st[sc-1]<<"\n\n";
    myfile.close();

    if (smfre==1){
        //C array
        timE(0,0,gogo(is(as,fre),0,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,0,gogo(sel(as,fre),1,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,0,gogo(bub(as,fre),2,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,0,gogo(is(ai,fre),0,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,0,gogo(sel(ai,fre),1,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,0,gogo(bub(ai,fre),2,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,0,gogo(is(alo,fre),0,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,0,gogo(sel(alo,fre),1,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,0,gogo(bub(alo,fre),2,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,0,gogo(is(ad,fre),0,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,0,gogo(sel(ad,fre),1,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,0,gogo(bub(ad,fre),2,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,0,gogo(is(af,fre),0,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,0,gogo(sel(af,fre),1,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,0,gogo(bub(af,fre),2,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        //std vector
        timE(0,1,gogo(is(vs,fre),0,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,1,gogo(sel(vs,fre),1,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,1,gogo(bub(vs,fre),2,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,1,gogo(is(vi,fre),0,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,1,gogo(sel(vi,fre),1,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,1,gogo(bub(vi,fre),2,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,1,gogo(is(vlo,fre),0,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,1,gogo(sel(vlo,fre),1,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,1,gogo(bub(vlo,fre),2,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,1,gogo(is(vd,fre),0,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,1,gogo(sel(vd,fre),1,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,1,gogo(bub(vd,fre),2,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,1,gogo(is(vf,fre),0,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,1,gogo(sel(vf,fre),1,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,1,gogo(bub(vf,fre),2,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        //srd array
        timE(0,2,gogo(is(aas,fre),0,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,2,gogo(sel(aas,fre),1,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,2,gogo(bub(aas,fre),2,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,2,gogo(is(aai,fre),0,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,2,gogo(sel(aai,fre),1,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,2,gogo(bub(aai,fre),2,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,2,gogo(is(aalo,fre),0,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,2,gogo(sel(aalo,fre),1,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,2,gogo(bub(aalo,fre),2,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,2,gogo(is(aad,fre),0,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,2,gogo(sel(aad,fre),1,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,2,gogo(bub(aad,fre),2,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(0,2,gogo(is(aaf,fre),0,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(1,2,gogo(sel(aaf,fre),1,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));
        timE(2,2,gogo(bub(aaf,fre),2,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf));

    }
    else{
        auto start = chrono::steady_clock::now();
        switch (sc){
        // C array
        case 1:
            gogo(is(as,fre),0,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(as,fre),1,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(as,fre),2,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(ai,fre),0,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(ai,fre),1,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(ai,fre),2,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(alo,fre),0,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(alo,fre),1,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(alo,fre),2,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(ad,fre),0,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(ad,fre),1,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(ad,fre),2,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(af,fre),0,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(af,fre),1,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(af,fre),2,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            break;
        // std vector
        case 2:
            gogo(is(vs,fre),0,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(vs,fre),1,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(vs,fre),2,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(vi,fre),0,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(vi,fre),1,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(vi,fre),2,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(vlo,fre),0,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(vlo,fre),1,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(vlo,fre),2,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(vd,fre),0,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(vd,fre),1,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(vd,fre),2,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(vf,fre),0,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(vf,fre),1,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(vf,fre),2,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            break;
        // std array
        case 3:
            gogo(is(aas,fre),0,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(aas,fre),1,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(aas,fre),2,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(aai,fre),0,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(aai,fre),1,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(aai,fre),2,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(aalo,fre),0,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(aalo,fre),1,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(aalo,fre),2,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(aad,fre),0,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(aad,fre),1,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(aad,fre),2,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);

            gogo(is(aaf,fre),0,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(sel(aaf,fre),1,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            gogo(bub(aaf,fre),2,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
            break;
        default:
            cout<<"404 error"<<endl;
            break;
        }
    
    //output(sel(vi,fre));

    auto end = chrono::steady_clock::now();
    long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    double ats=att*0.000000001;
    cout<<"\nAll time-->"<<att<<"ns"<<endl;
    myfile.open("count.txt",ios::app);      //改app
    myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    myfile<<"------------------------------------------------------------------------------------\n\n";
    myfile.close();
    }
    return 0;
}