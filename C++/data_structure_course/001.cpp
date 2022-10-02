#include <bits/stdc++.h>
using namespace std;

int fre=100000;       //quantity of data
int smfre=0;     //Use of small data

/*
input 1--> is sel bub merg 


*/
template <class ins>
    ins is(ins in,int n){
        int temp,j=0;
        for(int i=0;i<n;i++){
            temp=in[i];
            j=i-1;
            while((temp<in[j]) && (j>=0)){
                in[j+1]=in[j];
                j--;
            }
            in[j+1]=temp;
        }
        return in;
    }

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
    void gogo(go fun){
        double sta,end,ti=999;
        sta=clock();        //timing start
        if(smfre!=0 && smfre!=1){
            for(int i=0;i<smfre;i++){
            fun;
            }
            end=clock();    //timing end
        }
        else{
            fun;
            end=clock();    //timing end
        }
        
        if(smfre!=0 && smfre!=1){
            ti=(end-sta);//smfre;
        }
        else{
            ti=end-sta;
        }
        cout<<"usage time-->"<<ti<<"ms"<<endl;
        //return ti;
    }


int main(){
    cout<<"132";
    /*
    string as[fre];
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
    myfile.open("count.txt",ios::out);      //改app
    myfile<<"type\t";
    myfile<<"sort\t";
    myfile<<"time\t";
    myfile.close();
    
    cout<<"1259";

    int num;
    srand(time(NULL));
    for(int i=0;i<fre;i++){
        vi.push_back(rand()%100);
        vlo.push_back(rand()%100);
        vd.push_back(rand()%100);
        vf.push_back(rand()%100);
        string na="aaaaaa";
        for(int x=0;x<6;x++){
            na[x]+=rand()%26;
        }
        vs.push_back(na);
        /*
        pi=rand()%100;
        plo=rand()%100;
        pd=rand()%100;
        pf=rand()%100;
        as[i]=na;
        ai[i]=pi;
        alo[i]=plo;
        ad[i]=pd;
        af[i]=pf;
        */
    }

    gogo(bub(vi,fre));
    //output(sel(vi,fre));
    //cout<<"usage time-->"<<ti<<"ms"<<endl;
    return 0;
}