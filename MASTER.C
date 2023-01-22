#include<stdlib.h>

#define P cprintf
#define L gotoxy
#define F for
#define W while
#define E else
#define I if

void chr(x,y,c)
{
L(x,y);
P("%c",c);
}

void box(l,t,r,b,sd)
{
int a;
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

void say(x,y,c)
{
L(x,y);
P("%s",c);
}

void cls(l,t,r,b)
{
window(l,t,r,b);
clrscr();
window(1,1,80,25);
}

void main()
{
int A=1,B,C,D,H,J,K,N,R,T,S[10]={0,0,0,-1,0,0,-1},
Y[10]={0,10,13,13,16,19,19,19},Z[19][10];
randomize();
cls(1,1,80,25);
textattr(112);
say(2,25,"   MASTER MIND 1.02 - Copyright (c) (24/04/1992) by Rizwanullah Jamil (RJ).   ");
textattr(7);
box(1,1,48,24,1);
box(53,1,76,3,1);
box(49,4,58,6,0);
box(64,4,80,6,0);
box(61,7,68,9,1);
box(49,9,80,15,1);
chr(61,9,202);
chr(68,9,202);
box(59,16,70,18,1);
box(49,18,80,24,1);
chr(59,18,202);
chr(70,18,202);
say(55,2,"M A S T E R  M I N D");
say(66,5,"SCORE: +00000");
say(63,8,"HELP");
say(54,10,"*  Means correct line");
say(57,11,"and correct number");
say(54,12,"#  Means incorrect line");
say(57,13,"but currect number");
say(54,14,"Edit Lt/Rt key, Exit Esc");
say(61,17,"MESSAGES");
say(53,19,"For EASIER game `non");
say(53,20,"repeated numbers', Please");
say(53,21,"enter `number of holes'");
say(53,22,"must be less than or");
say(53,23,"equals to `Range + 1'");
say(2,2,"MASTER  MIND - The  object of the MASTER  MIND");
say(2,3,"game is to correctly guess a series of from  1");
say(2,4,"to 10 secret numbers depend upon the number of");
say(2,5,"Holes.  Each number is randomly generated from");
say(2,6,"0 to 9  depend upon the Range.  There are  Two");
say(2,7,"posibilities to play MASTER  MIND game, either");
say(2,8,"you may have no same number in a series, i.e.,");
say(2,9,"non  repeated numbers in EASIER game,  or  you");
say(2,10,"may  have some numbers to be same,  i.e., some");
say(2,11,"of them are repeated in HARDER game.  You will");
say(2,12,"have between  1 and 20  guesses,  i.e., lines,");
say(2,13,"to acomplish secret numbers. After each guess,");
say(2,14,"you will be told the number of correct digits,");
say(2,15,"in right position as `*' and in other position");
say(2,16,"as `#'.  Use these clues to guess the  correct");
say(2,17,"series.  Numbers are entered  through  Numeric");
say(2,18,"keys.  Only Left and Right Aero keys are to be");
say(2,19,"used  for  editing or  entering  the  numbers.");
say(2,20,"Pressing  Escape key  instead of a  number  or");
say(2,21,"pressing  Enter key without entering the whole");
say(2,22,"number will prompt you to continue the game or");
say(2,23,"Exit the game.  Press any key to play game.");
getch();
cls(2,2,47,23);
say(2,2,"RJ");
chr(4,1,209);
box(4,2,4,23,0);
chr(4,24,207);
chr(37,1,209);
box(37,2,37,23,0);
chr(37,24,207);
chr(1,3,199);
box(2,3,47,3,0);
chr(4,3,197);
chr(37,3,197);
chr(48,3,182);
W(A<21)
{
L(2,A+3);
P("%02d",A++);
}
say(5,2,"..A..B..C..D..E..F..G..H..I..J..");
say(38,2,"<<POINTS>>");
box(13,5,28,7,1);
say(15,6,"GAME SETTING");
say(13,9,"1 ... EASIER game");
say(13,10,"2 ... HARDER game ?");
say(13,12,"Enter number of");
say(13,13,"Holes (1 - 10) ?");
say(13,15,"Enter Range from");
say(13,16,"0 to (1 - 9) ?");
say(13,18,"Enter number of");
say(13,19,"Lines (1 - 20) ?");
textattr(112);
F(A=1;A<7;A++)
chr(33+((A%3)?0:1)+((A<7)?0:2),Y[A],32);
A=1;
do
{
L(33+((A%3)?0:1)+((A<7)?0:2),Y[A]);
B=((B=bioskey(0))&255)?(B&255)-48:((B&65280)>>8)+256;
I(B==328&&A>1)
{
B=331;
I(A==3||A==4||A==6)
A--;
}
E
I((B==-35||B==336)&&A<5)
{
B=333;
I(A==2)
A++;
}
I(B==331&&A>1)
A--;
E
I(B==333&&A<6)
A++;
E
I(B>=0&&B<=9&&A<7)
{
P("%d",B);
S[A]=B;
I(A<6)
A++;
}
}
W(B!=-35&&B!=-21);
textattr(7);
J=S[1];
H=S[2];
I(S[3]>-1)
H=H*10+S[3];
R=S[4];
C=S[5];
I(S[6]>-1)
C=C*10+S[6];
I(B>-35||J<1||J>2||H<1||H>10||R<1||(R++)>9||C<1||C>20||(J==1&&R<H))
exit(0);
cls(5,4,36,23);
cls(53,19,77,23);
say(51,5,(J<2)?"EASIER":"HARDER");
T=20*J*H*R+2*J*H*R*(20-C);
F(A=0;A<R;A++)
Y[A]=A;
F(B=0;B<H;B++)
{
K=random(A);
S[B]=Y[K];
I(J<2)
{
A--;
F(D=K;D<A;D++)
Y[D]=Y[D+1];
}
}
N=0;
do
{
L(73,5);
P("%+06d",T);
textattr(112);
F(A=0;A<H;A++)
{
Z[N][A]=-1;
chr(A*3+7,N+4,32);
}
A=0;
do
{
L(A*3+7,N+4);
B=((B=bioskey(0))&255)?(B&255)-48:((B&65280)>>8)+256;
F(K=0;K<H&&B==-38;K++)
chr(60+K,20,S[K]+48);
I(B==331&&A>0)
A--;
E
I(B==333&&A<H-1)
A++;
E
I(B>=0&&B<=9)
{
P("%d",B);
Z[N][A]=B;
I(A<H-1)
A++;
}
}
W(B!=-35&&B!=-21);
textattr(7);
F(A=0;A<H;A++)
chr(A*3+7,N+4,(Z[N][A]<0)?32:Z[N][A]+48);
I(B>-22)
{
say(54,19,"You are pressing the");
say(59,20,"Escape key.\a");
A=13;
}
E
{
F(A=0;A<H;A++)
I(Z[N][A]<0)
B++;
I(H<B+36)
{
say(53,19,"You are not entered the");
say(58,20,"whole number.\a");
A=13;
}
}
I(A>12)
{
say(54,21,"Do you really want to");
say(55,22,"continue this game");
say(56,23,"( Yes / No ) ? ");
I(tolower(getch())=='n')
break;
cls(53,21,75,23);
}
I(B<-34)
{
A=0;
do
{
I(Z[N][A]>R-1)
{
say(50,20,"is/are greater than the range.");
L(61,21);
P("i.e., %d",R-1);
A=10;
}
E
F(B=0;B<A&&J<2;B++)
I(Z[N][A]==Z[N][B])
{
say(51,20,"is/are repeated more times.");
A=10;
}
}
W(++A<H);
F(B=0;B<N&&A<11;B++)
F(A=K=0;K<H;K++)
I(Z[B][K]==Z[N][K])
A=12;
E
A=K=H;
}
E
I(H>B+35)
{
say(50,20,"is/are missing or not entered.");
A=11;
}
I(A>10)
{
I(A==12)
{
say(53,19,"You are entered the whole");
say(53,20,"number again as previous");
say(58,21,"line number");
P(" %02d",B);
}
E
I(A<12)
say(53,19,"Any one or more of them");
say(54,22,"Please enter again !!.\a");
say(52,23,"Press any key to continue.");
getch();
cls(50,19,79,23);
continue;
}
F(A=K=0;K<H;K++)
I(S[K]==Z[N][K])
{
A++;
Y[K]=0;
}
E
Y[K]=2;
F(B=K=0;K<H;K++)
F(D=0;D<H&&Y[K];D++)
I(S[K]==Z[N][D]&&Y[D]>1)
{
B++;
Y[D]=1;
break;
}
F(K=0;K<A;K++)
chr(K+38,N+4,42);
F(K=0;K<B;K++)
chr(A+K+38,N+4,35);
T=T+3*A+2*B-5*(H-A-B)-J*H*R;
I(A==H)
N+=21;
N++;
}
W(N<C);
cls(1,1,80,24);
I(N>21)
{
T=T+3*J*H*R*(C-N+21);
say(20,5,"Congratulations !.\a");
say(20,7,"You WON this game.");
}
E
{
say(26,5,"Sorry !.\a");
say(20,7,"You LOOSE this game.");
}
say(15,10,"The SECRET number is");
F(A=0;A<H;A++)
chr(A+36,10,S[A]+48);
say(15,12,"And your Final Score is ");
P("%+06d",T);
}
