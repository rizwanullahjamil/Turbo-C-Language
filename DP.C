#include<conio.h>
#include<stdlib.h>
#include<dos.h>

#define L gotoxy
#define P cprintf
#define S strcpy
#define F for
#define R return
#define W while
#define I if
#define E else
#define C case
#define B break;

int a,c,v,w=60,x,y[8]={4,10,23,32,41,50,62,71},z;
char l[9][40],ch[8]={"ltjprfcq"},s[3];
struct time ti;
struct date da;

cursor(cur)
{
union REGS reg;
reg.h.ah=1;
reg.x.cx=cur?0x2000:0x607;
int86(0x10,&reg,&reg);
}

cls(l,t,r,b)
{
window(l,t,r,b);
clrscr();
window(1,1,80,25);
}

say(t,x,y,s)
{
textattr(t);
L(x,y);
P("%s",s);
textattr(7);
}

chr(x,y,s)
{
L(x,y);
P("%c",s);
}

box(l,t,r,b,sd)
{
I(l==r)
F(a=t;a<=b;a++)
chr(l,a,179+sd*7);
E
I(t==b)
F(a=l;a<=r;a++)
chr(a,t,196+sd*9);
E
{
chr(l,t,218-sd*17);
chr(l,b,192+sd*8);
F(a=l+1;a<r;a++)
{
chr(a,t,196+sd*9);
chr(a,b,196+sd*9);
}
chr(r,t,191-sd*4);
chr(r,b,217-sd*29);
F(a=t+1;a<b;a++)
{
chr(l,a,179+sd*7);
chr(r,a,179+sd*7);
}
}
}

char *cday()
{
int p=da.da_year-1,q[12]={0,3,3,6,1,4,6,2,5,0,3,5},
r=da.da_day+q[da.da_mon-1]+p*1.25-p/100+p/400-p/4000;
I(da.da_mon>2&&p==(p/4)*4&&(p%100||p==(p/400)*400)&&p%4000)
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

help(int h)
{
int wx=wherex(),wy=wherey(),win[2000];
bioskey(0);
gettext(10,5,70,22,win);
box(10,5,70,22,1);
cls(11,6,69,21);
L(15,13);
P("%d Help not available. Press any key to continue.",h);
do
{
gettime(&ti);
L(72,1);
P("%02d:%02d:%02d",ti.ti_hour,ti.ti_min,ti.ti_sec);
}
W(!kbhit());
bioskey(0);
puttext(10,5,70,22,win);
L(wx,wy);
}

tm(int hlp)
{
do
{
gettime(&ti);
L(72,1);
P("%02d:%02d:%02d",ti.ti_hour,ti.ti_min,ti.ti_sec);
}
W(!kbhit());
I((bioskey(1)>>8)==59)
help(hlp);
}

ssm()
{
c=0;
I(w<2)
{
S(l[0]," 1 ... Aging for all Customers ");
S(l[1]," 2 ... Aging by Customer Code  ");
S(l[2]," 3 ... Customer List           ");
chr(44,7,32);
}
E
{
S(l[0]," 1 ... Aging for all Vendors ");
S(l[1]," 2 ... Aging by Vendor Code  ");
S(l[2]," 3 ... Vendor List           ");
chr(44,10,32);
}
chr(44,8,32);
chr(44,9,32);
box(43,w+5,strlen(l[0])+46,w+9,1);
F(a=0;a<3;a++)
say(7,45,a+w+6,l[a]);
do
{
say(112,45,c+w+6,l[c]);
tm(c+52+w*3);
v=((v=bioskey(0))&0xff)?(v&0xff)-48:((v&0xff00)>>8)+256;
say(7,45,c+w+6,l[c]);
switch(v)
{
C 328:
c=c?c-1:2;
B
C 336:
c=(c<2)?c+1:0;
B
C-35:
v=c+1;
B
C 331:
C 333:
C-21:
cls(43,w+5,strlen(l[0])+46,w+9);
R;
}
}
W(v<1||v>3);
say(112,45,v+w+5,l[v-1]);
}

sm()
{
int d=y[c]+2;
do
{
c=(v<0||v>3)?w-1:0;
v=0;
z=3;
switch(x)
{
C'l':
z=5;
S(l[0]," 1 ... Chart of Accounting ");
S(l[1]," 2 ... Customers           ");
S(l[2]," 3 ... Vendors             ");
S(l[3]," 4 ... Products            ");
S(l[4]," 5 ... Raw Materials       ");
S(l[5]," 6 ... Messages            ");
B
C't':
S(l[0]," 1 ... General Ledger      ");
S(l[1]," 2 ... Accounts Receivable ");
S(l[2]," 3 ... Accounts Payable    ");
S(l[3]," 4 ... Purchasing          ");
B
C'j':
z=2;
S(l[0]," 1 ... Sales Journal       ");
S(l[1]," 2 ... Purchase Journal    ");
S(l[2]," 3 ... Cash / Bank Journal ");
B
C'p':
z=5;
S(l[0]," 1 ... General Ledger Transaction      ");
S(l[1]," 2 ... Accounts Receivable Transaction ");
S(l[2]," 3 ... Accounts Payable Transaction    ");
S(l[3]," 4 ... Sales Journal                   ");
S(l[4]," 5 ... Purchase Journal                ");
S(l[5]," 6 ... Cash / Bank Journal             ");
B
C'r':
z=4;
S(l[0]," 1 ... Accounts Receivable ");
S(l[1]," 2 ... Accounts Payable    ");
S(l[2]," 3 ... Quotation Letter    ");
S(l[3]," 4 ... Invoice             ");
S(l[4]," 5 ... Inventory           ");
B
C'f':
d=35;
S(l[0]," 1 ... Chart of Accounts ");
S(l[1]," 2 ... Trial Balance     ");
S(l[2]," 3 ... Balance Sheet     ");
S(l[3]," 4 ... Income Statement  ");
B
C'c':
d=41;
S(l[0]," 1 ... Enquiry              ");
S(l[1]," 2 ... Cost Estimate        ");
S(l[2]," 3 ... Purchase Information ");
S(l[3]," 4 ... Delivery Challan     ");
B
default:
z=1;
d=56;
S(l[0]," 1 ... Yes Exit    ");
S(l[1]," 2 ... No Continue ");
}
box(d-2,4,d+strlen(l[0])+1,z+6,1);
F(a=0;a<=z;a++)
say(7,d,a+5,l[a]);
do
{
say(112,d,c+5,l[c]);
F(a=0;a<7&&x!=ch[a];a++);
tm(c+8+a*6);
w=((w=bioskey(0))&0xff)?(w&0xff)-48:((w&0xff00)>>8)+256;
say(7,d,c+5,l[c]);
switch(w)
{
C 328:
c=c?c-1:z;
B
C 336:
c=(c<z)?c+1:0;
B
C-35:
w=c+1;
B
C 60: /* l */
C 28: /* L */
C 68: /* t */
C 36: /* T */
C 58: /* j */
C 26: /* J */
C 64: /* p */
C 32: /* P */
C 66: /* r */
C 34: /* R */
C 54: /* f */
C 19: /* F */
C 51: /* c */
C 22: /* C */
C 65: /* q */
C 33: /* Q */
w=tolower(w+48);
C 331:
C 333:
C-21:
box(d-2,4,d+strlen(l[0])+1,4,0);
cls(d-2,5,d+strlen(l[0])+1,z+6);
R;
}
}
W(w<1||w>z+1);
say(112,d,w+4,l[w-1]);
I(x=='q'&&w<2)
{
cursor(0);
exit(0);
}
I(x=='r'&&w<3)
{
box(d-2,4,d+strlen(l[0])+1,z+6,0);
ssm();
}
}
W(v<0||v>3);
}

main()
{
cursor(1);
cls(1,1,80,1);
getdate(&da);
I(da.da_day==1||da.da_day==21||da.da_day==31)
S(s,"st");
E
I(da.da_day==2||da.da_day==22)
S(s,"nd");
E
I(da.da_day==3||da.da_day==23)
S(s,"rd");
E
S(s,"th");
L(1,1);
P("%s, %s %d%s, %d.",cday(),cmon(),da.da_day,s,da.da_year);
say(240,33,1," DURA PACK ");
W(1)
{
cls(1,2,80,25);
box(1,2,79,4,0);
say(7,5,3,
 "fiLe  Transaction  Journal  Posting  Reports  Financials  Costing  Quit");
do
{
S(l[0]," fiLe ");
S(l[1]," Transaction ");
S(l[2]," Journal ");
S(l[3]," Posting ");
S(l[4]," Reports ");
S(l[5]," Financials ");
S(l[6]," Costing ");
S(l[7]," Quit ");
F(c=7;c>0&&ch[c]!=x;c--);
do
{
I(w==331||w==333||strchr(ch,w)!=NULL)
{
say(7,y[c],3,l[c]);
I(w==331)
c=c?c-1:7;
E
I(w==333)
c=(c<7)?c+1:0;
E
F(c=0;c<7&&ch[c]!=w;c++);
x=13;
}
E
{
say(112,y[c],3,l[c]);
tm(c);
x=((x=bioskey(0))&0xff)?tolower(x&0xff):((x&0xff00)>>8)+256;
say(7,y[c],3,l[c]);
}
switch(x)
{
C 331:
c=c?c-1:7;
B
C 333:
c=(c<7)?c+1:0;
B
C 336:
C 13:
x=ch[c];
B
C 27:
x='q';
}
}
W(!strchr(ch,x));
c=-1;
W(ch[++c]!=x&&c<7);
say(112,y[c],3,l[c]);
sm();
}
W(w==-21||w==331||w==333||strchr(ch,w)!=NULL);
cursor(0);
L(1,24);
P("%c %d %d",x,w,v);
/* calc(); */
sleep(1);
cursor(1);
}
}
