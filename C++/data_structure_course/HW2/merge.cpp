#include<bits/stdc++.h>
using namespace std;

int fre=100000000;
int smfre=5;


template <class rds,class rdi,class rdd,class rdf>
    void randd(rds &vs,rdi &vi,rdd &vd,rdf &vf){
		int pi;long plo;double pd;float pf;
        srand(time(NULL));
        int rdn=1,rdm=100000;
        for(int i=0;i<fre;i++){
            vi.push_back(rand()%rdm/int(rdn));
            vd.push_back(rand()%rdm/double(rdn));
            vf.push_back(rand()%rdm/float(rdn));
            string na="aaaaaa";
            for(int x=0;x<6;x++){
                na[x]+=rand()%26;
            }
            vs.push_back(na);
        }
    }

template <class mer>
    int merge(mer &mr,int sn,int md,int en){
        using elType = typename mer::value_type;
        int L_s=md-sn+1;
        int R_s=en-md;
        elType *L=new elType[L_s];
        elType *R=new elType[R_s];
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
        delete [] L;
        delete [] R;
        return 0;
    }

template <class mes>
    int mergeso(mes &ms,int st,int ed){
        if(st<ed){
            int md=(st+ed)/2;
            mergeso(ms,st,md);
            mergeso(ms,md+1,ed);
            merge(ms,st,md,ed);
        }
        return 0;
    }

int rd(){
	fstream myfile;
	myfile.open("count.txt",ios::app);      //改app
	myfile<<"------------------------------------------------------------------------\n\n";
	fre=100000000;
	myfile.close();
	return 0;
}

int main(void){
	cout<<"start\n";
	fstream myfile;
	myfile.open("count.txt",ios::app);      //改app
	myfile<<"--------------------------------Merge-----------------------------------\n\n";
    myfile.close();

	vector<string>vs;
	vector<int>vi;
	vector<double>vd;
	vector<float>vf;
	
	vs.reserve(500000000);
    vi.reserve(500000000);
    vd.reserve(500000000);
    vf.reserve(500000000);

	for (int i=0;i<smfre;i++){
		fstream myfile;
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		mergeso(vs,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" String "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n\n";
		cout<<"fre-->"<<fre<<"\tALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
		myfile.close();
	}

	rd();
	for (int i=0;i<smfre;i++){
		fstream myfile;
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		mergeso(vi,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" int "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n\n";
		cout<<"fre-->"<<fre<<"\tALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
		myfile.close();
	}

	rd();
	for (int i=0;i<smfre;i++){
		fstream myfile;
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		mergeso(vd,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" double "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n\n";
		cout<<"fre-->"<<fre<<"\tALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
		myfile.close();
	}

	rd();
	for (int i=0;i<smfre;i++){
		fstream myfile;
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		mergeso(vf,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" float "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n\n";
		cout<<"fre-->"<<fre<<"\tALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
		myfile.close();
	}
	
	
	myfile<<"------------------------------------------------------------------------\n\n";
	myfile.close();
	return 0; 
}