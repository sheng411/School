#include <iostream>
#include <windows.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void gotoxy(int xpos, int ypos)
{
   COORD scrn;
   HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
   scrn.X = xpos; scrn.Y = ypos;
   SetConsoleCursorPosition(hOuput,scrn);
} 


int main(int argc, char** argv) {

	int arr[6][16] = {
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                     {1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1},
                     {1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1},
                     {1,1,1,0,0,1,1,0,0,0,0,1,1,1,0,1},
                     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
                     };	
					
	for(int y=0;y<6;y++)
      for(int x=0;x<16;x++){
         if(arr[y][x]==1){
            gotoxy(x,y);
            printf("*");
			}
			else{
				gotoxy(x,y);
            printf(" ");
			}
      }
	int x=1,y=1,x1=1,y1=1;
	gotoxy(x,y);
   printf("@");
	
	while(1){
      if(_kbhit()){
         x1=x;y1=y;
         switch (getch()){
         case 'w':
            if (arr[y-1][x]==0)
                  y--;
               gotoxy(15,20);
               printf("w");
               break;
         case 'a':
            if (arr[y][x-1]==0)
               x--;
               gotoxy(15,20);
               printf("a");
               break;
         case 's':
            if (arr[y+1][x]==0)
               y++;
               gotoxy(15,20);
               printf("s"); 
               break;    
         case 'd':
            if (arr[y][x+1]==0)
               x++;
               gotoxy(15,20);
               printf("d");
               break;
            default:
               break;
            }
         gotoxy(x1,y1);
         printf(" ");      
         gotoxy(x,y);
         printf("@");  
         Beep(100,100);  
      }
   }
	return 0;
}
