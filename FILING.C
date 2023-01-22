# include<stdio.h>
# include<string.h>
main()
{
char ch={' '};
FILE *fp;
while(1)
{
clrscr();
puts("\n\t\tThis program making a file");
puts("\t\t1: writing file");
puts("\t\t2: reading file");
puts("\t\t3: exit");
while(ch!='1'&&ch!='2'&&ch!='3')
ch=getch();
switch(ch)
{
case '1':
puts("\n\tReady for writing,then start\n");
puts("\n\tBecarefull the Esc is for exit\n");
if(fp=fopen("datafile.dat","w")==NULL)
{
perror("\tThe Error is ");
exit();
}
while((ch=getche())!=27)
putc(ch,fp);
fclose(fp);
break;
case '2':
if(fp=fopen("datafile.dat","r")==NULL)
{
perror("\tThe error is ");
exit();
}
while((ch=getc(fp))!=EOF)
putchar(ch);
fclose(fp);
break;
case '3':
exit();
}
ch=getche();
}
}
