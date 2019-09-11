
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>
#ifdef DEBUG
#define HTEST if(heapcheck()<0) {fprintf(stderr," Fatal: Heap corrupted! %s ,%d\n",__FILE__,__LINE__);abort(); }
#define PTEST(_P_) if((_P_)==NULL) {fprintf(stderr," Fatal: NULL USE! %s ,%d\n",__FILE__,__LINE__);abort(); }
#else
#define HTEST
#define PTEST
#endif
#include "pipek.hpp"

#pragma options -rd
 int Interface::key=0;
 unsigned
 int Interface::IsMouse=0;
 int Interface::mosX=-1;
 int Interface::mosY=-1;
 int Interface::mosClik=0;
 int Interface::gmode=0;
 static int divX=1;
 static int divY=1;
 static int DontUse=0;
 unsigned int Interface::Advanced=0;


int Interface::MousePresent()
{
 int gmode,gdriver ;
  /* detect graphics hardware available */
 if(DontUse) return (IsMouse=0);
 detectgraph(&gdriver, &gmode);
 if(gdriver==HERCMONO)
	pokeb( 0 , 0x449 , 6 );
_AX=0;// inicjacja
geninterrupt(51);// run long time ???
if(_AX==0 )
	IsMouse=0;
	else
	IsMouse=1;
return IsMouse;
}

void Interface::MouseToVideo(int mx,int my)
{
mx++;my++;    /* rozmiar ekranu a nie max */
divX=1;divY=1;/* Gdyby byly zmienione w powtornym wywolaniu */
MousePresent();
if(!IsMouse)
	{
	fprintf(stderr,"\nMouse not detected\n");
	return;/* Nie ma co delej robic */
	}
CheckClik();
mosX*=2;mosY*=2;/* Przy inicjacji kursor na srodek ekranu */
AdvancedFunctions();/* Obecnosc funkcji od 24H w gore */
if((mx-15)<mosX && mosX<(mx+15) && (my-15)<mosY && mosY<(my+15))
		goto RET;/* OK */
/*	if(mosX>615 && mosX<655)
		mosX=640;
	if(mosY>185 && mosY<215)
		mosY=200;*/
if((mosY>315 && mosY<360)||(mosY>465 && mosY<490))
		goto RET;/* OK */
if(mx<=mosX)
	divX=(long)mosX/(long)mx;
	else
	goto ERROR;
if(my<=mosY)
	divY=(long)mosY/(long)my;
	else
	goto ERROR;
RET:
DontUse=0;
#ifdef DEBUG
fprintf(stderr,"Mouse: maxX=%d maxY=%d divX=%d divY=%d Advanced=%d\n",mosX,mosY,divX,divY,Advanced);
#endif
return;
ERROR:
fprintf(stderr,"\nMouse does not match screen mode %dx%d (%dx%d)!\n",mx,my,mosX,mosY);
getch();
DontUse=1;
IsMouse=0;
}

unsigned int Interface::AdvancedFunctions() /* 32H */
{
unsigned int Adv;
if(!IsMouse) return 0;
_AX=0x32;
geninterrupt(51);
Adv=_AX;
if(Adv==50) /* Function 32H not Available !!! */
	Advanced=0;
	else
	Advanced=Adv;
return Adv;
}

void Interface::VisCursor()
{
if(!IsMouse) return;
_AX=1;
geninterrupt(51);
}

void Interface::UnVisCursor()
{
if(!IsMouse) return;
_AX=2;
geninterrupt(51);
}

void Interface::SetCursor(int x,int y) /* 4H */
{
x*=divX;y*=divY;
if(!IsMouse)
	{
	mosX=x;
	mosY=y;
	 return;
	}
_AX=4;
_CX=x;
_DX=y;
geninterrupt(51);
CheckClik();
}

void Interface::ConditionalOff(int x1,int y1,int x2,int y2)
{
if(!IsMouse) return;
x1*=divX;
y1*=divY;
x2*=divX;
y2*=divY;
_CX=x1;
_DX=y1;
_SI=x2;
_DI=y2;
_AX=16;
geninterrupt(51);
}

char Interface::Getcomm()
{
if(kbhit())
	{
	key=getch();
	if(key==NUL)
		switch(key=getch()){
		case STAB:break;/* Returned STAB==15 */
		case Home:
		key=NUL;break;
		case UPARR:
		key=NUL;break;
		case DNARR:
		key=NUL;break;
		case LFARR:
		key=NUL;break;
		case RTARR:
		key=NUL;break;
		case End:
		key=NUL; break;
		default:
		key=NUL;break;/* Ignore - no action*/
		}
	}
return  key;
}

int Interface::CheckClik()
{
if(IsMouse)
	{
	_AX=3;
	geninterrupt(51);
	mosX=_CX;
	mosY=_DX;
	mosX/=divX;
	mosY/=divY;
	mosClik=_BX;
	return mosClik;
	}
      else return 0;
}

int Interface:: WaitForDrop()
{
if(!IsMouse) return 0;
int OldClik=mosClik;
while(OldClik==mosClik && mosClik!=0)
	CheckClik();
return 1;
}


extern int maxcol; /* Musi gdzies byc !*/
void pipek::clear()
{
mosX=-1;
mosY=-1;
mosClik=0;
key=0;
}

pipek::pipek()
{
x=y=xd=yd=color=ramka=keychar=0;cliksens=-1;text=NULL;
}

int pipek::DoIt()
{
if(mosClik==cliksens && mosX>x && mosX<x+xd && mosY>y && mosY<y+yd)
		       return 1;
if(Getcomm()==keychar) return 1;
   else		       return 0;
}

void pipek::set(int lx,int ly,int lxd, int lyd, int lcol , int lram)
{
x=lx;y=ly;xd=lxd;yd=lyd;color=lcol;ramka=lram;
}

void pipek::put()
{
viewporttype  viewinfo;
getviewsettings(&viewinfo);
setfillstyle(SOLID_FILL,color);
bar(x,y,x+xd-2,y+yd-2);
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
if(maxcol>=15)
	setcolor(DARKGRAY);
    else
	setcolor(ramka);
line(x+3,y+yd,x+xd,y+yd);
line(x+xd,y+yd,x+xd,y+2);
setviewport(x,y,x+xd-2,y+yd-2,1);
setcolor(ramka);
	outtextxy(2,2,text);/* Text jest obcinany */
setviewport(viewinfo.left,viewinfo.top,viewinfo.right,viewinfo.bottom,viewinfo.clip);
}

void pipek::invers()
{
viewporttype  viewinfo;
getviewsettings(&viewinfo);
setfillstyle(SOLID_FILL,ramka);
bar(x,y,x+xd-2,y+yd-2);
setlinestyle(SOLID_LINE,0,THICK_WIDTH);
if(maxcol>=15)
	setcolor(DARKGRAY);
	else
	setcolor(color);
line(x+3,y+yd,x+xd,y+yd);
line(x+xd,y+yd,x+xd,y+2);
setviewport(x,y,x+xd-2,y+yd-2,1);
setcolor(color);
outtextxy(2,2,text);/* Text jest obcinany */
setviewport(viewinfo.left,viewinfo.top,viewinfo.right,viewinfo.bottom,viewinfo.clip);
}

void pipek::InstallText(const char* t,int lkey,int lsens)
{
if(text!=NULL) delete text;
HTEST;
text=new char[strlen(t)+1];
strcpy(text,t);
keychar=lkey;
if(lsens!=0)
	cliksens=lsens;
}

