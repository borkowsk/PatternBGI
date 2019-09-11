extern char *malloc(), *realloc();

# line 4 "patt2dat.y"
#include <stdio.h>
#include <stdlib.h>
#include "patt2dat.h"


# line 10 "patt2dat.y"
typedef union  {
	int   inv;
	char *str;
	float flo;
	} YYSTYPE;
# define LABEL 257
# define CONST 258
# define EPSILON 259
# define PRECISION 260
# define APPROXYMATION 261
# define NO 262
# define HIPER 263
# define NORMAL 264
# define POLY 265
# define LOGN 266
# define LOG2 267
# define LOG10 268
# define STANDART 269
# define DONE 270
# define ILLEGAL 271
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
YYSTYPE yylval, yyval;
# define YYERRCODE 256

# line 277 "patt2dat.y"
 	
int yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
	};
# define YYNPROD 28
# define YYLAST 220
int yyact[]={

    12,    49,     8,     9,    10,    12,    28,     8,     9,    10,
    75,    73,     6,     7,    11,    66,    70,     6,     7,    19,
    20,    22,    21,    23,    24,    25,    69,    63,    62,    61,
    60,    46,    44,    32,    31,    12,    65,    57,    54,    18,
    17,    56,    53,    41,    48,    47,    39,    38,    37,    36,
    35,    34,    33,    30,    29,    64,    55,    52,    40,    14,
    58,    51,    42,    74,    71,    68,    59,    72,    67,     5,
     3,    45,    43,    13,    26,     4,    15,    16,     2,     1,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    50,     0,     0,     0,     0,    27 };
int yypact[]={

  -257, -1000,  -252, -1000, -1000,     1,  -222,  -222,   -21,   -22,
  -243, -1000, -1000, -1000,   -39,    -4,    -5,  -224,  -225,    -7,
    -8,    -9,   -10,   -11,   -12,   -13,    -1, -1000,    15,  -226,
  -227,   -14,   -15, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
 -1000,   -44,    14,    -2,   -23,    -3,   -24, -1000, -1000,    13,
 -1000,    21, -1000,  -228,  -229, -1000,  -230,  -231,     8, -1000,
   -25, -1000,   -46,    25,    20,  -232,  -242,    19, -1000, -1000,
    24,  -247,    18, -1000,  -248, -1000 };
int yypgo[]={

     0,    79,    78,    70,    75,    69,    74,    72,    71 };
int yyr1[]={

     0,     1,     1,     2,     2,     2,     5,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
     6,     6,     6,     7,     7,     8,     8,     4 };
int yyr2[]={

     0,     0,     2,     2,     4,     2,     3,     9,    11,    11,
     9,     9,     7,     7,     7,     7,     7,     7,     7,     3,
    13,     9,     7,     7,    11,    13,    17,     3 };
int yychk[]={

 -1000,    -1,    -2,    -3,    -4,    -5,   269,   270,   259,   260,
   261,   271,   257,    -3,    58,    -5,    -5,    61,    61,   262,
   263,   265,   264,   266,   267,   268,    -6,   258,    45,    58,
    58,   258,   258,    59,    59,    59,    59,    59,    59,    59,
    59,    44,    47,    -7,   258,    -8,   258,    59,    59,    45,
   258,    47,    59,    44,    61,    59,    44,    61,    47,    45,
   258,   258,   258,   258,    47,    61,    61,    43,    45,   258,
   258,    45,    43,   258,    45,   258 };
int yydef[]={

     1,    -2,     2,     3,     5,     0,     0,     0,     0,     0,
     0,    27,     6,     4,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
     0,     0,     0,    12,    13,    14,    15,    16,    17,    18,
     7,     0,     0,     0,     0,     0,     0,    10,    11,     0,
    22,     0,     8,     0,     0,     9,     0,     0,     0,    21,
     0,    23,     0,     0,     0,     0,     0,     0,    20,    24,
     0,     0,     0,    25,     0,    26 };
typedef struct { char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	1	/* allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"LABEL",	257,
	"CONST",	258,
	"EPSILON",	259,
	"PRECISION",	260,
	"APPROXYMATION",	261,
	"NO",	262,
	"HIPER",	263,
	"NORMAL",	264,
	"POLY",	265,
	"LOGN",	266,
	"LOG2",	267,
	"LOG10",	268,
	"STANDART",	269,
	"DONE",	270,
	"ILLEGAL",	271,
	"-unknown-",	-1	/* ends search */
};

char * yyreds[] =
{
	"-no such reduction-",
	"specyfikacja : /* empty */",
	"specyfikacja : lines",
	"lines : line",
	"lines : lines line",
	"lines : error_ch",
	"Label : LABEL",
	"line : Label ':' lista_prazkow ';'",
	"line : STANDART Label ':' lista_standartu ';'",
	"line : DONE Label ':' lista_done ';'",
	"line : EPSILON '=' CONST ';'",
	"line : PRECISION '=' CONST ';'",
	"line : APPROXYMATION NO ';'",
	"line : APPROXYMATION HIPER ';'",
	"line : APPROXYMATION POLY ';'",
	"line : APPROXYMATION NORMAL ';'",
	"line : APPROXYMATION LOGN ';'",
	"line : APPROXYMATION LOG2 ';'",
	"line : APPROXYMATION LOG10 ';'",
	"lista_prazkow : CONST",
	"lista_prazkow : lista_prazkow ',' '-' '/' '/' '-'",
	"lista_prazkow : '-' '/' '/' '-'",
	"lista_prazkow : lista_prazkow ',' CONST",
	"lista_standartu : CONST '=' CONST",
	"lista_standartu : lista_standartu ',' CONST '=' CONST",
	"lista_done : CONST '=' CONST '+' '-' CONST",
	"lista_done : lista_done ',' CONST '=' CONST '+' '-' CONST",
	"error_ch : ILLEGAL",
};
#endif /* YYDEBUG */
#line 1 "/usr/lib/yaccpar"
/*	@(#)yaccpar 1.10 89/04/04 SMI; from S5R3 1.10	*/

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	{ free(yys); free(yyv); return(0); }
#define YYABORT		{ free(yys); free(yyv); return(1); }
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-1000)

/*
** static variables used by the parser
*/
static YYSTYPE *yyv;			/* value stack */
static int *yys;			/* state stack */

static YYSTYPE *yypv;			/* top of value stack */
static int *yyps;			/* top of state stack */

static int yystate;			/* current state */
static int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */

int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */


/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
int
yyparse()
{
	register YYSTYPE *yypvt;	/* top of value stack for $vars */
	unsigned yymaxdepth = YYMAXDEPTH;

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yyv = (YYSTYPE*)malloc(yymaxdepth*sizeof(YYSTYPE));
	yys = (int*)malloc(yymaxdepth*sizeof(int));
	if (!yyv || !yys)
	{
		yyerror( "out of memory" );
		return(1);
	}
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

	goto yystack;
	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			(void)printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				(void)printf( "end-of-file\n" );
			else if ( yychar < 0 )
				(void)printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				(void)printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			int yyps_index = (yy_ps - yys);
			int yypv_index = (yy_pv - yyv);
			int yypvt_index = (yypvt - yyv);
			yymaxdepth += YYMAXDEPTH;
			yyv = (YYSTYPE*)realloc((char*)yyv,
				yymaxdepth * sizeof(YYSTYPE));
			yys = (int*)realloc((char*)yys,
				yymaxdepth * sizeof(int));
			if (!yyv || !yys)
			{
				yyerror( "yacc stack overflow" );
				return(1);
			}
			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = yylex() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			(void)printf( "Received token " );
			if ( yychar == 0 )
				(void)printf( "end-of-file\n" );
			else if ( yychar < 0 )
				(void)printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				(void)printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = yylex() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				(void)printf( "Received token " );
				if ( yychar == 0 )
					(void)printf( "end-of-file\n" );
				else if ( yychar < 0 )
					(void)printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					(void)printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
				yynerrs++;
			skip_init:
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						(void)printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					(void)printf( "Error recovery discards " );
					if ( yychar == 0 )
						(void)printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						(void)printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						(void)printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			(void)printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{
		
case 6:
# line 34 "patt2dat.y"
{ /* LABEL */

			band *pom;
			if( leynnum>=MAX_LEYN_NUMBER)
				yyerror("To many layns");

			actual_leyn=leyns+leynnum;
			actual_leyn->label=yypvt[-0].str;
			actual_leyn->not_empty=1;

			actual_leyn->all_kill=0;
			actual_leyn->fresh=0;
			actual_leyn->done=0;
			actual_leyn->stand=0;

		pom=(band*)calloc(MAX_BANDS_NUMBER,sizeof(band));
			if(pom==NULL)
				{
				yyerror("NOT ENOUGHT MEMORY - SORRY!");
				return 1;
				}
			actual_leyn->bands=pom;
			bandnum=0;
			} break;
case 7:
# line 60 "patt2dat.y"
{ /* Label : lista_prazkow ; */

			band *pom;
	
			actual_leyn->band_number=bandnum;
			actual_leyn->fresh=1;
			pom=(band*)realloc(actual_leyn->bands,sizeof(band)*(1+bandnum));
			if(pom==NULL)
				{
				yyerror("ALLOCATION ERROR - SORRY!");
				return 1;
				}
			actual_leyn->bands=pom;
			leynnum++;
			} break;
case 8:
# line 77 "patt2dat.y"
{ /* STANDART Label : lista_standartu ; */

			band *pom;
			actual_leyn->band_number=bandnum;
			actual_leyn->stand=1;
					pom=(band*)realloc(actual_leyn->bands,sizeof(band)*(1+bandnum));
			if(pom==NULL)
				{
				yyerror("ALLOCATION ERROR - SORRY!");
				return 1;
				}
			leynnum++;	
			} break;
case 9:
# line 92 "patt2dat.y"
{/* DONE Label : lista_done ; */

			band *pom;
			actual_leyn->band_number=bandnum;
			actual_leyn->done=1;
			pom=(band*)realloc(actual_leyn->bands,sizeof(band)*(1+bandnum));
			if(pom==NULL)
				{
				yyerror("ALLOCATION ERROR - SORRY!");
				return 1;
				}
			leynnum++;	
			} break;
case 10:
# line 106 "patt2dat.y"
{/* EPSILON = CONST */
			epsilon=yypvt[-1].flo;
			} break;
case 11:
# line 110 "patt2dat.y"
{/* PRECISION = CONST ;*/
			epsilonapr=yypvt[-1].flo;
			} break;
case 12:
# line 114 "patt2dat.y"
{/* APPROXYMATION NO */

			} break;
case 13:
# line 118 "patt2dat.y"
{/* APPROXYMATION HIPER */

			} break;
case 14:
# line 122 "patt2dat.y"
{/* APPROXYMATION POLY */

			} break;
case 15:
# line 126 "patt2dat.y"
{/* APPROXYMATION NORMAL */

			} break;
case 16:
# line 130 "patt2dat.y"
{/* APPROXYMATION LOGN */

			} break;
case 17:
# line 134 "patt2dat.y"
{/* APPROXYMATION LOG2 */

			} break;
case 18:
# line 138 "patt2dat.y"
{/* APPROXYMATION LOG10 */

			} break;
case 19:
# line 144 "patt2dat.y"
{/* l i s t a _ p r a z k o w --- CONST*/
			actual_leyn->bands[0].met=yypvt[-0].flo;
			actual_leyn->bands[0].kbz=yypvt[-0].flo;
			actual_leyn->bands[0].eps=epsilon;
			bandnum=1;
			} break;
case 20:
# line 152 "patt2dat.y"
{/* lista , -//- */

			unsigned int i;

			if(leynnum==0)
				{
				yyerror("Illegal operator -//- in first layn"); 
				return 1;
				}
			for(i=bandnum;i<leyns[leynnum-1].band_number;i++)
				{
				actual_leyn->bands[i]=leyns[leynnum-1].bands[i];
				bandnum++;
				}
			} break;
case 21:
# line 169 "patt2dat.y"
{/* -//- */

			unsigned int i;

			if(leynnum==0)
				{
				yyerror("Illegal operator -//-"); 
				return 1;
				}
			for(i=bandnum;i<leyns[leynnum-1].band_number;i++)
				{
				actual_leyn->bands[i]=leyns[leynnum-1].bands[i];
				bandnum++;
				}
			} break;
case 22:
# line 186 "patt2dat.y"
{/* lista , CONST */

			if(bandnum>=MAX_BANDS_NUMBER)
				{
				yyerror("To many bands");
				return 1;
				}
			actual_leyn->bands[bandnum].met=yypvt[-0].flo;
			actual_leyn->bands[bandnum].kbz=0;
			actual_leyn->bands[bandnum].eps=epsilon;

			if(
			actual_leyn->bands[bandnum].met<actual_leyn->bands[bandnum-1].met
				)
				warning("Incorrect sequention of values ");
			bandnum++;
			} break;
case 23:
# line 206 "patt2dat.y"
{/* l i s ta _ s t a n d a r t u --- CONST = CONST */

			actual_leyn->bands[0].met=yypvt[-2].flo;
			actual_leyn->bands[0].kbz=yypvt[-0].flo;
			actual_leyn->bands[0].eps=0;

			bandnum=1;
			} break;
case 24:
# line 216 "patt2dat.y"
{/* lista , CONST = CONST */

			if(bandnum>=MAX_BANDS_NUMBER)
				{
				yyerror("To many bands");
				return 1;
				}
			actual_leyn->bands[bandnum].met=yypvt[-2].flo;
			actual_leyn->bands[bandnum].kbz=yypvt[-0].flo;
			actual_leyn->bands[bandnum].eps=0;

			if(
			actual_leyn->bands[bandnum].met<actual_leyn->bands[bandnum-1].met
				)
				warning("Incorrect sequention of standart values ");
			if(
			actual_leyn->bands[bandnum].kbz>actual_leyn->bands[bandnum-1].kbz
				)
				warning("Incorrect sequention of standart data values ");
			bandnum++;
			} break;
case 25:
# line 239 "patt2dat.y"
{/* l i s t a _ d o n e  --- CONST = CONST +- CONST */

			actual_leyn->bands[0].met=yypvt[-5].flo;
			actual_leyn->bands[0].kbz=yypvt[-3].flo;
			actual_leyn->bands[0].kbz=yypvt[-0].flo;
			bandnum=1;
			} break;
case 26:
# line 248 "patt2dat.y"
{/* lista , CONST = CONST +- CONST */

			if(bandnum>=MAX_BANDS_NUMBER)
				{
				yyerror("To many bands");
				return 1;
				}
			actual_leyn->bands[bandnum].met=yypvt[-5].flo;
			actual_leyn->bands[bandnum].kbz=yypvt[-3].flo;
			actual_leyn->bands[bandnum].eps=yypvt[-0].flo;

			if(
			actual_leyn->bands[bandnum].met<actual_leyn->bands[bandnum-1].met
				)
				warning("Incorrect sequention of standart values ");
			if(
			actual_leyn->bands[bandnum].kbz>actual_leyn->bands[bandnum-1].kbz
				)
				warning("Incorrect sequention of standart data values ");
			bandnum++;
			} break;
case 27:
# line 271 "patt2dat.y"
{/* I L L E G A L */

			yyerror("Illegal character");
			return 1;
			} break;
	}
	goto yystack;		/* reset registers in driver code */
}
