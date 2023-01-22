#include"stdio.h"
#include"graphics.h"
#include"conio.h"
#define P printf
#define S scanf
#define L gotoxy
#define CLS gotoxy(1,1);printf("                                         ");\
	    gotoxy(1,1);
#define HELP L(1,25);P("1Circle2Rectangle3Line4Ellipse5Arc6Bar");
main()
{
int driver,mode,o,x1,y1,x2,y2,radius,end;
char ch;
driver=CGA;
mode=CGAC0;
initgraph(&driver,&mode,"b:");
cleardevice();
HELP
while(1)
{
CLS
P("Option \( 0 - 6 \) 0 - Exit   ");
L(27,1);
S("%d",&o);
if(o==0)
{
restorecrtmode();
exit();
}
if(o>6)
{
cleardevice();
HELP
continue;
}
CLS
P("Enter x-axis ");
S("%d",&x1);
CLS
P("Enter y-axis ");
S("%d",&y1);
switch(o)
{
 case 1:
 CLS
 P("Enter radius ");
 S("%d",&radius);
 circle(x1,y1,radius);
 break;
 case 2:
 CLS
 P("Enter x2-axis ");
 S("%d",&x2);
 CLS
 P("Enter y2-axis ");
 S("%d",&y2);
 rectangle(x1,y1,x2,y2);
 break;
 case 3:
 CLS
 P("Enter x2-axis ");
 S("%d",&x2);
 CLS
 P("Enter y2-axis ");
 S("%d",&y2);
 line(x1,y1,x2,y2);
 break;
 case 4:
 CLS
 P("Enter x radius ");
 S("%d",&x2);
 CLS
 P("Enter y radius ");
 S("%d",&y2);
 CLS
 P("Enter starting angle ");
 S("%d",&radius);
 CLS
 P("Enter ending angle ");
 S("%d",&end);
 ellipse(x1,y1,x2,y2,radius,end);
 break;
 case 5:
 CLS
 P("Enter starting angle 0 - 360 ");
 S("%d",&x2);
 CLS
 P("Enter ending   angle 0 - 360 ");
 S("%d",&y2);
 CLS
 P("Enter radius ");
 S("%d",&radius);
 arc(x1,y1,x2,y2,radius);
 break;
 case 6:
 CLS
 P("Enter x2 axis ");
 S("%d",&x2);
 CLS
 P("Enter y2 axis ");
 S("%d",&y2);
 bar(x1,y1,x2,y2);
}
}
}
