#define P printf
#define L gotoxy
#define S scanf
#define RJ clrscr();\
 gotoxy(2,1);printf("***** Date Conversions Programme *****");\
 gotoxy(8,24);printf("Rizwan Ullah Jamil (RJ).");\
 gotoxy(7,25);printf("Copyright (c) (10/04/1990)");
char A[21][21]=
{
{"Sun"},{"Mon"},{"Tues"},{"Wednes"},{"Thurs"},{"Fri"},{"Satur"},
{"--------------------"},
{"January"},{"February"},{"March"},{"April"},{"May"},{"June"},{"July"},
{"August"},{"September"},{"October"},{"November"},{"December"}
},B;
int C;
long D,E,F,G,H,I,J;

void prn_dat()
{
P("\n         %s %ld",A[G+7],H);
if(H==1||H==21||H==31)
P("st");
else
if(H==2||H==22)
P("nd");
else
if(H==3||H==23)
P("rd");
else
P("th");
P(", %ld          ",I);
J=F%7;
P("\n\n         The Day is %sday   ",A[J]);
}
/* end prn_dat() block */

void day_mon()
{
J=31;
if(G==4||G==6||G==9||G==11)
J=30;
if(G==2)
{
J=28;
if((I%4)==0&&(I%100||(I%400)==0)&&I%4000)
J=29;
}
}
/* end day_mon() block */

ent_day()
{
L(16,21);
P(" and");
while(1)
{
L(10,11);
P("Enter \'n\' Days ");
S("%ld",&F);
if(F==0)
return;
L(10,13);
P("<A>fter or <B>efore ");
B=getch();
if(tolower(B)=='b')
{
F=-F;
P("Before");
}
else
P("After ");
L(10,15);
F+=E;
if(F<1||F>3652057)
{
P("%s  \n\n         ----Out of Range----\n\n         %s",A[7],A[7]);
continue;
}
G=F/365.25001;
H=F+G/100-G/400+G/4000;
I=H/365.25001;
H-=I*365.25;
I++;
for(G=1;G<13;G++)
{
day_mon();
if(H<=J)
break;
H-=J;
}
if(G==13)
{
G=1;
I++;
}
P("The Date is %ld/%ld/%ld     \n",H,G,I);
prn_dat();
}
}
/* end int_day() block */

void inp_dat()
{
P("\n\n         DD/MM/YYYY ");
S("%ld/%ld/%ld",&H,&G,&I);
if(H==0&&G==0&&I==0)
{
D=0;
return;
}
if(G>=1&&G<13)
day_mon();
if(G<1||G>12||H<1||H>J||I<1||I>9999)
{
P("\n         %s\n\n         -----Date Error-----",A[7]);
D=-1;
return;
}
D=G;
I--;
F=H+I*365.25-I/100+I/400-I/4000;
I++;
for(G=1;G<D;G++)
{
day_mon();
F+=J;
}
prn_dat();
}
/* end inp_dat() block */

sec_dat()
{
while(1)
{
L(10,11);
P("Enter Second Date as");
inp_dat();
if(D==0)
return;
L(10,19);
if(D<0)
P("%s",A[7]);
else
if(E==F)
P("---No  Difference---");
else
P("Difference is %ld Day",(E>F)?E-F:F-E);
if(((E>F)?E-F:F-E)>1)
P("s");
P("       ");
}
}
/* end sec-dat() block */

fst_dat()
{
while(1)
{
RJ
L(10,21);
P("Type 0/0/0 CR to Go");
L(11,22);
P("Back to Main Menu");
do
{
L(10,3);
P("Enter First Date as");
inp_dat();
if(D==0)
return;
}
while(C<2||D<0);
L(19,22);
P("First Date");
E=F;
if(C<3)
sec_dat();
else
ent_day();
}
}
/* end fst_dat() block */

main()
{
textmode(1); /* 1=C40 0=BW40 */
while(1)
{
RJ
L(15,4);
P("----------");
L(15,5);
P("Main  Menu");
L(15,6);
P("----------");
L(10,8);
P("1> Knowing Week Days");
L(10,10);
P("2> Knowing Difference");
L(13,11);
P("Between Two Dates");
L(10,13);
P("3> Knowing Date After");
L(13,14);
P("or Before \'n\' Days");
L(10,16);
P("4> End Date Programme");
L(8,18);
P("Enter your Choice as 1-4 ");
do
C=getch()-48;
while(C<1||C>4);
if(C>3)
{
textmode(3); /* 3=C80 2=BW80 */
clrscr();
exit();
}
fst_dat();
}
}
/* end main() block */
