#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

int findstartandloc();
string intTohex(int n);
string inttoA(int n);
int hextoint(string s);
void getop();
string getop2(string x);
void getretadr();
int get_byte();
string word_change();
void objectcode();
void pass1();
void textwrc();
void output();

int i=0,byten,n,loc=0,firstadd=0,counter=0,headtextwrc=0;
bool flag,f,errorflag=0,startflag=0,endflag=0;
ofstream ofs,of,s,ofsfinal;
string startadd="",sym="",fo="",lo="",str="",retadr="",code="",re="",wrc="";

bool symbol(){
	if(str[0]!=' ')return true;
	else return false;
}

bool symbol2(){
	if(str[5]!=' ')return true;
	else return false;
}
struct op{
	public:
		string opname;
		int opvalue;	 
};

class node{
    public :
        string data;
        int opcode;
        node *link = NULL;
};

class TreeNode {
	public:
		string data;
		string loc;
  		TreeNode *leftChild=NULL;
  		TreeNode *rightChild=NULL;
};

class binarytree{
	friend class TreeNode;
	public:
		int binarytreeinsert();
		void inorder_show(TreeNode *root);
		void findloc(TreeNode *root,string x);
		TreeNode *tree=new TreeNode;
		int i=0;
		string treeloc;
};

class ha_sh{ 
    friend class node;
    public:
        ha_sh(){
            table=new node *[3001];
            for(int i=0;i<3001;i++){
                table[i]=NULL;
            }
        }
        void HT_table();
        bool HT_search();
        int HT_opcode();
        void show_HT();
        node **table;
};

op optable[31]={//+3opcode總表 
    {   "ADD", 0x18},
    { "CLEAR", 0xB4},
    {  "COMP", 0x28},
    { "COMPR", 0xA0},
    {   "DIV", 0x24},
    {     "J", 0x3C},
    {   "JEQ", 0x30},
    {   "JGT", 0x34},
    {   "JLT", 0x38},
    {  "JSUB", 0x48},
    {   "LDA", 0x00},
    {   "LDB", 0x68},
    {   "LDCH", 0x50},
    {   "LDL", 0x08},
    {   "LDT", 0x74},
    {   "LDX", 0x04},
    {   "LDS", 0x6C},
    {   "MUL", 0x20},
    {    "RD", 0xD8},
    {   "STA", 0x0C},
    {   "STB", 0x78},
    {   "STCH", 0x54},
    {   "STL", 0x14},
    {   "STT", 0x84},
    {   "STS", 0x7C},
    {   "STX", 0x10},
    {   "SUB", 0x1C},
    {    "TD", 0xE0},
    {   "TIX", 0x2C},
    {  "TIXR", 0xB8},
    {    "WD", 0xDC},
};

void ha_sh::HT_table(){//根據opcode建立ha_shtable 
    node  *move;
    node  *last;
    int index;
    for(int i=0;i<31;i++){
        index=0;
        for(int j=0;j<optable[i].opname.length();j++){
            index+=(optable[i].opname[j]-65)*pow(17,j);
        }
        index=index%3001;
        if(table[index]==NULL){
            table[index]=new node;
            table[index]->data=optable[i].opname;
            table[index]->opcode=optable[i].opvalue;
        }
        else {
            last=new node;
            move=table[index]->link;
            last->data=optable[i].opname;
            last->opcode=optable[i].opvalue;
            table[index]->link=last;
            last->link=move;
        }
    }
}

bool ha_sh::HT_search(){//找有沒有指令(只限有在ha_shtable的) 
    int index;
    node *first;
    first=new node;
        index=0;
        for(int j=0;j<fo.length();j++){
            index+=(fo[j]-65)*pow(17,j);
        }
        index=index%3001;
        first=table[index];
        while(first!=NULL){
            if(first->data==fo){
                return true;
            }
            else first=first->link;
        }
        return false;
}

int ha_sh::HT_opcode(){//找有沒有指令(只限有在ha_shtable的) 
    int index;
    node *first;
    first=new node;
        index=0;
        for(int j=0;j<fo.length();j++){
            index+=(fo[j]-65)*pow(17,j);
        }
        index=index%3001;
        first=table[index];
        while(first!=NULL){
            if(first->data==fo){
                return first->opcode;
            }
            else first=first->link;
        }
}

void ha_sh::show_HT(){//列印optable 
    node *temp;
    temp=new node;
    temp->data="";
    for(int i=0;i<3001;i++){
        temp=table[i];
        while(temp!=NULL){
            of<< temp->data << " " << hex<<temp->opcode << " ";
            temp=temp->link;
            of<<endl;
        }
    }
}

int binarytree::binarytreeinsert() {//把symbol.loc裝進二元樹 
	TreeNode *preptr;
	TreeNode *ptr=tree;
	while(ptr!=NULL){
		preptr=ptr;
		if(sym>ptr->data){
			ptr=ptr->rightChild;
		}
		else if(sym<ptr->data){
			ptr=ptr->leftChild;
		}
		else if(sym==ptr->data){
			errorflag=1;
			ofs << "錯誤的變數宣告(重複宣告)" << endl;	
			return 0;
		}
	}
	if(tree==NULL){
		tree->data=sym;
		tree->loc=lo;
	}
	if(sym<preptr->data){
		preptr->leftChild=new TreeNode;
		preptr->leftChild->data=sym;
		preptr->leftChild->loc =lo;
	}
	else if(sym>preptr->data){
		preptr->rightChild=new TreeNode;
		preptr->rightChild->data=sym;
		preptr->rightChild->loc =lo;
	}
	ptr=tree;
	preptr=NULL;
}

void binarytree::inorder_show(TreeNode *root){//列印二元樹結果 
	if(root!= NULL){
		inorder_show(root->leftChild);
		s << root->data << " " << root->loc << endl;
		inorder_show(root->rightChild);
	}
}

void binarytree::findloc(TreeNode *root,string x){//二元樹結果 
	if(root!= NULL){
		findloc(root->leftChild,x);
		if(x==root->data) {
			treeloc=root->loc;
			i=1;
		}
		findloc(root->rightChild,x);
	}
}

string intTohex(int n){   //輸出是四個字元
    string ans;
    int t=0,length;
    char x[]={'A','B','C','D','E','F'},y;
    
    while(n!=0){
    	t=n%16;
    	if(t>=10) {
    		t=t-10;
    		ans=x[t]+ans;
		}
		else{
			y=t+48;
			ans=y+ans;
		}
		n=n/16;
	}
	length=4-ans.length();
	for(int i=0;i<length;i++) ans='0'+ans;
	return ans;
}

string intTohex6(int n){   //輸出是四個字元
    string ans;
    int t=0,length;
    char x[]={'A','B','C','D','E','F'},y;
    
    while(n!=0){
    	t=n%16;
    	if(t>=10) {
    		t=t-10;
    		ans=x[t]+ans;
		}
		else{
			y=t+48;
			ans=y+ans;
		}
		n=n/16;
	}
	length=6-ans.length();
	for(int i=0;i<length;i++) ans='0'+ans;
	return ans;
}

string inttoA(int n){   //輸出是兩個字元 
    string ans;
    int t,length;
    char x[]={'A','B','C','D','E','F'},y;
    while(n!=0){
    	t=n%16;
    	if(t>=10) {
    		t=t-10;
    		ans=x[t]+ans;
		}
		else{
			y=t+48;
			ans=y+ans;
		}
		n=n/16;
	}
	length=2-ans.length();
	for(int i=0;i<length;i++) ans='0'+ans;
	return ans;
}

int hextoint(string s){//把16進制轉10進制的int 
    string Hex="0123456789ABCDEF";
    int t=0,ans=0,k;
    k=s.length()-1;
    for(int i=0;i<s.length();i++){
    	for(int j=0;j<16;j++){
    		if(s[i]==Hex[j]){
    			t=j;
    			break;
			} 
		}
		ans+=pow(16,k)*t;
		k-=1;
	}
	return ans;
}


void getop(){//抓opcode的函數 
	int n,t;
	n=str.find(" ",0);
	for(int i=n;i<str.length();i++){
		if(str[i]!=' '){
			t=i;
			break;
		}
	}
	for(int i=t;i<str.length();i++){		
		if(str[i]==' ') break;
		fo+=str[i]; 
	}
}

string getop2(string x){ //沒有symbol抓空白的方式 
	string fo;
	int t;
	for(int i=0;i<x.length();i++){
		if(x[i]!=' '){
			t=i;
			break;
		}
	}
	for(int i=t;i<x.length();i++){
		if(x[i]==' ')break;
		fo+=x[i];
	}
	return fo;
}

void getop3(){//pass2抓opcode的函數 
	int n,t;
	n=str.find(" ",5);
	for(int i=n;i<str.length();i++){
		if(str[i]!=' '){
			t=i;
			break;
		}
	}
	for(int i=t;i<str.length();i++){		
		if(str[i]==' ') break;
		fo+=str[i]; 
	}
}

string getop4(string x){ //pass2沒有symbol抓空白的方式 
	string fo;
	int t;
	for(int i=5;i<x.length();i++){
		if(x[i]!=' '){
			t=i;
			break;
		}
	}
	for(int i=t;i<x.length();i++){
		if(x[i]==' ')break;
		fo+=x[i];
	}
	return fo;
}

void getretadr(){//抓taget address-的函數 
	int n;
	retadr="";
	int i=str.find(fo,0)+fo.length();
	for(;i<str.length();i++){
		if(str[i]!=32) retadr+=str[i];
	}
}

int get_byte(){//算 RESW
	int ans,a,j=retadr.length()-1;
	for(int i=0;i<retadr.length();i++){
		a=retadr[i]-48;
		ans+=a*pow(10,j);
		j--;
	}
	return ans;
}

string word_change(){//算 WORD
	int a=0,n,j=retadr.length()-1;
	string ans;
	for(int i=0;i<retadr.length();i++){
		a+=(retadr[i]-48)*pow(10,j);
		j--;
	}
	ans=inttoA(a);
	n=6-ans.length();
	for(int i=0;i<n;i++){
		ans='0'+ans;
	}
	return ans;
}

ha_sh data;
binarytree data2;

int findstartandloc()
{	
	if(str.find("START")!=string::npos) 
       	{
       		i=str.length()-1;
       		while(str[i]!=' ')//為了讀到地址 
			{		   	
			   	startadd=str[i]+startadd;
			   	i=i-1;
			}
			//cout<<startadd.length()<<endl;
			loc=hextoint(startadd);
			firstadd=loc;
			startflag=1;
			ofs << str << endl;
			n=str.find(" ",0);//從0開始找到空白 
			sym.assign(str,0,n);//抓到symbol
			lo=startadd;
			data2.binarytreeinsert();
			//cout << loc << endl;
			
			return 1;		 
		}
		
}

int findstartandloc2()
{	
	if(str.find("START")!=string::npos) 
       	{
       		i=str.length()-1;
       		while(str[i]!=' ')//為了讀到地址 
			{		   	
			   	startadd=str[i]+startadd;
			   	i=i-1;
			}
			//cout<<startadd.length()<<endl;
			loc=hextoint(startadd);
			startflag=1;
			ofs << str << endl;
			//cout << loc << endl;
			return 1;		 
		}
		
}

void objectcode(){
	if(data.HT_search()!=0){ //確認是不是opcode
				if(retadr.find(",")==string::npos){
					data2.findloc(data2.tree,retadr);
					if(data2.i==1){
						code+=inttoA(data.HT_opcode());
						code+=data2.treeloc;
						data2.i=0;
					}
				}
				else{
					n=retadr.find(",");
					for(int i=0;i<n;i++){
						re+=retadr[i];
					}
					data2.findloc(data2.tree,re);
					if(data2.i==1){
						code+=inttoA(data.HT_opcode());
						code+=intTohex(hextoint(data2.treeloc)+32768);//16**3*8
						data2.i=0;
					}
				}
				loc+=3;
			}
			else if(fo=="WORD"){
				code=word_change();
				loc+=3;
			}
			else if(fo=="BYTE"){
				if(retadr[0]=='C'){
					loc+=retadr.length()-3;//減掉C跟兩個'
					for(i=2;i<retadr.length()-1;i++){
						n=retadr[i];
						code+=inttoA(retadr[i]);
					}
				}
				else if(retadr[0]=='X'){
					for(i=2;i<retadr.length()-1;i++){
						code+=retadr[i];
					}
					loc+=(retadr.length()-3+1)/2;
				}
			}
			else if(fo=="RESW"){
				byten=get_byte();
				loc+=byten*3;
				code="";
			}
			else if(fo=="RESB"){
				loc+=get_byte();
				code="";
			}
			else if(fo=="RSUB"){
				loc+=3;
				code="4C0000";
			}
			else if(fo=="END"){
				endflag=1;
			}
			else {
				errorflag=1;
				ofs << "錯誤的指令宣告" << endl; 
			}
}

void objectcode2(){
	if(data.HT_search()!=0){ //確認是不是opcode
				if(retadr.find(",")==string::npos){
					data2.findloc(data2.tree,retadr);
					if(data2.i==1){
						code+=inttoA(data.HT_opcode());
						code+=data2.treeloc;
						data2.i=0;
					}
					else{
						errorflag=1;
						ofs << retadr << "沒有被宣告" << endl;
					}
				}
				else{
					n=retadr.find(",");
					for(int i=0;i<n;i++){
						re+=retadr[i];
					}
					data2.findloc(data2.tree,re);
					if(data2.i==1){
						code+=inttoA(data.HT_opcode());
						code+=intTohex(hextoint(data2.treeloc)+32768);//16**3*8
						data2.i=0;
					}
					else{
						errorflag=1;
						ofs << retadr << "沒有被宣告" << endl;
					}
				}
				loc+=3;
			}
			else if(fo=="WORD"){
				code=word_change();
				loc+=3;
			}
			else if(fo=="BYTE"){
				if(retadr[0]=='C'){
					loc+=retadr.length()-3;//減掉C跟兩個'
					for(i=2;i<retadr.length()-1;i++){
						n=retadr[i];
						code+=inttoA(retadr[i]);
					}
				}
				else if(retadr[0]=='X'){
					for(i=2;i<retadr.length()-1;i++){
						code+=retadr[i];
					}
					loc+=(retadr.length()-3+1)/2;
				}
			}
			else if(fo=="RESW"){
				byten=get_byte();
				loc+=byten*3;
				code="";
			}
			else if(fo=="RESB"){
				loc+=get_byte();
				code="";
			}
			else if(fo=="RSUB"){
				loc+=3;
				code="4C0000";
			}
			else if(fo=="END"){
				endflag=1;
			}
}

void pass1(){
	if(symbol()) { // 如果有symbol的話 
			n=str.find(" ",0);//從0開始找到空白 
			sym.assign(str,0,n);//抓到symbol
			fo=""; code="";re="";
			getop(); //抓opcode的函數
			lo=intTohex(loc);
			data2.binarytreeinsert();//建二元樹  
			getretadr();
			objectcode();
		}
		else {
			sym="       ";
			code="";re="";
			fo=getop2(str);
			lo=intTohex(loc);
			getretadr();
			//cout << "       " << fo <<  " " << lo << " " << retadr << endl;
			objectcode();
		}
	if(fo=="END"){
		ofs << str;
	}
}

void pass2(){
	if(symbol2()) { // 如果有symbol的話 
			n=str.find(" ",5);//從0開始找到空白 
			sym.assign(str,5,n);//抓到symbol
			fo=""; code="";re="";
			getop3(); //抓opcode的函數
			lo=intTohex(loc);
			getretadr();
			objectcode2();
		}
		else {
			sym="       ";
			code="";re="";
			fo=getop4(str);
			lo=intTohex(loc);
			getretadr();
			objectcode2();
		}
		textwrc();
		if(fo=="END") ofs << str;
}

void textwrc(){
	if(endflag==1){
		ofsfinal << inttoA(counter) << wrc <<endl;
		ofsfinal << "E^00" << intTohex(firstadd);
	}
	if(counter<=27 && code!=""){
		if(counter==0){
			ofsfinal << "T^00" << lo << "^";
		}
		wrc=wrc+"^"+code;
		counter+=code.length()/2;
	}
	else if(fo=="RESW"||fo=="RESB"||fo=="RSUB") {
		if(counter!=0)ofsfinal << inttoA(counter) << wrc << endl;
		counter=0;
		wrc="";
	}
	else if(counter>27){
		ofsfinal << inttoA(counter) << wrc << endl;
		counter=3;
		wrc="^"+code;
		ofsfinal << "T^00" << lo << "^";
	}
}

void output(){
	ofs << lo << " ";
		
		for(int a=0;a<8;a++){
			if(a<sym.length()) ofs << sym[a];
			else ofs << " ";
		}
		
		for(int a=0;a<5;a++){
			if(a<fo.length()) ofs << fo[a];
			else ofs << " ";
		}
		
		for(int a=0;a<9;a++){
			if(a<retadr.length()) ofs << retadr[a];
		}
		ofs << endl;
}

void output2(){
	ofs << lo << " ";
		
		for(int a=0;a<8;a++){
			if(a<sym.length()) ofs << sym[a];
			else ofs << " ";
		}
		
		for(int a=0;a<5;a++){
			if(a<fo.length()) ofs << fo[a];
			else ofs << " ";
		}
		
		for(int a=0;a<9;a++){
			if(a<retadr.length()) ofs << retadr[a];
			else ofs << " ";
		}
		
		for(int a=0;a<8;a++){
			if(a<code.length()) ofs << code[a];
			else ofs << " ";
		}
		ofs << endl;
}
