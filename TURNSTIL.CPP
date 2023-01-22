#include <iostream.h>
#include <conio.h>
#include <string.h>

void main(void)
{
  char c, t[26];
  long i, j = 0, z = 0, a[26];
  clrscr();
  cout << "TURNSTILE TAKINGS MANAGEMENT\n";
  do
  {
    cout << "ENTER TURNSTILE LETTER: ";
    cin >> c;
    if (c < 'A' || c > 'Z')
    {
      cout << "INVALID TURNSTILE LETTER. PLEASE RE-ENTER AGAIN\n";
      c = ' ';
    }
    else
    {
      for (i = 0; i < z; i++)
	if (t[i] == c)
	  i=99;
      if (i == 100)
	cout << "DATA FOR A GIVEN TURNSTILE HAS ALREADY BEEN ENTERED.\n";
      else
      {
	cout << "Enter takings in the range 1 - 500 (terminates by entering 0).\n";
	strcpy(&t[z], &c);
	a[z] = 0;
	do
	{
	  cout << "ENTER TAKING: ";
	  cin >> i;
	  if (i < 0 || i > 500)
	    cout << "INVALID NUMBER. PLEASE RE-ENTER AGAIN.\n";
	  else
	    a[z] += i;
	}
	while (i != 0);
	cout << "TURNSTILE " << t[z] << " TOTAL INCOME " << a[z] << "\n";
	z++;
      }
    }
    if (c != ' ')
    {
      do
      {
	cout << "ANY MORE TURNSTILES (Y/N) ? ";
	cin >> c;
      }
      while (c != 'Y' && c != 'N');
    }
  }
  while (c == 'Y' || c == ' ');
  for (i = 0; i < z; i++)
    j += a[i];
  cout << "\n----------------------------------";
  cout << "\nTOTAL INCOME FROM ALL TURNSTILES: " << j;
  cout << "\nAVERAGE TURNSTILE INCOME: " << j / z;
  cout << "\nTURNSTILE WITH HIGHEST TOTAL INCOME:";
  j = 0;
  for (i = 0; i < z; i++)
    if (a[i] > j)
      j = a[i];
  for (i = 0; i < z; i++)
    if (a[i] == j)
      cout << " " << t[i];
  cout << "\n----------------------------------";
  cout << "\nPress any key to exit.";
  getch();
}