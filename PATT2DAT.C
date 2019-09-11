/* main module for patt2dat */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <alloc.h>
#include <graphics.h>
#include <ctype.h>
#include <string.h>
#include <values.h>
#include "patt2dat.h"

extern char yytext[];
extern FILE* yyin;
extern char  datname[256];
extern char  inputname[256];
extern char  sciezka[256];
extern char  ext[10];
extern int   withStandard;
extern float epsilon;
extern FILE* inputfile;

int withStandard=0;
float epsilon=0.01;
unsigned int linenum=1;
unsigned int kommnum=0;
char*	  koment1=NULL;
char*	  koment2=NULL;
char*	  koment3=NULL;
unsigned int lanenum=0;
unsigned int bandnum=0;
lane* actual_lane=NULL;
lane lanes[MAX_lane_NUMBER];
band* pattern=NULL;
unsigned int pattnum=0;

int sort_function( const void* a, const void* b)
{
if( ((band*)a)->met == ((band*)b)->met )
	return 0;
if( ((band*)a)->met > ((band*)b)->met )
	return 1;
	else
	return -1;
}

void sortbands(band* STD,int n)
{
  qsort((void *)STD , n, sizeof( STD[0] ), sort_function);
}


int exist_band(f,a,n) double f;/* odleglosc prazka*/
		      band *a;/* array of band  */
	       unsigned int n;/* size of array */
{
int i;
for(i=0;i<n;i++)
	{
	if(a[i].met<0) continue;// skip killed bands
	if((a[i].kbz-a[i].eps<f)&&(f<a[i].kbz+a[i].eps))
		return 1;
	}
return 0;
}


void printpattern()
{
int i;
PRINTF("PATTERN:\n");
for(i=0;i<pattnum;i++)
		{
		float f=pattern[i].kbz;
		if(f!=0.0)
			PRINTF("%g,",f);
		 /*  else
			putchar('.'); */
		}
putchar('\n');
HTEST;
}

void make_pattern()
{
unsigned int i,j;
static PatSize=50;
if(pattern==NULL)/* Jesli patern nie byl jeszcze uzywany */
   {
   if(( pattern=(band*)malloc(PatSize*sizeof(band)) )==NULL) OutOfMem(1);
   }
for(i=0;i<PatSize;i++)/* Zerowanie paternu jesli nowy i jesli stary */
		{
		pattern[i].met=0.0;
		pattern[i].kbz=0.0;
		pattern[i].eps=0.0;
		}
HTEST;
pattnum=0;
for(i=0;i<MAX_lane_NUMBER;i++)
	{
	if(!(lanes[i].not_empty))
		{
		PRINTF("last not empty lane =%d\n",i-1);
		break;
		}
	if(!(lanes[i].stand)|| withStandard)
	    for(j=0;j<lanes[i].band_number;j++)
		if(!exist_band(lanes[i].bands[j].kbz,pattern,pattnum))
			{
			pattern[pattnum]=lanes[i].bands[j];
			pattnum++;
			if(PatSize-pattnum==2)
				{
				int k;
				PatSize*=2;
				if((pattern=(band*)realloc(pattern,PatSize*sizeof(band)))==NULL)
					OutOfMem(1);
					else
					{
					HTEST;
					for(k=pattnum;k<PatSize;k++)
						{
						pattern[k].met=0.0;
						pattern[k].kbz=0.0;
						pattern[k].eps=0.0;
						}
					}
				HTEST;
				}
			}
	}
sortbands(pattern,pattnum);
HTEST;
}

yywrap()
{
PRINTF("End of Data file !\n %d lines\n",linenum);
return(1);
}

yyerror(s) char* s;
{
fflush(stdout);
fprintf(stderr,"\nERROR: %s at line %d\n<< %s >>\n",s,linenum,yytext);
return 1;
}

void warning(s) char* s;
{
fflush(stdout);
fprintf(stderr,"\nWARNING: %s at line %d\n<< %s >>\n",s,linenum,yytext);
}

void dump_array()
{
unsigned int i;

PRINTF("\nARRAY:\n");
i=0;
while(lanes[i].not_empty)
		{
	PRINTF("%s ",lanes[i].label);
	PRINTF("b=%d\t",lanes[i].band_number);
		i++;
		}
putchar('\n');
}

void writedat()
{
FILE *datfile;
int i,j;
{
strcpy(datname,inputname);
for(i=strlen(datname);i>=0;i--)
	{
	if(datname[i]=='.') break;
	}
if(i>0)
      strcpy(datname+i, ext);
	else
       strcpy(datname,"output.dat");
}
PRINTF("WRITE to file %s \n",datname);

if((datfile=fopen(datname,"wt"))==NULL)
	{
	fprintf(stderr,"\nCan't open output *.dat file!\n");
	perror("->");
	getch();
	return;
	}
PTEST(datfile);
fprintf(datfile,
	"%s EPSILON=%f Approximation - %s\n%s\n%s\n"
	,koment1,epsilon,AppTypeStr[AppType],koment2,koment3);
i=0;
while(lanes[i].not_empty)
		{
	if(!(lanes[i].stand)|| withStandard)
		fprintf(datfile,"%s\n",lanes[i].label);
		i++;
		}

fprintf(datfile,"@\n");

for(i=0;i<pattnum;i++)
		{
		float f=pattern[i].kbz;
		for(j=0;j<lanenum;j++)
		  if(!(lanes[j].stand)|| withStandard)
			fprintf(datfile,"%d,",
		exist_band(f,lanes[j].bands,lanes[j].band_number)
				);
		fprintf(datfile,"b_%f,b",f);
		if(i<pattnum-1)
			fprintf(datfile,"\n");
			else
			fprintf(datfile,",@\n");
		}

fclose(datfile);
HTEST;
PRINTF("DONE: data in file %s\n",datname);
}

void print_lane(FILE* pttfile,lane *actual,int done)
{
int stand=actual->stand;
int druck=0,j;

PTEST(actual);
if(!done)
	done=actual->done;
if(actual->all_kill)
	return;

sortbands(actual->bands,actual->band_number);
HTEST;
if(stand)
	fprintf(pttfile,"Standard\n");
	else
	if(done)
		fprintf(pttfile,"DONE\n");

fprintf(pttfile,"%s:\t",actual->label);

for(j=0;j<actual->band_number;j++)
   if( actual->bands[j].met>=0 || stand )
	{
	if(druck)  putc(',',pttfile);
	if(stand)
	 fprintf(pttfile,"%f=%f",actual->bands[j].met,actual->bands[j].kbz);
	 else
	 if(done)
	    fprintf(pttfile,"%f=%f+-%f",actual->bands[j].met,actual->bands[j].kbz,actual->bands[j].eps);
	    else
	    fprintf(pttfile,"%f",actual->bands[j].met);
	druck=1;
	}
if(!druck)
	fprintf(pttfile,"0.000=0.000 {???}");
fprintf(pttfile,";\n");
}

void writepat()
{
FILE *pttfile;
int i;
strcpy(datname,inputname);
if((pttfile=fopen(datname,"wt"))==NULL)
	{
	(putchar)('\7');
	fprintf(stderr,"\n%s",datname);
	perror("- Can't open!");
	getch();
	return;
	}
PTEST(pttfile);
fprintf(pttfile,
	"{%s}\n{%s}\n{%s}\n epsilon=%f;\n"
    ,koment1,koment2,koment3,epsilon);

for(i=0;i<lanenum;i++)
		print_lane(pttfile,lanes+i,0);

fprintf(pttfile,"\n");
fclose(pttfile);
HTEST;
}

void writeptt()
{
char *ext=".ptt\0";
FILE *pttfile;
int i;

strcpy(datname,inputname);
for(i=strlen(datname);i>=0;i--)
	{
	if(datname[i]=='.') break;
	}
if(i>0)
      strcpy(datname+i, ext);
	else
      {
      gotoxy(1,1);
      printf("Warning: possible empty file !");
      strcpy(datname,"output.ptt");
      }

if((pttfile=fopen(datname,"wt"))==NULL)
	{
	restorecrtmode();
	fprintf(stderr,"\n%s",datname);
	perror("- Cant open !");
	getch();
	return;
	}

PTEST(pttfile);
fprintf(pttfile,
	"{%s}\n{%s}\n{%s}\n{ DONE FILE - APPROXIMATION %s }\nEPSILON=%f;\n"
    ,koment1,koment2,koment3,AppTypeStr[AppType],epsilon);

for(i=0;i<lanenum;i++)
		print_lane(pttfile,lanes+i,1);

fprintf(pttfile,"\n");
fclose(pttfile);
HTEST;
}

void lockbands()
{
unsigned int i;
for(i=0;i<lanenum;i++)
	lanes[i].done=1;
HTEST;
}

void freebands()
{
unsigned int i;
for(i=0;i<lanenum;i++)
	{
	free(lanes[i].bands);
	lanes[i].not_empty=0;
	lanes[i].band_number=0;
	}
lanenum=0;
inputname[0]='?';
inputname[1]='\0';

if(koment1) free(koment1);
if(koment2) free(koment2);
if(koment3) free(koment3);
kommnum=0;
koment1=NULL;
koment2=NULL;
koment3=NULL;
HTEST;
}

char* GetDescription(char* BaseName,char* Description)/* stringi minimum po 80 zmakow ! */
{
FILE* base;
base=fopen(BaseName,"rt");
if(base!=NULL)
	{/* wlasciwe dzialanie */
	char buf[81];
	buf[0]='\0';
	while( feof(base)==0)
		{
		//fscanf(base,"%80s",buf);
		fgets(buf, 80 , base);
		if(buf[0]=='/')
			{
			char* p=stpcpy(Description,buf);
			p--;/* Ostatni znaczacy znak */
			if(*p=='\n') *p='\0';
			break;
			}
		}
	}/* KONIEC */
	else
	{
	fprintf(stderr,"Can't open %s!\n",BaseName);
	strcpy(Description,"ERROR");
	return Description;
	}
fclose(base);
return Description;
}

void  MakeNewDBase(char* BaseName,char* Description)
{
FILE* base;
base=fopen(BaseName,"rt");
if(base!=NULL)
	{
	fclose(base);
	fprintf(stderr,"File %s already exists!\n",BaseName);
	return;
	}
if((base=fopen(BaseName,"wt"))==NULL)
	{
	fprintf(stderr,"Cant open %s to write!\n",BaseName);
	return;
	}
fprintf(base,"%c%s\n",(*Description!='/'?'/':'\0'),Description);
fclose(base);
}

void DeleteBand(lane* ,int);

void Packlane(lane* actual)
/* Sortowanie i pakowanie */
{
int i;
float pom;

sortbands(actual->bands,actual->band_number);

HTEST;
pom=-1.0;
for(i=0;i<actual->band_number;i++)
	if(actual->bands[i].met!=pom)
		pom=actual->bands[i].met;
		else
		{
		DeleteBand(actual,i);/* Zmiejsza band_number */
		i--;/* Trzeba wrocic i sprawdzic bo sie przesunelo */
		}
}

void  laneToDBase(char* BaseName,int l)
{
FILE* base=NULL;
lane* actual=NULL;
int i;
float pom;

HTEST;
if(l<0 || l>=lanenum)
	{
	fprintf(stderr,"Invalid lane number  %d!",l);
	return;
	}
actual=lanes+l;
Packlane(actual);

if((base=fopen(BaseName,"rt"))==NULL)
	{
	fprintf(stderr,"Cant open %s !\n",BaseName);
	return;
	}
	else fclose(base);
if((base=fopen(BaseName,"at"))==NULL)
	{
	fprintf(stderr,"Cant open %s to append!\n",BaseName);
	return;
	}



HTEST;
fprintf(base,"%s:\t",actual->label);
for(i=0;i<actual->band_number;i++)
		fprintf(base,"%g%c",actual->bands[i].kbz,(i!=actual->band_number-1)?',':';');
fprintf(base,"\n");
fclose(base);
HTEST;
}

/* Funkcje i typy pomocnicze dla przeszukiwania bazy */
typedef
struct {int tr;
	char naz[20];
	} traw;
int PominKomentarz(FILE* );/* Pomijanie komentarzy */
void WstawJesliLepsza(traw* ,int ,char *,int );
int SprawdzajTrafienia(FILE* ,lane* ,int* ,int* );
int CzytajNazwe(FILE* ,int ,char* ) ;

void  Searchlane(char*  BaseName,int l)
{
#define WAZNE 10
traw TR[WAZNE];	/* Nazwy najleprzych znalezionych trawien */
		/* i ilosci trafien w trawieniach */
char ACT_NAZ[40]; /* aktualnie obrabiany  */
int  ACT_TR;	  /* i jego ilosc trafien */

FILE* base=NULL;
lane* actual=NULL;
int i,licznik_lini=1,licznik_tr=0,c;

HTEST;
if(l<0 || l>=lanenum)
	{
	fprintf(stderr,"Invalid lane number  %d!",l);
	return;
	}
*ACT_NAZ='\0';	 /* aktualnie obrabiany  */
  ACT_TR=0;	 /* i jego ilosc trafien */
memset(TR,0,sizeof(TR));	/* inicjalizacja */
actual=lanes+l;

Packlane(actual);
if((base=fopen(BaseName,"rt"))==NULL)
	{
	fprintf(stderr,"Can't open %s!\n",BaseName);
	return;
	}
	else printf("Searching \"%s\" in file \"%s\"\n",actual->label,BaseName);
while((c=getc(base))!=EOF)
	{
	switch(c){
	case '/' :if(PominKomentarz(base))
			{
			fprintf(stderr,"Syntax error at line %d \n",c,licznik_lini);
			goto RET;
			}
		  break;/* Pomijanie komentarzy */
	case ' ' :
	case '\t':break;		     /* Pomijanie spacji i tabulacji */
	case '\n':licznik_lini++;break;	     /* Zliczanie lini */
	case ';' :if(*ACT_NAZ!='\0')
			{
			WstawJesliLepsza(TR,WAZNE,ACT_NAZ,ACT_TR);
			licznik_tr++;
			*ACT_NAZ='\0';
			 ACT_TR=0;
			}
		  break;		       /* Wstawianie do TR jesli lepsza i zliczanie trawien */
	case ':' :if(SprawdzajTrafienia(base,actual,&ACT_TR,&licznik_lini))/* czytanie listy wartosci */
				{			    /* i porownywanie */
				fprintf(stderr,"Invalid value at line %d\n",licznik_lini);
				goto RET;
				}
		  break;
	default:
		if((isalpha(c)) || c=='_')
			{
			ungetc(c,base);
			if(CzytajNazwe(base,40,ACT_NAZ))
				{
				fprintf(stderr,"Too long name at line %d\n",licznik_lini);
				goto RET;
				}
			DELLINE;
			printf("[%4d]",licznik_lini);
			}
			else
			{
			fprintf(stderr,"Syntax error -char <%c> at line %d \n",c,licznik_lini);
			goto RET;
			}
		}
	}
goto O_K;
RET:
fprintf(stderr,"Current record: %-20s",ACT_NAZ);
O_K:
DELLINE;
fclose(base);
printf("Tested %d lines and %d records :\n",licznik_lini,licznik_tr);
fprintf(stderr,"SORTING");/* Sortowanie niezbyt efektywne ale tu wystarczy */
for(i=0;i<WAZNE;i++)
   {
   int j;traw pomtr;
   for(j=0;j<(WAZNE-1);j++)
	 if(TR[j].tr<TR[j+1].tr)
		{pomtr=TR[j];TR[j]=TR[j+1];TR[j+1]=pomtr;}
   }
DELLINE;
for(i=0;i<WAZNE;i++)
	if(TR[i].tr>0)
		printf("%3d  band(s) in  %s\n",TR[i].tr,TR[i].naz);
HTEST;
}

int PominKomentarz(FILE* base)/* Pomijanie komentarzy */
{
int c;
while((c=getc(base))!='\n'&& c!=EOF)
	;
ungetc(c,base);
return 0;/* bez bledow */
}

void WstawJesliLepsza(traw* T,int STW,char *ACT_NAZ,int ACT_TR)
{
/*
typedef
struct {int tr;
	char naz[20];
	} traw;*/
int i,p=-1,min=MAXINT;
for(i=0;i<STW;i++)
	if(min>T[i].tr)
		{
		min=T[i].tr;
		p=i;
		}
if(min<=ACT_TR)
	{
	T[p].tr=ACT_TR;
	strncpy(T[p].naz,ACT_NAZ,20);
	}
}

int SprawdzajTrafienia(FILE* base,lane* actual,int* TR,int* licz_lin)/* czytanie listy wartosci */
{
#define SIZ 20
char Tab[SIZ],*endptr;
int c,i=0;
float pom=MAXDOUBLE,pom1=0;

do{
while((c=getc(base))!=EOF && c!=',' && c!=';')
	switch(c){
	case '\n': (*licz_lin)++;break;/* przejscie do nowej lini */
	case ' ' :
	case '\r':
	case '\t':break ;/* skipped */
	default:
		 {
		 Tab[i]=c;
		 i++;
		 if(i>=SIZ) { fprintf(stderr,"Too long - ");return 1;}
		 }
	}
Tab[i]='\0';
pom1 = strtod( Tab , &endptr );
if(*endptr!='\0') return 1;/* Invalid format */
*Tab ='\0';i=0;
if(pom1>=pom)
	fprintf(stderr,"Warning: Value not less - skipped !\n");
	else
	{
	/* Testowanie wartosci pom */
	int i;
	pom=pom1;
	for(i=0;i<actual->band_number;i++)
	if(actual->bands[i].kbz-actual->bands[i].eps<=pom1 )
	    {
	    if(actual->bands[i].kbz+actual->bands[i].eps>=pom1 )
		{
		(*TR)++;/* powiekszyc zawartosc */
		break;
		}
		else break;
	     }
	}
if(c==';') break;
}while(1);
RET:
ungetc(c,base);
return 0;
}

int CzytajNazwe(FILE* base,int Siz,char* ACT_NAZ)
{
int c,i=0;
while((c=getc(base))!=':'&& c!=EOF)
	{
	ACT_NAZ[i]=c;
	i++;
	if(i>=Siz) return 1;
	}
ACT_NAZ[i]='\0';
ungetc(c,base);
return 0;/* bez bledow */
}