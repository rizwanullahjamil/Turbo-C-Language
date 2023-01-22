main()
{
  char string[100], frame[4];
  int i, j, k = 0, p = 1;

  printf("Enter Int String upto 100====");
  scanf("%s", string);
  printf("\nYou entered %s = %d\n\n", string, strlen(string));

  for(i = 0; i < (strlen(string)); i++)
  {
     for (j = 0; j < 4; j++)
       if(string[i] == frame[j])
         break;
       if (j > 3)
       {
         if (k > 3)
         {
           k = 0;
           p++;
         }
         frame[k++] = string[i];
         printf("%s\n", frame);
       }
  }
  printf("Total Page false occured %d\n\n", p);
}

