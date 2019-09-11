# include "stdio.h"
# include <alloc.h>
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
			if(koment1) free(koment1);
			HTEST;
			koment1=(char*)calloc
			(yyleng+1,sizeof(char));
			strcpy(koment1,yytext);
				}break;
			case 1:
				{
			if(koment2) free(koment2);
			HTEST;
			koment2=(char*)calloc
			(yyleng+1,sizeof(char));
			strcpy(koment2,yytext);
				}break;

			case 2:
				{
			if(koment3) free(koment3);
			HTEST;
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
			return( NORMAL );
			}
break;
case 15:
	case 16:
	case 17:
	{
			ECHO;
			return(NO);
			}
break;
case 18:
case 19:
	case 20:
	{
			ECHO;
			return(HIPER);
		}
break;
case 21:
case 22:
	case 23:
	{
			ECHO;
			return(LOGN);
			}
break;
case 24:
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
			return(LOGN);
			}
break;
case 31:
case 32:
case 33:
{
			ECHO;
			return(EPSILON);
		}
break;
case 34:
case 35:
	case 36:
	{
			ECHO;
			return(DONE);
		}
break;
case 37:
case 38:
	case 39:
{
			ECHO;
			return( STANDART );
			}
break;
case 40:
{
			ECHO;
			yylval.str=(char*)calloc(yyleng+1,sizeof(char));
			strncpy(yylval.str,yytext,yyleng);
			return(LABEL);
			}
break;
case 41:
	{
			linenum++;
			ECHO;
			}
break;
case 42:
	case 43:
	{
			}
break;
case 44:
	case 45:
	case 46:
	case 47:
	case 48:
	case 49:
	case 50:
	case 51:
	{
			ECHO;
			return(*yytext);
			}
break;
case 52:
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

52,
0,

42,
52,
0,

41,
0,

43,
52,
0,

49,
52,
0,

44,
52,
0,

47,
50,
52,
0,

48,
52,
0,

4,
52,
0,

46,
52,
0,

45,
52,
0,

51,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

40,
52,
0,

52,
0,

4,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

15,
40,
0,

16,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

17,
40,
0,

40,
0,

40,
0,

3,
0,

5,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

34,
40,
0,

36,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

25,
0,

21,
40,
0,

40,
0,

26,
40,
0,

22,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

35,
40,
0,

40,
0,

40,
0,

40,
0,

27,
40,
0,

23,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

18,
40,
0,

19,
40,
0,

28,
0,

29,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

20,
40,
0,

30,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

12,
40,
0,

13,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

14,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

31,
40,
0,

33,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

32,
40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

40,
0,

37,
40,
0,

39,
40,
0,

40,
0,

40,
0,

38,
40,
0,

40,
0,

40,
0,

6,
40,
0,

7,
40,
0,

40,
0,

8,
40,
0,

40,
0,

40,
0,

40,
0,

1,
3,
0,

40,
0,

40,
0,

40,
0,

2,
3,
0,

40,
0,

40,
0,

40,
0,

9,
40,
0,

10,
40,
0,

11,
40,
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
0,0,	0,0,	0,0,	62,0,	
157,0,	188,0,	192,0,	0,0,	
0,0,	1,6,	0,0,	61,0,	
88,0,	187,0,	193,0,	197,0,	
0,0,	0,0,	0,0,	0,0,	
1,7,	1,8,	1,9,	1,3,	
1,10,	1,11,	157,170,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	1,12,	
1,13,	0,0,	1,14,	0,0,	
97,126,	0,0,	1,15,	1,16,	
1,16,	1,17,	1,18,	1,16,	
1,16,	1,19,	1,16,	1,16,	
1,16,	1,20,	1,16,	1,21,	
1,16,	1,22,	1,16,	1,16,	
1,23,	1,16,	1,16,	1,16,	
1,16,	1,16,	1,16,	1,16,	
88,119,	0,0,	61,88,	16,35,	
1,16,	187,192,	1,24,	1,16,	
1,16,	1,25,	1,26,	1,16,	
1,16,	1,27,	1,16,	1,16,	
1,16,	1,28,	1,16,	1,29,	
1,16,	1,30,	1,16,	1,16,	
1,31,	1,16,	1,16,	1,16,	
1,16,	1,16,	1,16,	1,16,	
1,32,	2,4,	11,33,	16,35,	
11,34,	11,34,	11,34,	11,34,	
11,34,	11,34,	11,34,	11,34,	
11,34,	11,34,	17,38,	17,35,	
18,40,	24,35,	62,62,	157,62,	
188,193,	192,197,	20,44,	20,35,	
2,6,	26,35,	61,62,	88,62,	
187,62,	193,62,	197,62,	0,0,	
0,0,	0,0,	0,0,	2,7,	
2,8,	2,9,	0,0,	2,10,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	17,39,	17,35,	
18,41,	24,52,	2,12,	2,13,	
23,35,	2,14,	20,45,	20,35,	
23,50,	26,54,	2,16,	2,16,	
2,17,	2,18,	2,16,	2,16,	
2,19,	2,16,	2,16,	2,16,	
2,20,	2,16,	2,21,	2,16,	
2,22,	2,16,	2,16,	2,23,	
2,16,	2,16,	2,16,	2,16,	
2,16,	2,16,	2,16,	0,0,	
23,35,	35,35,	0,0,	2,16,	
23,51,	2,24,	2,16,	2,16,	
2,25,	2,26,	2,16,	2,16,	
2,27,	2,16,	2,16,	2,16,	
2,28,	2,16,	2,29,	2,16,	
2,30,	2,16,	2,16,	2,31,	
2,16,	2,16,	2,16,	2,16,	
2,16,	2,16,	2,16,	2,32,	
15,35,	35,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
0,0,	21,46,	21,35,	0,0,	
22,35,	0,0,	22,48,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,36,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	21,47,	21,35,	25,35,	
22,35,	15,35,	22,49,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,37,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	15,35,	15,35,	15,35,	
15,35,	19,42,	25,53,	25,35,	
27,35,	32,60,	28,35,	36,64,	
19,35,	0,0,	29,35,	30,35,	
31,35,	0,0,	32,0,	33,63,	
33,63,	33,63,	33,63,	33,63,	
33,63,	33,63,	33,63,	33,63,	
33,63,	37,35,	38,66,	40,35,	
38,35,	27,55,	40,68,	39,35,	
41,35,	19,43,	42,70,	0,0,	
27,35,	28,56,	28,35,	36,35,	
19,35,	29,57,	29,35,	30,35,	
31,35,	30,58,	43,35,	44,72,	
31,59,	49,35,	32,60,	45,35,	
32,60,	46,35,	48,76,	46,74,	
44,35,	37,65,	47,35,	40,35,	
38,35,	39,67,	50,78,	39,35,	
41,35,	48,35,	42,35,	41,69,	
52,35,	32,60,	49,77,	53,35,	
32,61,	55,35,	45,73,	54,35,	
51,35,	50,35,	43,71,	56,35,	
57,35,	49,35,	0,0,	45,35,	
65,35,	46,35,	60,60,	59,35,	
44,35,	64,35,	47,35,	64,89,	
47,75,	51,79,	58,35,	60,0,	
0,0,	48,35,	69,35,	0,0,	
52,80,	53,81,	56,84,	53,35,	
59,87,	55,83,	66,91,	54,35,	
51,35,	50,35,	54,82,	56,35,	
57,35,	67,35,	57,85,	58,86,	
65,35,	66,35,	65,90,	59,35,	
68,93,	64,35,	71,35,	69,94,	
70,95,	74,103,	58,35,	68,35,	
74,35,	32,62,	69,35,	60,60,	
75,35,	60,60,	67,92,	70,35,	
72,97,	72,98,	73,100,	73,101,	
76,105,	79,35,	0,0,	71,96,	
77,35,	67,35,	78,107,	80,35,	
78,35,	66,35,	60,60,	81,35,	
82,35,	76,35,	71,35,	84,113,	
84,114,	83,35,	85,35,	68,35,	
74,35,	75,104,	87,35,	77,106,	
75,35,	89,120,	89,35,	70,35,	
91,35,	73,35,	92,35,	79,108,	
81,110,	79,35,	86,35,	94,35,	
77,35,	82,111,	83,112,	80,35,	
78,35,	80,109,	99,35,	81,35,	
82,35,	76,35,	84,35,	85,116,	
90,35,	83,35,	85,35,	93,122,	
87,118,	86,117,	87,35,	93,35,	
96,35,	100,127,	89,35,	73,102,	
91,35,	73,35,	92,35,	94,123,	
101,35,	102,35,	86,35,	94,35,	
103,128,	95,35,	60,62,	95,124,	
108,35,	72,99,	99,35,	72,35,	
84,115,	104,35,	84,35,	90,121,	
90,35,	106,35,	110,35,	103,35,	
105,130,	109,35,	107,132,	93,35,	
96,35,	100,35,	96,125,	105,35,	
108,133,	113,137,	104,129,	119,0,	
101,35,	102,35,	107,35,	111,35,	
112,35,	95,35,	0,0,	114,35,	
108,35,	115,35,	106,131,	72,35,	
117,35,	104,35,	0,0,	116,35,	
120,35,	106,35,	110,35,	103,35,	
109,134,	109,35,	118,35,	121,35,	
120,142,	100,35,	123,35,	105,35,	
124,35,	113,35,	125,35,	111,135,	
116,138,	127,35,	107,35,	111,35,	
112,35,	117,139,	112,136,	114,35,	
129,35,	115,35,	118,140,	136,35,	
117,35,	122,144,	122,35,	116,35,	
120,35,	128,146,	134,35,	131,35,	
132,150,	128,35,	118,35,	121,35,	
130,35,	123,145,	123,35,	130,148,	
124,35,	113,35,	125,35,	121,143,	
133,35,	127,35,	135,35,	132,35,	
129,147,	137,35,	139,35,	141,0,	
129,35,	0,0,	119,141,	136,35,	
138,35,	140,35,	122,35,	143,35,	
142,35,	133,151,	134,35,	131,35,	
146,35,	128,35,	131,149,	145,35,	
130,35,	142,158,	134,152,	144,160,	
147,35,	144,35,	140,156,	151,35,	
133,35,	135,153,	135,35,	132,35,	
148,162,	137,35,	139,35,	149,35,	
138,154,	139,155,	152,35,	148,35,	
138,35,	140,35,	153,35,	143,35,	
142,35,	150,35,	119,62,	150,164,	
146,35,	145,161,	154,35,	145,35,	
143,159,	155,35,	156,35,	158,171,	
147,35,	144,35,	158,35,	151,35,	
149,163,	151,165,	159,35,	160,35,	
141,157,	161,35,	165,35,	149,35,	
162,173,	162,35,	152,35,	148,35,	
153,167,	163,35,	153,35,	167,35,	
164,35,	150,35,	155,168,	152,166,	
164,175,	166,35,	154,35,	168,35,	
169,35,	155,35,	156,35,	170,0,	
156,169,	172,35,	158,35,	159,172,	
174,35,	175,35,	159,35,	160,35,	
171,181,	161,35,	165,35,	176,35,	
178,35,	162,35,	165,176,	179,35,	
163,174,	163,35,	172,182,	167,35,	
164,35,	177,35,	166,177,	171,35,	
180,0,	166,35,	168,178,	168,35,	
169,35,	173,183,	141,62,	173,35,	
169,179,	172,35,	174,184,	181,35,	
174,35,	175,35,	177,185,	181,189,	
182,35,	183,35,	178,186,	176,35,	
178,35,	184,35,	185,35,	179,35,	
186,35,	189,194,	0,0,	0,0,	
0,0,	177,35,	190,35,	171,35,	
189,35,	198,201,	191,35,	198,35,	
194,198,	194,35,	201,35,	173,35,	
195,35,	0,0,	196,35,	181,35,	
170,180,	199,35,	200,35,	202,35,	
182,35,	183,35,	203,35,	0,0,	
182,190,	184,35,	185,35,	190,195,	
186,35,	0,0,	185,191,	191,196,	
180,187,	0,0,	190,35,	0,0,	
189,35,	0,0,	191,35,	198,35,	
180,188,	194,35,	201,35,	195,199,	
195,35,	196,200,	196,35,	199,202,	
200,203,	199,35,	200,35,	202,35,	
0,0,	0,0,	203,35,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	170,62,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	180,62,	
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
yycrank+174,	yysvec+15,	yyvstop+54,
yycrank+176,	yysvec+15,	yyvstop+57,
yycrank+96,	yysvec+15,	yyvstop+60,
yycrank+61,	yysvec+15,	yyvstop+63,
yycrank+207,	yysvec+15,	yyvstop+66,
yycrank+69,	yysvec+15,	yyvstop+69,
yycrank+240,	yysvec+15,	yyvstop+72,
yycrank+242,	yysvec+15,	yyvstop+75,
yycrank+246,	yysvec+15,	yyvstop+78,
yycrank+247,	yysvec+15,	yyvstop+81,
yycrank+248,	yysvec+15,	yyvstop+84,
yycrank+-320,	0,		yyvstop+87,
yycrank+283,	0,		0,	
yycrank+0,	yysvec+11,	yyvstop+89,
yycrank+129,	yysvec+15,	yyvstop+91,
yycrank+243,	yysvec+15,	yyvstop+93,
yycrank+261,	yysvec+15,	yyvstop+95,
yycrank+264,	yysvec+15,	yyvstop+97,
yycrank+267,	yysvec+15,	yyvstop+99,
yycrank+263,	yysvec+15,	yyvstop+101,
yycrank+268,	yysvec+15,	yyvstop+103,
yycrank+270,	yysvec+15,	yyvstop+105,
yycrank+282,	yysvec+15,	yyvstop+107,
yycrank+292,	yysvec+15,	yyvstop+109,
yycrank+287,	yysvec+15,	yyvstop+111,
yycrank+289,	yysvec+15,	yyvstop+113,
yycrank+294,	yysvec+15,	yyvstop+116,
yycrank+301,	yysvec+15,	yyvstop+119,
yycrank+285,	yysvec+15,	yyvstop+121,
yycrank+313,	yysvec+15,	yyvstop+123,
yycrank+312,	yysvec+15,	yyvstop+125,
yycrank+304,	yysvec+15,	yyvstop+127,
yycrank+307,	yysvec+15,	yyvstop+129,
yycrank+311,	yysvec+15,	yyvstop+131,
yycrank+309,	yysvec+15,	yyvstop+133,
yycrank+315,	yysvec+15,	yyvstop+135,
yycrank+316,	yysvec+15,	yyvstop+137,
yycrank+330,	yysvec+15,	yyvstop+140,
yycrank+323,	yysvec+15,	yyvstop+142,
yycrank+-401,	0,		0,	
yycrank+-25,	yysvec+60,	0,	
yycrank+-17,	yysvec+60,	yyvstop+144,
yycrank+0,	yysvec+33,	yyvstop+146,
yycrank+325,	yysvec+15,	yyvstop+148,
yycrank+320,	yysvec+15,	yyvstop+150,
yycrank+353,	yysvec+15,	yyvstop+152,
yycrank+349,	yysvec+15,	yyvstop+154,
yycrank+363,	yysvec+15,	yyvstop+156,
yycrank+334,	yysvec+15,	yyvstop+158,
yycrank+371,	yysvec+15,	yyvstop+160,
yycrank+358,	yysvec+15,	yyvstop+162,
yycrank+451,	yysvec+15,	yyvstop+164,
yycrank+405,	yysvec+15,	yyvstop+166,
yycrank+364,	yysvec+15,	yyvstop+168,
yycrank+368,	yysvec+15,	yyvstop+170,
yycrank+389,	yysvec+15,	yyvstop+172,
yycrank+380,	yysvec+15,	yyvstop+174,
yycrank+384,	yysvec+15,	yyvstop+176,
yycrank+377,	yysvec+15,	yyvstop+178,
yycrank+383,	yysvec+15,	yyvstop+180,
yycrank+387,	yysvec+15,	yyvstop+182,
yycrank+388,	yysvec+15,	yyvstop+184,
yycrank+393,	yysvec+15,	yyvstop+186,
yycrank+422,	yysvec+15,	yyvstop+188,
yycrank+394,	yysvec+15,	yyvstop+190,
yycrank+410,	yysvec+15,	yyvstop+192,
yycrank+398,	yysvec+15,	yyvstop+194,
yycrank+-26,	yysvec+60,	0,	
yycrank+402,	yysvec+15,	yyvstop+196,
yycrank+424,	yysvec+15,	yyvstop+198,
yycrank+404,	yysvec+15,	yyvstop+200,
yycrank+406,	yysvec+15,	yyvstop+203,
yycrank+431,	yysvec+15,	yyvstop+206,
yycrank+411,	yysvec+15,	yyvstop+208,
yycrank+445,	yysvec+15,	yyvstop+210,
yycrank+432,	yysvec+15,	yyvstop+212,
yycrank+16,	0,		0,	
yycrank+0,	0,		yyvstop+214,
yycrank+418,	yysvec+15,	yyvstop+216,
yycrank+465,	yysvec+15,	yyvstop+219,
yycrank+440,	yysvec+15,	yyvstop+221,
yycrank+441,	yysvec+15,	yyvstop+224,
yycrank+459,	yysvec+15,	yyvstop+227,
yycrank+453,	yysvec+15,	yyvstop+229,
yycrank+467,	yysvec+15,	yyvstop+231,
yycrank+457,	yysvec+15,	yyvstop+233,
yycrank+474,	yysvec+15,	yyvstop+235,
yycrank+448,	yysvec+15,	yyvstop+237,
yycrank+461,	yysvec+15,	yyvstop+239,
yycrank+458,	yysvec+15,	yyvstop+241,
yycrank+475,	yysvec+15,	yyvstop+244,
yycrank+476,	yysvec+15,	yyvstop+246,
yycrank+501,	yysvec+15,	yyvstop+248,
yycrank+479,	yysvec+15,	yyvstop+250,
yycrank+481,	yysvec+15,	yyvstop+253,
yycrank+487,	yysvec+15,	yyvstop+256,
yycrank+484,	yysvec+15,	yyvstop+258,
yycrank+494,	yysvec+15,	yyvstop+260,
yycrank+-541,	yysvec+60,	0,	
yycrank+488,	yysvec+15,	yyvstop+262,
yycrank+495,	yysvec+15,	yyvstop+264,
yycrank+518,	yysvec+15,	yyvstop+266,
yycrank+498,	yysvec+15,	yyvstop+268,
yycrank+500,	yysvec+15,	yyvstop+270,
yycrank+502,	yysvec+15,	yyvstop+273,
yycrank+0,	0,		yyvstop+276,
yycrank+505,	yysvec+15,	yyvstop+278,
yycrank+525,	yysvec+15,	yyvstop+281,
yycrank+512,	yysvec+15,	yyvstop+283,
yycrank+528,	yysvec+15,	yyvstop+285,
yycrank+523,	yysvec+15,	yyvstop+287,
yycrank+539,	yysvec+15,	yyvstop+289,
yycrank+536,	yysvec+15,	yyvstop+291,
yycrank+522,	yysvec+15,	yyvstop+293,
yycrank+538,	yysvec+15,	yyvstop+295,
yycrank+515,	yysvec+15,	yyvstop+297,
yycrank+541,	yysvec+15,	yyvstop+300,
yycrank+548,	yysvec+15,	yyvstop+303,
yycrank+542,	yysvec+15,	yyvstop+305,
yycrank+549,	yysvec+15,	yyvstop+307,
yycrank+-613,	yysvec+60,	0,	
yycrank+552,	yysvec+15,	yyvstop+309,
yycrank+551,	yysvec+15,	yyvstop+311,
yycrank+565,	yysvec+15,	yyvstop+313,
yycrank+559,	yysvec+15,	yyvstop+315,
yycrank+556,	yysvec+15,	yyvstop+317,
yycrank+564,	yysvec+15,	yyvstop+320,
yycrank+579,	yysvec+15,	yyvstop+323,
yycrank+575,	yysvec+15,	yyvstop+325,
yycrank+585,	yysvec+15,	yyvstop+327,
yycrank+567,	yysvec+15,	yyvstop+329,
yycrank+578,	yysvec+15,	yyvstop+331,
yycrank+582,	yysvec+15,	yyvstop+333,
yycrank+590,	yysvec+15,	yyvstop+335,
yycrank+593,	yysvec+15,	yyvstop+338,
yycrank+594,	yysvec+15,	yyvstop+340,
yycrank+-18,	yysvec+60,	0,	
yycrank+598,	yysvec+15,	yyvstop+342,
yycrank+602,	yysvec+15,	yyvstop+344,
yycrank+603,	yysvec+15,	yyvstop+346,
yycrank+605,	yysvec+15,	yyvstop+349,
yycrank+609,	yysvec+15,	yyvstop+352,
yycrank+613,	yysvec+15,	yyvstop+354,
yycrank+616,	yysvec+15,	yyvstop+356,
yycrank+606,	yysvec+15,	yyvstop+358,
yycrank+621,	yysvec+15,	yyvstop+360,
yycrank+615,	yysvec+15,	yyvstop+362,
yycrank+623,	yysvec+15,	yyvstop+365,
yycrank+624,	yysvec+15,	yyvstop+367,
yycrank+-697,	yysvec+60,	0,	
yycrank+651,	yysvec+15,	yyvstop+369,
yycrank+629,	yysvec+15,	yyvstop+371,
yycrank+659,	yysvec+15,	yyvstop+373,
yycrank+632,	yysvec+15,	yyvstop+375,
yycrank+633,	yysvec+15,	yyvstop+377,
yycrank+639,	yysvec+15,	yyvstop+380,
yycrank+649,	yysvec+15,	yyvstop+383,
yycrank+640,	yysvec+15,	yyvstop+385,
yycrank+643,	yysvec+15,	yyvstop+387,
yycrank+-722,	yysvec+60,	0,	
yycrank+663,	yysvec+15,	yyvstop+390,
yycrank+668,	yysvec+15,	yyvstop+392,
yycrank+669,	yysvec+15,	yyvstop+394,
yycrank+673,	yysvec+15,	yyvstop+397,
yycrank+674,	yysvec+15,	yyvstop+400,
yycrank+676,	yysvec+15,	yyvstop+402,
yycrank+-27,	yysvec+60,	0,	
yycrank+-19,	yysvec+60,	0,	
yycrank+684,	yysvec+15,	yyvstop+405,
yycrank+682,	yysvec+15,	yyvstop+407,
yycrank+686,	yysvec+15,	yyvstop+409,
yycrank+-20,	yysvec+60,	0,	
yycrank+-28,	yysvec+60,	yyvstop+411,
yycrank+689,	yysvec+15,	yyvstop+414,
yycrank+692,	yysvec+15,	yyvstop+416,
yycrank+694,	yysvec+15,	yyvstop+418,
yycrank+-29,	yysvec+60,	yyvstop+420,
yycrank+687,	yysvec+15,	yyvstop+423,
yycrank+697,	yysvec+15,	yyvstop+425,
yycrank+698,	yysvec+15,	yyvstop+427,
yycrank+690,	yysvec+15,	yyvstop+429,
yycrank+699,	yysvec+15,	yyvstop+432,
yycrank+702,	yysvec+15,	yyvstop+435,
0,	0,	0};
struct yywork *yytop = yycrank+847;
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
