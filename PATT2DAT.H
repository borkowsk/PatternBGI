/* Globalne   deklaracje  dla   programu   patt2dat */
/*==================================================*/
#ifdef DEMO
#define MAX_lane_NUMBER	20
#define MAX_BANDS_NUMBER 20
#else
#define MAX_lane_NUMBER	200
#define MAX_BANDS_NUMBER 200
#endif


typedef struct
	{
	float met,kbz,eps;/* odleglosc od punktu startu , rozmiar i blad*/
	} band;

typedef struct
	{
	band  *bands;		 /* tablica prazkow */
	char *label;		 /* nazwa lejnu */
	unsigned int band_number;/* liczba prazkow */
	unsigned int arr_size;	 /* rozmiar tablicy */
	unsigned int not_empty:1;/* flaga wypelnienia - nieuzywana ?*/
	unsigned int all_kill :1;/* flaga skasowania */
	unsigned int     fresh:1;/* lane nieaproxymowany */
	unsigned int     stand:1;/* lane Standardu */
	unsigned int      done:1;/* lane wczytany juz z kalibracja */
	} lane;

typedef enum
       {
       NullType=0,
       HippType,
       StandType,
       PolyType,
       PoLnType,
       PoLogType,
       ManuType,
       ErrorType
       } AppEnum;

/* DECLARATIONS of FUNCTIONS */
int yylook();
int yywrap();
int yyparse();
int yylex();
void dump_array();
void make_pattern();
void printpattern();
void graphics_view();
void SwitchApproxymation();
void writedat();
void writeptt();
void freebands();
int exist_band();
void  makeApproxymation();


#ifdef unix
int yyback();
int yyerror();
void warning();
void sortbands();
/*
void DummyGenApprox();
void HiperGenApprox();
void StandardGenApprox();
void GramGenApprox();
void GramLnGenApprox();
void GramLog10GenApprox();
float HiperApproxymation();
float NullApproxymation();
float StandardApproxymation();
float GramApproxymation();
float GramLnApproxymation();
float GramLog10Approxymation();
*/
extern float (*Approxymation)();
extern void  (*genApproxymation)();
extern void  (*OutOfMem)();
#else
int yyback(int *p,int m);
int yyerror(char *s);
void warning(char *s);
void view(int WithSize , int stand, int bands , int patt );
void sortbands(band*,int );
/*
void DummyGenApprox(band*,int );
void HiperGenApprox(band*,int );
void StandardGenApprox(band*,int );
void GramGenApprox(band*,int );
void GramLnGenApprox(band*,int );
void GramLog10GenApprox(band*,int );
void ManualGenApprox(band*,int );
float HiperApproxymation(float );
float NullApproxymation(float );
float StandardApproxymation(float );
float GramApproxymation(float );
float GramLnApproxymation(float );
float GramLog10Approxymation(float );
*/
extern float (*Approxymation)(float);
extern void  (*genApproxymation)(band*,int);
extern void  (*OutOfMem)(int);
#endif
/* Makra przykrywajace wywolania starych funkcji view */
#define viewsize()    view(0 , stand, bands ,  patt )
#define lnview()      view(1 , stand, donebands , patt )
/* GLOBAL USE VARIABLES */
extern unsigned int linenum;
extern unsigned int kommnum;
extern 		int yydebug;
extern char* 	    koment1;
extern char*	    koment2;
extern char*	    koment3;
extern float 	    epsilon;
extern float	 epsilonapr;
extern unsigned int lanenum;
extern unsigned int bandnum;
extern lane* 	actual_lane;
extern lane 	    lanes[];
extern AppEnum 	    AppType;
extern char*   AppTypeStr[];
extern int 	  Transform;

/* USEABLE MACROS */
#ifdef unix

#define NEWTEXTPAGE putchar('\p');
#define DELLINE     putchar('\r');
#define PENTER	"(press RETURN)"
#define PAUSE	   { fprintf(stderr,PENTER);gets(); }

#else

#define PRINTF      printf
#define NEWTEXTPAGE gotoxy(1,1)
#define DELLINE    {gotoxy(1,wherey());}
#define PENTER	"(press <ͼ)"
#define PAUSE	   {PRINTF(PENTER);getch(); }

#endif

#ifdef DEBUG
#define HTEST if(heapcheck()<0) {fprintf(stderr," Fatal: Heap corrupted! %s ,%d\n",__FILE__,__LINE__);abort(); }
#define PTEST(_P_) if((_P_)==NULL) {fprintf(stderr," Fatal: NULL USE! %s ,%d\n",__FILE__,__LINE__);abort(); }
#else
#define HTEST
#define PTEST
#endif

/* Nakrycie funkcji z biblioteki GRAPH */
void RestoreCrtMode();
void SetGraphMode(int M);
#define restorecrtmode RestoreCrtMode
#define setgraphmode   SetGraphMode