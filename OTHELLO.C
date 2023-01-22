#include<stdlib.h>

#define K (bioskey(0)&255)-48;
#define L gotoxy
#define P printf
#define F for
#define B break;
#define C case
#define I if
#define W while
#define E exit(0);

int a=2,b=2,c=0,e,f,g,h,i,j,k,l,m[8]={9,10,11,1,-9,-10,-11,-1},
y[8]={0,0,0,0,0,0,0,0},z[100];

void rj(n)
{
z[n]=c;
L((n/10)*7+2,(n%10)*2+2);
P("%c%c%c%c%c%c",176+c*43,176+c*43,176+c*43,176+c*43,176+c*43,176+c*43);
delay(300);
}

void RJ(d)
{
I(d)
rj(j);
F(e=0;e<8;e++)
{
switch(e)
{
C 0:
l=j%10+81+j/10;
I(l<90)
l=(l%10-1)*10;
B
C 1:
l=j%10+90;
B
C 2:
l=j%10+99-j/10;
I(l>99)
l-=(l-99)*11;
B
C 3:
l=(j/10)*10+9;
B
C 4:
l=j%10+j/10;
I(l>9)
l=(l-9)*10+9;
B
C 5:
l=j%10;
B
C 6:
l=j%10-j/10;
I(l<0)
l*=-10;
B
C 7:
l=(j/10)*10;
}
f=j;
W(f!=l&&z[f+=m[e]]==1-c)
I(d&&y[e])
rj(f);
y[e]=0;
I(z[f]==c)
{
h+=(f-j)/m[e]-1;
y[e]=1;
}
}
}

void RUJ()
{
k=-1;
F(i=j=0;j<100;j++)
{
h=0;
I(z[j]==2)
RJ(0);
I(h>i||(h>0&&h==i&&random(2)<1))
{
i=h;
k=j;
}
}
h=i;
j=k;
}

main()
{
clrscr();
randomize();
L(8,25);
P("OTHELLO - Copyright (c) (05/02/1991) by Rizwanullah Jamil (RJ).");
L(1,1);
P("\nThe object of the  OTHELLO  game is to occupy the most squares at the");
P("\nend of the game.");
P("\nThe  game proceeds by occupying the squares in turn which  cause  the");
P("\nopponent's squares to be flipped.  Opponent's squares are flipped  if");
P("\nthey are in a direct line <vertical, horizontal or diagonals> between");
P("\na square of your colour and the square you just placed.\n");
P("\n\tEither 0, 1 or 2 players can play OTHELLO game.");
P("\n\tWith 0 player, computer plays itself.");
P("\n\tWith 1 player, computer plays against you.");
P("\n\tWith 2 players, you can play against another person.\n");
P("\nMoves are entered in response to your entry.  Your move must cause at");
P("\nleast 1 of your opponent's square to be flipped.  If no moves for you");
P("\nthen computer will never ask for your move.  If your move is invalid,");
P("\nthen  the computer will BEEP and respond 'Bad Move !!', and will  ask");
P("\nyou  for  your  move again.  If you have a move that  will  cause  an");
P("\nopponent's squares to be flipped then you must move.");
P("\nIf you have type a wrong number, press Esc key to cancel it and  then");
P("\ntype the correct number of square again.  Pressing Space Bar  instead");
P("\nof a number of square will EXIT and return you to DOS.");
P("\n\t\tType 0, 1 or 2 players to play OTHELLO game ");
g=K
I(g<0||g>2)
E
I(g)
{
P("%d\n\t\t%c, Would you like to move first [Y/N] ",g,176);
h=K
I(h==41||h==73)
c=1;
}
clrscr();
P("%c",201);
F(e=0;e<9;e++)
P("%c%c%c%c%c%c%c",205,205,205,205,205,205,203);
P("%c%c%c%c%c%c%c\n",205,205,205,205,205,205,187);
F(e=0;e<9;e++)
{
F(f=0;f<10;f++)
P("%c      ",186);
P("%c\n%c",186,204);
F(f=0;f<9;f++)
P("%c%c%c%c%c%c%c",205,205,205,205,205,205,206);
P("%c%c%c%c%c%c%c\n",205,205,205,205,205,205,185);
}
F(e=0;e<10;e++)
P("%c      ",186);
P("%c\n%c",186,200);
F(e=0;e<9;e++)
P("%c%c%c%c%c%c%c",205,205,205,205,205,205,202);
P("%c%c%c%c%c%c%c",205,205,205,205,205,205,188);
F(e=0;e<100;e++)
{
L((e/10)*7+4,(e%10)*2+2);
P("%02d",e);
z[e]=2;
}
L(8,25);
P("OTHELLO - Copyright (c) (05/02/1991) by Rizwanullah Jamil (RJ).");
rj(45);
rj(54);
c=1-c;
rj(44);
rj(55);
L(44,24);
P("Help: Escape  Exit  Score:");
W(1)
{
L(71,24);
P("%c=%02d %c=%02d",219,a,176,b);
I(bioskey(kbhit()?0:1)==283&&g==0)
E
RUJ();
I(j<0)
{
L(53,22+c);
P("Hint:\a Can't Move           ");
c=1-c;
RUJ();
I(j<0)
{
L(10,24);
P("No moves are possible at all !!!.\a OTHELLO terminated");
E
}
}
I(g>c)
{
L(53,22+c);
P("Hint: %02d has max flips = %02d",j,i);
L(1,22+c);
P("%c, Enter Your move (00 to 99)",176+c*43);
do
{
j=-1;
L(50,24);
P("Escape  Exit");
L(32,22+c);
P("  \b\b");
do
f=K
W((f<0||f>9)&&f!=-21);
L(50,24);
I(f<0)
E
P("Bksp  Cancel");
L(32,22+c);
P("%d",f);
j=f;
f=-1;
W((f<0||f>9)&&f!=-35&&f!=-40)
f=K
I(f>-1&&f<10)
{
P("%d",f);
j=j*10+f;
}
W(f!=-35&&f!=-40)
f=K
}
W(f!=-35);
L(50,24);
P("            ");
}
else
{
L(1,22+c);
P("%c, %s's move is %02d",176+c*43,(g<1&&c<1)?"COMPUTER":"computer",j);
}
h=0;
I(z[j]==2)
RJ(0);
L(40,22+c);
I(h)
{
P("             %02d - flips.                ",h);
I(c)
{
a+=h+1;
b-=h;
}
else
{
a-=h;
b+=h+1;
}
RJ(1);
c=1-c;
}
else
P("Bad Move\a !!");
}
}
