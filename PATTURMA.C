
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <signal.h>
#include <conio.h>
#include <string.h>
#include <setjmp.h>
#include <DOS.H>
#include "patt2dat.h"

extern jmp_buf post_error;
char datname[256]="???  ";
char inputname[256]="???";
char sciezka[256]=" ";
char ext[10]=".dat\0";
extern int withStandard;
extern float    epsilon;
FILE* inputfile;
extern FILE* yyin;

void TITLE()
{
extern char* autor();
extern char* user();
window(1,1,80,25);
textcolor(LIGHTRED);
textbackground(BLUE);
clrscr();
cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf("บ                  P A T T E R N      V I E W      v 1.2                       บ");
cprintf("บ%78sบ",autor());
cprintf("บ");
textcolor(YELLOW);
cprintf("%78s",user());
textcolor(LIGHTRED);
cprintf("บ");
cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
window(1,6,80,25);
textcolor(YELLOW);
textbackground(0);
clrscr();
}

int LOAD()
{
extern void poczasie();
int err=0;
char* ptr=NULL,iobuf[128],pom[1000];;
gotoxy(1,1);
strcpy(iobuf,_argv[0]);
if( (ptr=strrchr(iobuf,'\\'))!=NULL)
	     iobuf[(ptr-iobuf)]='\0';
	     else
	     *iobuf='\0';
poczasie();
*pom='\0';
strcpy(pom,iobuf);
strcat(pom,"\\config.tax");
if((inputfile=fopen(pom,"rt"))==NULL)
      {
      fprintf(stderr,"\nCan't open %s file!",pom);
      perror("->");
      putc('\n',stderr);
      strcpy(sciezka,".");
      }
      else
      {
      fgets(sciezka,256,inputfile);
      if(fileno(inputfile)==( FOPEN_MAX -2 ) )
	{
	fprintf(stderr,"To many open files! Save your data and exit!\n");
	fcloseall();
	}
	else
	fclose(inputfile);
       {
       int i;
       for(i=strlen(sciezka);i>=0;i--)
	   if(sciezka[i]=='\n')
		      sciezka[i]='\0';
       }
      PRINTF("			DATA from <<%s>>\n\n\n",sciezka);
      }
ptr=NULL;
strcpy(pom,iobuf);
strcat(pom,"\\okno ");
							//strcat(pom,sciezka);
							//strcat(pom," *.p?t\0");
PRINTF("			EXECUTE:%s\n", pom);
if((err=spawnl(P_WAIT,pom,pom,sciezka,"*.p?t","14","28",NULL))!=0)
							//if((err=system(pom))!=0)
	{
	perror("Okno can`t run ");
	delay(200);
	}
ptr=NULL;
strcpy(pom,".\\okno.job");
if((inputfile=fopen(pom,"rt"))==NULL)
	{
	if(err!=0)
		{
		//clrscr();
		fprintf(stderr,"\nNo %s file!\nPress  ENTER!\n",pom);
		gets(pom);
		strcpy(pom,"dir ");
		strcat(pom,sciezka);
		strcat(pom,"\\*.p?t /w");
		if(system(pom))
			{
			 perror("Dir error");
			 delay(200);
			 return 0;
			}
		PRINTF("\nFILE NAME ??? :");
		gets(pom);
		strcpy(inputname,sciezka);
		strcat(inputname,"\\");
		strcat(inputname,pom);
		}
		else
		return 0;
	}
	else
	{
	textcolor(YELLOW);
	fgets(inputname,256,inputfile);
	fclose(inputfile);
	 {
	 int i;
	 for(i=strlen(inputname);i>=0;i--)
	   if(inputname[i]=='\n')
		inputname[i]='\0';
	 }
	ptr=NULL;
	//strcpy(pom,"del ");
	//strcat(pom,iobuf);
	//strcat(pom,"okno.job");
	system("del okno.job");
	}
clrscr();
PRINTF("DATA from file %s\n",inputname);
if((inputfile=fopen(inputname,"rt"))==NULL)
	{
	fprintf(stderr,"\nCan't open input %s file!\n",inputname);
	perror("->");
	/*exit(1);*/
	return 1;
	}
	else
	{
	yyin=inputfile;
	if(yyparse()!=0)
		{
		fclose(inputfile);
		return 1;
		}
		else fclose(inputfile);
	}

return 0;
}

void BATHMODE()
  {
char pom[256];
  dump_array();
  PRINTF("\nCOMMENT:\n<<\n%s\n%s\n%s\n>>",koment1,koment2,koment3);
  PRINTF("\nUSE Standard'S IN *.DAT FILE (y/n)");

  fflush(stdout);
  gets(pom);
  if(pom[0]=='y')
	{
	withStandard=1;
	PRINTF("  With Standard\n");
	}
  if(epsilon==0.0)
	{
	PRINTF("   EPSILON ???=");
	gets(pom);
	epsilon=atof(pom);
	}
  PRINTF("   Epsilon=%f\n\n",epsilon);
  make_pattern();
  printpattern();
  writedat();
}

int main()
{
char pom[256];
int value = setjmp(post_error);
if (value != 0)
   {
   printf("\nUnrecoverable error - code %d\n", value);
   exit(value);
   }
directvideo=0;
TITLE();
if(LOAD())
	{
	fflush(stdout);
	PRINTF("\nSTART GRAPHICS? (y/n)\n");
	gets(pom);
	}
	else  *pom='y';

if(pom[0]=='y')
  {
  graphics_view();
  }

freebands();
return 0;
}
