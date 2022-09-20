#include <bits/stdc++.h>
using namespace std;

vector <int> txt(27);
char ch;

int main(){
    ifstream ifile("D:/code/School/C++/oop.txt",ios::in);
    while(ifile.get(ch)){
        switch(ch){
            case 'a':
                txt[0]++;
                break;
            case 'b':
                txt[1]++;
                break;
            case 'c':
                txt[2]++;
                break;
            case 'd':
                txt[3]++;
                break;
            case 'e':
                txt[4]++;
                break;
            case 'f':
                txt[5]++;
                break;
            case 'g':
                txt[6]++;
                break;
            case 'h':
                txt[7]++;
                break;
            case 'i':
                txt[8]++;
                break;
            case 'j':
                txt[9]++;
                break;
            case 'k':
                txt[10]++;
                break;
            case 'l':
                txt[11]++;
                break;
            case 'm':
                txt[12]++;
                break;
            case 'n':
                txt[13]++;
                break;
            case 'o':
                txt[14]++;
                break;
            case 'p':
                txt[15]++;
                break;
            case 'q':
                txt[16]++;
                break;
            case 'r':
                txt[17]++;
                break;
            case 's':
                txt[18]++;
                break;
            case 't':
                txt[19]++;
                break;
            case 'u':
                txt[20]++;
                break;
            case 'v':
                txt[21]++;
                break;
            case 'w':
                txt[22]++;
                break;
            case 'x':
                txt[23]++;
                break;
            case 'y':
                txt[24]++;
                break;
            case 'z':
                txt[25]++;
                break;
        }
    }

    ifile.close();
    int maax=0;
    for(int i=0;i<26;i++){
        if(txt[maax]<txt[i+1]){
            maax=i+1;
        }
        cout<<"[i]-"<<i<<"-"<<char(i+'a')<<"--"<<txt[i]<<endl;
    }
    cout<<"Max:"<<char(maax+'a')<<" num:"<<txt[maax]<<endl;

    int miin=0,i=0;
    do{
        if(txt[miin]>txt[i+1]){
            miin=i+1;
        }
        i++;
    }while(i<26);
    cout<<"Min:"<<char(miin+'a')<<" num:"<<txt[miin]<<endl;
    return 0;
}