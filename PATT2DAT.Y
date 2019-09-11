/* translator opisu zelu na tablice programu patt2dat */

%{
#include <stdio.h>
#include <stdlib.h>
#include "patt2dat.h"

%}

%union {
	int   inv;
	char *str;
	float flo;
	}

%START specyfikacja
%TOKEN <str> LABEL
%TOKEN <flo> CONST
%TOKEN EPSILON  PRECISION  APPROXYMATION  NO HIPER NORMAL  POLY LOGN LOG2 LOG10 STANDART DONE ILLEGAL 


%%
specyfikacja	: 	  /* empty */
		|   	lines 
		;

lines		:	line
		|	lines line
		|	error_ch
		;

		
Label		: 	LABEL
			{ /* LABEL */

			band *pom;
			if( leynnum>=MAX_LEYN_NUMBER)
				{
				yyerror("T o   m a n y   l a n e s !!!");
				return 1;
				}
			actual_leyn=leyns+leynnum;
			actual_leyn->label=$1;
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
			}

line		: 	Label ':' lista_prazkow ';'
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
			}

		| 	STANDART Label ':' lista_standartu ';'
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
			}

		|	DONE Label ':' lista_done ';'
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
			}
		|	EPSILON '=' CONST ';'
			{/* EPSILON = CONST */
			epsilon=$3;
			}
		|	PRECISION '=' CONST ';'
			{/* PRECISION = CONST ;*/
			epsilonapr=$3;
			}
		|	APPROXYMATION  NO ';'
			{/* APPROXYMATION NO */

			}
		|	APPROXYMATION  HIPER  ';'
			{/* APPROXYMATION HIPER */

			}
		|	APPROXYMATION  POLY  ';'
			{/* APPROXYMATION POLY */

			}
		|	APPROXYMATION NORMAL ';'
			{/* APPROXYMATION NORMAL */

			}		
		|	APPROXYMATION LOGN  ';'
			{/* APPROXYMATION LOGN */

			}		
		|	APPROXYMATION LOG2  ';'
			{/* APPROXYMATION LOG2 */

			}		
		|	APPROXYMATION LOG10 ';'
			{/* APPROXYMATION LOG10 */

			}
		
		
lista_prazkow   :	CONST 
			{/* l i s t a _ p r a z k o w --- CONST*/
			actual_leyn->bands[0].met=$1;
			actual_leyn->bands[0].kbz=$1;
			actual_leyn->bands[0].eps=epsilon;
			bandnum=1;
			}

		|	lista_prazkow ',' '-''/''/''-'
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
			}

		|	'-''/''/''-'
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
			}

		|	lista_prazkow ',' CONST
			{/* lista , CONST */

			if(bandnum>=MAX_BANDS_NUMBER)
				{
				yyerror("To many bands");
				return 1;
				}
			actual_leyn->bands[bandnum].met=$3;
			actual_leyn->bands[bandnum].kbz=0;
			actual_leyn->bands[bandnum].eps=epsilon;

			if(
			actual_leyn->bands[bandnum].met<actual_leyn->bands[bandnum-1].met
				)
				warning("Incorrect sequention of values ");
			bandnum++;
			}


lista_standartu	:	CONST '=' CONST
			{/* l i s ta _ s t a n d a r t u --- CONST = CONST */

			actual_leyn->bands[0].met=$1;
			actual_leyn->bands[0].kbz=$3;
			actual_leyn->bands[0].eps=0;

			bandnum=1;
			}

		|	lista_standartu ',' CONST '=' CONST
			{/* lista , CONST = CONST */

			if(bandnum>=MAX_BANDS_NUMBER)
				{
				yyerror("To many bands");
				return 1;
				}
			actual_leyn->bands[bandnum].met=$3;
			actual_leyn->bands[bandnum].kbz=$5;
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
			}

lista_done	:	CONST '=' CONST  '+' '-' CONST
			{/* l i s t a _ d o n e  --- CONST = CONST +- CONST */

			actual_leyn->bands[0].met=$1;
			actual_leyn->bands[0].kbz=$3;
			actual_leyn->bands[0].eps=$6;
			bandnum=1;
			}

		|	lista_done ',' CONST '=' CONST '+' '-' CONST
			{/* lista , CONST = CONST +- CONST */

			if(bandnum>=MAX_BANDS_NUMBER)
				{
				yyerror("To many bands");
				return 1;
				}
			actual_leyn->bands[bandnum].met=$3;
			actual_leyn->bands[bandnum].kbz=$5;
			actual_leyn->bands[bandnum].eps=$8;

			if(
			actual_leyn->bands[bandnum].met<actual_leyn->bands[bandnum-1].met
				)
				warning("Incorrect sequention of done values ");
			if(
			actual_leyn->bands[bandnum].kbz>actual_leyn->bands[bandnum-1].kbz
				)
				warning("Incorrect sequention of done data values ");
			bandnum++;
			}

error_ch	: 	ILLEGAL
			{/* I L L E G A L */

			yyerror("Illegal character");
			return 1;
			}

%% 	
