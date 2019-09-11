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
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
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
#include "yparse.h"
#endif 

#include "patt2dat.h"
#undef ECHO
#define ECHO
# define YYNEWLINE 10
yylex(){
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
			return(PRECISION);
			}
break;
case 9:
case 10:
case 11:
{
			ECHO;
			return(APPROXYMATION);
			}
break;
case 12:
case 13:
	case 14:
	{
			ECHO;
			return(NO);
			}
break;
case 15:
case 16:
	case 17:
	{
			ECHO;
			return(HIPER);
		}
break;
case 18:
case 19:
	case 20:
	{
			ECHO;
			return(LOGN);
			}
break;
case 21:
case 23:
	case 24:
	{
			ECHO;
			return(LOGN);
			}
break;
case 25:
case 26:
	case 27:
	{
			ECHO;
			return(LOGN);
			}
break;
case 28:
case 29:
case 30:
{
			ECHO;
			return(EPSILON);
		}
break;
case 31:
case 32:
	case 33:
	{
			ECHO;
			return(DONE);
		}
break;
case 34:
{
			ECHO;
		yylval.str=(char*)calloc(yyleng,sizeof(char));
			strncpy(yylval.str,yytext,yyleng);
			return(LABEL);
			}
break;
case 35:
	{
			linenum++;
			ECHO;
			}
break;
case 36:
	case 37:
	{
			}
break;
case 38:
	case 39:
	case 40:
	case 41:
	case 42:
	case 43:
	case 44:
	case 45:
	{
			ECHO;
			return(*yytext);
			}
break;
case 46:
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

46,
0,

36,
46,
0,

35,
0,

37,
46,
0,

43,
46,
0,

38,
46,
0,

41,
44,
46,
0,

42,
46,
0,

4,
46,
0,

40,
46,
0,

39,
46,
0,

45,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

34,
46,
0,

46,
0,

4,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

13,
34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

14,
34,
0,

34,
0,

3,
0,

5,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

31,
34,
0,

33,
34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

23,
34,
0,

19,
34,
0,

34,
0,

34,
0,

34,
0,

32,
34,
0,

34,
0,

34,
0,

34,
0,

24,
34,
0,

20,
34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

15,
34,
0,

16,
34,
0,

26,
34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

17,
34,
0,

27,
34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

28,
34,
0,

30,
34,
0,

34,
0,

34,
0,

34,
0,

29,
34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

34,
0,

6,
34,
0,

7,
34,
0,

34,
0,

8,
34,
0,

34,
0,

34,
0,

1,
3,
0,

34,
0,

34,
0,

2,
3,
0,

34,
0,

34,
0,

10,
34,
0,

11,
34,
0,
0};
# define YYTYPE int
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,4,	1,5,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	55,0,	
119,0,	0,0,	141,0,	144,0,	
0,0,	1,6,	0,0,	54,0,	
74,0,	145,0,	148,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
1,7,	1,8,	1,9,	1,3,	
1,10,	1,11,	119,128,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	1,12,	
1,13,	0,0,	1,14,	0,0,	
0,0,	0,0,	1,15,	1,16,	
1,16,	1,17,	1,18,	1,16,	
1,16,	1,19,	1,16,	1,16,	
1,16,	1,20,	1,16,	1,21,	
1,16,	1,22,	1,16,	1,16,	
1,16,	1,16,	1,16,	1,16,	
1,16,	1,16,	1,16,	1,16,	
74,96,	0,0,	54,74,	16,33,	
1,16,	110,0,	1,23,	1,16,	
1,16,	1,24,	1,25,	1,16,	
1,16,	1,26,	1,16,	1,16,	
1,16,	1,27,	1,16,	1,28,	
1,16,	1,29,	1,16,	1,16,	
1,16,	1,16,	1,16,	1,16,	
1,16,	1,16,	1,16,	1,16,	
1,30,	2,4,	11,31,	16,33,	
11,32,	11,32,	11,32,	11,32,	
11,32,	11,32,	11,32,	11,32,	
11,32,	11,32,	17,36,	17,33,	
18,38,	23,33,	55,55,	119,55,	
21,43,	141,145,	144,148,	20,33,	
2,6,	24,33,	54,55,	74,55,	
145,55,	148,55,	0,0,	0,0,	
0,0,	0,0,	110,119,	2,7,	
2,8,	2,9,	0,0,	2,10,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	17,37,	17,33,	
18,39,	23,46,	2,12,	2,13,	
21,33,	2,14,	20,42,	20,33,	
24,47,	24,33,	2,16,	2,16,	
2,17,	2,18,	2,16,	2,16,	
2,19,	2,16,	2,16,	2,16,	
2,20,	2,16,	2,21,	2,16,	
2,22,	2,16,	2,16,	2,16,	
2,16,	2,16,	2,16,	2,16,	
2,16,	2,16,	2,16,	0,0,	
21,33,	25,33,	0,0,	2,16,	
110,55,	2,23,	2,16,	2,16,	
2,24,	2,25,	2,16,	2,16,	
2,26,	2,16,	2,16,	2,16,	
2,27,	2,16,	2,28,	2,16,	
2,29,	2,16,	2,16,	2,16,	
2,16,	2,16,	2,16,	2,16,	
2,16,	2,16,	2,16,	2,30,	
15,33,	25,48,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
0,0,	22,33,	33,33,	22,44,	
0,0,	0,0,	0,0,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,34,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	22,33,	33,33,	22,45,	
27,33,	15,33,	28,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,35,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	15,33,	15,33,	15,33,	
15,33,	19,40,	26,33,	27,50,	
27,33,	28,51,	28,33,	29,33,	
19,33,	30,53,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	30,0,	0,0,	
34,57,	35,33,	0,0,	36,59,	
0,0,	36,33,	0,0,	26,49,	
37,33,	38,33,	39,33,	40,63,	
38,61,	19,41,	26,33,	41,33,	
42,33,	43,33,	46,33,	29,33,	
19,33,	29,52,	31,56,	31,56,	
31,56,	31,56,	31,56,	31,56,	
31,56,	31,56,	31,56,	31,56,	
34,33,	35,58,	30,53,	44,66,	
30,53,	36,33,	37,60,	42,65,	
37,33,	38,33,	39,33,	40,33,	
45,33,	39,62,	44,33,	41,64,	
42,33,	43,33,	46,68,	47,33,	
48,33,	30,53,	49,33,	53,53,	
30,54,	50,33,	51,33,	0,0,	
57,33,	52,33,	57,75,	58,33,	
53,0,	45,67,	59,77,	60,33,	
61,79,	62,33,	0,0,	0,0,	
65,83,	65,84,	63,81,	61,33,	
45,33,	59,33,	44,33,	0,0,	
50,72,	47,69,	52,73,	47,33,	
48,33,	63,33,	49,71,	48,70,	
60,78,	50,33,	51,33,	64,33,	
57,33,	52,33,	62,80,	58,33,	
67,33,	58,76,	66,86,	60,33,	
53,53,	62,33,	53,53,	65,33,	
68,33,	69,33,	0,0,	61,33,	
71,33,	59,33,	75,33,	66,33,	
64,82,	30,55,	70,33,	67,87,	
76,33,	63,33,	77,33,	53,53,	
72,92,	72,93,	73,33,	64,33,	
78,33,	80,33,	69,89,	79,98,	
67,33,	71,91,	81,33,	79,33,	
81,100,	65,85,	82,33,	65,33,	
68,33,	69,33,	68,88,	70,90,	
71,33,	73,95,	75,33,	66,33,	
83,102,	84,33,	70,33,	76,97,	
76,33,	96,0,	77,33,	72,33,	
85,33,	80,99,	73,33,	87,33,	
78,33,	80,33,	86,103,	88,33,	
89,33,	90,33,	81,33,	79,33,	
91,33,	86,33,	82,33,	92,108,	
82,101,	93,33,	94,33,	97,33,	
98,112,	98,33,	100,33,	95,33,	
83,33,	84,33,	99,33,	53,55,	
87,104,	72,94,	101,33,	72,33,	
85,33,	102,33,	104,33,	87,33,	
105,33,	90,106,	88,105,	88,33,	
89,33,	90,33,	106,33,	107,33,	
91,33,	86,33,	91,107,	92,33,	
95,109,	93,33,	94,33,	97,33,	
108,33,	98,33,	100,33,	95,33,	
83,33,	99,113,	99,33,	97,111,	
103,33,	109,33,	101,33,	103,114,	
114,123,	102,33,	104,33,	111,33,	
105,33,	104,115,	113,33,	114,33,	
96,110,	106,117,	106,33,	107,33,	
105,116,	116,33,	120,33,	92,33,	
112,121,	115,33,	112,33,	128,0,	
108,33,	117,33,	134,0,	121,33,	
122,33,	123,130,	123,33,	118,33,	
103,33,	109,33,	124,33,	125,33,	
109,118,	126,33,	140,0,	111,33,	
113,122,	127,33,	113,33,	114,33,	
129,33,	131,33,	115,124,	120,129,	
111,120,	116,33,	120,33,	133,33,	
96,55,	115,33,	112,33,	117,126,	
118,127,	117,33,	116,125,	121,33,	
122,33,	129,135,	123,33,	118,33,	
125,132,	124,131,	124,33,	125,33,	
130,136,	126,33,	130,33,	132,33,	
127,133,	127,33,	135,33,	131,137,	
129,33,	131,33,	0,0,	136,33,	
137,33,	133,139,	138,33,	133,33,	
139,33,	0,0,	134,140,	149,33,	
132,138,	0,0,	142,33,	150,33,	
128,134,	146,33,	134,141,	143,33,	
0,0,	147,33,	140,144,	151,33,	
152,33,	0,0,	130,33,	132,33,	
0,0,	0,0,	135,33,	0,0,	
0,0,	0,0,	135,142,	136,33,	
137,33,	0,0,	138,33,	142,146,	
139,33,	149,151,	138,143,	149,33,	
143,147,	150,152,	142,33,	150,33,	
146,149,	146,33,	0,0,	143,33,	
147,150,	147,33,	0,0,	151,33,	
152,33,	0,0,	0,0,	0,0,	
0,0,	0,0,	128,55,	0,0,	
0,0,	134,55,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	140,55,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
yycrank+-1,	0,		0,	
yycrank+-116,	yysvec+1,	0,	
yycrank+0,	0,		yyvstop+1,
yycrank+0,	0,		yyvstop+3,
yycrank+0,	0,		yyvstop+6,
yycrank+0,	0,		yyvstop+8,
yycrank+0,	0,		yyvstop+11,
yycrank+0,	0,		yyvstop+14,
yycrank+0,	0,		yyvstop+17,
yycrank+0,	0,		yyvstop+21,
yycrank+80,	0,		yyvstop+24,
yycrank+0,	0,		yyvstop+27,
yycrank+0,	0,		yyvstop+30,
yycrank+0,	0,		yyvstop+33,
yycrank+194,	0,		yyvstop+36,
yycrank+15,	yysvec+15,	yyvstop+39,
yycrank+59,	yysvec+15,	yyvstop+42,
yycrank+60,	yysvec+15,	yyvstop+45,
yycrank+244,	yysvec+15,	yyvstop+48,
yycrank+67,	yysvec+15,	yyvstop+51,
yycrank+96,	yysvec+15,	yyvstop+54,
yycrank+173,	yysvec+15,	yyvstop+57,
yycrank+61,	yysvec+15,	yyvstop+60,
yycrank+69,	yysvec+15,	yyvstop+63,
yycrank+129,	yysvec+15,	yyvstop+66,
yycrank+238,	yysvec+15,	yyvstop+69,
yycrank+208,	yysvec+15,	yyvstop+72,
yycrank+210,	yysvec+15,	yyvstop+75,
yycrank+243,	yysvec+15,	yyvstop+78,
yycrank+-324,	0,		yyvstop+81,
yycrank+310,	0,		0,	
yycrank+0,	yysvec+11,	yyvstop+83,
yycrank+174,	yysvec+15,	yyvstop+85,
yycrank+256,	yysvec+15,	yyvstop+87,
yycrank+257,	yysvec+15,	yyvstop+89,
yycrank+261,	yysvec+15,	yyvstop+91,
yycrank+264,	yysvec+15,	yyvstop+93,
yycrank+265,	yysvec+15,	yyvstop+95,
yycrank+266,	yysvec+15,	yyvstop+97,
yycrank+267,	yysvec+15,	yyvstop+99,
yycrank+271,	yysvec+15,	yyvstop+101,
yycrank+272,	yysvec+15,	yyvstop+103,
yycrank+273,	yysvec+15,	yyvstop+105,
yycrank+302,	yysvec+15,	yyvstop+108,
yycrank+300,	yysvec+15,	yyvstop+110,
yycrank+274,	yysvec+15,	yyvstop+112,
yycrank+307,	yysvec+15,	yyvstop+114,
yycrank+308,	yysvec+15,	yyvstop+116,
yycrank+310,	yysvec+15,	yyvstop+118,
yycrank+313,	yysvec+15,	yyvstop+120,
yycrank+314,	yysvec+15,	yyvstop+122,
yycrank+317,	yysvec+15,	yyvstop+125,
yycrank+-390,	0,		0,	
yycrank+-25,	yysvec+53,	0,	
yycrank+-17,	yysvec+53,	yyvstop+127,
yycrank+0,	yysvec+31,	yyvstop+129,
yycrank+316,	yysvec+15,	yyvstop+131,
yycrank+319,	yysvec+15,	yyvstop+133,
yycrank+333,	yysvec+15,	yyvstop+135,
yycrank+323,	yysvec+15,	yyvstop+137,
yycrank+331,	yysvec+15,	yyvstop+139,
yycrank+325,	yysvec+15,	yyvstop+141,
yycrank+341,	yysvec+15,	yyvstop+143,
yycrank+347,	yysvec+15,	yyvstop+145,
yycrank+359,	yysvec+15,	yyvstop+147,
yycrank+367,	yysvec+15,	yyvstop+149,
yycrank+352,	yysvec+15,	yyvstop+151,
yycrank+360,	yysvec+15,	yyvstop+153,
yycrank+361,	yysvec+15,	yyvstop+155,
yycrank+370,	yysvec+15,	yyvstop+157,
yycrank+364,	yysvec+15,	yyvstop+159,
yycrank+407,	yysvec+15,	yyvstop+161,
yycrank+378,	yysvec+15,	yyvstop+163,
yycrank+-26,	yysvec+53,	0,	
yycrank+366,	yysvec+15,	yyvstop+165,
yycrank+372,	yysvec+15,	yyvstop+167,
yycrank+374,	yysvec+15,	yyvstop+169,
yycrank+380,	yysvec+15,	yyvstop+172,
yycrank+387,	yysvec+15,	yyvstop+175,
yycrank+381,	yysvec+15,	yyvstop+177,
yycrank+386,	yysvec+15,	yyvstop+179,
yycrank+390,	yysvec+15,	yyvstop+181,
yycrank+432,	yysvec+15,	yyvstop+183,
yycrank+401,	yysvec+15,	yyvstop+185,
yycrank+408,	yysvec+15,	yyvstop+188,
yycrank+421,	yysvec+15,	yyvstop+191,
yycrank+411,	yysvec+15,	yyvstop+193,
yycrank+415,	yysvec+15,	yyvstop+195,
yycrank+416,	yysvec+15,	yyvstop+197,
yycrank+417,	yysvec+15,	yyvstop+200,
yycrank+420,	yysvec+15,	yyvstop+202,
yycrank+455,	yysvec+15,	yyvstop+204,
yycrank+425,	yysvec+15,	yyvstop+206,
yycrank+426,	yysvec+15,	yyvstop+209,
yycrank+431,	yysvec+15,	yyvstop+212,
yycrank+-475,	yysvec+53,	0,	
yycrank+427,	yysvec+15,	yyvstop+214,
yycrank+429,	yysvec+15,	yyvstop+216,
yycrank+434,	yysvec+15,	yyvstop+218,
yycrank+430,	yysvec+15,	yyvstop+220,
yycrank+438,	yysvec+15,	yyvstop+223,
yycrank+441,	yysvec+15,	yyvstop+226,
yycrank+468,	yysvec+15,	yyvstop+229,
yycrank+442,	yysvec+15,	yyvstop+231,
yycrank+444,	yysvec+15,	yyvstop+233,
yycrank+450,	yysvec+15,	yyvstop+235,
yycrank+451,	yysvec+15,	yyvstop+237,
yycrank+460,	yysvec+15,	yyvstop+240,
yycrank+469,	yysvec+15,	yyvstop+243,
yycrank+-87,	yysvec+53,	0,	
yycrank+475,	yysvec+15,	yyvstop+245,
yycrank+490,	yysvec+15,	yyvstop+247,
yycrank+478,	yysvec+15,	yyvstop+249,
yycrank+479,	yysvec+15,	yyvstop+251,
yycrank+489,	yysvec+15,	yyvstop+253,
yycrank+485,	yysvec+15,	yyvstop+255,
yycrank+493,	yysvec+15,	yyvstop+257,
yycrank+499,	yysvec+15,	yyvstop+259,
yycrank+-18,	yysvec+53,	0,	
yycrank+486,	yysvec+15,	yyvstop+261,
yycrank+495,	yysvec+15,	yyvstop+263,
yycrank+496,	yysvec+15,	yyvstop+266,
yycrank+498,	yysvec+15,	yyvstop+269,
yycrank+502,	yysvec+15,	yyvstop+271,
yycrank+503,	yysvec+15,	yyvstop+273,
yycrank+505,	yysvec+15,	yyvstop+275,
yycrank+509,	yysvec+15,	yyvstop+278,
yycrank+-561,	yysvec+53,	0,	
yycrank+512,	yysvec+15,	yyvstop+280,
yycrank+538,	yysvec+15,	yyvstop+282,
yycrank+513,	yysvec+15,	yyvstop+284,
yycrank+539,	yysvec+15,	yyvstop+286,
yycrank+519,	yysvec+15,	yyvstop+288,
yycrank+-564,	yysvec+53,	0,	
yycrank+542,	yysvec+15,	yyvstop+290,
yycrank+547,	yysvec+15,	yyvstop+292,
yycrank+548,	yysvec+15,	yyvstop+295,
yycrank+550,	yysvec+15,	yyvstop+298,
yycrank+552,	yysvec+15,	yyvstop+300,
yycrank+-576,	yysvec+53,	0,	
yycrank+-20,	yysvec+53,	0,	
yycrank+558,	yysvec+15,	yyvstop+303,
yycrank+563,	yysvec+15,	yyvstop+305,
yycrank+-21,	yysvec+53,	0,	
yycrank+-27,	yysvec+53,	yyvstop+307,
yycrank+561,	yysvec+15,	yyvstop+310,
yycrank+565,	yysvec+15,	yyvstop+312,
yycrank+-28,	yysvec+53,	yyvstop+314,
yycrank+555,	yysvec+15,	yyvstop+317,
yycrank+559,	yysvec+15,	yyvstop+319,
yycrank+567,	yysvec+15,	yyvstop+321,
yycrank+568,	yysvec+15,	yyvstop+324,
0,	0,	0};
struct yywork *yytop = yycrank+701;
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
	}
yyunput(c)
   int c; {
	unput(c);
	}
