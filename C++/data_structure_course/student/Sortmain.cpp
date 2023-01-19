#include <bits/stdc++.h>
using namespace std;

int fre=50000000;	//初始數
int sfre=50000000;	//遞增數
int smfre=5;

template<class T>
void Adjust(T &a,int root,int n){
	auto e=a[root];
	int j;
	for(j=2*root;j<=n;j*=2){
		if(j<n&&a[j]<a[j+1])
			j++;
		if(e>=a[j])
			break;
		a[j/2]=a[j];
	}
	a[j/2]=e;
}

void HeapSort(vector<string>  &a,const int n){
	a.insert(a.begin(), "0"); 
	for(int i=n/2;i>=1;i--)
		Adjust(a,i,n);
	for(int i=n-1;i>=1;i--){//�Ƨ� 
		swap(a[1],a[i+1]);
		Adjust(a,1,i);
	}
	a.erase(a.begin());  
}

template<class T>
void HeapSort(T &a,const int n){
	a.insert(a.begin(), 0); 
	for(int i=n/2;i>=1;i--)
		Adjust(a,i,n);
	for(int i=n-1;i>=1;i--){//�Ƨ� 
		swap(a[1],a[i+1]);
		Adjust(a,1,i);
	}
	a.erase(a.begin());  
}

int rd(){
	fstream myfile;
	myfile.open("count.txt",ios::app);      //改app
	myfile<<"------------------------------------------------------------------------\n\n";
	fre=sfre;
	myfile.close();
	return 0;
}

int main(void){
	fstream myfile;
	myfile.open("count.txt",ios::app);      //改app
	myfile<<"--------------------------------HeapSort--------------------------------\n\n";
    myfile.close();

	srand(time(NULL)) ;
	vector<string>vs;
	vector<int>vi;
	vector<double>vd;
	vector<float>vf;
	
	vs.reserve(500000000);
	vi.reserve(500000000);
	vd.reserve(500000000);
	vf.reserve(500000000);
    int data[5]={50000000,100000000,150000000,200000000,250000000};
    clock_t start,end;
    double time;

//STL::algorithm:: sort()
	for(int i=5;i<5;i++){
		cout<<data[i]<<endl;
	
		//double algorithm:: sort()
		C(dr,data[i]);
		start=clock();
		sort(dr.begin(),dr.begin()+data[i]);
		end=clock();
		dr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��double���algorithm::sort()���ɶ���: "<<time<<endl; 
		

		C(fr,data[i]);

		start=clock();
		sort(fr.begin(),fr.begin()+data[i]);
		end=clock();
		fr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"�� float���algorithm::sort()���ɶ���: "<<time<<endl; 
		

		C(ir,data[i]);

		start=clock();
		sort(ir.begin(),ir.begin()+data[i]);
		end=clock();
		ir.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��   int���algorithm::sort()���ɶ���: "<<time<<endl; 
		

		C(sr,data[i]);

		start=clock();
		sort(sr.begin(),sr.begin()+data[i]);
		end=clock();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��string���algorithm::sort()���ɶ���: "<<time<<endl; 	
		sr.clear();
	}

//STL::algorithm:: stable_sort(

	for(int i=0;i<5;i++){
		cout<<data[i]<<endl;
		
		//double algorithm::stable_sort()
		C(dr,data[i]);
		start=clock();
		stable_sort(dr.begin(),dr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		dr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��double���algorithm::stable_sort()���ɶ���: "<<time<<endl; 
		
		//float algorithm::stable_sort()
		C(fr,data[i]);
		start=clock();
		stable_sort(fr.begin(),fr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		fr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"�� float���algorithm::stable_sort()���ɶ���: "<<time<<endl; 
		
		//int algorithm::stable_sort()
		C(ir,data[i]);
		start=clock();
		stable_sort(ir.begin(),ir.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		ir.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��   int���algorithm::stable_sort()���ɶ���: "<<time<<endl; 
		
		//string algorithm::stable_sort()
		C(sr,data[i]);
		start=clock();
		stable_sort(sr.begin(),sr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��string���algorithm::stable_sort()���ɶ���: "<<time<<endl; 
		//sr.clear();	
	}
	
// HeapSort
  	for(int i=0;i<5;i++){//�H������1���A2���A3���A4���A5������� 
		cout<<data[i]<<endl;
  	  
	    //double HeapSort
		C(dr,data[i]);   //	printA(dr,data[i]);
		start=clock();
		HeapSort(dr,data[i]);//printA(dr,data[i]);
		end=clock(); 
		dr.clear();	
	    time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��double���HeapSort���ɶ���: "<<time<<endl; 
		
   		 //float HeapSort
    	C(fr,data[i]);//	printA(fr,data[i]);
    	start=clock();
  		HeapSort(fr,data[i]);
  		end=clock(); //printA(fr,data[i]);
		fr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"�� float���HeapSort���ɶ���: "<<time<<endl; 
		
    	//int HeapSort
    	C(ir,data[i]);//	printA(ir,data[i]);
    	start=clock();
  		HeapSort(ir,data[i]);
  		end=clock(); //printA(ir,data[i]);
		ir.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��   int���HeapSort���ɶ���: "<<time<<endl; 

		//string HeapSort
		C(sr,data[i]);//	printA(sr,data[i]);
    	start=clock();
  		HeapSort(sr,data[i]);	
		end=clock(); //printA(sr,data[i]);
		sr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"��string���HeapSort���ɶ���: "<<time<<endl; 
			
	}
	file<<"�����w�]��"<<endl;	
	system("pause");
	return 0;
	
	
	 
/*
	C(dr,10);
		for(int j=0;j<10;j++){cout<<dr[j]<<"   ";} cout<<endl;	
	stable_sort(dr.begin(),dr.end());
	for(int j=0;j<10;j++){cout<<dr[j]<<"   ";} cout<<endl;	
	dr.clear();
	C(fr,10);
		for(int j=0;j<10;j++){cout<<fr[j]<<"   ";} cout<<endl;	
	stable_sort(fr.begin(),fr.end());
	for(int j=0;j<10;j++){cout<<fr[j]<<"   ";} cout<<endl;	
	fr.clear();
	C(ir,10);
		for(int j=0;j<10;j++){cout<<ir[j]<<"   ";} cout<<endl;	
	stable_sort(ir.begin(),ir.end());
	for(int j=0;j<10;j++){cout<<ir[j]<<"   ";} cout<<endl;	
	ir.clear();
	C(sr,10);
		for(int j=0;j<10;j++){cout<<sr[j]<<"   ";} cout<<endl;	
	stable_sort(sr.begin(),sr.end());
	for(int j=0;j<10;j++){cout<<sr[j]<<"   ";} cout<<endl;	
	sr.clear();
*/ 
}
