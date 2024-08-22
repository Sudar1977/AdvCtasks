#include <stdio.h>

int main()
{
    unsigned int n;
    int n_max;
    unsigned int q_max = 1;
    scanf("%u", &n);
    scanf("%d", & n_max);
    n--;
    for(;n;n--)
    {
        int n_cur;
        scanf("%d", &n_cur);
        if(n_cur > n_max)
        {
            n_max = n_cur;
            q_max = 1;
        }
        else if(n_cur == n_max)
        {
            q_max++;
        }

    }
    printf("%u", q_max);
    return 0;
}
