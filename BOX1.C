# include<stdio.h>
# include<graphics.h>
# define C clrscr();
# define P printf
# define I scanf
# define F for
# define G gotoxy
main()
{
int x1,y1,x2,y2,l;
P("\nEnter upper left  x-axis x1 ");
I("%d",&x1);
P("\nEnter upper left  y-axis y1 ");
I("%d",&y1);
P("\nEnter lower right x-axis x2 ");
I("%d",&x2);
P("\nEnter lower right y-axis y2 ");
I("%d",&y2);
C
F(l=x1;l<=x2;l++)
{
G(l,y1);
P("%c",219);
G(l,y2);
P("%c",219);
}
F(l=y1;l<=y2;l++)
{
G(x1,l);
P("%c",219);
G(x2,l);
P("%c",219);
}
}
