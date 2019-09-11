/* MODUL ZALEZNY OD BIBLIOTEKI GRAFICZNEJ - NIEPRZENOSNY */
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
extern jmp_buf post_error;
#include "patt2dat.h"
#include "pipek.hpp"
#include "grreadst.h"

float skala=20.0;
extern float epsilonapr;
extern int gdriver, gmode;
extern int mx,my,sx,sy,maxcol;
char* AppTypeStr[]={"No: Y=X  "," Y=A/X+C ","Standard","Polynominal","Poly... ln(Y)","Poly... log(Y)","Manual"," Error "};
int changeany,textband,bandband,text,bacg,bands,donebands,stand,patt,paper;
int krok=1;  /* Wspolna dla wszystkich procedur tego modulu */
int Transform=0;  /* Flaga stasowania odwrotnej Approxymacji dla "x" w opcji view */
pipek load,locking,clear,edit,dbase,aproks,aprtyp,apreps,scale1,scale2,scale3,epsil,flip,on,Trans,dat,done;

void CRTOutOfMem(int);
void GROutOfMem(int);
void  (*OutOfMem)(int)=CRTOutOfMem;

int AreFresh()
{/* sprawdzenie czy dane byly aproksymowane */
for(int i=0;i<lanenum;i++)
	if(lanes[i].fresh &&(!lanes[i].all_kill)) return 1;
return 0;
}

void view(int WithSize , int stand, int bands , int patt )
{
static char stat[128];
int 	    i,j,odleg,OdlegOld;
int 	 width,height;		/* parametry wyswietlania rozmiarow */
int           beg,end;		/* i wyswietlania prazkow */
double 		  Met;
extern double hA,hB,hC; /* Dostep do parametrow regresji hiperbolicznej dla transformacji */
void HiperGenApprox(band*,int ); /* import funkcji hiper Approxymacji uzytej tutaj w sposob nietypowy */

krok=((textband)/(float)(lanenum+1));	/* Uaktualnienia wartosci globalnego kroku */
bandband=krok*lanenum;			/* Wartosc pozbawiona bledu dzielenia calkowitego */
settextstyle(SMALL_FONT,HORIZ_DIR,4);
width=krok/textwidth("X");      /* Ustalenie szerokosci liczb */
if( width>127 ) width=127;	/* Test dla bardzo dlugich band */
height=textheight("1");		/* Ustalenie wysokosci liczb */
HTEST;
if( Transform  )
	{
	if( AreFresh() )
		    {
		    (putchar)(7);
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		    grreadstr(stat,10,"ERROR:  No   approximation!  "PENTER,sx/2,sy,42,stand);
		    goto END;
		    }
	if(hA==1.0)
	  {
	  /* Potrzebne sa dane do odwrotnej Approxymacji hiperbolicznej */
	  i=0;
	  while(!lanes[i].stand) i++; /* Szukanie jakiegos standartu */
	  if( i<lanenum )	/* Znaleziono */
		HiperGenApprox( lanes[i].bands , lanes[i].band_number );
	      else
		{
		/* Jesli nie ma to cos trzeba wpisac ! */
		hA=15;hB=0;hC=0;
		}
	  }
	}
if(changeany)
	{
	setbkcolor(bacg);
	setfillstyle(SOLID_FILL,0);
	bar(0,0,textband,my);
	if(lanenum==0)
		goto END;
	setviewport(0,0,textband,my,1);
	if(maxcol<4 && Transform )
		{
		setfillstyle(SOLID_FILL,1);
		bar(bandband,0,textband,my);
		}
	}
setlinestyle(SOLID_LINE,0,NORM_WIDTH);
for(i=0;i<lanenum;i++)
	{
	beg=i*krok+1;
	end=(i+1)*krok-1;
	setcolor(text);
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	line(beg,0,end,0);
	if(lanes[i].done)
		{
		setcolor(donebands);
		line(beg,0,beg,mx);
		line(end,0,end,mx);
		}
	setcolor(stand);
	if(krok>textheight("X"))
		settextstyle(SMALL_FONT,VERT_DIR,5);
		else
		settextstyle(SMALL_FONT,VERT_DIR,3);
	moveto(beg,my-textwidth(lanes[i].label));
	outtext(lanes[i].label);
	if(Transform && lanes[i].fresh)
		{
		setcolor(maxcol);
		moverel(0,-textwidth(" No approximation."));
		outtext(" No approximation.");
		setcolor(stand);
		}
	if(Transform && lanes[i].all_kill)
		{
		setcolor(maxcol);
		moverel(0,-textwidth(" All killed."));
		outtext(" All killed.");
		setcolor(stand);
		}
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	odleg=0; /* Nadanie wartosci */
	for(j=0;j<lanes[i].band_number;j++)
		{
		OdlegOld=odleg;/* Przepisanie odleglosci poprzedniego prazka */
		if(Transform)
			{
			Met=hA/(lanes[i].bands[j].kbz-hC);
			if(lanes[i].bands[j].met<0)
				 Met*=-1;
			}
			else
			Met=lanes[i].bands[j].met;
		odleg=Met*skala;
		if(odleg<0)
			{
			odleg*=-1;
			setlinestyle(DOTTED_LINE,0,NORM_WIDTH);
			}
			else
			setlinestyle(SOLID_LINE,0,NORM_WIDTH);

		if(lanes[i].stand)
			{
			setcolor(stand);
			line(beg,odleg,end,odleg);
			}
			else
			{
			if(Transform)
				{
				setcolor(patt);
				line(end,odleg,textband,odleg);
				}
			if(WithSize /*& maxcol>8 */ )
			  {
			  if(maxcol>8)
				  setfillstyle(SOLID_FILL,9); //No HERC
				  else
				  setfillstyle(LTSLASH_FILL,1); //HERC itp
			  if(Transform && !lanes[i].fresh )
				bar(beg,(hA/(lanes[i].bands[j].kbz-lanes[i].bands[j].eps-hC))*skala,
				    end,(hA/(lanes[i].bands[j].kbz+lanes[i].bands[j].eps-hC))*skala);
				else
				bar(beg,(Met-epsilon)*skala,
				    end,(Met+epsilon)*skala);
			  }
			setcolor(bands);
			line(beg,odleg,end,odleg);
			}
		if(WithSize && Met>0)
		 if(odleg-(OdlegOld)>height)
			{
			sprintf(stat,"%*.4g",width,lanes[i].bands[j].kbz);
			if( strlen(stat)>width)
				{
				if( strchr(stat,'e')==NULL )
				    stat[width]='\0';
				    else
				    stat[0]='\0';
				}
			outtextxy(beg+1,odleg-10,stat);
			}
		}

	}
END:
setviewport(0,0,mx,my,1);
settextstyle(SMALL_FONT,HORIZ_DIR,5);
}


void editing();/* Edycja patternu w innym module */

void opis()
{
extern char datname[256];
extern char inputname[256];
/*char pattern[8] = {0xFF, 0xAA, 0xFF, 0x55, 0xFF, 0xAA, 0xFF, 0x55};*/
char pattern[8] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};
int hai;

if(maxcol>=15)
	setfillstyle(SOLID_FILL,paper);
	else
	setfillpattern(pattern,paper);

bar(textband,0,mx,my);
setcolor(RED);
settextstyle(SANS_SERIF_FONT,0,3);
outtextxy(textband+2,0,"PATTERN VIEW");
hai=textheight("P");
setcolor(text);
settextstyle(SMALL_FONT,0,4);
outtextxy(textband+5,hai,inputname);
hai+=textheight("C");
settextstyle(SMALL_FONT,0,5);
outtextxy(textband+5,hai,"COMMENT:");
hai+=textheight("C");
if(koment1) outtextxy(textband+5,hai,koment1);
hai+=textheight("C");
if(koment2) outtextxy(textband+5,hai,koment2);
hai+=textheight("C");
if(koment3) outtextxy(textband+5,hai,koment3);
}

void repaintdesktop()
{
changeany=1;
opis();
viewsize();
gotoxy(1,1);/* Kursor tekstowy na pocztek */
}

void graphics_view()
{
int errorcode=0,olderror=0;
char iobuf[514];/* Conajmniej 2 bajty bezpieczenstwa */
extern void TITLE();
extern void  LOAD();
extern void lockbands();
extern int StartGraphix();

if( StartGraphix() ) return;/* Inicjacja trybu graficznego i myszy */

OutOfMem=GROutOfMem;
changeany=0;
if(maxcol>=15)
	{
	setbkcolor(DARKGRAY);
	setcolor(RED);
	text=YELLOW;
	bacg=BLUE;
	patt=LIGHTBLUE;
	bands=LIGHTMAGENTA;
	donebands=LIGHTGRAY;
	stand=LIGHTRED;
	paper=BROWN;//GREEN
	READ_BACKGROUND=DARKGRAY;
	}
	else
	if(maxcol>=3)
		{
		setcolor(0);
		text=3;
		bacg=0;
		bands=1;
		donebands=1;
		stand=3;
		paper=1;
		READ_BACKGROUND=0;
		}
		else
		{
		setcolor(0);
		text=0;
		bacg=0;
		bands=1;
		donebands=1;
		stand=1;
		paper=1;
		READ_BACKGROUND=0;
		}
{
textband=sx+sx/2;
int onefive=(mx-textband)/5;
load.set(textband+3          ,my-199,onefive*1.5-3,17,donebands,bacg);
locking.set(textband+onefive*1.5+3,my-199,onefive*1.5-3,17,donebands,bacg);
clear.set(textband+onefive*3+3,my-199,onefive*2-3,17,donebands,bacg);
edit.set(textband+3        ,my-179,onefive*2.5-3,17,donebands,bacg);
dbase.set(textband+onefive*2.5+3,my-179 ,onefive*2.5-3,17,donebands,bacg);
  flip.set(textband+3          ,my-160 ,onefive*2.5-3,17,donebands,bacg);
 Trans.set(textband+onefive*2.5+3,my-160 ,onefive*2.5-3,17,donebands,bacg);
scale1.set(textband+3          ,my-140,onefive*3-3,17,donebands,bacg);
scale2.set(textband+onefive*3+3,my-140,onefive-3  ,17,donebands,bacg);
scale3.set(textband+onefive*4+1,my-140,onefive-3  ,17,donebands,bacg);
aproks.set(textband+3          ,my-120,onefive*4-3,17,donebands,bacg);
aprtyp.set(textband+3          ,my-100,onefive*4-3,17,donebands,bacg);
apreps.set(textband+3          ,my-80,onefive*5-3,17,donebands,bacg);
 epsil.set(textband+4          ,my-60 ,onefive*5-3,17,donebands,bacg);
    on.set(textband+3          ,my-40 ,onefive*3-3,17,donebands,bacg);
   dat.set(textband+4	       ,my-20 ,onefive*3-3,17,donebands,bacg);
  done.set(textband+onefive*3+6,my-40 ,onefive*2-6,35,donebands,(maxcol>1?stand:0));
}
load.InstallText("Load",	'l',1);
locking.InstallText("lOck",	'o',1);
clear.InstallText("Clear",	'c',1);
aproks.InstallText("Approximation",'a',1);
SwitchApproxymation();
aprtyp.InstallText(AppTypeStr[AppType],'=',1);
	sprintf(iobuf,"Precision: %g ",epsilonapr);
apreps.InstallText(iobuf,	'p',1);
	sprintf(iobuf,"Scale %g : 1",skala);
scale1.InstallText(iobuf,	's',1);
scale2.InstallText(">",		'.',1);
scale3.InstallText("<",		',',1);
	sprintf(iobuf,"epsIlon %g",epsilon);
epsil.InstallText(iobuf,	'i',1);
edit.InstallText("Edit",	'e',1);
dbase.InstallText("d.Base",	'b',1);
 flip.InstallText("View",	'v',1);
Trans.InstallText("Trans",	't',1);
   on.InstallText("Write *.ptt",'w',1);
  dat.InstallText("write *.Dat",'d',1);
 done.InstallText("QUIT",	'q',1);
HTEST;
errorcode = setjmp(post_error);
if (errorcode != 0)
   {
   extern int ingraph;/* znacznik przebywania w trybie graficznym */
if(gdriver==HERCMONO || !ingraph)
	{
	setgraphmode(gmode);
	OutOfMem=GROutOfMem;
	Interface::MousePresent(); /* Long time running */
	}
   if(olderror==errorcode)
	{
	(putchar)(7);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	sprintf(iobuf,"FATAL ERROR %d !: Terminate program ? (y/n)",errorcode);
	grreadstr(iobuf,10,iobuf,sx/2,sy,3,stand);
	if(strchr(iobuf,'y'))
		{
		exit(1);
		}
	olderror=0;
	}
	else olderror=errorcode;
   }
repaintdesktop();
do{
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
load.put();
locking.put();
clear.put();
aproks.put();
aprtyp.put();
apreps.put();
edit.put();
dbase.put();
scale1.put();
scale2.put();
scale3.put();
epsil.put();
flip.put();
Trans.put();
on.put();
dat.put();
done.put();
Interface::VisCursor();
while(!kbhit()&&(!Interface::CheckClik()))
	;
{
Interface::UnVisCursor();
if(wherex()>50 || wherey()>19 )
		{
		changeany=0;
		repaintdesktop();
		}
if(aproks.DoIt())
		{
		aproks.invers();
		makeApproxymation();
		if(gdriver==HERCMONO)
			Interface::MousePresent(); /* Long time running */
		changeany=0;
		goto END_LOOP;
		}
if(aprtyp.DoIt())
		{
		aprtyp.invers();
		(++AppType)%=ErrorType;
		aprtyp.InstallText(AppTypeStr[AppType],'=',1);
		SwitchApproxymation();
		changeany=1;
		goto END_LOOP;
		}
if(apreps.DoIt())
		{
		 apreps.invers();
		 settextstyle( DEFAULT_FONT,HORIZ_DIR,1);
		 grreadstr(iobuf,512,"Precision ? ",sx/2,sy,25,donebands);
		 if(*iobuf=='\0')
			goto END_LOOP;
		 epsilonapr=atof(iobuf);
		 sprintf(iobuf,"Precision %g",epsilonapr);
		 apreps.InstallText(iobuf,'p',1);
		 changeany=1;
		 goto END_LOOP;
		}
if(edit.DoIt())
		{
		edit.invers();
		changeany=1;
		editing();
		goto END_LOOP;
		}
if(dbase.DoIt())
		{
		extern void gr_dbase();/* zapowiedz */
		dbase.invers();
		changeany=1;
		gr_dbase();
		goto END_LOOP;
		}
if(scale1.DoIt())
		{
		 scale1.invers();
		 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		 grreadstr(iobuf,512,"Scale ? ",sx/2,sy,25,donebands);
		 if(*iobuf=='\0')
			goto END_LOOP;
		 skala=atof(iobuf);
		 sprintf(iobuf,"Scale %g:1",skala);
		 scale1.InstallText(iobuf,'s',1);
		 changeany=1;
		 goto END_LOOP;
		}
if(scale2.DoIt())
	{
	scale2.invers();
	skala*=2;
	sprintf(iobuf,"Scale %g:1",skala);
	scale1.InstallText(iobuf,'s',1);
	changeany=1;
	goto END_LOOP;
	}
if(scale3.DoIt())
	{
	scale3.invers();
	skala/=2;
	sprintf(iobuf,"Scale %g:1",skala);
	scale1.InstallText(iobuf,'s',1);
	changeany=1;
	goto END_LOOP;
	}
if(epsil.DoIt())
	{
	epsil.invers();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	grreadstr(iobuf,512,"Epsilon ? ",sx/2,sy,25,donebands);
	if(*iobuf=='\0')
			goto END_LOOP;
	epsilon=atof(iobuf);
	sprintf(iobuf,"epsIlon %g ",epsilon);
	epsil.InstallText(iobuf,'i',1);
	changeany=1;
	goto END_LOOP;
	}

}
if( clear.DoIt())
		{
		clear.invers();
		(putchar)(7);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		grreadstr(iobuf,10,"Clear storage ?! (y/n)",sx/2,sy,24,stand);
		if( strchr(iobuf,'y') )
			{
			freebands();
			changeany=1;
			repaintdesktop();
			}
		goto END_LOOP;
		}
if( flip.DoIt() )
		{
		flip.invers();
		viewsize();
		changeany=0;
		goto END_LOOP;
		};


if( Trans.DoIt())
		{
		Trans.invers();
		changeany=1;
		Transform=1;
		view(1, stand, bands , patt );
		Transform=0;
		goto END_LOOP;
		};
if(   on.DoIt()){
		on.invers();
		if( AreFresh() )
		    {
		    (putchar)(7);
		    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		    grreadstr(iobuf,10,"ERROR:  No   Approximation!  "PENTER,sx/2,sy,42,stand);
		    }
		    else
		    writeptt();
		goto END_LOOP;
		}
if( dat.DoIt())
		{
		dat.invers();
		if(epsilon==0)
			{
			(putchar)(7);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			grreadstr(iobuf,10,"ERROR !: EPSILON=0"PENTER,sx/2,sy,32,stand);
			continue;
			}
		if( gdriver!=HERCMONO)
			{
			make_pattern();
			writedat();
			setfillstyle(SOLID_FILL,paper);
			opis();
			changeany=1;
			}
			else
			{
			restorecrtmode();
			OutOfMem=CRTOutOfMem;
			TITLE();
			make_pattern();
			writedat();
			setgraphmode(gmode);
			OutOfMem=GROutOfMem;
			Interface::MousePresent(); /* Long time running */
			repaintdesktop();
			}
		    goto END_LOOP;
		    }

if( locking.DoIt()){
		lockbands();
		viewsize();
		goto END_LOOP;
		}
if( load.DoIt()){
		restorecrtmode();
		OutOfMem=CRTOutOfMem;
		linenum=0;
		TITLE();
		LOAD();
		PAUSE;
		setgraphmode(gmode);
		OutOfMem=GROutOfMem;
		if(gdriver==HERCMONO)
			Interface::MousePresent(); /* Long time running */
		repaintdesktop();
		goto END_LOOP;
		}

if( done.DoIt())
		{
		done.invers();
		Interface::WaitForDrop();
		restorecrtmode();
		OutOfMem=CRTOutOfMem;
		return;
		}
END_LOOP:
Interface::WaitForDrop();
pipek::clear();
}while(1);

}

void CRTOutOfMem(int mod)
{
fprintf(stderr,"\7Sorry!  Out of memory...\n");
if( mod )
  {
  fprintf(stderr,"Fatal: Can`t continue!\n");
  exit(mod);
  }
}

void GROutOfMem(int mod)
{
char iobuf[12];
(putchar)(7);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
grreadstr(iobuf,10,"Sorry:  Out of memory! "PENTER,sx/2,sy,37,stand);
if(mod)
      {
grreadstr(iobuf,10,"Fatal:  Can`t  continue! "PENTER,sx/2,sy,39,stand);
      exit(mod);
      }
}
