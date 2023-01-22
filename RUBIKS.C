#define P printf
#define F for
#define L gotoxy
#define C case
#define A putch

int e=1,r[6][3][3],s[3],i,j,k,z=0;

void cdijop(l,m)
{
j=r[m][0][0];
k=r[m][0][1];
if(l)
{
r[m][0][0]=r[m][2][0];
r[m][0][1]=r[m][1][0];
r[m][2][0]=r[m][2][2];
r[m][1][0]=r[m][2][1];
r[m][2][2]=r[m][0][2];
r[m][2][1]=r[m][1][2];
r[m][0][2]=j;
r[m][1][2]=k;
}
else
{
r[m][0][0]=r[m][0][2];
r[m][0][1]=r[m][1][2];
r[m][0][2]=r[m][2][2];
r[m][1][2]=r[m][2][1];
r[m][2][2]=r[m][2][0];
r[m][2][1]=r[m][1][0];
r[m][2][0]=j;
r[m][1][0]=k;
}
}

void abcdef(l,m)
{
F(i=0;i<3;i++)
s[i]=r[0][m][i];
if(l)
{
F(i=0;i<3;i++)
s[i]=r[0][m][i];
F(i=0;i<3;i++)
r[0][m][i]=r[1][m][2-i];
F(i=0;i<3;i++)
r[1][m][i]=r[2][m][i];
F(i=0;i<3;i++)
r[2][m][i]=r[4][m][2-i];
F(i=0;i<3;i++)
r[4][m][i]=s[i];
}
else
{
F(i=0;i<3;i++)
r[0][m][i]=r[4][m][i];
F(i=0;i<3;i++)
r[4][m][i]=r[2][m][2-i];
F(i=0;i<3;i++)
r[2][m][i]=r[1][m][i];
F(i=0;i<3;i++)
r[1][m][i]=s[2-i];
}
}

void ghijkl(l,m)
{
F(i=0;i<3;i++)
s[i]=r[1][i][m];
if(l)
{
F(i=0;i<3;i++)
r[1][i][m]=r[5][2-i][m];
F(i=0;i<3;i++)
r[5][i][m]=r[4][i][m];
F(i=0;i<3;i++)
r[4][i][m]=r[3][2-i][m];
F(i=0;i<3;i++)
r[3][i][m]=s[i];
}
else
{
F(i=0;i<3;i++)
r[1][i][m]=r[3][i][m];
F(i=0;i<3;i++)
r[3][i][m]=r[4][2-i][m];
F(i=0;i<3;i++)
r[4][i][m]=r[5][i][m];
F(i=0;i<3;i++)
r[5][i][m]=s[2-i];
}
}

void mnopqr(l,m)
{
F(i=0;i<3;i++)
s[i]=r[0][i][m];
if(l)
{
F(i=0;i<3;i++)
r[0][i][m]=r[3][2-m][2-i];
F(i=0;i<3;i++)
r[3][2-m][i]=r[2][i][m];
F(i=0;i<3;i++)
r[2][i][m]=r[5][2-m][2-i];
F(i=0;i<3;i++)
r[5][2-m][i]=s[i];
}
else
{
F(i=0;i<3;i++)
r[0][i][m]=r[5][2-m][i];
F(i=0;i<3;i++)
r[5][2-m][i]=r[2][2-i][m];
F(i=0;i<3;i++)
r[2][i][m]=r[3][2-m][i];
F(i=0;i<3;i++)
r[3][2-m][i]=s[2-i];
}
}

main()
{
char c=97,l[6][7]={"Left","Front","Right","Top","Rear","Bottom"};
clrscr();
F(i=0;i<6;i++)
{
L((i%3)*30+1,(i/3)*9+1);
A(201);
F(j=0;j<2;j++)
P("%c%c%c%c%c%c",205,205,205,205,205,203);
P("%c%c%c%c%c%c",205,205,205,205,205,187);
F(j=0;j<2;j++)
{
L((i%3)*30+1,(i/3)*9+j*2+2);
A(186);
F(k=0;k<3;k++)
P("     %c",186);
L((i%3)*30+1,(i/3)*9+j*2+3);
A(204);
F(k=0;k<2;k++)
P("%c%c%c%c%c%c",205,205,205,205,205,206);
P("%c%c%c%c%c%c",205,205,205,205,205,185);
}
L((i%3)*30+1,(i/3)*9+6);
A(186);
F(j=0;j<3;j++)
P("     %c",186);
L((i%3)*30+1,(i/3)*9+7);
A(200);
F(j=0;j<2;j++)
P("%c%c%c%c%c%c",205,205,205,205,205,202);
P("%c%c%c%c%c%c",205,205,205,205,205,188);
L((i%3)*30+8,(i/3)*9+8);
P("%s",l[i]);
}
L(1,19);
P("A - First Row Right,   G - First Column Up,     M - Left First Column Up\n");
P("B - First Row Left,    H - First Column Down,   N - Left First Column Down\n");
P("C - Second Row Right,  I - Second Column Up,    O - Left Second Column Up\n");
P("D - Second Row Left,   J - Second Column Down,  P - Left Second Column Down\n");
P("E - Third Row Right,   K - Third Column Up,     Q - Left Third Column Up\n");
P("F - Third Row Left,    L - Third Column Down,   R - Left Third Column Down\n");
P("Total Moves :-");
while(1)
{
if(c>96&&c<115)
{
L(16,25);
P("%03d",z++);
F(i=0;i<6;i++)
F(j=0;j<3;j++)
F(k=0;k<3;k++)
{
if(e)
r[i][j][k]=i*100+j*10+k;
L((i%3)*30+k*6+3,(i/3)*9+j*2+2);
P("%03d",r[i][j][k]);
delay(99);
}
}
e=0;
L(20,25);
P("Enter your move [A to R, S - New, X - Exit ]  \b");
c=tolower(getche());
switch(c)
{
C'a':
abcdef(0,0);
cdijop(0,3);
break;
C'b':
abcdef(1,0);
cdijop(1,3);
break;
C'c':
abcdef(0,1);
break;
C'd':
abcdef(1,1);
break;
C'e':
abcdef(0,2);
cdijop(0,5);
break;
C'f':
abcdef(1,2);
cdijop(1,5);
break;
C'g':
ghijkl(1,0);
cdijop(1,0);
break;
C'h':
ghijkl(0,0);
cdijop(0,0);
break;
C'i':
ghijkl(1,1);
break;
C'j':
ghijkl(0,1);
break;
C'k':
ghijkl(1,2);
cdijop(1,2);
break;
C'l':
ghijkl(0,2);
cdijop(0,2);
break;
C'm':
mnopqr(0,0);
cdijop(1,1);
break;
C'n':
mnopqr(1,0);
cdijop(0,1);
break;
C'o':
mnopqr(0,1);
break;
C'p':
mnopqr(1,1);
break;
C'q':
mnopqr(0,2);
cdijop(1,4);
break;
C'r':
mnopqr(1,2);
cdijop(0,4);
break;
C's':
if(z>1)
{
c=97;
e=1;
z=0;
}
break;
C'x':
exit();
default:
A(7);
}
}
}
