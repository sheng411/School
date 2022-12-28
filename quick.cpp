template<class T>
T partition(T &arr,int start,int end){
	using elType = typename	T::value_type;
	elType x=arr[r];
    int pivotPosition=start;
    for (int pos=start+1;pos<=end;pos++){
        if (arr[pos]<pivotValue){
            swap(arr[pivotPosition+1],arr[pos]);
            swap(arr[pivotPosition],arr[pivotPosition+1]);
            pivotPosition ++;
        }
	}
    return pivotPosition;
}

template<class T>
void quickSort(T &arr,int start,int end){
    if (start<end){
        int p=partition(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);
	}
}