main()
{
int ivar,*iptr;
iptr=&ivar;
*iptr=421;
printf("\nLocation of ivar : %p",&ivar);
printf("\nContents of ivar : %d",ivar);
printf("\nContents of iptr : %p",iptr);
printf("\nValue pointed to : %d",*iptr);
}
