#include <stdio.h>
#include <stdint.h>

uint32_t worker(uint32_t ,int );
uint32_t slice_bits(uint32_t, int start, int length);

int main ()
{
  int k;
  uint32_t n, res;
  
  scanf("%u %d", &n, &k);
  
  res = worker (n, k);
  
  printf("%u\n", res);
  return 0;
}




uint32_t worker (uint32_t n, int k)
{
  uint32_t max = 0;  // minimal value for unsigned types
  for (int i = 0; i<=32-k ; i++)
  {
    uint32_t cur = slice_bits (n, i, k);
    if(cur > max)
    {
      max = cur;
    }
  }
  return max;
}


uint32_t slice_bits(uint32_t n, int start, int length)
{
  return  (n & (~(uint32_t)0 >> (32-length))<<start ) >> start;
}

