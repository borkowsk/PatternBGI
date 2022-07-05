#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(void)
{
   char *str = "This is a test string";
   int c,oldx,oldy,newx,newy;
   clrscr();
   cputs(str);
   getch();
oldx=oldy=1;
randomize();
do{
 newx=random(10);
 newy=random(15);
 movetext(oldx,oldy, strlen(str), 2, newx, newy);
 oldx=newx;
 oldy=newy;
 c=getch();
  }while(c!='q');

   return 0;
}
