/* START GRAPHIX MODULE */

#include <graphics.h> /* MODUL ZALEZNY OD BIBLIOTEKI GRAFICZNEJ - NIEPRZENOSNY */
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pipek.hpp"

int gdriver = DETECT;	/* GRAPHICS DRIVER NUMBER & MODE NUMBER */
int gmode=0,mx=0,my=0,sx=0,sy=0,maxcol=0;	/* SCREEN PARAMETERS */
int ingraph=0;/* znacznik przebywania w trybie graficznym */
int FORCE_GRAY=0;/* znacznik monitora szarego */
char *cards[]={"None","MDA mono","CGA color",
	       "3-reserved","EGA color","EGA mono",
	       "PGC","VGA mono","VGA color",
	       "9-reserved"};

int GrayMonitor()
{
unsigned char test;
//return 1;
_AH=0x1A;
_AL=0x0;
geninterrupt(0x10);
test=_AL;
if( test==0x1A )
	return (_BL==7);
     else
	return 0;
return 0;
}


void grexit(void)
{
closegraph();
printf("\n BGI Graphics shut down");
}

void GrayCorection()
{
_BX=0;
_CX=256;
_AL=0x1B;// korekcja szarosci
_AH=0x10;// funkcja 10H "kolory i atrybuty"
geninterrupt(0x10);
}

int huge mydetect()
{
return gmode;
}

int StartGraphix()
{
int errorcode=0;
FILE* config=NULL;
char startup[128];
char iobuf[256];
char* ptr=NULL;
/* Check startup directory */
strcpy(startup,_argv[0]);
if( (ptr=strrchr(startup,'\\'))!=NULL)
	     startup[(ptr-startup)]='\0';
	     else
	     *startup='\0';
/* Check Config.scr */
strcpy(iobuf,startup);
strcat(iobuf,"\\config.scr");
if((config=fopen(iobuf,"r"))!=NULL)
	{
	/* init graph in user driver & mode */
	fscanf(config,"%s\n",iobuf);
	fscanf(config,"%d",&gmode);
	fscanf(config,"%d%d%d",&maxcol,&mx,&my);
	gdriver=installuserdriver(iobuf,mydetect);
	if((errorcode = graphresult()) !=grOk) goto ON_ERROR;
	printf("If not in graph.mode press Q !\n");
	initgraph(&gdriver, &gmode,startup);
	if((errorcode = graphresult()) !=grOk) goto ON_ERROR;
	if(mx==0) mx=getmaxx();
	if(my==0) my=getmaxy();
	if(maxcol<0)
		{ maxcol=-maxcol;FORCE_GRAY=1;}
	if(maxcol==0) maxcol=getmaxcolor();
	}
	else
	{
	/* init graph in detected mode */
	printf("If not in graph.mode press Q !\n");
	initgraph(&gdriver, &gmode,startup);
	if((errorcode = graphresult()) !=grOk) goto ON_ERROR;
	*iobuf='\0';
	mx=getmaxx();
	my=getmaxy();
	maxcol=getmaxcolor();
	}
/* If Sukces */
atexit(grexit);
if(FORCE_GRAY==0)
	FORCE_GRAY=GrayMonitor();
if(FORCE_GRAY)
	GrayCorection();/* Konwersja kolorow */
Interface::MouseToVideo(mx,my);/* Inicjacje pakietu obslugi myszy */
/* Usable parameters */
sx=mx/2;
sy=my/2;
ingraph=1;
return 0;/* OK */
ON_ERROR:
if (errorcode != grOk)  /* an error occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);             /* return with error code */
}

}

void RestoreCrtMode()
{
ingraph=0;
restorecrtmode();
}

void SetGraphMode(int M)
{
setgraphmode(M);
if(graphresult() ==grOk)
	{
	ingraph=1;
	if(FORCE_GRAY)	GrayCorection();/* Konwersja kolorow */
	}
}
