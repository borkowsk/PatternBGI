#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define NUL	'\0'
#define ESC 	((char)27)
#define SL  	'\\'
#define BS	((char)8)
#define TAB 	((char)9)
#define STAB 	((char)15)
#define Home	 ((char)71)
#define UPARR	 ((char)72)
#define PGUP	 ((char)73)
#define LFARR	 ((char)75)
#define RTARR	 ((char)77)
#define End 	 ((char)79)
#define DNARR	 ((char)80)
#define PGDN     ((char)81)

class Interface
{
protected:
static int key;
static unsigned int IsMouse;
static int mosX,mosY;
static int mosClik;
static int gmode;
static unsigned int Advanced;
public:
static int  GetLastKey(){return key;}
static int  GetMosX(){return mosX;}
static int  GetMosY(){return mosY;}
static int  GetClik(){return mosClik;}
static int  GetIsMouse(){return IsMouse;}
static int  WaitForDrop();
static char Getcomm();

static int  MousePresent();  /* 0H */
static int  CheckClik();     /* 3H */
static void VisCursor();     /* 2H */
static void UnVisCursor();   /* 1H */
static void ConditionalOff(int x1,int y1,int x2,int y2); /* 10H */
static void SetCursor(int x,int y); /* 5H */
static void SetCursorPage(int p); /* 1DH */
static int  GetCursorPage(); /* 1EH */
static void SetCursorBox(int x1,int y1,int x2,int y2);/* 7H i 8H */
static int   SetVideoMode(int mode,int CSize); /* 28H */
static char* GetModeInfo(int& mode); /* 29H */
static unsigned int AdvancedFunctions(); /* 32H */
static void  MouseToVideo(int mx,int my); /* Przystosowanie myszy do trybu Video */
};

class pipek : Interface
{
int x,y,xd,yd;
int color,ramka;
int keychar,cliksens;
char* text;
public:
static void clear();
pipek();
int DoIt();
void InstallText(const char* t,int lkey,int lsens);
void set(int lx,int ly,int lxd, int lyd, int lcol , int lram);
void put();
void invers();
};
