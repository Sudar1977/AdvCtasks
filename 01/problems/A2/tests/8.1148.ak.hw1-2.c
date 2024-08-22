#include <stdio.h>
#include <stdint.h>

uint32_t worker(uint32_t , unsigned int );

int main ()
{
  unsigned int k;
  uint32_t n, res;
  
  scanf("%u %u", &n, &k);
  
  res = worker (n, k);
  
  printf("%u\n", res);
  return 0;
}




uint32_t worker (uint32_t n, unsigned int k)
{
  return n>>k | n<<(32-k);
}