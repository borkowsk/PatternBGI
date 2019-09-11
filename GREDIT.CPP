 /* MODUL ZALEZNY OD BIBLIOTEKI GRAFICZNEJ - NIEPRZENOSNY */
#include <graphics.h>
#include <dos.h>
#include <time.h>
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
extern pipek clear,scale1,scale2,scale3,epsil,flip,on,Trans,dat/*,done*/;
clock_t OLDTICS=0;
clock_t MIN_DELAY=CLK_TCK/5;
int Add_Del=1;/* Editing mode */

void writepat();
void view(int WithSize , int stand, int bands , int patt );
void opis();
void repaintdesktop();

static void Newlane()/* Umieszczenie nowego lejnu na koncu listy */
{
char bufor[256];
char* naz=NULL;
band *pom=NULL;
lane* actual=NULL;
Interface::UnVisCursor();

settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
grreadstr(bufor,255,"lane  name?:",sx/3,sy,45,donebands);
if(*bufor=='\0')
	{
	goto END;
	}
if((naz=(char*)calloc( strlen(bufor)+2,sizeof(char) ))==NULL)
	{
	OutOfMem(0);
	goto END;
	}
	else
	{
	PTEST(naz);
	strcpy(naz,bufor);
	}
if( lanenum>=MAX_lane_NUMBER)
	{
	(putchar)(7);
	grreadstr(bufor,255,"Too many lanes!"PENTER,sx/2,sy,15,donebands);
	goto END;
	}
actual=lanes+lanenum;
if(actual->label!=NULL)
	free(actual->label);
HTEST;
actual->label=naz;
actual->not_empty=0;
actual->all_kill=0;
actual->fresh=0;
actual->done=0;
actual->stand=0;
actual->arr_size=10;
pom=(band*)calloc(10,sizeof(band));
if(pom==NULL)
	{
	OutOfMem(0);
	goto END ;
	}
actual->bands=pom;
actual->band_number=0;
grreadstr(bufor,25,"Is it a standard lane?(y/n):",sx/2,sy,31,donebands);
if( strchr(bufor,'y') )
	actual->stand=1;
	else
	actual->fresh=1;
bandnum=0;
lanenum++;
changeany=1;
viewsize();

END:
Interface::VisCursor();
}

static void killall(int i)
{/* procedura pomocnicza dla nastepnej */
int pacik,odleg,j;
lanes[i].all_kill=!lanes[i].all_kill;
if(lanes[i].all_kill)
	     {
	      setcolor(0);
	      pacik=0xAAAA;
	     }
	else
	     {
	      if(lanes[i].stand) setcolor(stand);
			else     setcolor(13);
	      pacik=0xFFF0;
	     }
for(j=0;j<lanes[i].band_number;j++)
		{
		float fp=lanes[i].bands[j].met;
		odleg=abs(fp*skala);
		if(lanes[i].all_kill)
			lanes[i].bands[j].met=(fp>0.0?-fp:fp);
			else
			lanes[i].bands[j].met=(fp>0.0?fp:-fp);
		setlinestyle(USERBIT_LINE,pacik,NORM_WIDTH);
		line(i*krok+1,odleg,(i+1)*krok-1,odleg);
		}
}

static void Activ_Deactiv_lane(int serX)
{
int i=serX/krok;
Interface::UnVisCursor();
if(Interface::GetClik()==1 || Interface::Getcomm()=='-'  || Interface::Getcomm()=='+' )
	{
	killall(i);
	}
	else
	{
	char iobuf[80];
	sprintf(iobuf,"%s%s%s%s",lanes[i].done?"DONE ":"\0",lanes[i].fresh?"FRESH ":"\0",lanes[i].stand?"STANDARD ":"\0",lanes[i].all_kill?"NON ACTIVE":"\0");
	grreadstr(iobuf,80,iobuf,serX,1,1,donebands);
	}
changeany=1;
Interface::VisCursor();
}

static void killthis(int i,int j)
{/* procedura pomocnicza dla nastepnej */
int pacik;
int odleg=abs(lanes[i].bands[j].met*skala);
if((lanes[i].bands[j].met*=-1)<0)
	     {
	      setcolor(0);
	      pacik=0xAAAA;
	     }
	else
	     {
	     if(lanes[i].stand) setcolor(stand);
			else     setcolor(13);
	      pacik=0xFFF0;
	     }
setlinestyle(USERBIT_LINE,pacik,NORM_WIDTH);
line((i)*krok+1,odleg,(i+1)*krok-1,odleg);
}

static void Activ_Deactiv_Band(int serX,int serY)
{
Interface::UnVisCursor();
changeany=0;
Interface::UnVisCursor();
if(Interface::GetClik()!=0 || Interface::Getcomm()!='\0') /* Swith prazka */
	{
	float pom2=(serY+1)/skala;
	float pom1=serY/skala;
	float met;
	int j=serX/krok,i=0;
	lane* actual=lanes+j;

	for(i=0;i<actual->band_number;i++)/* Szukanie prazka */
		{
		met=fabs( actual->bands[i].met );
		if(pom1 <= met  &&   met<=pom2)
			break;
		}
	if(i<actual->band_number)
	    if(Interface::GetClik()==1 || Interface::Getcomm()=='+')
			killthis(j,i);
			else
			{
			char iobuf[64];
			sprintf(iobuf,"%g=%g+-%g",actual->bands[i].met,actual->bands[i].kbz,actual->bands[i].eps);
			grreadstr(iobuf,63,iobuf,serX,serY,1,donebands);
			}
	}
Interface::VisCursor();
}

int laneTransfer(int i,int j)
/* Transfer laneu w inne miejsce zelu */
{
if(i==j || j<0 || j>=lanenum || i<0 || i>=lanenum)
	return 0;
lane pom=lanes[i];/* Zapamientanie laneu - bo bedzie zniszczony */
assert(i>=0 && i<lanenum);
if(i<j)/* stara pozycja jest przed nowa */
	{
	memmove(lanes+i,lanes+(i+1),sizeof(lane)*abs(j-i));
	lanes[j]=pom;
	}
	else
	{
	memmove(lanes+(j+1),lanes+j,sizeof(lane)*abs(j-i));
	lanes[j]=pom;
	}
return 1;
}

void Deletelane(int i)
{
lane* actual=NULL;
if(i<0 || i>=lanenum) return;
actual=lanes+i;
free(actual->label);
free(actual->bands);
memcpy(lanes+i,lanes+i+1,sizeof(lane)*(--lanenum-i));/* zmniejsza lanenum */
lanes[lanenum].label=NULL;
lanes[lanenum].bands=NULL;
}

void laneEdit(int serX)/* Przeniesienie albo usuniecie laneu */
{
int i=serX/krok;
int j=i;
Interface::UnVisCursor();

if(Interface::GetClik()==2 || Interface::Getcomm()=='-') /* Usuwanie laneu */
	{
	char iobuf[64];
	(putchar)(7);
	grreadstr(iobuf,31,"Delete this lane ? (y/n)",sx/2,sy,27,stand);
	if(strchr(iobuf,'y')==NULL) goto END;
	Deletelane(i);
	changeany=1;
	HTEST;
	goto END;
	}
if(Interface::GetClik()==1) /* Przesuwanie laneu tylko z mysza */
	{
	j=i;/* prawidlowy numer laneu */
	killall(i);
	setwritemode(XOR_PUT);
	setcolor(maxcol);
	line(j*krok,0,j*krok,my);
	do{
	if(Interface::GetMosX()/krok!=j)
		{
		line(j*krok,0,j*krok,my);
		j=Interface::GetMosX()/krok;
		line(j*krok,0,j*krok,my);
		}
	}while(Interface::CheckClik()!=0);
	line(j*krok,0,j*krok,my);
	killall(i);
	if(i==j || j<0 || j>=lanenum )
		goto END;
	/* Transfer laneu w inne miejsce zelu */
	changeany=laneTransfer(i,j);
	}
END:
HTEST;
setwritemode(COPY_PUT);
viewsize();
changeany=0;
Interface::VisCursor();
}

void DeleteBand(lane*,int);
void BandEdit(int serX,int serY)/* Dodanie albo usuniecie prazka */
{
int i=serX/krok;
lane* actual=NULL;
Interface::UnVisCursor();
changeany=0;
if(i<0 || i>=lanenum)
	 return;
actual=lanes+i;
if(Interface::GetClik()==1 || Interface::Getcomm()=='+') /* Dodawanie prazka */
	{
	if(actual->band_number>=actual->arr_size)/* Wylapuje rekordy z nieustawionym rozmiarem tablicy */
		{
		band* pom=(band*)realloc(actual->bands,(actual->band_number+10)*sizeof(band));
		if(pom==NULL)
			{ OutOfMem(0);goto END ; }
		actual->arr_size=(actual->band_number+10);
		actual->bands=pom;
		}
	  actual->band_number++;
	i=actual->band_number-1;
	actual->bands[i].met=serY/skala;
	actual->bands[i].eps=epsilon;
	actual->not_empty=1;
	actual->fresh=1;
	actual->done=0;
	if(actual->stand)
		{
		char iobuf[32];
		float pom=0.0;
		ONERROR:
		grreadstr(iobuf,31,"Size ?:",sx/2,sy,25,donebands);
		if(*iobuf=='\0')
			{ actual->band_number--;goto E_S_C;}
		pom=atof(iobuf);
		if(pom!=0.0)
			actual->bands[i].kbz=pom;
			else
			{
			grreadstr(iobuf,31,"Format  error!"PENTER,sx/2,sy,30,stand);
			goto ONERROR;
			}
		E_S_C: ;
		}
		else
		actual->bands[i].kbz=0.0;
	changeany=0;
	HTEST;
	}
	else		    /* Usuwanie prazka */
	{
	float pom2=(serY+1)/skala;
	float pom1=serY/skala;
	float met;
	for(i=0;i<actual->band_number;i++)/* Szukanie prazka */
		{
		met=fabs( actual->bands[i].met );
		if(pom1 <= met  &&  met<=pom2)
			break;
		}
	if(i<actual->band_number)
		{
		(putchar)(7);
		DeleteBand(actual,i);
		changeany=1;
		}
	HTEST;
	}
END:
viewsize();
changeany=0;
Interface::VisCursor();
Interface::WaitForDrop();
pipek::clear();
}

void DeleteBand(lane *actual,int i)
{
memcpy(actual->bands+i,actual->bands+(i+1),sizeof(band)*(--actual->band_number-i));
if(actual->band_number==0)
	actual->not_empty=0;
}

void editing()
{
int serX,serY,j,i;
int onefive=(mx-textband)/5;
int onethre=(mx-textband)/3;
pipek pipESC;
pipek laneNum,BandNum,Mode;
pipek Save,SaveAs,comm1,comm2,comm3;
char iobuf[514];
int Add_Del=1;/* Editing mode */

Mode.set(textband+3          ,my-100,onefive*5-3,17,donebands,bacg);
Mode.InstallText("Mode: insert/delete",'m',1);
Save.set(textband+3          ,my-40 ,onefive*3-3,17,donebands,bacg);
Save.InstallText("savE",'e',1);
SaveAs.set(textband+4	       ,my-20 ,onefive*3-3,17,donebands,bacg);
SaveAs.InstallText("save As",'a',1);
pipESC.set(textband+onefive*3+6,my-40 ,onefive*2-6,35,donebands,(maxcol>1?stand:0));
pipESC.InstallText("ESC",27,1);
laneNum.set(textband+3          ,my-199,onefive*3-3,17,(maxcol>4?stand:0),maxcol);
BandNum.set(textband+3          ,my-179,onefive*3-3,17,(maxcol>4?stand:0),maxcol);
laneNum.InstallText("y:",'y',1);
BandNum.InstallText("x:",'x',1);
comm1.set(textband+4          ,my-60 ,onethre-3,17,donebands,bacg);
comm1.InstallText("com.1",'1',1);
comm2.set(textband+4+onethre  ,my-60 ,onethre-3,17,donebands,bacg);
comm2.InstallText("com.2",'2',1);
comm3.set(textband+4+2*onethre,my-60 ,onethre-3,17,donebands,bacg);
comm3.InstallText("com.3",'3',1);
opis();
if(changeany)
	viewsize();
Interface::VisCursor();
pipek::clear();
do{
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
Interface::UnVisCursor();
Save.put();
SaveAs.put();
Mode.put();
pipESC.put();
clear.put();
flip.put();
laneNum.put();
BandNum.put();
scale1.put();
scale2.put();
scale3.put();
comm1.put();
comm2.put();
comm3.put();
Interface::VisCursor();
/* Wizualizacja pozycji */
if(Interface::GetIsMouse()==0)
  {
  while(Interface::Getcomm()=='\0');
  if(Interface::GetMosX()!=-1)
	  serX=Interface::GetMosX();
  if(Interface::GetMosY()!=-1)
	  serY=Interface::GetMosY();
  }
  else
  while(!kbhit()&&(!Interface::CheckClik()))
   if(clock()-OLDTICS>=MIN_DELAY)/* Zabezpieczenie przed kolizja myszy z BGI */
      {
      if((j=Interface::GetMosY())!=serY)
	{ serY=j;
	if(skala!=0.0) sprintf(iobuf,"y:%5.3g cm",(float)serY/skala);
		  else strcpy(iobuf,"ERROR");
	laneNum.InstallText(iobuf,'y',1);
//		Interface::ConditionalOff(textband,my-200,mx,my-200+20);
	Interface::UnVisCursor();
	OLDTICS=clock();
	laneNum.put();
	Interface::VisCursor();
	}
      if((i=Interface::GetMosX())!=serX)
	{ serX=i;
	if(i<bandband) sprintf(iobuf,"x:%3d lane",(serX/krok+1));
		  else if(i>textband) strcpy(iobuf,"MENU");
			       else   strcpy(iobuf,"EMPTY");
	BandNum.InstallText(iobuf,'x',1);
//		Interface::ConditionalOff(textband,my-180,mx,my-180+20);
	Interface::UnVisCursor();
	OLDTICS=clock();
	BandNum.put();
	Interface::VisCursor();
	}
      }
if(
(serX<textband && (Interface::Getcomm()=='+'|| Interface::Getcomm()=='-')) ||
((Interface::GetIsMouse()) && (serX=Interface::GetMosX())<textband && Interface::GetClik()!=0)
)
 if(Add_Del)/* Addition/Deletion/Move */
	{
	if(serX>bandband)
		Newlane();
		else
		if(serY==0)
		    laneEdit(serX);
		    else
		    BandEdit(serX,serY);
	goto END_LOOP;
	}
	else
	{/* Activate/Deactivate */
	if(serY==0)
		Activ_Deactiv_lane(serX);
		else
		Activ_Deactiv_Band(serX,serY);
	goto END_LOOP;
	}

/* Cos z menu */
Interface::UnVisCursor();
if(wherex()>=50 || wherey()>19 )
		{
		changeany=0;
		repaintdesktop();
		}
if(Interface::Getcomm()== TAB)
	{
	int i=serX/krok;
	if((changeany=laneTransfer(i,i+1))!=0)
		{
		viewsize();
		changeany=0;
		Interface::SetCursor((i+1)*krok+krok/2,0);
		if(Interface::GetIsMouse()==0)
			{
			serX+=krok;
			sprintf(iobuf,"x:%3d lane",serX/krok+1);
			BandNum.InstallText(iobuf,'x',1);
			}
		}
	while(Interface::Getcomm())
		pipek::clear();
	goto END_LOOP;
	}
if(Interface::Getcomm()==STAB)
	{
	int i=serX/krok;
	if((changeany=laneTransfer(i,i-1))!=0)
		{
		viewsize();
		changeany=0;
		Interface::SetCursor((i-1)*krok+krok/2,0);
		if(Interface::GetIsMouse()==0)
			{
			serX-=krok;
			sprintf(iobuf,"x:%3d lane",serX/krok+1);
			BandNum.InstallText(iobuf,'x',1);
			}
		}
	while(Interface::Getcomm()==STAB)
		pipek::clear();
	goto END_LOOP;
	}
if(BandNum.DoIt())	/* x */
	{
	 BandNum.invers();
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	 grreadstr(iobuf,512,"lane: ? ",sx/2,sy,25,donebands);
	 if(*iobuf=='\0')
			goto END_LOOP;
	 if((i=atoi(iobuf))<=0)
		i=1;/* obcinanie */
	serX=(i-1)*krok+krok/2;
	if(serX<bandband)
		       sprintf(iobuf,"x:%3d lane",(serX/krok+1));
		  else if(serX>textband) strcpy(iobuf,"MENU");
			       else   strcpy(iobuf,"EMPTY");
	BandNum.InstallText(iobuf,'x',1);
	Interface::SetCursor(serX,serY);
	goto END_LOOP;
	}

if(laneNum.DoIt())	/* y */
	{
	 laneNum.invers();
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	 grreadstr(iobuf,512,"y: ? ",sx/2,sy,25,donebands);
	 if(*iobuf=='\0')
			goto END_LOOP;
	 serY=skala*atof(iobuf);
	if(skala!=0.0) sprintf(iobuf,"y:%5.3g cm",(float)serY/skala);
		  else strcpy(iobuf,"ERROR");
	laneNum.InstallText(iobuf,'y',1);
	Interface::SetCursor(serX,serY);
	goto END_LOOP;
	}

if(Mode.DoIt())
	{
	if(Add_Del)
		{
		Add_Del=0;
		Mode.InstallText("Mode:{in}activate",'m',1);
		}
		else
		{
		Add_Del=1;
		Mode.InstallText("Mode: insert/delete",'m',1);
		}
	goto END_LOOP;
	}
if( flip.DoIt())
		{
		flip.invers();
		viewsize();
		changeany=0;
		goto END_LOOP;
		};
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
		 viewsize();
		 changeany=0;
		 goto END_LOOP;
		}
if(scale2.DoIt())
	{
	scale2.invers();
	skala=2*skala;
	sprintf(iobuf,"Scale %g:1",skala);
	scale1.InstallText(iobuf,'s',1);
	changeany=1;
	 viewsize();
	 changeany=0;
	goto END_LOOP;
	}
if(scale3.DoIt())
	{
	scale3.invers();
	skala/=2;
	sprintf(iobuf,"Scale %g:1",skala);
	scale1.InstallText(iobuf,'s',1);
	changeany=1;
	viewsize();
	changeany=0;
	goto END_LOOP;
	}
if(comm1.DoIt())
	{
	size_t l=0;
	comm1.invers();
	grreadstr(iobuf,90,"HEADER:",8,sy,78,stand);
	if((l=strlen(iobuf))>0)
		{
		if(koment1!=NULL) {free(koment1);koment1=NULL;}
		HTEST;
		koment1=(char*)calloc(l+2,sizeof(char));
		if(koment1==NULL)
			OutOfMem(0);
			else
			strcpy(koment1,iobuf);
		}
	opis();
	HTEST;
	goto END_LOOP;
	}

if(comm2.DoIt())
	{
	size_t l=0;
	comm2.invers();
	grreadstr(iobuf,90,"DESCRIPTION 1:",8,sy,78,stand);
	if((l=strlen(iobuf))>0)
		{
		if(koment2!=NULL) {free(koment2);koment2=NULL;}
		HTEST;
		koment2=(char*)calloc(l+2,sizeof(char));
		if(koment2==NULL)
			OutOfMem(0);
			else
			strcpy(koment2,iobuf);
		}
	opis();
	HTEST;
	goto END_LOOP;
	}

if(comm3.DoIt())
	{
	size_t l=0;
	comm1.invers();

	grreadstr(iobuf,90,"DESCRIPTION 2:",8,sy,78,stand);
	if((l=strlen(iobuf))>0)
		{
		if(koment3!=NULL) {free(koment3);koment3=NULL;}
		HTEST;
		koment3=(char*)calloc(l+2,sizeof(char));
		if(koment3==NULL)
			OutOfMem(0);
			else
			strcpy(koment3,iobuf);
		}
	opis();
	HTEST;
	goto END_LOOP;
	}
if( clear.DoIt())
		{
		(putchar)(7);clear.invers();
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
if( SaveAs.DoIt()){
		SaveAs.invers();
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		grreadstr(iobuf,10,"Name (*.pat):",sx/2,sy,42,stand);
		if(*iobuf!='\0')
			{
			*inputname='\0';
			if(strchr(iobuf,'\\')==NULL)
				{
				strcat(inputname,sciezka);
				strcat(inputname,"\\");
				}
			strcat(inputname,iobuf);
			if(strchr(iobuf,'.')==NULL)
				strcat(inputname,".pat");
			opis();
			writepat();
			}
		goto END_LOOP;
		}
if( Save.DoIt()){
		Save.invers();
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		if(*inputname=='?')
			{
			grreadstr(iobuf,10,"Name (*.pat):",sx/2,sy,42,stand);
			if(*iobuf=='\0') goto END_LOOP;
			if(strchr(iobuf,'\\')==NULL)
				{
				strcat(inputname,sciezka);
				strcat(inputname,"\\");
				}
			strcat(inputname,iobuf);
			if(strchr(iobuf,'.')==NULL)
				strcat(inputname,".pat");
			opis();
			}
		writepat();
		goto END_LOOP;
		}
if(pipESC.DoIt())
	{
	pipESC.invers();
	Interface::WaitForDrop();
	break;
	}
END_LOOP:
Interface::VisCursor();
Interface::WaitForDrop();
pipek::clear();
}while(1);
repaintdesktop();
}
