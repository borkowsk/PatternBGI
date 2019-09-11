# include "stdio.h"
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX BUFSIZ
# define output(c) putc(c,yyout)
# define input()   (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c)  {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore()  (yymorfg=1)
# define ECHO      fprintf(yyout, "%s",yytext)
# define REJECT    { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern char *yysptr, yysbuf[];
int yytchar;
FILE *yyin = {stdin}, *yyout = {stdout};
extern int yylineno;
struct yysvf {
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;
#include <stdlib.h>
#include <string.h>

#ifdef unix
#include "y.tab.h"
#else
#include "y~tab~ua.h"
#endif

#include "patt2dat.h"
#undef ECHO
#define ECHO
# define YYNEWLINE 10

yylex(){ /* LEXICAL ANALIZER */
int nstr; extern int yyprevious;
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:
{ yydebug=1;
		}
break;
case 2:
{ yydebug=0;
		}
break;
case 3:
	{       yytext[0]=' ';
			yytext[yyleng-1]=' ';

			switch(kommnum){
			case 0:
				{
			koment1=(char*)calloc
			(yyleng+1,sizeof(char));
			strcpy(koment1,yytext);
				}break;
			case 1:
				{
			koment2=(char*)calloc
			(yyleng+1,sizeof(char));
			strcpy(koment2,yytext);
				}break;

			case 2:
				{
			koment3=(char*)calloc
			(yyleng+1,sizeof(char));
			strcpy(koment3,yytext);
				}break;

			}
			kommnum++;
			}
break;
case 4:
	case 5:
{
			ECHO;
			yylval.flo=atof(yytext);
			return(CONST);
			}
break;
case 6:
case 7:
case 8:
{
			ECHO;
			return(STANDART);
			}
break;
case 9:
case 10:
case 11:
{
			ECHO;
			return(EPSILON);
		}
break;
case 12:
case 13:
	case 14:
	{
			ECHO;
			return(DONE);
		}
break;
case 15:
{
			ECHO;
		if((yylval.str=(char*)calloc(yyleng+1,sizeof(char)))==NULL)
			{perror("OUT OF MEMORY");exit(1);}
			strncpy(yylval.str,yytext,yyleng+1);
			return(LABEL);
			}
break;
case 16:
	{
			linenum++;
			ECHO;
			}
break;
case 17:
	case 18:
	{
			}
break;
case 19:
	case 20:
	case 21:
	case 22:
	case 23:
	case 24:
	{
			ECHO;
			return(*yytext);
			}
break;
case 25:
	{ 
		ECHO;
		return(ILLEGAL);
		}
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */
int yyvstop[] = {
0,

25,
0,

17,
25,
0,

16,
0,

18,
25,
0,

19,
25,
0,

22,
25,
0,

23,
25,
0,

4,
25,
0,

21,
25,
0,

20,
25,
0,

24,
25,
0,

15,
25,
0,

15,
25,
0,

15,
25,
0,

15,
25,
0,

15,
25,
0,

15,
25,
0,

15,
25,
0,

25,
0,

4,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

3,
0,

5,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

12,
15,
0,

14,
15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

13,
15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

15,
0,

9,
15,
0,

11,
15,
0,

15,
0,

15,
0,

10,
15,
0,

15,
0,

6,
15,
0,

8,
15,
0,

7,
15,
0,

1,
3,
0,

2,
3,
0,
0};
# define YYTYPE char
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,4,	1,5,	
0,0,	0,0,	0,0,	2,4,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	1,6,	0,0,	0,0,	
0,0,	0,0,	2,6,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	1,7,	1,8,	1,3,	
1,9,	1,10,	2,7,	2,8,	
0,0,	2,9,	0,0,	0,0,	
0,0,	0,0,	0,0,	1,11,	
1,12,	0,0,	1,13,	35,0,	
2,11,	2,12,	1,14,	2,13,	
0,0,	1,15,	1,16,	0,0,	
0,0,	0,0,	2,15,	2,16,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
1,17,	0,0,	0,0,	0,0,	
10,22,	2,17,	10,23,	10,23,	
10,23,	10,23,	10,23,	10,23,	
10,23,	10,23,	10,23,	10,23,	
25,38,	1,18,	1,19,	27,40,	
0,0,	0,0,	2,18,	2,19,	
15,25,	16,27,	17,29,	29,42,	
36,0,	0,0,	0,0,	0,0,	
1,20,	0,0,	0,0,	0,0,	
0,0,	2,20,	35,47,	0,0,	
1,21,	0,0,	0,0,	18,31,	
14,24,	2,21,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
15,26,	16,28,	17,30,	19,32,	
20,33,	26,39,	28,41,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	30,43,	31,44,	32,45,	
33,46,	14,24,	35,36,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	14,24,	14,24,	14,24,	
14,24,	21,34,	38,48,	39,49,	
40,50,	41,51,	42,52,	43,53,	
44,54,	45,55,	21,0,	22,37,	
22,37,	22,37,	22,37,	22,37,	
22,37,	22,37,	22,37,	22,37,	
22,37,	46,56,	34,34,	36,36,	
47,0,	50,58,	51,59,	52,60,	
53,61,	55,62,	56,63,	34,0,	
57,0,	58,65,	59,66,	60,67,	
61,68,	62,69,	63,70,	64,0,	
65,72,	66,73,	67,74,	68,75,	
69,76,	70,77,	21,34,	74,79,	
21,34,	71,0,	75,80,	77,81,	
78,0,	83,0,	82,0,	84,0,	
85,0,	86,0,	87,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	21,34,	0,0,	34,34,	
21,35,	34,34,	0,0,	71,78,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
47,57,	0,0,	0,0,	0,0,	
0,0,	0,0,	34,34,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
64,71,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	57,64,	
0,0,	0,0,	0,0,	0,0,	
0,0,	83,85,	82,83,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	78,82,	82,84,	0,0,	
0,0,	21,36,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	47,36,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	34,36,	57,36,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	64,36,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
71,36,	0,0,	0,0,	78,36,	
83,36,	82,36,	84,86,	85,87,	
86,36,	87,36,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
yycrank+-1,	0,		0,	
yycrank+-6,	yysvec+1,	0,	
yycrank+0,	0,		yyvstop+1,
yycrank+0,	0,		yyvstop+3,
yycrank+0,	0,		yyvstop+6,
yycrank+0,	0,		yyvstop+8,
yycrank+0,	0,		yyvstop+11,
yycrank+0,	0,		yyvstop+14,
yycrank+0,	0,		yyvstop+17,
yycrank+42,	0,		yyvstop+20,
yycrank+0,	0,		yyvstop+23,
yycrank+0,	0,		yyvstop+26,
yycrank+0,	0,		yyvstop+29,
yycrank+82,	0,		yyvstop+32,
yycrank+29,	yysvec+14,	yyvstop+35,
yycrank+29,	yysvec+14,	yyvstop+38,
yycrank+26,	yysvec+14,	yyvstop+41,
yycrank+16,	yysvec+14,	yyvstop+44,
yycrank+31,	yysvec+14,	yyvstop+47,
yycrank+28,	yysvec+14,	yyvstop+50,
yycrank+-204,	0,		yyvstop+53,
yycrank+167,	0,		0,	
yycrank+0,	yysvec+10,	yyvstop+55,
yycrank+0,	yysvec+14,	yyvstop+57,
yycrank+22,	yysvec+14,	yyvstop+59,
yycrank+35,	yysvec+14,	yyvstop+61,
yycrank+20,	yysvec+14,	yyvstop+63,
yycrank+31,	yysvec+14,	yyvstop+65,
yycrank+46,	yysvec+14,	yyvstop+67,
yycrank+76,	yysvec+14,	yyvstop+69,
yycrank+64,	yysvec+14,	yyvstop+71,
yycrank+60,	yysvec+14,	yyvstop+73,
yycrank+79,	yysvec+14,	yyvstop+75,
yycrank+-225,	0,		0,	
yycrank+-53,	yysvec+34,	0,	
yycrank+-102,	yysvec+34,	yyvstop+77,
yycrank+0,	yysvec+22,	yyvstop+79,
yycrank+137,	yysvec+14,	yyvstop+81,
yycrank+106,	yysvec+14,	yyvstop+83,
yycrank+135,	yysvec+14,	yyvstop+85,
yycrank+104,	yysvec+14,	yyvstop+87,
yycrank+132,	yysvec+14,	yyvstop+89,
yycrank+101,	yysvec+14,	yyvstop+91,
yycrank+111,	yysvec+14,	yyvstop+93,
yycrank+108,	yysvec+14,	yyvstop+95,
yycrank+115,	yysvec+14,	yyvstop+97,
yycrank+-218,	yysvec+34,	0,	
yycrank+0,	yysvec+14,	yyvstop+99,
yycrank+0,	yysvec+14,	yyvstop+102,
yycrank+153,	yysvec+14,	yyvstop+105,
yycrank+122,	yysvec+14,	yyvstop+107,
yycrank+163,	yysvec+14,	yyvstop+109,
yycrank+132,	yysvec+14,	yyvstop+111,
yycrank+0,	yysvec+14,	yyvstop+113,
yycrank+125,	yysvec+14,	yyvstop+116,
yycrank+134,	yysvec+14,	yyvstop+118,
yycrank+-226,	yysvec+34,	0,	
yycrank+158,	yysvec+14,	yyvstop+120,
yycrank+127,	yysvec+14,	yyvstop+122,
yycrank+174,	yysvec+14,	yyvstop+124,
yycrank+143,	yysvec+14,	yyvstop+126,
yycrank+130,	yysvec+14,	yyvstop+128,
yycrank+145,	yysvec+14,	yyvstop+130,
yycrank+-233,	yysvec+34,	0,	
yycrank+166,	yysvec+14,	yyvstop+132,
yycrank+135,	yysvec+14,	yyvstop+134,
yycrank+164,	yysvec+14,	yyvstop+136,
yycrank+133,	yysvec+14,	yyvstop+138,
yycrank+138,	yysvec+14,	yyvstop+140,
yycrank+135,	yysvec+14,	yyvstop+142,
yycrank+-243,	yysvec+34,	0,	
yycrank+0,	yysvec+14,	yyvstop+144,
yycrank+0,	yysvec+14,	yyvstop+147,
yycrank+167,	yysvec+14,	yyvstop+150,
yycrank+138,	yysvec+14,	yyvstop+152,
yycrank+0,	yysvec+14,	yyvstop+154,
yycrank+139,	yysvec+14,	yyvstop+157,
yycrank+-246,	yysvec+34,	0,	
yycrank+0,	yysvec+14,	yyvstop+159,
yycrank+0,	yysvec+14,	yyvstop+162,
yycrank+0,	yysvec+14,	yyvstop+165,
yycrank+-248,	yysvec+34,	0,	
yycrank+-247,	yysvec+34,	0,	
yycrank+-249,	yysvec+34,	0,	
yycrank+-250,	yysvec+34,	0,	
yycrank+-251,	yysvec+34,	yyvstop+168,
yycrank+-252,	yysvec+34,	yyvstop+171,
0,	0,	0};
struct yywork *yytop = yycrank+377;
struct yysvf *yybgin = yysvec+1;
char yymatch[] = {
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,'.' ,01  ,
'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,
'0' ,'0' ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,01  ,01  ,01  ,01  ,'A' ,
01  ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,01  ,01  ,01  ,01  ,01  ,
0};
char yyextra[] = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
#ifndef lint
static	char ncform_sccsid[] = "@(#)ncform 1.6 88/02/08 SMI"; /* from S5R2 1.2 */
#endif

int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
char yysbuf[YYLMAX];
char *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
yylook(){
	register struct yysvf *yystate, **lsp;
	register struct yywork *yyt;
	struct yysvf *yyz;
	int yych, yyfirst;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	char *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	yyfirst=1;
	if (!yymorfg)
		yylastch = yytext;
	else {
		yymorfg=0;
		yylastch = yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank && !yyfirst){  /* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
			*yylastch++ = yych = input();
			yyfirst=0;
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if ( (int)yyt > (int)yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if((int)yyt < (int)yycrank) {		/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
					sprint(yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = yytext[0] = input();
		if (yyprevious>0)
			output(yyprevious);
		yylastch=yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}
yyback(p, m)
	int *p;
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
yyinput(){
	return(input());
	}
yyoutput(c)
  int c; {
	output(c);
	return 1;
	}
yyunput(c)
   int c; {
	unput(c);
	return 1;
	}
