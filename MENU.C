#include<conio.h>
#include<stdlib.h>
#include<dos.h>

#define L gotoxy
#define P cprintf
#define S sprintf
#define F for
#define R return
#define W while
#define I if
#define E else
#define C case
#define B break;
#define OMP \
 say(7,11,23,"                    One Moment Please!.                    ");

int a,p,q[12]={0,3,3,6,1,4,6,2,5,0,3,5},r,
chm,chs,xmn,xmx,ymn,ymx,clm,abc,xyz,ndx,pss=1,prx=1,prt=0,
cm[10]={19,8,9,10,11,12,13,15,16,17},cs[10]={20,7,9,10,12,13,15,16,17,18};
char *c,*cmd,*hed,*fld,l[10][55],m[10][55]={
{" 0 ...... To  EXIT   from Library Programme.        "},
{" 1 ...... To ADD NEW records  in  Library File.     "},
{" 2 ...... To  EDIT   records  in  Library File.     "},
{" 3 ...... To REMOVE  records from Library File.     "},
{" 4 ...... To SEARCH  records  in  Library File.     "},
{" 5 ...... To  PRINT  records from Library File.     "},
{" 6 ...... To  INDEX  records  in  Library File.     "},
{" 7 ...... To  go to  Subject Menu.                  "},
{" 8 ...... To  go to  Author/Editor/Translator Menu. "},
{" 9 ...... To  go to  Borrower Menu.                 "}};

struct time ti;
struct date da;

void cursor(cur)
{
union REGS reg;
reg.h.ah=1;
reg.x.cx=cur?0x2000:0x607;
int86(0x10,&reg,&reg);
}

void cls(l,t,r,b)
{
window(l,t,r,b);
clrscr();
window(1,1,80,25);
}

void say(t,x,y,s)
{
textattr(t);
L(x,y);
P("%s",s);
textattr(7);
}

void chr(t,x,y,s)
{
L(x,y);
textattr(t);
P("%c",s);
textattr(7);
}

void box(l,t,r,b,sd)
{
int clr=7;
I(sd>3)
{
clr=0;
sd-=3;
}
I(l==r)
F(a=t;a<=b;a++)
chr(clr,l,a,179+sd*7);
E
I(t==b)
F(a=l;a<=r;a++)
chr(clr,a,t,196+sd*9);
E
{
chr(clr,l,t,218-sd*17);
chr(clr,l,b,192+sd*8);
F(a=l+1;a<r;a++)
{
chr(clr,a,t,196+sd*9);
chr(clr,a,b,196+sd*9);
}
chr(clr,r,t,191-sd*4);
chr(clr,r,b,217-sd*29);
F(a=t+1;a<b;a++)
{
chr(clr,l,a,179+sd*7);
chr(clr,r,a,179+sd*7);
}
}
}

char *cday()
{
p=da.da_year-1;
r=da.da_day+q[da.da_mon-1]+p*1.25-p/100+p/400-p/4000;
I(da.da_mon>2&&(p%4)==0&&(p%100||(p%400)==0)&&p%4000)
r++;
switch(r%7)
{
C 1:
R "Monday";
C 2:
R "Tuesday";
C 3:
R "Wednesday";
C 4:
R "Thursday";
C 5:
R "Friday";
C 6:
R "Saturday";
default:
R "Sunday";
}
}

char *cmon()
{
switch(da.da_mon)
{
C 1:
R "January";
C 2:
R "February";
C 3:
R "March";
C 4:
R "April";
C 5:
R "May";
C 6:
R "June";
C 7:
R "July";
C 8:
R "August";
C 9:
R "September";
C 10:
R "October";
C 11:
R "November";
default:
R "December";
}
}

void clk()
{
gettime(&ti);
L(66,2);
P("%02d:%02d:%02d",ti.ti_hour,ti.ti_min,ti.ti_sec);
}

int tm()
{
unsigned t=0,m=10000;
W(!kbhit()&&++t<m)
clk();
a=(t==m)?27:bioskey(0);
R ((a&255)?(a&255)-48:((a&0xff00)>>8)+256);
}

void xg()
{
say(96,29,8," ");
say(96,50,8,"                    ");
say(96,29,9," ");
say(96,50,9,"                    ");
say(96,20,10,"                                                  ");
say(96,20,11,"                    ");
say(96,50,11,"                    ");
say(96,20,12,"                    ");
say(96,50,12,"                    ");
say(96,25,13,"               ");
say(96,62,13,"  /  /  ");
say(96,20,14,"                                                  ");
say(96,28,15,"    ");
say(96,55,15,"               ");
say(96,28,16,"    ");
say(96,65,16,"     ");
say(96,28,17,"  ");
say(96,62,17,"        ");
say(96,35,18," ");
say(96,69,18," ");
say(96,31,19," ");
say(96,47,19," ");
say(96,69,19," ");
}

void xs(s)
{
int i=6;
p=40-strlen(s)/2;
/*
cls(11,4,69,20);
box(11,6,69,6,1);
*/
cls(15,4,65,5);
while(i<13)
{
clk();
box(i-1,i,81-i,27-i,4);
i++;
box(i-1,i,81-i,27-i,1);
}
while(i>6)
{
clk();
box(i-1,i,81-i,27-i,4);
i--;
box(i-1,i,81-i,27-i,1);
}
say(96,p,5,s);
box(p-2,4,wherex()+1,6,1);
chr(7,wherex()-1,6,202);
chr(7,p-2,6,202);
}

void pw()
{
xs(" P A S S   W O R D S ");
say(7,25,23,"Enter Password :");
say(96,42,23,"          ");
p=0;
do
{
xyz=tm();
chr(96,42+p,23,46);
I(xyz==-21)
{
say(96,42,23,"         ");
q[0]=p=0;
}
I(xyz>16&&xyz<44)
q[p++]=xyz+80;
I(xyz>48&&xyz<76)
q[p++]=xyz+48;
}
W(p<10&&xyz!=-35);
I((q[0]=='r'&&q[1]=='j')
||(q[0]=='m'&&q[1]=='a'&&q[2]=='s'&&q[3]=='t'&&q[4]=='e'&&q[5]=='r')
||(q[0]=='s'&&q[1]=='l'&&q[2]=='a'&&q[3]=='v'&&q[4]=='e'))
pss=0;
E
{
say(7,15,23,"Access Violation !!. Press any key for Main Menu.");
tm();
}
OMP
}

void ys()
{
say(7,11,8,"[A]uthor/[E]ditor   Author/Editor Name");
say(7,11,9,"[A]uthor/[E]ditor   Author/Editor Name");
say(7,11,10,"Title");
say(7,11,11,"Subject1                      Subject2");
say(7,11,12,"Subject3                      Subject4");
say(7,11,13,"Call Number                   Acguisition Date");
say(7,11,14,"Publisher");
say(7,11,15,"Publication Year       Place of Publication");
say(7,11,16,"Number of Pages               Miscellaneous Pages");
say(7,11,17,"Currency                      Price");
say(7,11,18,"Book checked out (Y/N)?       Paperback Edition (Y/N)?");
say(7,11,19,"Bibliography (Y/N)?    Index (Y/N)?   Card Printed (Y/N)?");
xg();
}

void sm()
{
W(1)
{
switch(chm)
{
C 2:
cmd="EDITING";
xs(" E D I T I N G   M E N U ");
B
C 3:
cmd="DELETING";
xs(" D E L E T I N G   M E N U ");
B
C 4:
cmd="SEARCHING";
xs(" S E A R C H I N G   M E N U ");
B
C 5:
cmd="PRINTING";
xs(" P R I N T I N G   M E N U ");
B
default:
cmd="INDEXING";
xs(" I N D E X I N G   M E N U ");
}
S(l[0]," 0 ...... To return you to Main Menu.%*c",strlen(cmd)-4,32);
S(l[1]," 1 ...... %s by Record Number.     ",cmd);
S(l[2]," 2 ...... %s by Call Number.       ",cmd);
S(l[3]," 3 ...... %s by Book Title.        ",cmd);
S(l[4]," 4 ...... %s by Author/Editor One. ",cmd);
S(l[5]," 5 ...... %s by Author/Editor Two. ",cmd);
S(l[6]," 6 ...... %s by Subject One.       ",cmd);
S(l[7]," 7 ...... %s by Subject Two.       ",cmd);
S(l[8]," 8 ...... %s by Subject Three.     ",cmd);
S(l[9]," 9 ...... %s by Subject Four.      ",cmd);
F(a=0;a<10;a++)
say(7,20,cs[a],l[a]);
say(7,20,23,"Please enter your choice as [ 0 - 9 ]");
p=1;
do
{
say(96,20,cs[p],l[p]);
chr(96,58,23,p+48);
chs=tm();
say(7,20,cs[p],l[p]);
switch(chs)
{
C 328:
p=p?p-1:9;
B
C 336:
p=(p<9)?p+1:0;
B
C-35:
chs=p;
B
C-21:
chs=0;
}
}
W(chs<0||chs>9);
OMP
switch(chs)
{
C 1:
hed="RECORD NUMBER";
fld="";
B
C 2:
hed="CALL NUMBER";
fld="callno";
B
C 3:
hed="BOOK TITLE";
fld="title";
B
C 4:
hed="AUTHOR ONE";
fld="author1";
B
C 5:
hed="AUTHOR TWO";
fld="author2";
B
C 6:
hed="SUBJECT ONE";
fld="subject1";
B
C 7:
hed="SUBJECT TWO";
fld="subject2";
B
C 8:
hed="SUBJECT THREE";
fld="subject3";
B
C 9:
hed="SUBJECT FOUR";
fld="subject4";
B
default:
R;
}
S(&c," %s by %s ",cmd,hed);
xs(&c);
I(chm==6)
{
say(7,15,23,"Please Wait !!. I am ");
say(7,36,23,&c);
tm();
OMP
}
ys();
tm();
}
}

void main()
{
cursor(1);
cls(1,1,80,25);
OMP
getdate(&da);
I(da.da_day==1||da.da_day==21||da.da_day==31)
c="st";
E
I(da.da_day==2||da.da_day==22)
c="nd";
E
I(da.da_day==3||da.da_day==23)
c="rd";
E
c="th";
S(&cmd," %s, %s %d%s, %d. ",cday(),cmon(),da.da_day,c,da.da_year);
say(96,7,2,&cmd);
box(5,1,wherex()+1,3,1);
box(64,1,75,3,1);
box(5,6,75,21,1);
box(5,22,75,24,1);
chr(7,34,22,185);
say(96,35,22," MESSAGES ");
chr(7,45,22,204);
say(96,70,24,"(RJ)");
xs(" C O P Y R I G H T ");
say(96,33,9," DEVELOPED BY ");
say(96,27,12," RIZWAN ULLAH JAMIL (RJ) ");
say(96,37,15," FOR ");
say(96,24,18," THE  KHALID  ISHAQUE  LIBRARY ");
say(7,27,23,"Press any key to continue..");
tm();
OMP
W(1)
{
xs(" M A I N   M E N U ");
F(a=0;a<10;a++)
say(7,15,cm[a],m[a]);
say(7,20,23,"Please enter your choice as [ 0 - 9 ]");
p=1;
do
{
say(96,15,cm[p],m[p]);
chr(96,58,23,p+48);
chm=tm();
say(7,15,cm[p],m[p]);
switch(chm)
{
C 328:
p=p?p-1:9;
B
C 336:
p=(p<9)?p+1:0;
B
C-35:
chm=p;
B
C-21:
chm=0;
}
}
W(chm<0||chm>9);
OMP
I(((chm>0&&chm<4)||chm>6)&&pss)
{
pw();
I(pss)
continue;
}
switch(chm)
{
C 0:
xs(" G O O D   B Y E ");
say(96,33,9," DEVELOPED BY ");
say(96,27,12," RIZWAN ULLAH JAMIL (RJ) ");
say(96,37,15," FOR ");
say(96,24,18," THE  KHALID  ISHAQUE  LIBRARY ");
L(1,24);
cursor(0);
exit(0);
C 1:
cmd="ADDING";
xs(" ADD NEW RECORDS ");
ys();
tm();
B
C 7:
C 8:
C 9:
/* mnu(); */
B
default:
sm();
}
}
}
