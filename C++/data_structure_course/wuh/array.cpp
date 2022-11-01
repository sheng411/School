#include<iostream>
#include<array>
#include <typeinfo>
using namespace std;

template<class T>
void output(T &x){
	cout << typeid(x[0]).name() << endl;  // 印出資料型別 i是int; d是double; l是long; f是float; Ss是string 
	for(int i=0;i<5;i++){
		cout << x[i] << " ";
	}
	cout << endl << endl;
}


int main(){
	std::array<int,5> array_int ={1,2,3,4,5};
	std::array<float,5> array_float = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::array<double,5> array_double = {1.111, 2.222,3.333, 4.444, 5.555};
	std::array<long,5> array_long = {111111111 ,222222222 , 333333333 , 444444444 , 555555555};
	std::array<string,5> array_string = {"aaaa" ,"bbbb" ,"cccc" ,"dddd" ,"eeee"};
	
	output(array_int);
	output(array_float);
	output(array_double);
	output(array_long);
	output(array_string);
	return 0;
}
