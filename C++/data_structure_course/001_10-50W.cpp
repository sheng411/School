#include <bits/stdc++.h>
using namespace std;


constexpr int arnum=500000;
long smfre=1;     //Use of small data
int fre=100000;       //quantity of data



template <class rds,class rdi,class rdlo,class rdd,class rdf,class rdas,class rdai,class rdalo,class rdad,class rdaf,class rdaas,class rdaai,class rdaalo,class rdaad,class rdaaf>
    void randd(rds &vs,rdi &vi,rdlo &vlo,rdd &vd,rdf &vf,rdas &as,rdai &ai,rdalo &alo,rdad &ad,rdaf &af,rdaas &aas,rdaai &aai,rdaalo &aalo,rdaad &aad,rdaaf &aaf){
        int pi;long plo;double pd;float pf;
        srand(time(NULL));
        int rdn=10,rdm=10000;
        for(int i=0;i<fre;i++){
            /*
            vi.push_back(rand()%rdm/int(rdn));
            vlo.push_back(rand()%rdm/long(rdn));
            vd.push_back(rand()%rdm/double(rdn));
            vf.push_back(rand()%rdm/float(rdn));*/
            string na="aaaaaa";
            for(int x=0;x<6;x++){
                na[x]+=rand()%26;
            }
            //vs.push_back(na);

            /*
            pi=rand()%rdm/int(rdn);
            plo=rand()%rdm/long(rdn);
            pd=rand()%rdm/double(rdn);
            pf=rand()%rdm/float(rdn);
            as[i]=na;
            ai[i]=pi;
            alo[i]=plo;
            ad[i]=pd;
            af[i]=pf;*/

            
            aas[i]=na;
            aai[i]=rand()%rdm/int(rdn);
            aalo[i]=rand()%rdm/long(rdn);
            aad[i]=rand()%rdm/double(rdn);
            aaf[i]=rand()%rdm/float(rdn);
        }
    }

template <class ins>
    int is(ins &in,int n){
        //ins temp;
        int j=0;
        for(int i=1;i<n;i++){
            auto temp=in[i];
            j=i-1;
            while(j>=0 && temp<in[j]){
                in[j+1]=in[j];
                j--;
            }
            in[j+1]=temp;
        }
        return 0;
    }

template <class se>
    int sel(se &s,int n){
        for(int i=0;i<n-1;i++){
            int mins=i;
            for(int j=i+1;j<n;j++){
                if(s[j]<s[mins]){
                    mins=j;
                }
            }
            if(mins!=i){
                swap(s[i],s[mins]);
            }
        }
        return 0;
    }

template <class bu>
    int bub(bu &b,int n){     //b is list ,n is list size.
        int i,j,k;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(b[j]>b[j+1]){
                    swap(b[j],b[j+1]);
                }
            }
        }
        return 0;
    }


template <class go,class rds,class rdi,class rdlo,class rdd,class rdf,class rdas,class rdai,class rdalo,class rdad,class rdaf,class rdaas,class rdaai,class rdaalo,class rdaad,class rdaaf>
    int gogo(go fun,int stn,int dt,int dsn,rds &vs,rdi &vi,rdlo &vlo,rdd &vd,rdf &vf,rdas &as,rdai &ai,rdalo &alo,rdad &ad,rdaf &af,rdaas &aas,rdaai &aai,rdaalo &aalo,rdaad &aad,rdaaf &aaf){  //dt is data type
        fstream myfile,read;
        myfile.open("count.txt",ios::app);      //改app
        auto gst=chrono::steady_clock::now();
        fun;
        auto gend=chrono::steady_clock::now();
        long long ti=chrono::duration_cast<chrono::nanoseconds>((gend-gst)/smfre).count();
        string dtl[5] {"string","int\t","long","double","float"};
        string st[4] {"insertion","selection","bubble","merge"};
        string ds[3] {"C array","vector","std array"};
        cout<<"Sort: \""<<st[stn]<<" \",data type is \" "<<dtl[dt]<<" \""<<"data str"<<ds[dsn]<<endl;
        cout<<"usage time-->"<<ti<<"ns\n"<<endl;
		myfile<<dtl[dt]<<"\t\t"
                <<st[stn]<<"\t\t"
                <<ti<<"ns\t\t"
                <<fre<<"\t\t"
                <<smfre<<"\t\t"
                <<ds[dsn]<<"\n"
                <<endl;
        myfile.close();

        //input read
        read.open("read.txt",ios::app);     //app
        read<<st[stn]<<" "
            <<dtl[dt]<<" "
            <<ti<<" "
            <<fre<<" "
            <<smfre<<" "
            <<ds[dsn]<<" "
            <<endl;
            read.close();
        return 0;
    }

int rd(){
    fstream read;
    read.open("read.txt",ios::app);
    read<<"\n-----------------------------------------\n";
    read.close();
    return 0;
}

int main(){
    cout<<"GO start"<<endl;
    
    fstream myfile,read;
    read.open("read.txt",ios::app);
    read<<"\n-----------------------------------------\n";
    read.close();
    cout<<"file 200OK"<<endl;

    fre=100000;
    for(int i=0;i<5;i++){
        cout<<"start\n";
    	string *as=new string[fre];
	    int *ai=new int[fre],pi;
	    long *alo=new long[fre],plo;
	    double *ad=new double[fre],pd;
	    float *af=new float[fre],pf;
	    
	    vector <string>vs;
	    vector <int>vi;
	    vector <long>vlo;
	    vector <double>vd;
	    vector <float>vf;
	    
	    static array <string,arnum> aas;
	    static array <int,arnum> aai;
	    static array <long,arnum> aalo;
	    static array <double,arnum> aad;
	    static array <float,arnum> aaf;

		cout << i+1 <<"W fre~~~\n\n" ;

    	randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	auto start = chrono::steady_clock::now();
    	gogo(is(aas,fre),0,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "1-yes\n"  << endl;
    	auto end = chrono::steady_clock::now();
    	long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	double ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nInsertionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"1------------------------------------------------------"<<endl;
    // ----------------------------------------------------------------------------------------------
    	randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(sel(aas,fre),1,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "2-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"2------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(bub(aas,fre),2,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "3-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"3------------------------------------------------------"<<endl;
        cout<<"i-->"<<i<<endl;
    	fre+=100000;
    	
    	delete [] as;
    	delete [] ai;
    	delete [] alo;
    	delete [] ad;
    	delete [] af;
    	
    	vs.clear();
    	vi.clear();
    	vlo.clear();
    	vd.clear();
    	vf.clear();
    	
    	aas.fill("");
    	aai.fill(0);
    	aalo.fill(0);
    	aad.fill(0);
    	aaf.fill(0);
        cout<<"HELLO\n\n";
    }
    rd();

    fre=100000;
    for(int i=0;i<5;i++){
        cout<<"start\n";
    	string *as=new string[fre];
	    int *ai=new int[fre],pi;
	    long *alo=new long[fre],plo;
	    double *ad=new double[fre],pd;
	    float *af=new float[fre],pf;
	    
	    vector <string>vs;
	    vector <int>vi;
	    vector <long>vlo;
	    vector <double>vd;
	    vector <float>vf;
	    
	    static array <string,arnum> aas;
	    static array <int,arnum> aai;
	    static array <long,arnum> aalo;
	    static array <double,arnum> aad;
	    static array <float,arnum> aaf;

		cout << i+1 <<"W fre~~~\n\n" ;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	auto start = chrono::steady_clock::now();
    	gogo(is(aai,fre),0,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "4-yes\n"  << endl;
    	auto end = chrono::steady_clock::now();
    	long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	double ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"4------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(sel(aai,fre),1,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "5-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"5------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(bub(aai,fre),2,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "6-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"6------------------------------------------------------"<<endl;
        cout<<"i-->"<<i<<endl;
    	fre+=100000;
    	
    	delete [] as;
    	delete [] ai;
    	delete [] alo;
    	delete [] ad;
    	delete [] af;
    	
    	vs.clear();
    	vi.clear();
    	vlo.clear();
    	vd.clear();
    	vf.clear();
    	
    	aas.fill("");
    	aai.fill(0);
    	aalo.fill(0);
    	aad.fill(0);
    	aaf.fill(0);
        cout<<"HELLO\n\n";
    }
    rd();

    fre=100000;
    for(int i=0;i<5;i++){
        cout<<"start\n";
    	string *as=new string[fre];
	    int *ai=new int[fre],pi;
	    long *alo=new long[fre],plo;
	    double *ad=new double[fre],pd;
	    float *af=new float[fre],pf;
	    
	    vector <string>vs;
	    vector <int>vi;
	    vector <long>vlo;
	    vector <double>vd;
	    vector <float>vf;
	    
	    static array <string,arnum> aas;
	    static array <int,arnum> aai;
	    static array <long,arnum> aalo;
	    static array <double,arnum> aad;
	    static array <float,arnum> aaf;
		cout << i+1 <<"W fre~~~\n\n" ;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	auto start = chrono::steady_clock::now();
    	gogo(is(aalo,fre),0,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "7-yes\n"  << endl;
    	auto end = chrono::steady_clock::now();
    	long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	double ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"7------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(sel(aalo,fre),1,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "8-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"8------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(bub(aalo,fre),2,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "9-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"9------------------------------------------------------"<<endl;
    //output i--------------------------------------------------------------------------------------------
        cout<<"i-->"<<i<<endl;
    	fre+=100000;
    	
    	delete [] as;
    	delete [] ai;
    	delete [] alo;
    	delete [] ad;
    	delete [] af;
    	
    	vs.clear();
    	vi.clear();
    	vlo.clear();
    	vd.clear();
    	vf.clear();
    	
    	aas.fill("");
    	aai.fill(0);
    	aalo.fill(0);
    	aad.fill(0);
    	aaf.fill(0);
        cout<<"HELLO\n\n";
    }
    rd();

    fre=100000;
    for(int i=0;i<5;i++){
        cout<<"start\n";
    	string *as=new string[fre];
	    int *ai=new int[fre],pi;
	    long *alo=new long[fre],plo;
	    double *ad=new double[fre],pd;
	    float *af=new float[fre],pf;
	    
	    vector <string>vs;
	    vector <int>vi;
	    vector <long>vlo;
	    vector <double>vd;
	    vector <float>vf;
	    
	    static array <string,arnum> aas;
	    static array <int,arnum> aai;
	    static array <long,arnum> aalo;
	    static array <double,arnum> aad;
	    static array <float,arnum> aaf;
		cout << i+1 <<"W fre~~~\n\n" ;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	auto start = chrono::steady_clock::now();
    	gogo(is(aad,fre),0,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "10-yes\n"  << endl;
    	auto end = chrono::steady_clock::now();
    	long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	double ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"10------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(sel(aad,fre),1,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "11-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"11------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(bub(aad,fre),2,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "12-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"12------------------------------------------------------"<<endl;
    //output i--------------------------------------------------------------------------------------------
        cout<<"i-->"<<i<<endl;
    	fre+=100000;
    	
    	delete [] as;
    	delete [] ai;
    	delete [] alo;
    	delete [] ad;
    	delete [] af;
    	
    	vs.clear();
    	vi.clear();
    	vlo.clear();
    	vd.clear();
    	vf.clear();
    	
    	aas.fill("");
    	aai.fill(0);
    	aalo.fill(0);
    	aad.fill(0);
    	aaf.fill(0);
    }
    rd();

    fre=100000;
    for(int i=0;i<5;i++){
        cout<<"start\n";
    	string *as=new string[fre];
	    int *ai=new int[fre],pi;
	    long *alo=new long[fre],plo;
	    double *ad=new double[fre],pd;
	    float *af=new float[fre],pf;
	    
	    vector <string>vs;
	    vector <int>vi;
	    vector <long>vlo;
	    vector <double>vd;
	    vector <float>vf;
	    
	    static array <string,arnum> aas;
	    static array <int,arnum> aai;
	    static array <long,arnum> aalo;
	    static array <double,arnum> aad;
	    static array <float,arnum> aaf;
		cout << i+1 <<"W fre~~~\n\n" ;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	auto start = chrono::steady_clock::now();
    	gogo(is(aaf,fre),0,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "13-yes\n"  << endl;
    	auto end = chrono::steady_clock::now();
    	long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	double ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"13------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(sel(aaf,fre),1,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "14-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"14------------------------------------------------------"<<endl;
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(bub(aaf,fre),2,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "15-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"15------------------------------------------------------"<<endl;
    //output i--------------------------------------------------------------------------------------------
        cout<<"i-->"<<i<<endl;
    	fre+=100000;
    	
    	delete [] as;
    	delete [] ai;
    	delete [] alo;
    	delete [] ad;
    	delete [] af;
    	
    	vs.clear();
    	vi.clear();
    	vlo.clear();
    	vd.clear();
    	vf.clear();
    	
    	aas.fill("");
    	aai.fill(0);
    	aalo.fill(0);
    	aad.fill(0);
    	aaf.fill(0);
        cout<<"ENDDDDDDDDDD\n\n";
    }
    rd();

    /* 
	gogo(is(as,fre),0,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(as,fre),1,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(as,fre),2,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(ai,fre),0,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(ai,fre),1,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(ai,fre),2,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(alo,fre),0,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(alo,fre),1,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(alo,fre),2,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(ad,fre),0,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(ad,fre),1,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(ad,fre),2,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(af,fre),0,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(af,fre),1,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(af,fre),2,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);*/
    
    /*
    vector
    gogo(is(vs,fre),0,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(vs,fre),1,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(vs,fre),2,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(vi,fre),0,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(vi,fre),1,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(vi,fre),2,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(vlo,fre),0,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(vlo,fre),1,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(vlo,fre),2,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(vd,fre),0,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(vd,fre),1,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(vd,fre),2,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(vf,fre),0,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(vf,fre),1,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(vf,fre),2,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);*/
    
    /*
    array
    gogo(is(aas,fre),0,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(aas,fre),1,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(aas,fre),2,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(aai,fre),0,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(aai,fre),1,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(aai,fre),2,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(aalo,fre),0,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(aalo,fre),1,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(aalo,fre),2,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(aad,fre),0,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(aad,fre),1,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(aad,fre),2,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(is(aaf,fre),0,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(sel(aaf,fre),1,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(bub(aaf,fre),2,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    */ 
    return 0;
}
