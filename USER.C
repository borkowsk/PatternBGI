#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <time.h>

#undef DEMO

#ifndef ANTY_DEBUG
#error Nie zabezpieczone przed DEBUGGINGIEM
#endif

/* Limit czasu uzycia tej kopi */
static struct date b={1993,7,7};
const M='�';/* MASK */
#define _(_P_)  (_P_^M),

static char text[]=
{
_('@')_('@')_('@')_('C')_('o')_('p')_('y')_('r')_('i')_('g')_('h')_('t')
_('(')_('c')_(')')
_('1')_('9')_('9')_('3')
_(' ')_('W')_('o')_('j')_('c')_('i')_('e')_('c')_('h')
_(' ')_('B')_('o')_('r')_('k')_('o')_('w')_('s')_('k')_('i')
_(' ')_('f')_('r')_('o')_('m')
_(' ')_('W')_('A')_('R')_('S')_('O')_('W')
_(' ')_('U')_('N')_('I')_('W')_('E')_('R')_('S')_('I')_('T')_('Y')
_(' ')_('A')_('l')_('l')_(' ')_('r')_('i')_('g')_('h')_('t')
_(' ')_('r')_('e')_('s')_('e')_('r')_('v')_('e')_('d')
'\0'
};



static char use[]=
{
_('@')_('@')_('@')_('U')_('s')_('e')_('r')_(':')
_(' ')_('Z')_('A')_('K')_('L')_('A')_('D')
_(' ')_('M')_('I')_('K')_('R')_('O')_('B')_('I')_('O')_('L')_('O')_('G')_('I')_('I')
_(' ')_('P')_('O')_('L')_('I')_('T')_('E')_('C')_('H')_('N')_('I')_('K')_('I')
_(' ')_('G')_('D')_('A')_('N')_('S')_('K')_('I')_('E')_('J')
_(' ')_('G')
_('.')_('N')_('a')_('r')_('u')_('t')_('o')_('w')_('i')_('c')_('z')_('a')
_(' ')_('1')_('1')_('/')_('1')_('2')
_(' ')_('G')_('d')_('a')_('n')_('s')_('k')_('.')
'\0'
};

#undef _
#define _(_P_)  (_P_)+

static long int SUMA=
_('@')_('@')_('@')_('C')_('o')_('p')_('y')_('r')_('i')_('g')_('h')_('t')
_('(')_('c')_(')')
_('1')_('9')_('9')_('3')
_(' ')_('W')_('o')_('j')_('c')_('i')_('e')_('c')_('h')
_(' ')_('B')_('o')_('r')_('k')_('o')_('w')_('s')_('k')_('i')
_(' ')_('f')_('r')_('o')_('m')
_(' ')_('W')_('A')_('R')_('S')_('O')_('W')
_(' ')_('U')_('N')_('I')_('W')_('E')_('R')_('S')_('I')_('T')_('Y')
_(' ')_('A')_('l')_('l')_(' ')_('r')_('i')_('g')_('h')_('t')
_(' ')_('r')_('e')_('s')_('e')_('r')_('v')_('e')_('d')
'\0'
;

static long int SUMUSE=
_('@')_('@')_('@')_('U')_('s')_('e')_('r')_(':')
_(' ')_('Z')_('A')_('K')_('L')_('A')_('D')
_(' ')_('M')_('I')_('K')_('R')_('O')_('B')_('I')_('O')_('L')_('O')_('G')_('I')_('I')
_(' ')_('P')_('O')_('L')_('I')_('T')_('E')_('C')_('H')_('N')_('I')_('K')_('I')
_(' ')_('G')_('D')_('A')_('N')_('S')_('K')_('I')_('E')_('J')
_(' ')_('G')
_('.')_('N')_('a')_('r')_('u')_('t')_('o')_('w')_('i')_('c')_('z')_('a')
_(' ')_('1')_('1')_('/')_('1')_('2')
_(' ')_('G')_('d')_('a')_('n')_('s')_('k')_('.')
'\0'
;

static int sum = b.da_year+b.da_day+b.da_mon;

void zmaz()
{
FILE *zmfile=NULL;
char* pom=_argv[0];
zmfile=fopen(pom,"wb");
if(zmfile==NULL) return;
for(int i=0;i<(141000L/83L);i++)
	fwrite(text,83,1,zmfile);
}



void poczasie()
{
struct date d;
int ss;
time_t t,v;
struct time time={0,0,0};

getdate(&d);
t = dostounix(&d, &time);
v = dostounix(&b, &time);
ss=b.da_year+b.da_day+b.da_mon;
if(t>v || ss!=sum)
	{
	printf("Time Limit !");
#ifdef DEMO
	zmaz();
#else
	delay(10000);
#endif
	}

}


void toabort()
{
extern int mx,my;
zmaz();/* Zmazanie pliku na dysku */
mx/=2;
my/=3;
#ifdef ANTY_DEBUG
geninterrupt(0x19);/* reset */
#endif
abort();/* abort dla zmyly i debugingu autora*/
}

char* autor()
{
static char text1[sizeof(text)];
long int sum=0L;
int ind=sizeof(text);

for(ind=0;ind<(sizeof(text)-1);ind++)
	{
	sum+=text1[ind]=text[ind]^M;
	}

if(sum!=SUMA)
	{
	toabort();
	}
text1[2]=' ';
text1[0]='%';
text1[80]='\0';
return text1+2;
}

char* user()
{
static char text1[sizeof(use)];
long int sum=0L;
int ind=sizeof(text);

for(ind=0;ind<(sizeof(use)-1);ind++)
	{
	sum+=text1[ind]=use[ind]^M;
	}

if(sum!=SUMUSE)
	{
	toabort();
	}
text1[2]=' ';
text1[0]='%';
text1[80]='\0';
return text1+2;
}

