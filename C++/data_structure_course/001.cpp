#include <bits/stdc++.h>
using namespace std;

int fre=100000;       //quantity of data
int smfre=0;     //Use of small data

/*
input 1--> is sel bub merg 


*/
/*template <class ins>
    ins is(ins in,int n){
        ins temp;
        int j=0;
        for(int i=0;i<n;i++){
            ins temp=in[i];
            j=i-1;
            while(temp<in[j] && j>=0){
                in[j+1]=in[j];
                j--;
            }
            in[j+1]=temp;
        }
        return in;
    }*/

template <class se>
    se sel(se s,int n){
        for(int i=0;i<n;i++){
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
    void gogo(go fun,int stn,int dt){  //dt is data type
        fstream myfile;
        myfile.open("count.txt",ios::out);      //改app
        double sta,end,ti=999;
        sta=clock();        //timing start
        cout<<"\nsta "<<sta<<endl;    //test
        if(smfre>=2){
            for(int i=0;i<smfre;i++){
            fun;
            }
        }
        else{
            fun;
        }
        end=clock();    //timing end
        cout<<"\n1end "<<end<<endl;
        //cout<<"\n1usage time-->"<<ti<<"ms"<<endl; test
        if(smfre>=2){
            ti=(end-sta)/smfre;
        }
        else{
            ti=end-sta;
        }
        string st[4] {"insertion","selection","bubble","merge"};
        string dtl[5] {"string","int\t","long","double","float"};
        cout<<"Sort: \""<<st[stn]<<" \",data type is \" "<<dtl[dt]<<" \""<<endl;
        cout<<"usage time-->"<<ti<<"ms\n"<<endl;
        myfile<<st[stn]<<"\t"
                <<dtl[dt]<<"\t"
                <<ti<<"ms\t\t"
                <<fre<<"\n"
                <<endl;
        myfile.close();
        //return ti;
    }


int main(){
    cout<<"start"<<endl;
    double asta,aend,ati=999;
    /*
    list<string> as[fre];
    int ai[fre],pi;
    long alo[fre],plo;
    double ad[fre],pd;
    float af[fre],pf;
    */
    vector <string>vs;
    vector <int>vi;
    vector <long>vlo;
    vector <double>vd;
    vector <float>vf;
    
    /*
    array <string>vs;
    array <int>vi;
    array <long>vlo;
    array <double>vd;
    array <float>vf;
    */

    // open file
    fstream myfile;
    myfile.open("count.txt",ios::app);      //改app
    myfile<<"sort\t\t";
    myfile<<"type\t";
    myfile<<"time\t";
    myfile<<"data num\n\n";
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
        /*
        pi=rand()%rdn;
        plo=rand()%rdn;
        pd=rand()%rdn;
        pf=rand()%rdn;
        as[i]=na;
        ai[i]=pi;
        alo[i]=plo;
        ad[i]=pd;
        af[i]=pf;
        */
    }

    //sort choose
    int sc;
    cout<<"sort choose-->";
    cin>>sc;
    asta=clock();        //timing start
    switch (sc){
    case 1:
        /*gogo(is(vs,fre),0,0);
        gogo(is(vi,fre),0,1);
        gogo(is(vlo,fre),0,2);
        gogo(is(vd,fre),0,3);
        gogo(is(vf,fre),0,4);*/
        break;
    case 2:
        gogo(sel(vs,fre),1,0);
        gogo(sel(vi,fre),1,1);
        gogo(sel(vlo,fre),1,2);
        gogo(sel(vd,fre),1,3);
        gogo(sel(vf,fre),1,4);
        break;
    case 3:
        gogo(bub(vs,fre),2,0);
        gogo(bub(vi,fre),2,1);
        gogo(bub(vlo,fre),2,2);
        gogo(bub(vd,fre),2,3);
        gogo(bub(vf,fre),2,4);
        break;
    case 4:

        break;
    default:
        cout<<"404 error"<<endl;
        break;
    }
    
    //output(sel(vi,fre));


    aend=clock();    //timing end
    ati=(aend-asta)/1000;
    cout<<"\nAll time-->"<<ati<<"s"<<endl;
    myfile.open("count.txt",ios::app);      //改app
    myfile<<"All time-->"<<ati<<"s\n\n";
    myfile.close();
    return 0;
}