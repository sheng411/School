#include <bits/stdc++.h>
using namespace std;

int fre=100000;       //quantity of data
long double smfre=1;     //Use of small data

/*
input 1--> is sel bub merg 

更改時間:2022/10/10 17:00
*/

//insertion sort經更改過仍會出現錯誤
/*template <class ins>
    void is(ins *in,int n){
        ins temp;
        int j=0;
        for(int i=1;i<n;i++){
            temp=in[i];
            j=i-1;
            while(j>=0 && temp<in[j]){
                in[j+1]=in[j];
                j--;
            }
            in[j+1]=temp;
        }
    }*/

template <class se>
    se sel(se s,int n){
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
        return s;
    }

template <class bu>
    bu bub(bu b,int n){     //b is list ,n is list size.
        int i,j,k;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(b[j]>b[j+1]){
                    swap(b[j],b[j+1]);
                }
            }
        }
        return b;
    }

/*
int Mx=1000;
template <class mer>
    void merg(mer mr,int sn,int md,int en){
        mer l(mr.begin()+sn,mr.begin()+md+1),
            r(mr.begin()+md,mr.begin()+en+1);
        l.insert(l.end(),Mx);
        r.insert(r.end(),Mx);
        int il=0,ir=0;
        for(int i=sn;i<=en;i++){
            if(l[il]<=r[ir]){
                mr[i]=l[il];
                il++;
            }
            else{
                mr[i]=r[ir];
                ir++;
            }
        }
    }


template <class mers>
    void mergsort(mers m,int snr,int enr){      //snr is start num,enr is end num.
        if(snr<enr){
            int mid=(snr+enr)/2;
            mergsort(m,snr,mid);
            mergsort(m,mid+1,enr);
            merg(m,snr,mid,enr);
        }
        cout<<"merge list-->"<<endl;
        for(int c=0;c<fre;c++){
            cout<<m[c]<<"\t";
            if(c%10==0){
                cout<<endl;
            }
        }
    }*/

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

template <class go>
    void gogo(go fun,int stn,int dt,int dsn){  //dt is data type
        fstream myfile;
        myfile.open("count.txt",ios::app);      //改app
        auto gst=chrono::steady_clock::now();
        //cout<<"\nsta "<<gst<<endl;    //test
        if(smfre>=2){
            for(int i=0;i<smfre;i++){
                fun;
            }
        }
        else{
            fun;
        }
        auto gend=chrono::steady_clock::now();
        //cout<<"\n1end "<<gend<<endl;
        //cout<<"\n1usage time-->"<<ti<<"ms"<<endl; test

        long double ti=chrono::duration_cast<chrono::nanoseconds>(gend-gst).count();
        string st[4] {"insertion","selection","bubble","merge"};
        string dtl[5] {"string","int\t","long","double","float"};
        string ds[3] {"C array","vector","std array"};
        cout<<"Sort: \""<<st[stn]<<" \",data type is \" "<<dtl[dt]<<" \""<<"data str"<<ds[dsn]<<endl;
        cout<<"usage time-->"<<ti<<"ns\n"<<endl;
        myfile<<st[stn]<<"\t\t"
                <<dtl[dt]<<"\t\t"
                <<ti<<"ns\t\t"
                <<fre<<"\t\t"
                <<smfre<<"\t\t"
                <<ds[dsn]<<"\n"
                <<endl;
        myfile.close();
        //return ti;
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
    
    /*
    array <string,100> aas;
    array <int,100> aai;
    array <long,100> aalo;
    array <double,100> aad;
    array <float,100> aaf;
    */


    // open file
    fstream myfile;
    myfile.open("count.txt",ios::out);      //改app
    myfile<<"sort\t\t";
    myfile<<"type\t\t";
    myfile<<"time\t\t";
    myfile<<"data num\t";
    myfile<<"rep ti\t\t";   //repeat time
    myfile<<"data str\n\n";
    myfile.close();
    
    cout<<"file 200OK"<<endl;

    int num,rdn;
    srand(time(NULL));

    rdn=1000;

    for(int i=0;i<fre;i++){
        vi.push_back(rand()%rdn);
        vlo.push_back(rand()%rdn);
        vd.push_back(rand()%rdn);
        vf.push_back(rand()%rdn);
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        vs.push_back(na);

        pi=rand()%rdn;
        plo=rand()%rdn;
        pd=rand()%rdn;
        pf=rand()%rdn;
        as[i]=na;
        ai[i]=pi;
        alo[i]=plo;
        ad[i]=pd;
        af[i]=pf;
        
    }

    //sort choose
    int sc;
    cout<<"sort choose-->";
    cin>>sc;
    auto start = chrono::steady_clock::now();
    switch (sc){
    case 1:/*
        gogo(is(as,fre),0,0,0);
        gogo(is(ai,fre),0,1,0);
        gogo(is(alo,fre),0,2,0);
        gogo(is(ad,fre),0,3,0);
        gogo(is(af,fre),0,4,0);
        gogo(is(vs,fre),0,0,1);
        gogo(is(vi,fre),0,1,1);
        gogo(is(vlo,fre),0,2,1);
        gogo(is(vd,fre),0,3,1);
        gogo(is(vf,fre),0,4,1);*/
        break;
    case 2:
        gogo(sel(as,fre),1,0,0);
        gogo(sel(ai,fre),1,1,0);
        gogo(sel(alo,fre),1,2,0);
        gogo(sel(ad,fre),1,3,0);
        gogo(sel(af,fre),1,4,0);
        gogo(sel(vs,fre),1,0,1);
        gogo(sel(vi,fre),1,1,1);
        gogo(sel(vlo,fre),1,2,1);
        gogo(sel(vd,fre),1,3,1);
        gogo(sel(vf,fre),1,4,1);
        break;
    case 3:
        gogo(bub(as,fre),2,0,0);
        gogo(bub(ai,fre),2,1,0);
        gogo(bub(alo,fre),2,2,0);
        gogo(bub(ad,fre),2,3,0);
        gogo(bub(af,fre),2,4,0);
        gogo(bub(vs,fre),2,0,1);
        gogo(bub(vi,fre),2,1,1);
        gogo(bub(vlo,fre),2,2,1);
        gogo(bub(vd,fre),2,3,1);
        gogo(bub(vf,fre),2,4,1);
        break;
    case 4:

        break;
    default:
        cout<<"404 error"<<endl;
        break;
    }
    
    //output(sel(vi,fre));


    auto end = chrono::steady_clock::now();
    long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    cout<<"\nAll time-->"<<att<<"ns"<<endl;
    myfile.open("count.txt",ios::app);      //改app
    myfile<<"All time-->"<<att<<"ns\n\n";
    myfile.close();
    return 0;
}