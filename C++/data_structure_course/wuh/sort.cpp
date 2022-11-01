#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string>

using namespace std;

template <class T>
class sort{
	public :
//		sort();
		void set(int number,int col);
		void output(int number,int col);
		void bubble(int number,int col);
		void selection(int number,int col);
		void insertion(int number,int col);
		void mergesort(int infront, int behide,int col);
		void merge(int infront, int behiden, int mid,int col);
	
	private :
		T **A;
	
	
};

int main(){
	srand(time(0));
	
	int number,col, change = 0;
	double start = 0, stop = 0;
	sort<double> data;
	cout << "quentity = ";
	cin >> number;
	cout << "column = ";
	cin >> col;
	
	cout << endl;
	data.set(number,col);
//	data.output(number,col);
	cout << endl;
	start = clock();
	for(int i=0;i<col;i++){
		data.bubble(number,i);
	}
	stop = clock();
//	data.output(number,col);
	cout << "\nbubblesort cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	
	cout << endl;
	data.set(number,col);
//	data.output(number,col);
	cout << endl;
	start = clock();
	for(int i=0;i<col;i++){
		data.selection(number,i);
	}
	stop = clock();
//	data.output(number,col);
	cout << "\nselectionsort cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	
	cout << endl;
	data.set(number,col);
//	data.output(number,col);
	cout << endl;
	start = clock();
	for(int i=0;i<col;i++){
		data.insertion(number,i);
	}
	stop = clock();
//	data.output(number,col);
	cout << "\ninsertionsort cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;

	cout << endl;
	data.set(number,col);
//	data.output(number,col);
	cout << endl;
	start = clock();
	for(int i=0;i<col;i++){
	data.mergesort(0, number-1,i);
	}
	stop = clock();
//	data.output(number,col);
	cout << "\nmergesort cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;

	return 0;
}

template <class T>
void sort<T>::set(int number,int col){
	char aph;
	A = new T*[col];
    for(int i = 0; i < col; i++)
        A[i] = new T[number];
	
	for(int k=0;k<col;k++){
		for(int i=0;i<number;i++){
			/*for(int j=0;j<6;j++){
				aph=rand()%26+97;
				A[k][i]=A[k][i]+aph;
			}*/ //string¶Ã¼Æ 
		//	A[k][i]=rand()%(1000000);//int¶Ã¼Æ 
			A[k][i]=(T)(rand())/(RAND_MAX +1)+1; //double ¶Ã¼Æ 
		}
	}
}

template <class T>
void sort<T>::output(int number,int col){
	for(int k=0;k<col;k++){	
		for(int i=0;i<number;i++){
			cout << A[k][i] << " ";
		}
		cout << endl;
	}
}

template <class T>
void sort<T>::bubble(int number,int col){
	for(int i=0; i<number-1; i++){
		for(int j=0; j<number-1-i; j++){
			if(A[col][j] > A[col][j+1]){
				swap(A[col][j], A[col][j+1]);
			}
		}
	} 
}

template <class T>
void sort<T>::selection(int number,int col){
	T temp;
	int count;
	for(int i=0;i<number-1;i++){
		temp=A[col][i];
		for(int j=i+1;j<number;j++){
			if(temp>A[col][j]){
				temp=A[col][j];
				count=j;
			}
		}
		swap(A[col][i],A[col][count]); 
	}
}

template <class T>
void sort<T>::insertion(int number,int col){
	T temp;
	int count;
	for(int i=1;i<number;i++){
		temp=A[col][i];
		count=i;
		for(int j=i-1;j>=0;j--){
			if(temp<A[col][j]){
				A[col][j+1]=A[col][j];
				count=j;
			}
			else break;
		}
		A[col][count]=temp;
	}
}

template <class T>
void sort<T>::mergesort(int first,int last,int col){
	if(first<last){
		int mid=(first+last)/2;
		mergesort(first,mid,col);
		mergesort(mid+1,last,col);
		merge(first,last,mid,col);
	}
}

template <class T>
void sort<T>::merge(int first,int last,int mid,int col){
	int size1=mid-first+1,size2=last-mid;
	int right=0,left=0;
	
	T *P=new T[size1];
	T *Q=new T[size2];
	
	for(int i=0;i<size1;i++){
		P[i]=A[col][i+first];
	}
	
	for(int i=0;i<size2;i++){
		Q[i]=A[col][i+mid+1];
	}
	
	for(int i=first;i<=last;i++){
		if(right==size2){
			for(int j=i;j<=last;j++){
				A[col][j]=P[left];
				left++;
			}
			break;
		}
		if(left==size1){
			for(int j=i;j<=last;j++){
				A[col][j]=Q[right];
				right++;
			}
			break;
		}
		
		if(P[left]<=Q[right]){
			A[col][i]=P[left];
			left++;
		}
		else{
			A[col][i]=Q[right];
			right++;
		}
	}
	
	delete []P;
	delete []Q;
}
