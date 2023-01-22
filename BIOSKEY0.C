main()
{
int lo,hi,key;
clrscr();
do
{
key=bioskey(0);
lo=key&0xff;
hi=((key&0xff00)>>8)+256;
printf("key = %05d\tlow = %03d\thigh = %03d\tchar = %c\n",
 key,lo,hi,(lo==0)?7:lo);
}
while(lo!=27);
}
