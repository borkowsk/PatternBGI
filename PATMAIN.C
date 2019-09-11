#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patt2dat.h"

char datname[256]="???  ";
char inputname[256]="???";
char sciezka[256]=" ";
char ext[10]=".dat\0";
int withstandart=0;
float epsilon=0.0;

FILE* inputfile;
extern FILE* yyin;

main()
{
fprintf(stdout,"                  PATTERN TOO TYTAN *.DAT FILE CONVERTER !\n");
fprintf(stdout,"================================================================================\n");
	{
	if((inputfile=fopen("config.tyt","rt"))==NULL)
		{
		fprintf(stderr,"\nCant open config.tyt file!",inputname);
		perror("->");
		putc('\n',stderr);
		strcpy(sciezka,".");
		}
		else
		{
		fgets(sciezka,256,inputfile);
		fclose(inputfile);
			{
			int i;
			for(i=strlen(sciezka);i>=0;i--)
			  if(sciezka[i]=='\n')
				sciezka[i]='\0';
			}
		fprintf(stdout,"DATA from <<%s>>\n",sciezka);
		}
	}

{
char pom[1000];

#ifdef unix /*<<<<	 U  N  I X	 <<<<*/

strcpy(pom,"ls ");
strcat(pom,sciezka);
strcat(pom,"/*.pat\n");
if(system(pom))
	 perror("ls error=posible invalid path");

#else	  /*<<<<<<	D  O   S	<<<<<<*/

strcpy(pom,"dir ");
	strcat(pom,sciezka);
	strcat(pom,"\\*.pat /w");
	if(system(pom))
		 perror("Dir error=posible invalid path");
	fprintf(stdout,"\nFILE NAME ??? :");
	gets(pom);
#endif  /*<<<<	end	<<<<<*/

strcpy(inputname,sciezka);

#ifdef unix
	strcat(inputname,"/");
#else
	strcat(inputname,"\\");
#endif

strcat(inputname,pom);
fprintf(stdout,"DATA from file %s\n",inputname);
}

if((inputfile=fopen(inputname,"rt"))==NULL)
	{
	fprintf(stderr,"\nCant open input %s file!\n",inputname);
	perror("->");
	exit(1);
	}
	else
	{
	yyin=inputfile;
	}


if(yyparse()!=0)
	{
	fclose(inputfile);
	exit(1);
	}
	else
	fclose(inputfile);
dump_array();
fprintf(stdout,"\nCOMMENT:\n<<\n%s\n%s\n%s\n>>",koment1,koment2,koment3);
fprintf(stdout,"\nUSE STANDART'S IN *.DAT FILE (y/n)");
	{
	char pom[256];

	fflush(stdout);
	gets(pom);
	if(pom[0]=='y')
		{
		withstandart=1;
		fprintf(stdout,"  With standart\n");
		}
	if(epsilon==0.0)
		{
		fprintf(stdout,"   EPSILON ???=");
		gets(pom);
		epsilon=atof(pom);
		}
	fprintf(stdout,"   Epsilon=%f\n\n",epsilon);
	}
make_pattern();
writedat();
{ unsigned int i;
for(i=0;i<leynnum;i++)
	free(leyns[i].bands);
}

return 0;
}
