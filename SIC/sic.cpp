#include <bits/stdc++.h>
#include "all_function.h"
using namespace std;


int main(){
	//open file
	out_f.open("output.txt");
	hash_f.open("hash.txt");
	s.open("tree.txt");
	ifstream input_file("input.txt");

    data.hash_table();			//creation optable
    while (getline(input_file, str)) {	//load txt file
       	if(check_start()==1){
		   	continue;
		}
       	if(startflag==1){
			pass();
			if(endflag==1) break;
			if(errorflag==1) break;
			output();
		}
    }
	
    if(errorflag) return 0;
    data2.inorder_show(data2.tree);
    data.show_hash();

	//close file
    hash_f.close();
    s.close();
    out_f.close();
    input_file.close();
}
