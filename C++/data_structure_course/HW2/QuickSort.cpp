#include<bits/stdc++.h>
using namespace std;

int fre=0;

void C(vector<double> &randnuma,int MAX){
	double min=0.0,max=100000.0000000000;
	for(int i=0;i<MAX;i++){
		double j=(double)(max-min)*rand()/(RAND_MAX+1.0);
		randnuma.push_back(j);
	}
/*	cout<<"�Ƨǫe";
	cout<<"double:  ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
cout<<endl;*/
}
void C(vector<float>&randnuma,int MAX){
	float min=0.0f,max=10000.0f;
	for(int i=0;i<MAX;i++){
		randnuma.push_back((float)(max-min)*rand()/(RAND_MAX+1.0));
	}
/*	 cout<<"float: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/
}

void C(vector<int> &randnuma,int MAX){
	for(int i=0;i<MAX;i++){
		randnuma.push_back(rand());
	}
/*   cout<<"int: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/

}

void C(vector<string>  &randnuma,int MAX){
	for(int i=0;i<MAX;i++){	
		string str="aaaaaa";
		for(int k=0;k<6;k++){
			str[k]+=rand()%26;
		}
		randnuma.push_back(str);
	}
/*  cout<<"string: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/
    
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
	
	vector<int>ir;
    ir.reserve(500000000);
    vector<float>fr;
    fr.reserve(500000000);
    vector<double>dr;
    dr.reserve(500000000);
    vector<string>sr;
    sr.reserve(500000000);
    C(ir,100000000);
	auto start = chrono::steady_clock::now();
    QuickSort(ir,0,100000000-1);
	auto end = chrono::steady_clock::now();
	long long att=chrono::duration_cast<chrono::seconds>(end-start).count();    //秒 seconds
	
	for(int j=0;j<10000000;j++){
			cout<<ir[j]<<"\t ";
	}
	cout<<"ALL Time-->"<<att<<endl;
	return 0; 
}
