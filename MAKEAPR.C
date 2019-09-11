/* MODUL ZALEZNY OD BIBLIOTEKI GRAFICZNEJ - NIEPRZENOSNY */
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <dos.h>
#include <values.h>
#include <math.h>
#include <alloc.h>
#include "patt2dat.h"
#include "pipek.hpp"
#include "grreadst.h"
extern float skala,epsilonapr;
extern int gdriver,gmode,changeany,mx,my,sx,sy,maxcol,textband,bandband,text,bacg,bands,donebands,stand,patt,paper;
static float max=1; /* Wartosc uzywana przez ponizsze funkcje jako
			maximum na osi 0Y - ustawiana przez  curve	*/
extern void GROutOfMem(int);
extern void CRTOutOfMem(int);
extern void TITLE();
void opis();
void curve();		/* pelna krzywa aproksymacji z punktami standartu */
void standartpoint();	/* Punkty standartow */
void curveslave();	/* sama krzywa */
void putscale(); 	/* drawt - wykres skali z krzywa Approxymacji*/

void ManualGenApprox(band* STD,int n)
{
extern double hA,hB,hC;/* Zmienne uzywane przez hiper Approxymacje */
char iobuf[128];
pipek pipA,pipB,pipC,pipAUTO,pipESC;
float lhA=hA,lhB=hB,lhC=hC;
//int onefive=(mx-textband)/5;
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
int width=mx-textband-5;
int begband=textband+3;
pipA.set(begband ,my-100,width,17,donebands,bacg);
pipB.set(begband ,my-80,width,17,donebands,bacg);
pipC.set(begband ,my-60,width,17,donebands,bacg);
pipAUTO.set(begband ,my-40,width/2,34,donebands,bacg);
pipESC.set(begband+width/2,my-40,width/2,34,donebands,(maxcol>1?stand:0));
sprintf(iobuf,"a=%g",hA);
pipA.InstallText(iobuf,'a',1);
sprintf(iobuf,"b=%g",hB);
pipB.InstallText(iobuf,'b',1);
sprintf(iobuf,"c=%g",hC);
pipC.InstallText(iobuf,'c',1);
pipAUTO.InstallText("!auto",'!',1);
pipESC.InstallText("ESC ",27,1);
opis();
curve();
outtextxy(sx,sy," Y=A/(X-B)+C ");
do{
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
pipA.put();
pipB.put();
pipC.put();
pipAUTO.put();
pipESC.put();
Interface::VisCursor();
while(!kbhit()&&(!Interface::CheckClik()))
	;
Interface::UnVisCursor();
if(pipESC.DoIt())
		{
		pipESC.invers();
		Interface::WaitForDrop();
		changeany=1;
		break;
		}
if(pipA.DoIt())
		{
		 pipA.invers();Interface::WaitForDrop();pipek::clear();
		 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		 grreadstr(iobuf,512,"A ? ",sx/2,sy,25,donebands);
		 if(*iobuf=='\0')
			goto END_LOOP;
		 lhA=atof(iobuf);
		 sprintf(iobuf,"a=%g",lhA);
		 pipA.InstallText(iobuf,'a',1);
		}
if(pipB.DoIt())
		{
		 pipB.invers(); Interface::WaitForDrop();pipek::clear();
		 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		 grreadstr(iobuf,512,"B ? ",sx/2,sy,25,donebands);
		 if(*iobuf=='\0')
			goto END_LOOP;
		 lhB=atof(iobuf);
		 sprintf(iobuf,"b=%g",lhB);
		 pipB.InstallText(iobuf,'b',1);
		}
if(pipC.DoIt())
		{
		 pipC.invers(); Interface::WaitForDrop();pipek::clear();
		 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		 grreadstr(iobuf,512,"C ? ",sx/2,sy,25,donebands);
		 if(*iobuf=='\0')
			goto END_LOOP;
		 lhC=atof(iobuf);
		 sprintf(iobuf,"c=%g",lhC);
		 pipC.InstallText(iobuf,'c',1);
		}
if(pipAUTO.DoIt())
		{
		pipAUTO.invers(); Interface::WaitForDrop();pipek::clear();
		double y1=STD[0].kbz  ,p=1/(/*x1*/STD[0].met-lhB);
		double y2=STD[n-1].kbz,q=1/(/*x2*/STD[n-1].met-lhB);;
		lhC=(y1*q-y2*p)/(q-p);
		lhA=(y2-y1)/(q-p);
		sprintf(iobuf,"a=%g",lhA);
		pipA.InstallText(iobuf,'a',1);
		sprintf(iobuf,"c=%g",lhC);
		pipC.InstallText(iobuf,'c',1);
		}
if(lhA!=hA || lhB!=hB || lhC!=hC ) /* byla zmiana parametrow */
	{
	setcolor(text);
	setwritemode(XOR_PUT);
	curveslave();		/* Wymazanie */
	hA=lhA;hB=lhB;hC=lhC;   /* Faktyczna wymiana parametrow hiperboli */
	curveslave();		/* Nowe narysowanie */
	setwritemode(COPY_PUT);
	}
END_LOOP:
pipek::clear();
}while(1);
pipek::clear();
opis();
}

void SetKbz()
{
int i,j;
for(i=0;i<lanenum;i++)
   {
   if(!lanes[i].all_kill) lanes[i].fresh=0;/*Jesli caly skasowany to pozostaje swierzy !*/
   if((!lanes[i].stand) && (!lanes[i].done) ) /* wpisuje tylko laneom wczytanym bez flag "done" i "standart"*/
   for(j=0;j<lanes[i].band_number;j++)
		     if(lanes[i].bands[j].met>0)
			{
			float pf,pk;
			/* wartosc Approxymowana */
			lanes[i].bands[j].kbz=pk=Approxymation( pf=lanes[i].bands[j].met );
			/* sredni blad */
			lanes[i].bands[j].eps=
(
fabs(pk-Approxymation(pf+epsilon))+fabs(pk-Approxymation(pf-epsilon))
)
		       /2;
			}
			else
			{
			lanes[i].bands[j].kbz=0;
			lanes[i].bands[j].eps=0;
			}
	}
}

void makeApproxymation()
{
band* STDlane=NULL;
double AE=0.0,AP;/* Sredni blad aproksymacji standartu i zminna pomocnicza */
char iobuf[64];
int i,j=0,stdbandnum=0,poz=0;
extern void opis();
/* SPRAWDZENIE ILE JEST STANDARTOW */
for(i=0;i<lanenum;i++)
	if(lanes[i].stand && (!lanes[i].all_kill))
		{ j++;
		 stdbandnum+=lanes[i].band_number;}
/* JESLI 0 TO BLAD */
if(j==0){
	(putchar)(7);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	grreadstr(iobuf,10,"ERROR:  No Standard!"PENTER,sx/2,sy,35,stand);
	return;
	}
/* JESLI WIECEJ NIZ JEDEN TO PYTANIE */
if(j>1){
	setcolor(text);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	grreadstr(iobuf,10,"Which standart ?(1..n or 'a' for all)",sx/2,sy,40,stand);
	}
	else
	{
	iobuf[0]='1';
	iobuf[1]='\0';
	}
/* JESLI TRZEBA LACYC TO LACZENIE */
if( strchr(iobuf,'a') )
	{
	STDlane=(band*)calloc(stdbandnum,sizeof(band));/* alokacja tymczasowej tablicy */
	if(STDlane==NULL)
		{
		OutOfMem(0);
		return;
		}
	poz=0;
	for(i=0;i<lanenum;i++)
		if(lanes[i].stand && (!lanes[i].all_kill))
			{
			for(j=0;j<lanes[i].band_number;j++)
				{
				if(lanes[i].bands[j].met>0)
				   STDlane[poz++]=lanes[i].bands[j];
				}
			 }
	}
	else
	{
	int st=atoi(iobuf)-1;j=0;
	for(i=0;i<lanenum;i++) /* searching standart lane */
		if(lanes[i].stand && (!lanes[i].all_kill))
			{
			if(j==st) break;
			j++;
			}
	if( i<0 || i>=lanenum ) /* checking validation */
		{
		(putchar)(7);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		grreadstr(iobuf,10,"ERROR:  Invalid lane number!"PENTER,sx/2,sy,44,stand);
		return;
		}
	STDlane=(band*)calloc(lanes[i].band_number,sizeof(band));/* alokacja tymczasowej tablicy */
	poz=0;
	for(j=0;j<lanes[i].band_number;j++)
		if(lanes[i].bands[j].met>0)
		 {
		 STDlane[poz++]=lanes[i].bands[j];
		 }
	}
/* MAKE-APPROXYMATION */
sortbands(STDlane,poz);      /* sortowanie tablicy */
max=STDlane->kbz*2;	     /* konieczne ustawienia dla funkcji rysujacych */
if(gdriver==HERCMONO)
	{
	if(AppType!=ManuType)
		{
		restorecrtmode();
		OutOfMem=CRTOutOfMem;
		TITLE();
		genApproxymation(STDlane,poz);/* wykonanie aproksymacji dla "poz" punktow */
		setgraphmode(gmode);
		OutOfMem=GROutOfMem;
		opis();
		}
		else
		genApproxymation(STDlane,poz);
	}
	else
	/* wykonanie aproksymacji dla "poz" punktow */
	genApproxymation(STDlane,poz);

/* Policzenie sredniego bledu */
AE=0.0;
AP=0.0;
for(i=0;i<poz;i++)
	{
	AP=Approxymation(STDlane[i].met);
	AE+=fabs(STDlane[i].kbz-AP);
	}
AE=AE/poz;

free(STDlane);		     /* tablica tymczasowa juz niepotrzebna */
/* NARYSOWANIE KRZYWEJ ApproxYMACJI I PYTANIE O ZGODE */
curve();
HTEST;
setcolor(text);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
{
char tbuf[50];
sprintf(tbuf,"AE=%10.5g(y/n)",AE);
grreadstr(iobuf,3,tbuf,sx,10,20,stand);
}
/* ODPOWIEDNIA AKCJA RYSOWANIA */
if( strchr(iobuf,'y') )
  {
  setbkcolor(DARKGRAY);
  setfillstyle(SOLID_FILL,0);
  bar(0,0,textband,my);
  putscale();	    /* Dla Approxymacji NullType - kopiujacej */
		    /* nie jest spelniona monotonicznosc     */
  /* WPISANIE WARTOSCI*/
  SetKbz();
  HTEST;
  /* RYSOWANIE Z LICZBAMI */
  changeany=0;
  lnview();
  }
  else
  {
  changeany=1;
  viewsize();
  }
}

void standartpoint()
{
int k,i,x,y,nkas;
setcolor(stand);
for(k=0;k<lanenum;k++)
 if(lanes[k].stand)
    for(i=0;i<lanes[k].band_number;i++)
	{
	x=lanes[k].bands[i].met*skala;
	y=my-((lanes[k].bands[i].kbz/max)*my);
	setcolor(stand);
	nkas=(x>0);
	if(nkas) /* jesli nie skasowany */
		setlinestyle(SOLID_LINE,0,NORM_WIDTH);
		else
		{
		setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
		x=-x;
		}
	line(x-10,y,x+10,y);
	line(x,y-10,x,y+10);
	if(nkas)
		{
		setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
		setcolor(text);
		line(0,y,x,y);
		line(x,y,x,my);
		}
	}
}

void curveslave()
{
int y;
double yf;
setlinestyle(SOLID_LINE,0,NORM_WIDTH);
moveto(0,0);
setcolor(bands);
for(int i=1;i<textband;i++)
	{
	yf=my-((Approxymation(i/skala)/max)*my);
	if( yf< MAXINT && yf> -MAXINT )
	    y=yf;
	    else
	    {
	    if(yf>0) y=MAXINT-1;
		else y=-(MAXINT-1);
	    }
	moverel(1,0);
	lineto(i,y);
	}
}

void curve()
/* pelna krzywa aproksymacji z punktami standartu */
{
int i,scint=skala,my_5=my-5;
setbkcolor(BLACK);
setfillstyle(SOLID_FILL,0);
bar(0,0,textband,my);
setcolor(maxcol);
setlinestyle(SOLID_LINE,0,NORM_WIDTH);
line(0,0,0,my);
line(0,0,5,10);
line(0,my,textband,my);
line(textband,my,textband-10,my_5);
if(scint>0)
   for(i=1;i<textband;i++)
	if(i%scint==0)
		{
		line(i,my,i,my_5);
		}
standartpoint();
curveslave();
}

void putscale()
{
int x,y,curveband=bandband,width;
/*int dec,sign;*/
char stat[32];
double fy,fyy;
setviewport(0,0,textband,my,1);
moveto( curveband, 0 );
setlinestyle(SOLID_LINE,0,NORM_WIDTH);
setcolor(maxcol);
settextstyle(SMALL_FONT,HORIZ_DIR,4);
width=(textband-curveband)/textwidth("X");

lineto( curveband , 1 );
for(x=1;x<=my;x++)
	{
	fy=Approxymation(x/skala);
	fyy=curveband*(fy/max);
	if(x%20==0){
		line(curveband,x,textband,x);
		sprintf(stat,"%*.4g",width-1,fy);
		outtextxy(curveband+1,x-10,stat);
		if(fyy<curveband)
			moveto(fyy,x);
			else
			moveto(curveband,x);
		}
	if(fyy<curveband)
		y=fyy;
		else
		y=curveband;
	if( AppType )
		lineto( y , x );
	}
settextstyle(SMALL_FONT,HORIZ_DIR,5);
setviewport(0,0,mx,my,1);
}
