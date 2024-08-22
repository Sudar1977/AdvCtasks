#include <stdio.h>

int main ()
{
  unsigned int n, k, res=0;
  
  scanf("%u", &n);
  
  for(;n;n--)
  {
    scanf("%u", &k);
    res ^= k;
  }
  
  printf("%u\n", res);
  return 0;
}


