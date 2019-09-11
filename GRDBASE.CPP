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
#include <assert.h>
#include "pipek.hpp"
#include "patt2dat.h"
#include "grreadst.h"

extern char  datname[256];
extern char  inputname[256];
extern char  sciezka[256];
extern char  ext[10];
extern float skala;
extern float epsilonapr;
extern int gdriver , gmode, changeany,mx,my,sx,sy,maxcol,textband,bandband,text,bacg,bands,donebands,stand,patt,paper;
extern int krok;  /* Wspolna dla wszystkich procedur tego modulu */
extern int Transform;  /* Flaga stasowania odwrotnej Approxymacji dla "x" w opcji view */
extern pipek dbase,flip;
static char BaseName[128]="*.cut ?";
static char Description[128]="/ No data base";
extern void  (*OutOfMem)(int);

void CRTOutOfMem(int);
void GROutOfMem(int);
void TITLE();
void  view(int WithSize , int stand, int bands , int patt );
void  opis();
void  repaintdesktop();
char* GetDescription(char* BaseName,char* Description);/* stringi minimum po 80 zmakow ! */
void  MakeNewDBase(char* BaseName,char* Description);
void  Searchlane(char*  BaseName,int l);
void  laneToDBase(char* BaseName,int l);

void gr_dbase()
{
char iobuf[156];
int onefive=(mx-textband)/5;
int serX=0,serY=0,i=-1,lnum=-1;
pipek search,save,Name,NewDb,pipESC,laneNum,comm;

Name.set(textband+3          ,my-199,onefive*5-3,17,(maxcol>1?text:1),bacg);
Name.InstallText(BaseName,'\\',1);
laneNum.set(textband+3          ,my-179,onefive*2.5-3,17,(maxcol>4?stand:0),maxcol);
laneNum.InstallText("laNe ?",'n',1);
search.set(textband+3          ,my-100,onefive*5-3,17,donebands,bacg);
search.InstallText("Search in d.base",'s',1);
save.set(textband+3          ,my-40 ,onefive*3-3,17,donebands,bacg);
save.InstallText("Lane to d.base",'l',1);
NewDb.set(textband+4	       ,my-20 ,onefive*3-3,17,donebands,bacg);
NewDb.InstallText("new d.bAse",'a',1);
comm.set(textband+4          ,my-60 ,onefive*5-3,17,(maxcol>1?text:1),bacg);
comm.InstallText(Description,'/',1);
pipESC.set(textband+onefive*3+6,my-40 ,onefive*2-6,35,donebands,(maxcol>1?stand:0));
pipESC.InstallText("ESC",27,1);



/* miejsce na nowe przyciski */
opis();
Interface::VisCursor();

do{
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
Interface::UnVisCursor();
Name.put();
laneNum.put();
dbase.put();
flip.put();
search.put();
comm.put();
save.put();
NewDb.put();
pipESC.put();
Interface::VisCursor();

while(!kbhit()&&(!Interface::CheckClik()))
	;
if( (serX=Interface::GetMosX())<textband && Interface::GetClik()!=0)
	{
	if(serX<0) serX=0;/* Gdy nie ma myszy to moze byc -1 */
	if(serX<bandband)
		{
		sprintf(iobuf,"lane:%3d",(lnum=(serX/krok+1)));
		laneNum.InstallText(iobuf,'y',1);
		serY=Interface::GetMosY();
		Interface::SetCursor(serX,serY);
		}
	goto END_LOOP;
	}
Interface::UnVisCursor();
/* obsluga bazy */
if(wherex()>50 || wherey()>19 )
		{
		changeany=0;
		repaintdesktop();
		}
if(laneNum.DoIt())
	{
	 laneNum.invers();
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	 grreadstr(iobuf,512,"lane: ? ",sx/2,sy,25,donebands);
	 if(*iobuf=='\0')
		goto END_LOOP;
	 if((i=atoi(iobuf))<0)
		i=1;/* obcinanie */
	 if(i==0) goto END_LOOP;
	serX=(i-1)*krok+krok/2;
	if(serX<bandband)
		       sprintf(iobuf,"lane:%3d",(lnum=(serX/krok+1)));
		  else
		  {
		  if(serX>textband) strcpy(iobuf,"MENU");
			       else   strcpy(iobuf,"EMPTY");
		  lnum=0;
		  }
	laneNum.InstallText(iobuf,'y',1);
	Interface::SetCursor(serX,serY);
	goto END_LOOP;
	}
if(dbase.DoIt() || Name.DoIt())
	{
	dbase.invers();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	grreadstr(iobuf,128,"Base name (*.cut):",sx/4,sy,64,donebands);
	if(*iobuf!='\0')
	       {
		*BaseName='\0';
	       if(strchr(iobuf,'\\')==NULL)
			{
			strcpy(BaseName,sciezka);
			strcat(BaseName,"\\");
			}
		strcat(BaseName,iobuf);
		if(strchr(iobuf,'.')==NULL)
			strcat(BaseName,".cut");
		Name.InstallText(BaseName,'\\',1);
		comm.InstallText("/ ???",'/',1);
		}
	goto END_LOOP;
	}
if(comm.DoIt())
	{
	comm.invers();
	if(gdriver!=HERCMONO)
		comm.InstallText(GetDescription(BaseName,Description),'/',1);
		else
		{
		 restorecrtmode();
		 OutOfMem=CRTOutOfMem;
		 TITLE();

		comm.InstallText(GetDescription(BaseName,Description),'/',1);

		 PAUSE;
		 setgraphmode(gmode);
		 OutOfMem=GROutOfMem;
		 Interface::MousePresent(); /* Long time running */
		 repaintdesktop();
		}
	goto END_LOOP;
	}
if(search.DoIt())
	{
	search.invers();
	if(lnum>0 && lnum<=lanenum)
		{
		if(lanes[lnum-1].fresh && !lanes[lnum-1].stand)
			{
			(putchar)('\7');
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			grreadstr(iobuf,12,"ERROR: Fresh or modified lane! "PENTER,sx/4,sy,45,stand);
			goto END_LOOP;
			}
		restorecrtmode();
		OutOfMem=CRTOutOfMem;
		linenum=0;
		TITLE();
		Searchlane(BaseName,lnum-1);
		changeany=1;
		PAUSE;
		setgraphmode(gmode);
		OutOfMem=GROutOfMem;
		if(gdriver==HERCMONO)
			Interface::MousePresent(); /* Long time running */
		repaintdesktop();
		}
		else
		{
		(putchar)('\7');
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		grreadstr(iobuf,12,"ERROR: Invalid lane number!"PENTER,sx/4,sy,40,stand);
		}
	goto END_LOOP;
	}
if(save.DoIt())
	{
	save.invers();
	if(lnum>0 && lnum<=lanenum)
		{
		if(lanes[lnum-1].fresh && !lanes[lnum-1].stand)
			{
			(putchar)('\7');
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			grreadstr(iobuf,12,"ERROR: Fresh or modified lane! "PENTER,sx/4,sy,45,stand);
			goto END_LOOP;
			}
			else
			{
			if(gdriver!=HERCMONO)
				{
				laneToDBase(BaseName,(lnum-1));
				changeany=1;
				}
				else
				{
				restorecrtmode();
				OutOfMem=CRTOutOfMem;
				TITLE();

				laneToDBase(BaseName,(lnum-1));
				changeany=1;

				PAUSE;
				setgraphmode(gmode);
				OutOfMem=GROutOfMem;
				Interface::MousePresent(); /* Long time running */
				repaintdesktop();
				}
			}
		}
		else
		{
		(putchar)('\7');
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		grreadstr(iobuf,12,"ERROR: Invalid lane number!"PENTER,sx/4,sy,40,stand);
		}
	goto END_LOOP;
	}
if(NewDb.DoIt())
	{
	NewDb.invers();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	grreadstr(iobuf,128,"Description:",sx/4,sy,64,donebands);
	if(*iobuf!='\0')
	  if(gdriver!=HERCMONO)
		{
		strcpy(Description,iobuf);
		MakeNewDBase(BaseName,Description);
		changeany=1;
		}
		else
		{
		restorecrtmode();
		OutOfMem=CRTOutOfMem;
		TITLE();

		strcpy(Description,iobuf);
		MakeNewDBase(BaseName,Description);
		changeany=1;

		PAUSE;
		setgraphmode(gmode);
		OutOfMem=GROutOfMem;
		Interface::MousePresent(); /* Long time running */
		repaintdesktop();
		}
	}
if( flip.DoIt())
		{
		flip.invers();
		viewsize();
		changeany=0;
		goto END_LOOP;
		};
/* Wyjscie */
if(pipESC.DoIt())
	{
	pipESC.invers();
	Interface::WaitForDrop();
	pipek::clear();
	break;
	}
END_LOOP:
Interface::VisCursor();
Interface::WaitForDrop();
pipek::clear();
HTEST;
}while(1);
/* sprzatanie */
repaintdesktop();
}
