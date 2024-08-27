#include <stdio.h>
#include <stdint.h>
#include <string.h>

void setbit(uint8_t *, int);
int count_bits(uint8_t *, size_t);

enum{maxN = 100};

int main(int argc, char ** argv)
{
    uint8_t res[1000/8 + 2] = {0};
    char string[maxN+2];
    int l = 0;
    int n;
    scanf("%101s", string);

    l = strlen(string);

    for (int a2 = 0; a2 < l-2 ; a2++)
    {
        for (int a1 = a2+1; a1 < l-1; a1++ )
        {
            for (int a0 = a1+1; a0 < l; a0++ )
            {
                 n = (string[a0] - '0') + 10*(string[a1]- '0') + 100*(string[a2] - '0');
#ifdef DEBUG
                  printf("a2 a1 a0 = %d  %d %d; chs = %c%c%c; n = %d\n", a2,a1,a0, string[a2], string[a1], string[a0], n);
#endif
                 if(n>=100)
                 {
                    setbit(res, n);
                 }
            }
        }
    }

    printf("%d\n", count_bits(res, 1000/8 + 2));

    return 0;
}


void setbit (uint8_t *arr, int pos)
{
    int byte = pos/8;
    int bit  = pos - byte*8;
     arr[byte] |= (uint8_t)1<<bit;

}

int count_bits(uint8_t *arr, size_t l)
{
    int res=0;


    for (size_t i=0; i<l;i++)
    {
        for(int j=0; j<8;j++)
        {
            res += (1 & (arr[i]>>j));
        }
    }
    return res;
}

