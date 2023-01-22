#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#define G gotoxy

void main()
{
int driver=DETECT,mode,font,size,x,y;
char ch[1]={" "},name[200];
clrscr();
G(12,12);
cputs("PLEASE ENTER YOUR MASSAGE :- ");
gets(name);
while(1)
{
clrscr();
G(30,4);
cputs("CHOOSE A FONT");
G(30,6);
cputs("0:EXIT");
G(30,8);
cputs("1:TRIPLEX");
G(30,10);
cputs("2:SMALL");
G(30,12);
cputs("3:SANSSERIF");
G(30,14);
cputs("4:GOTHIC");
G(30,16);
cputs("5:DEFAULT");
G(30,18);
cputs("ENTER FONT 0-5:-");
G(48,18);
scanf("%d",&font);
if(font==0)
exit();
G(30,18);
cputs("ENTER SIZE 1-10:-");
G(50,18);
scanf("%d",&size);
initgraph(&driver,&mode,"c:\\tc\\bgi");
settextstyle(font,VERT_DIR,size);
settextjustify(BOTTOM_TEXT,TOP_TEXT);
outtextxy(0,0,name);
settextstyle(font,HORIZ_DIR,size);
settextjustify(BOTTOM_TEXT,TOP_TEXT);
outtextxy(150,0,name);
x=y=0;
while((ch[0]=getch())!=27&&ch[0]!=13)
{
if(x<1||x>600)
{
y+=5*size;
x=10;
}
outtextxy(x,y,ch);
x+=10*size;
}
if(ch[0]==27)
{
closegraph();
exit();
}
else
restorecrtmode();
}
}
