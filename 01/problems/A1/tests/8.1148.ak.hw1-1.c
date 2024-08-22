#include <stdio.h>


char cifer(char, unsigned  int);
int main()
{
  unsigned  int n;
  char ch;
  
  scanf("%u ", &n);

  while('.' != (ch = getchar()))
  {
    putchar(cifer(ch, n));
  }
  putchar('.');
  putchar('\n');
  return 0;
}


char cifer(char ch, unsigned int n)
{
  char base;
  const char range = 'z'-'a' + 1;

  char shift = n % range;// чтобы избежать переполенения

  if(ch >= 'a' && ch <= 'z')
  {
    base = 'a';
  }
  else if(ch >= 'A' && ch <= 'Z')
  {
    base = 'A';
  }
  else
  {
    return ch;
  }
  
  return base + ((ch + shift - base) % range );
}



