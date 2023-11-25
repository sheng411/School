#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>
#include <sstream>
#include <cmath>
#include "function.h"
using namespace std;

int main()
{
	ofs.open("output.txt");
	of.open("hash.txt");
	s.open("tree.txt");
	ifstream ifs("input.txt");
	ofsfinal.open("programing.txt");
    data.HT_table();//建立optable
    while (getline(ifs, str)) {//讀文件檔，逐行讀取 
       	if(findstartandloc()==1){
       		ofsfinal << "H^" << sym << "^" << lo << "^";
		   	continue;
		}
       	if(startflag==1){
			pass1();
			if(endflag==1) break;
			if(errorflag==1) break;
			output();
		}
    }
    if(errorflag) return 0;
    ofsfinal << intTohex6(loc-firstadd) << endl; 
    data2.inorder_show(data2.tree);
    data.show_HT();
    of.close();
    s.close();
    ofs.close();
    ifs.close();
    ifstream ifs2("output.txt");
    errorflag=0,startflag=0,endflag=0;
    startadd="",sym="",fo="",lo="",str="",retadr="",code="",re="";
    ofs.open("output2.txt");
    while(getline(ifs2,str)){
    	if(findstartandloc2()==1)continue;
    	if(startflag==1){
    		pass2();
    		if(endflag==1) break;
    		if(errorflag==1) break;
    		output2();
		}
	}
	ifs2.close();
	ofs.close();
    ofsfinal.close();
}
