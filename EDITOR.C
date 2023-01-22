#include<stdio.h>

#define MY 700 /* Maximum number of lines */
#define MX 81  /* Maximum number of characters per line */
#define L gotoxy
#define P printf
#define B break;
#define C case
#define F for
#define W while
#define I if
#define E else
#define M movmem
#define S strcpy
#define IL insline();
#define DL delline();
#define CS clrscr();
#define WN window

unsigned char f[50],s[MY][MX],fn[20]={"edit.txt"};
int X=1,Y=1,H=80,V=25,c,e=0,l[MY]={0},m=0,n=0,x=0,y=0,i=0,p=0;

void prtscr(b)
{
switch(b)
{
C 1:
L(1,2);
IL
P("%.*s",H,&s[--m][n]);
B
C 2:
L(1,2);
DL
m++;
I(m+V-1<p)
{
L(1,V);
P("%.*s",H,&s[m+V-2][n]);
}
B
default:
WN(X,Y+1,X+H-1,Y+V-1);
CS
WN(X,Y,X+H-1,Y+V-1);
F(c=m;c<m+V-1&&c<=p;c++)
{
L(1,c-m+2);
I(n<l[c])
P("%.*s",H,&s[c][n]);
}
}
}

void hlpscr()
{
unsigned char wn[4000];
WN(1,1,80,25);
gettext(1,1,80,25,wn);
CS
P("\n\t\t\tEditor Help Screen  (F1)");
P("\n\t\t\t------------------------\n");
P("\n\t^A   Word Left       ^%c              ^N   Insert a Line",17);
P("\n\t^B   Beg of Doc      ^Home           ^O   Beg of Line     Home");
P("\n\t^C   Page Down       PgDn            ^P   End of Line     End");
P("\n\t^D   Char Right      %c               ^Q   Quit & Save     Esc",16);
P("\n\t^E   Line Up         %c               ^R   Page Up         PgUp",30);
P("\n\t^F   Word Right      ^%c              ^S   Char Left       %c",16,17);
P("\n\t^G   Del Char Right  Del             ^T   Del Word Right");
P("\n\t^H   Del Char Left   BkSpace         ^U   Del Word Left");
P("\n\t^I   Tab Right       Tab             ^V   Insert/Overtype Ins");
P("\n\t     Tab Left        Shift-Tab       ^W   Scroll Line Dn  ^PgDn");
P("\n\t^J   Del to End of Line              ^X   Line Down       %c",31);
P("\n\t^K   Del to Beg      ^BkSpace        ^Y   Delete Line");
P("\n\t^L   Last of Doc     ^End            ^Z   Scroll Line Up  ^PgUp");
P("\n\t^M   Carriage Return Enter           F1   Editor Help Screen");
P("\n\tF2   Save Current File               F3   Load New File");
P("\n\tF4   Find String                     F10  Resize Editor Window");
P("\n\n\t\t\tCreated By Rizwanullah Jamil (RJ).");
P("\n\n\t\t\t\t\t\tPress any key to continue ... ");
bioskey(0);
puttext(1,1,80,25,wn);
WN(X,Y,X+H-1,Y+V-1);
}

void edyn()
{
I(!e)
{
e=1;
L(H-14,1);
P("%c",15);
}
}

void setline(a)
{
I(a<0||a>MY)
return;
y=a;
I(m-y==1)
prtscr(1);
E
I(y-m==V-1)
prtscr(2);
E
I(y<m||y>m+V-2)
{
m=y;
prtscr(0);
}
I(y>p)
{
l[y]=0;
p++;
edyn();
}
}

void moveup()
{
L(1,y-m+2);
DL
F(c=y;c<p;c++)
{
S(&s[c],&s[c+1]);
l[c]=l[c+1];
}
I(p>m+V-2)
{
L(1,V);
I(n<l[m+V-2])
P("%.*s",H,&s[m+V-2][n]);
}
p--;
edyn();
}

void movedn()
{
I(p<MY)
{
P("%*.*s",l[y]-x+1,H,32);
I(y-m<V-2)
{
L(1,y-m+3);
IL
I(x+n<l[y])
P("%.*s",H,&s[y][x+n]);
}
F(c=++p;c>y+1;c--)
{
S(&s[c],&s[c-1]);
l[c]=l[c-1];
}
S(&s[y+1],&s[y][x]);
l[y+1]=l[y]-x;
s[y][x]=0;
l[y]=x;
}
edyn();
}

void locate(int a,int b)
{
if(a<n||a>n+H-1)
{
if(a<n)
n=a;
else
n=a-H+1;
prtscr(0);
}
L(a>n+H?H:a-n+1,b-m+2);
}

main(int argc,char *argv[])
{
FILE *fp;
WN(X,Y,X+H-1,Y+V-1);
CS
textattr(96);
cprintf(" F1 Help. (RJ)%*cWait ",H-19,32);
textattr(7);
I(argc==2)
S(fn,argv[1]);
I((fp=fopen(fn,"rb"))!=NULL)
{
W((c=getc(fp))!=EOF&&p<MY-1)
I(c==13)
{
(void) getc(fp);
s[p][l[p++]]=0;
}
E
s[p][l[p]++]=c;
}
prtscr(0);
W(1)
{
L(H-8,1);
P("X%02d Y%03d",x+1,y+1);
/*
L(15,1);
P("%5u",coreleft());
*/
locate(x,y);
c=((c=bioskey(0))&255)?c&255:((c&0xff00)>>8)+256;
I(c<32||c==127||c>255)
switch(c)
{
C 1:   /* ^A word left */
C 371:
I(x>0)
{
W(--x>0&&s[y][x]==' ');
F(;x>0&&s[y][x-1]!=' ';x--);
}
E
I(y>0)
{
setline(y-1);
x=l[y];
}
B
C 2:   /* ^B beginning of document */
C 375:
setline(0);
x=0;
B
C 3:   /* ^C page down */
C 337:
I(m+V-2<p)
{
m+=V-2;
prtscr(0);
}
setline((y+V-2<p)?y+V-2:p);
x=(x<l[y])?x:l[y];
B
C 4:   /* ^D character right */
C 333:
I(x<l[y])
x++;
E
I(y<p)
{
setline(y+1);
x=0;
}
B
C 5:   /* ^E line up */
C 328:
setline(y-1);
x=(x<l[y])?x:l[y];
B
C 6:   /* ^F word right */
C 372:
I(x<l[y])
{
W(++x<l[y]&&s[y][x-1]!=' ');
F(;x<l[y]&&s[y][x]==' ';x++);
}
E
I(y<p)
{
setline(y+1);
x=0;
}
B
C 7:   /* ^G delete character right */
C 339:
I(x<l[y])
{
P("%.*s ",H-x,&s[y][x+n+1]);
M(&s[y][x+1],&s[y][x],l[y]-x);
l[y]--;
edyn();
}
E
I(y<p)
{
P("%.*s",H-x,&s[++y][n]);
l[y-1]+=l[y];
strcat(&s[y-1],&s[y]);
moveup();
y--;
}
B
C 8:   /* ^H delete character left */
I(x>0)
{
locate(x-1,y);
P("%-*.*s",l[y],H-x+1,&s[y][x+n]);
M(&s[y][x],&s[y][x-1],l[y]-x);
l[y]--;
x--;
edyn();
}
E
I(y>0)
{
setline(y-1);
x=l[y];
l[y]+=l[y+1];
locate(x,y);
P("%.*s",H-x,&s[++y][n]);
strcat(&s[y-1],&s[y]);
moveup();
y--;
}
B
C 9:   /* ^I tab right */
I((x/8)*8+8<=l[y])
x=(x/8)*8+8;
B
C 271: /* Shift Tab tab left */
I(x>0)
x=((x+7)/8)*8-8;
B
C 10:  /* ^J delete to end of line */
I(x<l[y])
{
P("%*.*s",l[y]-x,H-x,32);
l[y]=x;
edyn();
}
B
C 11:  /* ^K delete to beginning of line */
C 127:
I(x>0)
{
locate(0,y);
P("%-*.*s",l[y],H,&s[y][x+n]);
M(&s[y][x],s[y],l[y]-x);
l[y]-=x;
x=0;
edyn();
}
B
C 12:  /* ^L last of document */
C 373:
I(p>m+V-1)
{
m=p-V+2;
prtscr(0);
}
setline(p);
x=l[y];
B
C 13:  /* ^M carriage return */
I(p<MY)
{
I(i)
movedn();
setline(y+1);
x=0;
}
B
C 14:  /* ^N insert a line */
I(p<MY)
movedn();
B
C 15:  /* ^O beginning of line */
C 327:
x=0;
B
C 16:  /* ^P end of line */
C 335:
x=l[y];
B
C 17:  /* ^Q quit and / or save */
C 27:
I(e)
{
L(1,1);
P("%*cWait",H-5,32);
L(1,1);
P("Save it [Y/N] ? ");
W((c=tolower(getch()))!='y'&&c!='n');
I(c=='y')
{
I(strlen(fn)==0)
{
L(1,1);
P("Save File Name : ");
gets(fn);
}
I((fp=fopen(fn,"w"))!=NULL)
F(c=0;c<=p;c++)
{
fputs(s[c],fp);
I(c<p)
putc('\n',fp);
}
}
}
CS
exit(0);
C 18:  /* ^R page up */
C 329:
I(m-V+3>0)
{
m-=V-2;
prtscr(0);
}
setline((y-V+2>0)?y-V+2:0);
x=(x<l[y])?x:l[y];
B
C 19:  /* ^S char left */
C 331:
I(x>0)
x--;
E
I(y>0)
{
setline(y-1);
x=l[y];
}
B
C 20:  /* ^T delete word right */
I(x<l[y])
{
F(c=x+1;c<l[y]&&s[y][c-1]!=' ';c++);
F(;c<l[y]&&s[y][c]==' ';c++);
P("%-*.*s",l[y]-x,H-x,&s[y][c+n]);
M(&s[y][c],&s[y][x],l[y]-c);
l[y]-=c-x;
edyn();
}
B
C 21:  /* ^U delete word left */
I(x>0)
{
F(c=x-1;c>0&&s[y][c]==' ';c--);
F(;c>0&&s[y][c-1]!=' ';c--);
locate(c,y);
P("%-*.*s",l[y]-c,H-c,&s[y][x+n]);
M(&s[y][x],&s[y][c],l[y]-x);
l[y]-=x-c;
x=c;
edyn();
}
B
C 22:  /* ^V insert / overtype */
C 338:
i=1-i;
L(H-12,1);
P("%s",i?"Ins":"   ");
B
C 23:  /* ^W scroll line down */
C 388:
I(m>0)
{
prtscr(1);
setline((m+V-2<y)?y-1:y);
x=(x<l[y])?x:l[y];
}
B
C 24:  /* ^X line down */
C 336:
I(y<p)
setline(y+1);
x=(x<l[y])?x:l[y];
B
C 25:  /* ^Y delete line */
moveup();
x=0;
B
C 26:  /* ^Z scroll line up */
C 374:
I(m<p)
{
prtscr(2);
setline((m>y)?m:y);
x=(x<l[y])?x:l[y];
}
B
C 315: /* F1 help screen */
hlpscr();
B
C 316: /* F2 save file */
I(e)
{
L(1,1);
P("%*cWait",H-5,32);
I(strlen(fn)==0)
{
L(1,1);
P("Save File Name : ");
gets(fn);
L(1,1);
P("%*cWait",H-5,32);
}
I((fp=fopen(fn,"w"))!=NULL)
F(c=0;c<=p;c++)
{
fputs(s[c],fp);
I(c<p)
putc('\n',fp);
}
L(2,1);
P("F1 Help. (RJ)%*s",H-24,i?"Ins":"   ");
e=0;
}
B
C 317: /* F3 load file */
L(1,1);
P("%*cWait",H-5,32);
I(e)
{
L(1,1);
P("Save it [Y/N] ? ");
W((c=tolower(getch()))!='y'&&c!='n');
I(c=='y')
{
I(strlen(fn)==0)
{
L(1,1);
P("Save File Name : ");
gets(fn);
L(1,1);
P("%*cWait",H-5,32);
}
I((fp=fopen(fn,"w"))!=NULL)
F(c=0;c<=p;c++)
{
fputs(s[c],fp);
s[c][0]=l[c]=0;
I(c<p)
putc('\n',fp);
}
}
}
F(c=0;c<=p;c++)
s[c][0]=l[c]=0;
e=m=p=x=y=0;
L(1,1);
P("Load File Name : ");
gets(fn);
L(1,1);
P("%*cWait",H-5,32);
I((fp=fopen(fn,"rb"))!=NULL)
{
W((c=getc(fp))!=EOF&&p<MY-1)
I(c==13)
{
(void) getc(fp);
s[p][l[p++]]=0;
}
E
s[p][l[p]++]=c;
}
prtscr(0);
L(2,1);
P("F1 Help. (RJ)%*s",H-24,i?"Ins":"   ");
B
C 318: /* F4 find string */
{
int u,v=1;
L(1,1);
P("%*cWait",H-5,32);
L(1,1);
P("Find ? ");
scanf("%s",f);
F(u=y;u<=p&&v;u++)
I(strstr(s[u],f)!=NULL)
v=0;
I(v)
F(u=0;u<y&&v;u++)
I(strstr(s[u],f)!=NULL)
v=0;
I(v)
{
L(1,1);
P("%c\a\b ",15);
}
E
{
y=u-1;
F(;v<=l[y]&&u;v++)
I(strnicmp(f,&s[y][v],strlen(f))==0)
u=0;
setline(y);
x=v-1;
}
}
L(1,1);
P(" F1 Help. (RJ)%*s",H-24,i?"Ins":"   ");
B
C 324: /* F10 screen resize */
CS
L(1,1);
P("Enter Top X-axis ");
scanf("%d",&X);
I(X<1)
X=1;
I(X>50)
X=50;
L(1,2);
P("Enter Top Y-axis ");
scanf("%d",&Y);
I(Y<1)
Y=1;
I(Y>22)
Y=22;
L(1,3);
P("Enter Right Character ");
scanf("%d",&H);
I(H<X+29)
H=30;
I(H>80)
H=80;
L(1,4);
P("Enter Bottom Line ");
scanf("%d",&V);
CS
I(V<3)
V=3;
I(V>25)
V=25;
y=(m+V-2>y)?y:m+V-2;
WN(X,Y,X+H-1,Y+V-1);
L(1,1);
textattr(96);
cprintf("%*cWait ",H-5,32);
textattr(7);
L(2,1);
P("F1 Help. (RJ)%*c %s",H-28,e?15:32,i?"Ins":"   ");
prtscr(0);
B
default:
L(1,1);
P("%c\a\b ",15);
}
E
{
P("%c",c);
I(i)
{
P("%.*s",H-x-1,&s[y][x+n]);
memmove(&s[y][x+1],&s[y][x],l[y]-x+1);
}
I((i||x==l[y])&&l[y]<MX-1)
l[y]++;
s[y][x]=c;
I(x<MX-1)
x++;
edyn();
}
s[y][l[y]]=0;
}
}
