/* GRAPHICS.C A programme to draw different shapes */
#include"stdio.h"
#include"graphics.h"
#include"conio.h"
#define P gotoxy(1,24);printf("                    ");gotoxy(1,24);printf
#define I scanf
#define H gotoxy(1,25);\
 printf("ArcBarCircleDrawpolyEllipseFillpolyLineNewRectanglePixelQuit");
#define B break;
main()
{
int x1,y1,x2,y2,r1,r2,poly[10],dr=DETECT,md;
char ch,ans;
initgraph(&dr,&md,"c:\\tc\\bgi");
H
while(1)
{
P("choice");
do
ch=tolower(getch());
while(ch!='a'&&ch!='b'&&ch!='c'&&ch!='d'&&ch!='e'
&&ch!='f'&&ch!='l'&&ch!='n'&&ch!='p'&&ch!='r'&&ch!='q');
gotoxy(78,25);
printf("%c",toupper(ch));
if(ch=='q')
{
closegraph();
exit();
}
if(ch=='n')
{
cleardevice();
H
continue;
}
P("x1-coord ");
I("%3d",&x1);
P("y1-coord ");
I("%3d",&y1);
switch(ch)
{
case'a':
P("start angle ");
I("%3d",&x2);
P("end angle ");
I("%3d",&y2);
P("radius ");
I("%3d",&r1);
arc(x1,y1,x2,y2,r1);
B
case'b':
P("x2-coord ");
I("%3d",&x2);
P("y2-coord ");
I("%3d",&y2);
bar(x1,y1,x2,y2);
B
case'c':
P("radius ");
I("%3d",&r1);
circle(x1,y1,r1);
B
case'd':
P("how many corners ");
I("%3d",&x2);
for(y2=2;y2<=x2;y2++)
{
P("x%d-coord ",y2);
I("%3d",&poly[(y2-1)*2]);
P("y%d-coord ",y2);
I("%3d",&poly[y2*2-1]);
}
P("close it \( Y / N \) ");
ans=tolower(getch());
poly[0]=x1;
poly[1]=y1;
if(ans=='y')
{
poly[y2*2]=x1;
poly[y2*2+1]=y1;
x2++;
}
drawpoly(x2,poly);
B
case'e':
P("start angle ");
I("%3d",&x2);
P("end angle ");
I("%3d",&y2);
P("x-radius ");
I("%3d",&r1);
P("y-radius ");
I("%3d",&r2);
ellipse(x1,y1,x2,y2,r1,r2);
B
case'f':
P("how many corners ");
I("%3d",&x2);
for(y2=2;y2<=x2;y2++)
{
P("x%d-coord ",y2);
I("%3d",&poly[(y2-1)*2]);
P("y%d-coord ",y2);
I("%3d",&poly[y2*2-1]);
}
P("close it \( Y / N \) ");
ans=tolower(getch());
poly[0]=x1;
poly[1]=y1;
if(ans=='y')
{
poly[y2*2]=x1;
poly[y2*2+1]=y1;
x2++;
}
fillpoly(x2,poly);
B
case'l':
P("x2-coord ");
I("%3d",&x2);
P("y2-coord ");
I("%3d",&y2);
line(x1,y1,x2,y2);
B
case'p':
putpixel(x1,y1,15);
B
case'r':
P("x2-coord ");
I("%3d",&x2);
P("y2-coord ");
I("%3d",&y2);
rectangle(x1,y1,x2,y2);
}
}
}
