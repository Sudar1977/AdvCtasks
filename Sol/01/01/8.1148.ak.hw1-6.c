#include <stdio.h>
#include <stdint.h>

uint32_t worker(uint32_t  );

int main ()
{
  uint32_t n, res;
  
  scanf("%u", &n);
  
  res = worker (n);
  
  printf("%u\n", res);
  return 0;
}




uint32_t worker (uint32_t n)
{
  return  (~(n>>24))<<24  | (n & (~(uint32_t)0) >>8);
}

