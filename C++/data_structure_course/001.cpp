#include <bits/stdc++.h>
using namespace std;

int fre=10;       //quantity of data
int smfre=0;     //Use of small data

/*
template <class ins>
    ins is(ins in,int n){
        int temp,j=0;
        double sta,end,ti;
        sta=clock();
        for(int i=0;i<n;i++){
            temp=in[i];
            j=i-1;
            while(temp<in[j] && j>=0){
                in[j+1]=in[j-1];
                j--;
            }
            in[j+1]=temp;
        }
        end=clock();
        ti=(end-sta)/1000;
        cout<<fre<<"data"<<endl;
        cout<<"insertion list-->"<<in<<endl;
        //cout<<"usage time-->"<<ti<<"s"<<endl;
        return in;
    }

template <class se>
    se sel(se s,int n){
        double sta,end,ti;
        sta=clock();
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
        end=clock();
        ti=(end-sta)/1000;
        cout<<fre<<"data"<<endl;
        cout<<"insertion list-->"<<s<<endl;
        //cout<<"usage time-->"<<ti<<"s"<<endl;
        return s;
    }

*/
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
        /*
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
        for(int c=0;c<fre;c++){
            cout<<st[c]<<"\t";
        if(c>=10 && c%10==0){
            cout<<endl;
            }
        }
    }


int main(){
    vector <int>a;
    vector <float>f;
    int len,len1;
    double sta,end,ti;
    
    srand(time(NULL));
    
    // open file
    fstream myfile;
    myfile.open("count.txt",ios::app);
    myfile<<"data\n";
    myfile.close();
    
    for(int i=0;i<fre;i++){
        a.push_back(rand()%100);
        //f.push_back(rand()%100);
    }
    len=a.size();

    //timing start
    sta=clock();
    if(smfre!=0){
        for(int i=0;i<smfre;i++){
            //123
        }
    }
    else{
        bub(a,len);
    }
    end=clock();
    //timing end
    ti=(end-sta)/1000;
    output(bub(a,len));
    cout<<"\nlen-->"<<len<<endl;
    cout<<"usage time-->"<<ti<<"s"<<endl;
    return 0;
}