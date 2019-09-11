#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include "pipek.hpp"

int READ_BACKGROUND=1;

char far* grreadstr(
		char far* dest,
		unsigned bufsiz,
		char far* zacheta,
		int x1,
		int y1,
		int szer_zn,
		int color)
{
void* bufor=NULL;
int   ismap=0;
int   oldcolor=getcolor();
struct viewporttype info;
struct linesettingstype linfo;
struct fillsettingstype fillinfo;
size_t size=0;
int     x2,y2;
char    key[2]="\0";
int licz=0,mx=getmaxx(),my=getmaxy();

getviewsettings(&info);
getlinesettings(&linfo);
getfillsettings(&fillinfo);
szer_zn*=textwidth("X");
graphresult();
if(szer_zn>textwidth(zacheta))
	x2=x1+szer_zn;
    else
	x2=x1+szer_zn+textwidth(zacheta);
y2=y1+textheight("X")+6;
if(x1<0) x1=0;if(x2>mx) x2=mx;
if(y1<0) y1=0;if(y2>my) y2=my;
size=imagesize(x1,y1,x2,y2);
if((bufor=malloc(size))!=NULL)
	{
	getimage(x1,y1,x2,y2,bufor);
	if(graphresult()==grOk) ismap=1;
	}
	else ismap=0;
/* wlasciwe dzialania */
setfillstyle(SOLID_FILL,READ_BACKGROUND);

bar(x1,y1,x2,y2);
setviewport(x1,y1,x2,y2,1);

setlinestyle(SOLID_LINE,0,THICK_WIDTH);
setcolor(color);
line(0,0,x2-x1, 0);
line(0,0, 0,y2-y1);
line(x2-x1,y2-y1,0,y2-y1);
line(x2-x1,y2-y1,x2-x1,0);
setviewport(x1+3,y1+4,x2-2,y2-2,1);
outtext(zacheta);
dest[0]='\0';
Interface::WaitForDrop();
do{
while(!kbhit() && !Interface::CheckClik())
	;
if(Interface::GetClik()!=0)
	*key='\r';
	else
	*key=getch();
if(*key==27)
	{
	*dest='\0';
	licz=1;
	break;
	}
if(*key!='\b')
	{
	outtext(key);
	dest[licz]=*key;
	licz++;
	}
    else
	{
	int pomx=getx()-textwidth("X");
	int pomy=gety();
	licz--;
	if( licz<0 )
		{
		putchar('\a');
		licz=0;
		}
	  else
		{
		dest[licz]='\0';
		bar(pomx,pomy,getx(),pomy+textheight("X"));
		moveto(pomx,pomy);
		}
	}

}while( licz<bufsiz && (*key!='\r'));
Interface::WaitForDrop();
licz--;
dest[licz]='\0';
/* koniec dzialan */
/* PRZYWRACANIE PARAMETROW */
setviewport(0,0,getmaxx(),getmaxy(),1);
if(ismap)
	putimage(x1,y1,bufor,COPY_PUT);
if(bufor!=NULL)
	free(bufor);
setviewport(info.left,info.top,info.right,info.bottom,info.clip);
setlinestyle(linfo.linestyle,linfo.upattern,linfo.thickness);
setfillstyle(fillinfo.pattern, fillinfo.color);
setcolor(oldcolor);
return dest;
}