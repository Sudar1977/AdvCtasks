#include <inttypes.h>
#include <stdio.h>


int extractExp(float f);

int main()
{
    float f;
    scanf("%f",&f);
    int res = extractExp(f);
    printf("%d",res);
    return 0;
}


int extractExp(float f)
{
  union
  {
    float f;
    struct
    {
      uint32_t significand: 23;
      uint32_t exponent: 8;
      uint32_t sign: 1;
    } fields;
  } number;

  number.f = f;
  return number.fields.exponent;
}

