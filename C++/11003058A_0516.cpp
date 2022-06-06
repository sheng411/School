#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

int a,fre=5;//fre為vector需存多少數字
int partialsum(vector<int>, int);

int main(void){
   srand(time(NULL));
   int max=100,min=0;
   vector<int> myvector{};
   for(int i=0;i<fre;i++){
      int num;
      num=rand()%(max-min+1)+min;   //以後若需更改可直接改上方範圍
      myvector.push_back(num);
   }
   cout<<"f:";
   cin>>a;
   cout<<"SUM:"<< partialsum(myvector,a)<<endl;
   system("pause");
   return 0;
}

int partialsum(vector<int> myvect, int f){
   int sum=0,i=0;
   switch (f){
   case 1:
      for (int i=0;i<myvect.size();i+=2){
         sum+=myvect[i];
      }
      return sum;
      break;
   case 2:
      for (int i=1;i<myvect.size();i+=2){
         sum+=myvect[i];
      }
      return sum;
      break;
   case 3:
      //int i=0;
      while (myvect.size()>3*i){
         sum+=myvect[3*i];
         i+=1;
      }
      return sum;
      break;
   case 4:
      //int i=0;
      do{
         sum+=myvect[3*i+1];
         i+=1;
      } while (myvect.size()>3*i+1);
      return sum;
      break;
   case 5:
      for (int i=0;i<myvect.size();i=3*i+2){
         sum+=myvect[i];
      }
      return sum;
      break;
   default:
      cout<<"Number is not in range!"<<endl;
   }

   /*
   if(f==2)
      for (int i=0;i<myvect.size();i+=2){
         sum+=myvect[i];
      }
      return sum;
   */
   return 0;
}