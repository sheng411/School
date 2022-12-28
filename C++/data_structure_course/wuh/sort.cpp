#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

template <class T>
class sort{
public :
void set(int number);
void output(int number);
void mergesort(int infront, int behide);
void merge(int infront, int behiden, int mid);
void heapsort(int number);
void Max_Heapify(int k,int size);
void Build_Max_Heap(int number);
  void quicksort(int p,int r);
int partation(int p,int r);
T *A;
};

int main(void){
	srand(time(0));
	
	ofstream ofs;
	ofs.open("c++_sorttime.txt",ios::app);
	char aph;
	double start = 0, stop = 0,ans=0;
	sort<string> data;
	
	for(int number=100000000;number<=100000000;number+=20000000){
	
		ofs << "\n";
		ofs << number << "\n";
		ofs << "\n\n";
		data.set(number);
		//data.output(number);
		start = clock();
		data.heapsort(number);
		stop = clock();
		//data.output(number);
		ans=(stop - start) / CLOCKS_PER_SEC;
		ofs << "\nheapsort cost time : " << ans << "\n";
		delete []data.A;
		cout << "cheak line" << endl;
		
		ofs << "\n";
		data.set(number);
		//data.output(number);
		ofs << "\n";
		start = clock();
		data.quicksort(0,number-1);
		stop = clock();
		//data.output(number);
		ans=(stop - start) / CLOCKS_PER_SEC;
		ofs << "\nqiucksort cost time : " << ans << endl;
		delete []data.A;
		cout << "cheak line" << endl;
		
		ofs << "\n";
		data.set(number);
		//data.output(number);
		ofs << "\n";
		start = clock();
		data.mergesort(0, number-1);
		stop = clock();
		//data.output(number);
		ans=(stop - start) / CLOCKS_PER_SEC;
		ofs << "\nmergesort cost time : " << ans << endl;
		delete []data.A;
		cout << "cheak line" << endl;
	}
	ofs.close();
	return 0;
}

template <class T>
void sort<T>::set(int number){
	char aph;
	    A= new T[number];
	for(int i=0;i<number;i++){
		for(int j=0;j<6;j++){
			aph=rand()%26+97;
			A[i]=A[i]+aph;
		} //string¶Ã¼Æ
		//A[i]=rand()%(1000000);//int¶Ã¼Æ
		//A[i]=(T)(rand())/(RAND_MAX +1)+1; //double ¶Ã¼Æ
	}
}


template <class T>
void sort<T>::output(int number){
	for(int i=0;i<number;i++){
		printf("%s ",A[i].c_str());
	}
}

template <class T>
void sort<T>::heapsort(int number){
	int size=number;
	Build_Max_Heap(number);
	for(int j=number;j>1;j--){
		swap(A[0],A[j-1]);
		size--;
		Max_Heapify(1,size);
	}
}

template <class T>
void sort<T>::Build_Max_Heap(int number){
	int size=number;
	for(int i=size/2;i>0;i--){
		Max_Heapify(i,size);
	}
}

template <class T>
void sort<T>::Max_Heapify(int k,int size){
	int left=2*k-1,right=2*k,largest;
	if(left<=size && A[left-1]>A[k-1]){
		largest=left;
	}
	else{
		largest=k;
	}
	if(right<=size && A[right-1]>A[largest-1]){
		largest=right;
	}
	if(largest!=k){
		swap(A[k-1],A[largest-1]);
		Max_Heapify(largest,size);
	}
}

template <class T>
void sort<T>::quicksort(int p,int r){
	int q;
	if(p<r){
	    q=partation(p,r);
	    quicksort(p,q-1);
	    quicksort(q+1,r);
	}
}

template <class T>
int sort<T>::partation(int p,int r){
	int i=p-1;
	for(int j=p;j<r;j++){
		if(A[j]<=A[r]){
		i++;
		swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	
	return i+1;
}

template <class T>
void sort<T>::mergesort(int first,int last){
	if(first<last){
		int mid=(first+last)/2;
		mergesort(first,mid);
		mergesort(mid+1,last);
		merge(first,last,mid);
	}
}

template <class T>
void sort<T>::merge(int first,int last,int mid){
	int size1=mid-first+1,size2=last-mid;
	int right=0,left=0;
	
	T *P=new T[size1];
	T *Q=new T[size2];
	
	for(int i=0;i<size1;i++){
		P[i]=A[i+first];
	}
	
	for(int i=0;i<size2;i++){
		Q[i]=A[i+mid+1];
	}
	
	for(int i=first;i<=last;i++){
		if(right==size2){
		for(int j=i;j<=last;j++){
			A[j]=P[left];
			left++;
		}
		break;
		}
		if(left==size1){
			for(int j=i;j<=last;j++){
				A[j]=Q[right];
				right++;
			}
		break;
		}
		
		if(P[left]<=Q[right]){
			A[i]=P[left];
			left++;
		}
		else{
			A[i]=Q[right];
			right++;
		}
	}

	delete []P;
	delete []Q;
}

