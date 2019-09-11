#include <graphics.h> /* MODUL ZALEZNY OD BIBLIOTEKI GRAFICZNEJ - NIEPRZENOSNY */
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "patt2dat.h"
#include "pipek.hpp"
#include "grreadst.h"

extern float skala;
extern float epsilonapr;
extern int gdriver , gmode, changeany,mx,my,sx,sy,maxcol,textband,bandband,text,bacg,bands,donebands,stand,patt,paper;
extern int krok;  /* Wspolna dla wszystkich procedur tego modulu */
extern int Transform;  /* Flaga stasowania odwrotnej Approxymacji dla "x" w opcji view */
extern pipek load,lock,clear,aproks,aprtyp,apreps,killband,scale1,scale2,scale3,epsil,flip,on,Trans,dat,done;

void view(int WithSize , int stand, int bands , int patt );
void opis();

static void killall(int i)
{/* procedura pomocnicza dla nastepnej */
int pacik,odleg,j;
leyns[i].all_kill=!leyns[i].all_kill;
if(leyns[i].all_kill)
	     {
	      setcolor(0);
	      pacik=0xAAAA;
	     }
	else
	     {
	      setcolor(13);
	      pacik=0xFFF0;
	     }
for(j=0;j<leyns[i].band_number;j++)
		{
		float fp=leyns[i].bands[j].met;
		odleg=abs(fp*skala);
		if(leyns[i].all_kill)
			leyns[i].bands[j].met=(fp>0.0?-fp:fp);
			else
			leyns[i].bands[j].met=(fp>0.0?fp:-fp);
		setlinestyle(USERBIT_LINE,pacik,NORM_WIDTH);
		line(i*krok+1,odleg,(i+1)*krok-1,odleg);
		}
}

static void killthis(int i,int j)
{/* procedura pomocnicza dla nastepnej */
int pacik;
int odleg=abs(leyns[i].bands[j].met*skala);
if((leyns[i].bands[j].met*=-1)<0)
	     {
	      setcolor(0);
	      pacik=0xAAAA;
	     }
	else
	     {
	      setcolor(13);
	      pacik=0xFFF0;
	     }
setlinestyle(USERBIT_LINE,pacik,NORM_WIDTH);
line((i)*krok+1,odleg,(i+1)*krok-1,odleg);
}

void editing()
{
int serX,serY,serI,j;
int onefive=(mx-textband)/5;
float Met;
pipek pipESC;
pipESC.set(textband+onefive*3+6,my-40 ,onefive*2-6,35,donebands,(maxcol>1?stand:0));
pipESC.InstallText("ESC",27,1);
opis();
pipESC.put();
scale1.put();
scale2.put();
scale3.put();

if(changeany)
	viewsize();
if(Interface::GetIsMouse())
	Interface::VisCursor();
do{
if(Interface::GetIsMouse())
 {
 if(Interface::CheckClik()==1)
   {
   int pom=0;
   if(pipESC.DoIt())
		{
		Interface::UnVisCursor();
		break;/* zeby nie bylo dwukrotnego rysowania */
		}
   Interface::WaitForDrop();
   Interface::UnVisCursor();
   serX=Interface::GetMosX();
   serI=serX/krok;
   serY=Interface::GetMosY();
   if(serY==0)
	{
	killall(serI);
	changeany=1;
	}
    else
    if(serI>=leynnum)
	{
	viewsize();
	pipESC.put();
	changeany=0;
	}
	else
	{
	//jakie jest j jesli znamy serY ???
	  for(j=0;j<leyns[serI].band_number;j++)
		{
		pom=abs(leyns[serI].bands[j].met*skala);
		if(pom==serY) break;// j ustawione
		}
	// Zmiana znaku prazka - ujemna wartosc oznacza pomijanie
	if(serI>=0 && serI<leynnum && j>=0 && j<leyns[serI].band_number)
		 {
		 killthis(serI,j);
		 changeany=1;
		 }

	}
   Interface::VisCursor();
   }
 }
 else
 {
 char pom[256];
 int i,j;
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 grreadstr(pom,256,"LEYN ? ",sx/2,sy/2,12,donebands);
 if((i=atof(pom))>0 && i<=leynnum )
	{
	grreadstr(pom,256,"BAND ?(1..a) ",krok*i,sy/2,17,donebands);
	if(pom[0]=='A'||pom[0]=='a')/* zmiana znaku calego leynu */
		{
		killall(i-1);
		changeany=1;
		}
		else
		if((j=atof(pom))>0 && j<=leyns[i-1].band_number)
			{
			killthis(i-1,j-1);
			changeany=1;
			}
	}
 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 grreadstr(pom,256,"END (y/n/v) ? ",textband,sy/2,17,donebands);
 if(toupper(pom[0])=='Y') break;
 if(toupper(pom[0])=='V') viewsize();
 }
}while(Interface::GetClik()!=2);
pipek::clear();
changeany=1;
viewsize();
}
