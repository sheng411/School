#include <bits/stdc++.h>
#include "all_function.h"
using namespace std;


int main(){
	//pass1
	program.open("program.txt");
	out_f.open("pass1_output.txt");
	hash_f.open("hash.txt");
	s.open("tree.txt");
	ifstream input_file("input.txt");

    data.hash_table();			//creation optable
    while (getline(input_file, str)) {	//load txt file
       	if(check_start()==1){
			program << "H^" << sym << "^" << lo << "^";	//pass2 use
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
	program << dec_hex6(loc-firstadd) << endl; 

	//close file
    hash_f.close();
    s.close();
    out_f.close();
    input_file.close();


	//pass2
	ifstream pass2_get("pass1_output.txt");		//Load pass1 result
	
	//reset variable
	errorflag=0,startflag=0,endflag=0;
    startadd="",sym="",fo="",lo="",str="",retadr="",code="",re="";
    
	out_f.open("pass2_output.txt");
    while(getline(pass2_get,str)){
    	if(check_start2()==1){
			continue;
		}
    	if(startflag==1){
    		pass2();
    		if(endflag==1) break;
    		if(errorflag==1) break;
    		output2();
		}
	}
	pass2_get.close();
	out_f.close();
    program.close();
}