#include<bits/stdc++.h>
using namespace std;

int fre=100000000;
int smfre=1;

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

template<class T>
	int partition(T &A,const int p ,const int r){
		using elType = typename	T::value_type;
		elType x=A[r];
		int i=p-1;
		for(int j=p;j<=r-1;j++){
			if(A[j]<=x){
				i=i+1;
			//	elType *a=new elType[i];
				auto temp=A[i];
				A[i]=A[j];
				A[j]=temp;
				}
		}
		
		auto temp=A[i+1];
		A[i+1]=A[r];
		A[r]=temp;
		return i+1;
	}

template<class T>
	void QuickSort(T &A,const int p ,const int r){
		if(p<r){
			int q=partition(A,p,r);
			QuickSort(A,p,q-1);
			QuickSort(A,q+1,r);
		}
	}

int main(void){
	cout<<"start\n";
	fstream myfile;
	myfile<<"--------------------------------Quick-----------------------------------\n\n";

	vector<string>vs;
	vector<int>vi;
	vector<double>vd;
	vector<float>vf;
	
	vs.reserve(500000000);
    vi.reserve(500000000);
    vd.reserve(500000000);
    vf.reserve(500000000);

	for (int i=0;i<smfre;i++){
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		QuickSort(vs,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" String "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n";
		cout<<"fre-->"<<fre<<"ALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
	}

	myfile<<"------------------------------------------------------------------------------------\n\n";
	for (int i=0;i<smfre;i++){
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		QuickSort(vi,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" int "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n\n";
		cout<<"fre-->"<<fre<<"ALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
	}

	myfile<<"------------------------------------------------------------------------------------\n\n";
	for (int i=0;i<smfre;i++){
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		QuickSort(vd,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" double "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n\n";
		cout<<"fre-->"<<fre<<"ALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
	}
	
	myfile<<"------------------------------------------------------------------------------------\n\n";
	for (int i=0;i<smfre;i++){
		cout<<"for go\n";
		randd(vs,vi,vd,vf);
		cout<<"rand ok\n";
		auto start = chrono::steady_clock::now();
		QuickSort(vf,0,fre-1);
		auto end = chrono::steady_clock::now();
		long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
		myfile.open("count.txt",ios::app);      //改app
		myfile<<"Data type-->"<<" float "<<"\tData quantity-->"<<fre<<"\tUsage time-->"<<att<<"s\n\n";
		cout<<"fre-->"<<fre<<"ALL Time-->"<<att<<endl;
		fre+=100000000;
		vs.clear();
		vi.clear();
		vd.clear();
		vf.clear();
	}
	
	
	myfile<<"------------------------------------------------------------------------------------\n\n";
	myfile.close();
	return 0; 
}
