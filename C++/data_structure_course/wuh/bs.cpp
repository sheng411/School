#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<string>
#include<iomanip>

using namespace std;
int success=0,notfound=0;


template<class T>
class TreeNode {
	public:
		T data;
  		TreeNode *leftChild=NULL;
  		TreeNode *rightChild=NULL;
};


template<class T>
class binarysearch{
	friend class TreeNode<T>;
	public:	
		void output(int number);
		void outputtarget(int number);
		bool rebinarysearch(int first,int last,int time);
		bool irbinarysearch(int number,int time);
		void set(int number);
		void settarget(int time); 
		void quicksort(int p,int r);
		int partation(int p,int r);	
		void binarytreeinsert(int number);
		void inorder(TreeNode <T>*root ,int time);
		void hashinsert(int number);
		T *A;
		T *target;
		TreeNode <T>*tree;
};

int main (){
	srand(time(0));
	int number,time;
	binarysearch <string> data;
	string *target,*A; 
	char aph;
	double start,stop;
	cout << "quentity = ";
	cin >> number;
	cout << "time = ";
	cin >> time;
		
	success=0;
	notfound=0;
	data.settarget(time);
	start = clock();
	data.set(number);
//	data.output(number);
	cout << endl << endl;
	data.quicksort(0,number-1);
//	data.output(number);
	stop = clock();
	cout << "\nsetting cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout << endl << endl;
	start = clock();
	for(int i=0;i<time;i++){
		data.irbinarysearch(number,i);
	}
	stop = clock();
	cout << "\nirbinarysearch cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout << endl << endl;
	cout << "success " << success << " times " << endl;
	cout << "false "<< notfound << " times " << endl;
	
	
	cout << endl << endl;
	success=0;
	notfound=0;
	data.settarget(time);
	start = clock();
	data.set(number);
//	data.output(number);
	cout << endl << endl;
	data.quicksort(0,number-1);
//	data.output(number);
	stop = clock();
	cout << "\nsetting cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout << endl << endl;
	start = clock();
	for(int i=0;i<time;i++){
		if(data.rebinarysearch(0,number-1,i)==0)notfound++;
		else success++;
	}
	stop = clock();
	cout << "\nrebinarysearch cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout << endl << endl;
	cout << "success " << success << " times " << endl;
	cout << "false "<< notfound << " times " << endl;
	

	cout << endl << endl;
	success=0;
	notfound=0;
//	data.outputtarget(time);
	start = clock();
	data.set(number);
//	data.output(number);
	cout << endl << endl;
	data.binarytreeinsert(number);
//	data.output(number);
	stop = clock();
	cout << "\nsetting cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout << endl << endl;
	data.settarget(time);
	cout << time << endl;
	start = clock();
	for(int i=0;i<time;i++){
		data.inorder(data.tree,i);
	}
	stop = clock();
	notfound=time-success;
	cout << "\nbinarysearchtree cost time : " << (stop - start) / CLOCKS_PER_SEC << endl;
	cout << endl << endl;
	cout << "success " << success << " times " << endl;
	cout << "false "<< notfound << " times " << endl;
	
	
	return 0;
}

template<class T>
void binarysearch<T>::set(int number){
	char aph;
	A=new T[number];
	for(int i=0;i<number;i++){
		for(int j=0;j<6;j++){
			aph=rand()%26+97;
			A[i]+=aph;
		}
	}
}


template<class T>
void binarysearch<T>::settarget(int time){
	char aph;
	target=new T[time];
	for(int i=0;i<time;i++){
		for(int j=0;j<6;j++){
			aph=rand()%26+97;
			target[i]+=aph;
		}
	}
}


template <class T>
void binarysearch<T>::output(int number){	
	for(int i=0;i<number;i++){
		cout << A[i] << " ";
	}
}

template <class T>
void binarysearch<T>::outputtarget(int number){	
	for(int i=0;i<number;i++){
		cout << target[i] << " ";
	}
}

template<class T>
bool binarysearch<T>::rebinarysearch(int first,int last,int time){
	int mid=(first+last)/2;
	if(A[mid]==target[time]){return true;} 
	if(first<last){
		if(A[mid]<target[time])rebinarysearch(mid+1,last,time);
		else if(A[mid]>target[time])rebinarysearch(first,mid-1,time);
	}
	else return false;
}

template<class T>
bool binarysearch<T>::irbinarysearch(int number,int time){
	int left=0,right=number-1,mid;
	while(left<=right){
		mid=(left+right)/2;
		if(A[mid]==target[time]){success++;return true;}
		else if(A[mid]<target[time]){
			left=mid+1;
		}
		else if(A[mid]>target[time]){
			right=mid-1;
		}
	}
	notfound++;
	return false;
}

template <class T>
void binarysearch<T>::quicksort(int p,int r){
	int q;
	if(p<r){
    	q=partation(p,r);
    	quicksort(p,q-1);
    	quicksort(q+1,r);
	}
}

template <class T>
int binarysearch<T>::partation(int p,int r){
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

template<class T>
void binarysearch<T>::binarytreeinsert(int number){
	tree=new TreeNode<T>;
	tree->data=A[0];
	//tree->leftChild=tree->rightChild=NULL;
	TreeNode <T>*preptr;
	TreeNode <T>*ptr=tree;
	
	for(int i=1;i<number;i++){
		while(ptr!=NULL){
			preptr=ptr;
			if(A[i]>ptr->data){
				ptr=ptr->rightChild;
			}
			else if(A[i]<ptr->data){
				ptr=ptr->leftChild;
			}
			else if(A[i]==ptr->data)break;
		}
		if(A[i]<preptr->data){
			preptr->leftChild=new TreeNode<T>;
			preptr->leftChild->data=A[i];
			//preptr->leftChild->leftChild=preptr->leftChild->rightChild=NULL;
		}
		else if(A[i]>preptr->data){
			preptr->rightChild=new TreeNode<T>;
			preptr->rightChild->data=A[i];;
			//preptr->rightChild->leftChild=preptr->rightChild->rightChild=NULL;
		}
		ptr=tree;
		preptr=NULL;
	}
}

template<class T>
void binarysearch<T>::inorder(TreeNode <T>*root,int time){
	if(root!= NULL){
		if(root->data == target[time])success++;
		else if(root-> data > target[time]){
			inorder(root->leftChild,time);
		}
		else if(root-> data < target[time]){
			inorder(root->rightChild,time);
		}
	}
}



