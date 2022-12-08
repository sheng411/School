#include <bits/stdc++.h>
using namespace std;

constexpr int arnum=1000000;
long double smfre=1;     //Use of small data
int fre=100000;         //quantity of data
int fadd=100000;        //add num
int frt=fadd;         //return num

//亂數排序
template <class rds,class rdi,class rdlo,class rdd,class rdf,class rdas,class rdai,class rdalo,class rdad,class rdaf,class rdaas,class rdaai,class rdaalo,class rdaad,class rdaaf>
    void randd(rds &vs,rdi &vi,rdlo &vlo,rdd &vd,rdf &vf,rdas &as,rdai &ai,rdalo &alo,rdad &ad,rdaf &af,rdaas &aas,rdaai &aai,rdaalo &aalo,rdaad &aad,rdaaf &aaf){
        int pi;long plo;double pd;float pf;
        srand(time(NULL));
        int rdn=10,rdm=10000;
        for(int i=0;i<fre;i++){
            
            vi.push_back(rand()%rdm/int(rdn));
            vlo.push_back(rand()%rdm/long(rdn));
            vd.push_back(rand()%rdm/double(rdn));
            vf.push_back(rand()%rdm/float(rdn));
            string na="aaaaaa";
            for(int x=0;x<6;x++){
                na[x]+=rand()%26;
            }
            vs.push_back(na);

            
            pi=rand()%rdm/int(rdn);
            plo=rand()%rdm/long(rdn);
            pd=rand()%rdm/double(rdn);
            pf=rand()%rdm/float(rdn);
            as[i]=na;
            ai[i]=pi;
            alo[i]=plo;
            ad[i]=pd;
            af[i]=pf;

            
            aas[i]=na;
            aai[i]=rand()%rdm/int(rdn);
            aalo[i]=rand()%rdm/long(rdn);
            aad[i]=rand()%rdm/double(rdn);
            aaf[i]=rand()%rdm/float(rdn);
        }
    }

template <class mer>
    int merg(mer &mr,int sn,int md,int en){
        using elType = typename mer::value_type;
        int L_s=md-sn+1;
        int R_s=en-md;
        elType L[L_s],R[R_s];
        for(int ll=0;ll<L_s;ll++){
            L[ll]=mr[sn+ll];
        }
        for(int rr=0;rr<R_s;rr++){
            R[rr]=mr[md+1+rr];
        }
        int i=0,j=0,k=sn;
        while(i<L_s && j<R_s){
            if(L[i] <=R[j]){
                mr[k]=L[i];
                i++;
            }
            else{
                mr[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<L_s){
            mr[k]=L[i];
            i++;
            k++;
        }
        while(j<R_s){
            mr[k]=R[j];
            j++;
            k++;
        }
        return 0;
    }

template <class mes>
    int mergso(mes &ms,int st,int ed){
        if(st<ed){
            int md=(st+ed)/2;
            mergso(ms,st,md);
            mergso(ms,md+1,ed);
            merg(ms,st,md,ed);
        }
        return 0;
    }

int rd(){
    fstream read;
    read.open("read.txt",ios::app);
    read<<"\n-----------------------------------------\n";
    read.close();
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


int main(){
    cout<<"GO start"<<endl;

    fstream myfile,read;
    read.open("read.txt",ios::app);
    read<<"\n-----------------------------------------\n";
    read.close();
    cout<<"file 200OK"<<endl;

    string *as=new string[fre];
    int *ai=new int[fre],pi;
    long *alo=new long[fre],plo;
    double *ad=new double[fre],pd;
    float *af=new float[fre],pf;

    /*
    fre=frt;
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
    	cout << "1ttt\n"  << endl;
        auto start = chrono::steady_clock::now();
        
    	gogo(mergso(as,0,fre-1),3,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
    	gogo(mergso(ai,0,fre-1),3,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
    	gogo(mergso(alo,0,fre-1),3,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(mergso(ad,0,fre-1),3,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "4-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
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
    	gogo(mergso(af,0,fre-1),3,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
        cout<<"i-->"<<i<<"\nTotal data:"<<fre<<endl;
    	fre+=fadd;
    	
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
        cout<<"1 2 3 4 5 ENDDDDD :)\n\n";
    }
    rd();
    */
    fre=frt;
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
    	cout << "1ttt\n"  << endl;
        auto start = chrono::steady_clock::now();
        
    	gogo(mergso(vs,0,fre-1),3,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "6-yes\n"  << endl;
    	auto end = chrono::steady_clock::now();
    	long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	double ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nInsertionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"6------------------------------------------------------"<<endl;
    // ----------------------------------------------------------------------------------------------
    	randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(mergso(vi,0,fre-1),3,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "7-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
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
    	gogo(mergso(vlo,0,fre-1),3,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
    	gogo(mergso(vd,0,fre-1),3,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(mergso(vf,0,fre-1),3,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "10-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nSelctionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"10------------------------------------------------------"<<endl;
        cout<<"i-->"<<i<<"\nTotal data:"<<fre<<endl;
    	fre+=fadd;
    	
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
        cout<<"6 7 8 9 10 ENDDDDD :)\n\n";
    }
    rd();
    
    fre=frt;
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
    	cout << "1ttt\n"  << endl;
        auto start = chrono::steady_clock::now();
        
    	gogo(mergso(aas,0,fre-1),3,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "11-yes\n"  << endl;
    	auto end = chrono::steady_clock::now();
    	long long att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	double ats=att*0.000000001;
    	cout << fre << endl;
    	cout<<"\nInsertionsort time-->"<<att<<"ns"<<endl;
    	myfile.open("count.txt",ios::app);      //改app
    	myfile<<"All time-->"<<att<<"ns-->"<<ats<<"s\n";
    	myfile<<"------------------------------------------------------------------------------------\n\n";
    	myfile.close();
        cout<<"11------------------------------------------------------"<<endl;
    // ----------------------------------------------------------------------------------------------
    	randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(mergso(aai,0,fre-1),3,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
    //-------------------------------------------------------------------------------------------------
        randd(vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	start = chrono::steady_clock::now();
    	gogo(mergso(aalo,0,fre-1),3,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    	cout << "13-yes\n"  << endl;
    	end = chrono::steady_clock::now();
    	att=chrono::duration_cast<chrono::nanoseconds>(end-start).count();    //秒 seconds
    	ats=att*0.000000001;
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
    	gogo(mergso(aad,0,fre-1),3,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
    	gogo(mergso(aaf,0,fre-1),3,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
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
        cout<<"i-->"<<i<<"\nTotal data:"<<fre<<endl;
    	fre+=fadd;
    	
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
        cout<<"11 12 13 14 15 ENDDDDD :)\n\n";
    }
    rd();

    /* 有問題
    gogo(mergso(as,0,fre-1),3,0,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(ai,0,fre-1),3,1,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(alo,0,fre-1),3,2,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(ad,0,fre-1),3,3,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(af,0,fre-1),3,4,0,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    */

    /*
    gogo(mergso(vs,0,fre-1),3,0,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(vi,0,fre-1),3,1,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(vlo,0,fre-1),3,2,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(vd,0,fre-1),3,3,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(vf,0,fre-1),3,4,1,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    */

    /*
    gogo(mergso(aas,0,fre-1),3,0,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(aai,0,fre-1),3,1,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(aalo,0,fre-1),3,2,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(aad,0,fre-1),3,3,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    gogo(mergso(aaf,0,fre-1),3,4,2,vs,vi,vlo,vd,vf,as,ai,alo,ad,af,aas,aai,aalo,aad,aaf);
    */
    cout<<"\n\nBye~~~\n\n";
    return 0;
}