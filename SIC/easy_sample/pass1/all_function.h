#include <bits/stdc++.h>
using namespace std;

bool flag,f,errorflag=0,startflag=0,endflag=0;
int i=0,byten,n,loc=0,firstadd=0,counter=0;
string startadd="",sym="",fo="",lo="",str="",retadr="",code="",re="";
ofstream out_f,hash_f,s;


int check_start();
string dec_hex(int n);
string inttoA(int n);
int hex_dec(string s);
void getop();
string getop2(string x);
void getretadr();
int get_byte();
string word_change();
void ob_c();
void pass();
void output();


//symbol area
bool symbol(){
	if(str[0]!=' '){
		return true;
	} 
	else{
		return false;
	} 
}


//op table area
struct op_c{
	public:
		string op_n;
		int op_va;
};

op_c opt[31]={			//optable 
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


void getop(){				//functions for catching opcodes 
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

string getop2(string x){ 	//there is no symbolic way to catch blanks 
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

void getretadr(){			//function to capture taget address 
	int n;
	retadr="";
	int i=str.find(fo,0)+fo.length();
	for(;i<str.length();i++){
		if(str[i]!=32) retadr+=str[i];
	}
}


//binarytree area
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

class b_tree{
	friend class TreeNode;
	public:
		int b_treeinsert();
		void inorder_show(TreeNode *root);
		void findloc(TreeNode *root,string x);
		TreeNode *tree=new TreeNode;
		int i=0;
		string treeloc;
};

int b_tree::b_treeinsert() {				//Put symbol and loc into binarytree 
	TreeNode *ptr=tree;
	TreeNode *pre;
	while(ptr!=NULL){
		pre=ptr;
		if(sym>ptr->data){
			ptr=ptr->rightChild;
		}
		else if(sym<ptr->data){
			ptr=ptr->leftChild;
		}
		else if(sym==ptr->data){
			errorflag=1;
			out_f << "*Error* Incorrect variable declaration (repetitive declaration)" << endl;	
			return 0;
		}
	}
	if(tree==NULL){
		tree->data=sym;
		tree->loc=lo;
	}
	if(sym<pre->data){
		pre->leftChild=new TreeNode;
		pre->leftChild->data=sym;
		pre->leftChild->loc =lo;
	}
	else if(sym>pre->data){
		pre->rightChild=new TreeNode;
		pre->rightChild->data=sym;
		pre->rightChild->loc =lo;
	}
	ptr=tree;
	pre=NULL;
}

void b_tree::inorder_show(TreeNode *root){		//show binarytree 
	if(root!= NULL){
		inorder_show(root->leftChild);
		s << root->data << " " << root->loc << endl;
		inorder_show(root->rightChild);
	}
}

void b_tree::findloc(TreeNode *root,string x){	//binarytree results 
	if(root!= NULL){
		findloc(root->leftChild,x);
		if(x==root->data) {
			treeloc=root->loc;
			i=1;
		}
		findloc(root->rightChild,x);
	}
}


//hash area
class ha_sh{ 
    friend class node;
    public:
        ha_sh(){
            table=new node *[4027];
            for(int i=0;i<4027;i++){
                table[i]=NULL;
            }
        }
        void hash_table();
        bool hash_search();
        int hash_opcode();
        void show_hash();
        node **table;
};

void ha_sh::hash_table(){		//cheat hash table 
    node  *m;		//move
    node  *la;		//last
    int ind;		//index
    for(int i=0;i<31;i++){
        ind=0;
        for(int j=0;j<opt[i].op_n.length();j++){
            ind+=(opt[i].op_n[j]-65)*pow(97,j);		//pow number is random prime number
        }
        ind%=4027;		//random
        if(table[ind]==NULL){
            table[ind]=new node;
            table[ind]->data=opt[i].op_n;
            table[ind]->opcode=opt[i].op_va;
        }
        else {
            la=new node;
            m=table[ind]->link;
            la->data=opt[i].op_n;
            la->opcode=opt[i].op_va;
            table[ind]->link=la;
            la->link=m;
        }
    }
}

bool ha_sh::hash_search(){	//Find Instructions 
    int ind;
    node *fir;		//first
    fir=new node;
        ind=0;
        for(int j=0;j<fo.length();j++){
            ind+=(fo[j]-65)*pow(97,j);
        }
        ind=ind%4027;
        fir=table[ind];
        while(fir!=NULL){
            if(fir->data==fo){
                return true;
            }
            else fir=fir->link;
        }
        return false;
}

int ha_sh::hash_opcode(){
	int ind;
    node *fir;		//first
    fir=new node;
        ind=0;
        for(int j=0;j<fo.length();j++){
            ind+=(fo[j]-65)*pow(97,j);
        }
        ind=ind%4027;
        fir=table[ind];
        while(fir!=NULL){
            if(fir->data==fo){
                return fir->opcode;
            }
            else fir=fir->link;
        }
}

void ha_sh::show_hash(){		//show optable 
    node *temp;
    temp=new node;
    temp->data="";
    for(int i=0;i<4027;i++){
        temp=table[i];
        while(temp!=NULL){
            hash_f<< temp->data << " " << hex<<temp->opcode << " ";
            temp=temp->link;
            hash_f<<endl;
        }
    }
}


//Hex <--> Dec area
string dec_hex(int n){   //output is 4 char
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

string inttoA(int n){   //output is 2 char 
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

int hex_dec(string s){	//Hex to dec 
    string Hex="0123456789ABCDEF";
    int n=0,ans=0,m;
    m=s.length()-1;
    for(int i=0;i<s.length();i++){
    	for(int j=0;j<16;j++){
    		if(s[i]==Hex[j]){
    			n=j;
    			break;
			} 
		}
		ans+=pow(16,m)*n;
		m-=1;
	}
	return ans;
}


//other calculation
int get_byte(){			//calculation "RESW"
	int ans,a,j=retadr.length()-1;
	for(int i=0;i<retadr.length();i++){
		a=retadr[i]-48;
		ans+=a*pow(10,j);
		j--;
	}
	return ans;
}

string word_change(){	//calculation "WORD"
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
b_tree data2;


//check get "START"
int check_start()
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
			loc=hex_dec(startadd);
			firstadd=loc;
			startflag=1;
			out_f << str << endl;
			n=str.find(" ",0);//從0開始找到空白 
			sym.assign(str,0,n);//抓到symbol
			lo=startadd;
			data2.b_treeinsert();
			//cout << loc << endl;
			
			return 1;		 
		}
		
}


//pass function
void pass(){
	if(symbol()) { 					//if there is a symbol
			n=str.find(" ",0);		//start from 0 and find the blanks
			sym.assign(str,0,n);	//get symbol
			fo=""; code="";re="";
			getop(); 				//get opcode function
			lo=dec_hex(loc);
			data2.b_treeinsert();	//creating a binary
			getretadr();
			ob_c();
		}
		else {
			sym="       ";
			code="";re="";
			fo=getop2(str);
			lo=dec_hex(loc);
			getretadr();
			ob_c();
		}
	if(fo=="END"){
		out_f << str;
	}
}

void ob_c(){
	if(data.hash_search()!=0){ 		//check opcode
				if(retadr.find(",")==string::npos){
					data2.findloc(data2.tree,retadr);
					if(data2.i==1){
						code+=inttoA(data.hash_opcode());
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
						code+=inttoA(data.hash_opcode());
						code+=dec_hex(hex_dec(data2.treeloc)+32768);//16**3*8
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
					loc+=retadr.length()-3;		//Minus C and two '
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
			else if(fo=="RESB"){
				loc+=get_byte();
				code="";
			}
			else if(fo=="RESW"){
				byten=get_byte();
				loc+=byten*3;
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
				out_f << "*Error* Erroneous Command Announcementx" << endl; 
			}
}


//output area
void output(){
	out_f << lo << " ";
		
		for(int a=0;a<8;a++){
			if(a<sym.length()) out_f << sym[a];
			else out_f << " ";
		}
		
		for(int a=0;a<5;a++){
			if(a<fo.length()) out_f << fo[a];
			else out_f << " ";
		}
		
		for(int a=0;a<9;a++){
			if(a<retadr.length()) out_f << retadr[a];
		}
		out_f << endl;
}
