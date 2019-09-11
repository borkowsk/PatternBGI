
DIG		[0-9]
ALFA    	[_A-Za-z]
ALFANUM 	[_0-9a-zA-Z\.]

%{
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
%}

%%
"{"DEBUG\ ON"}"	{ yydebug=1;
		}
"{"DEBUG\ OFF"}" { yydebug=0;
		}
"{".*"}" 	{       yytext[0]=' ';
			yytext[yyleng-1]=' ';

			switch(kommnum){
			case 0:
				{
			if(koment1) free(koment2);
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
 *				}break;

			case 2:
				{
			if(koment3) free(koment2);
			HTEST;
			koment3=(char*)calloc
			(yyleng+1,sizeof(char));
			strcpy(koment3,yytext);
				}break;

			}
			kommnum++;
			}
{DIG}+		|
{DIG}+"."{DIG}+ {
			ECHO;
			yylval.flo=atof(yytext);
			return(CONST);
			}
\P\R\E\C\I\S\I\O\N	|
"Precision"	|
"precision"	{
			ECHO;
			return(PRECISION);
			}
\A\P\P\R\O\X\Y\M\A\T\I\O\N	|
"Approxymation"	|
"approxymation"	{
			ECHO;
			return(APPROXYMATION);
			}
\N\O\R\M\A\L	|
"Normal"	|
"normal"	{
			ECHO;
			return( NORMAL );
			}
\N\O		|
"No"		|
"no"		{
			ECHO;
			return(NO);
			}
\H\I\P\E\R	|
"Hiper"		|
"hiper"		{
			ECHO;
			return(HIPER);
		}
\L\O\G\N	|
"Logn"		|
"logn"		{
			ECHO;
			return(LOGN);
			}
\L\O\G\2	|
"Log2"		|
"log2"		{
			ECHO;
			return(LOGN);
			}
\L\O\G\1\0	|
"Log10"		|
"log10"		{
			ECHO;
			return(LOGN);
			}
\E\P\S\I\L\O\N	|
"epsilon"	|
"Epsilon"	{
			ECHO;
			return(EPSILON);
		}
\D\O\N\E	|
"done"		|
"Done"		{
			ECHO;
			return(DONE);
		}
\S\T\A\N\D\A\R\T	|
"standart"		|
"Standart"	{
			ECHO;
			return( STANDART );
			}
{ALFA}{ALFANUM}* {
			ECHO;
		yylval.str=(char*)calloc(yyleng+1,sizeof(char));
			strncpy(yylval.str,yytext,yyleng);
			return(LABEL);
			}
\n		{
			linenum++;
			ECHO;
			}
\t		|
" "		{
			}	
","		|
";"		|
":"		|
"-"		|
"/"		|
"+"		|
"-"		|
"="		{
			ECHO;
			return(*yytext);
			}
.		{ 
		ECHO;
		return(ILLEGAL);
		}
%%
