#include <stdio.h>
#include <string.h>
enum{maxlength = 10001};

int search_prefix(char*, char*);


int main ()
{
    char s1[maxlength ], s2[maxlength ];
    int pr1=0, pr2=0;
    int l1, l2, l;

    scanf("%10001s", s1);
    scanf("%10001s", s2);


    printf("%d %d\n", search_prefix(s2,s1), search_prefix(s1,s2));

    return 0;
}


int search_prefix(char*s1, char*s2)
{
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int l = l1<l2?l1:l2;
    int i1, i2, max=0;
    char c1, c2;
    for (i1 = l1-l; i1<l1; i1++)
    {
        for(i2 = 0; i2<l2; i2++)
        {
            c1 = s1[i1+i2];
            c2 = s2[i2];
#ifdef DEBUG
            printf("%c/%c ", c1, c2);
#endif
             if(c1 != c2 )
             {
                 break;
             }
        }
#ifdef DEBUG
                printf("\n");
#endif
            if(s1[l1-1] == s2[i2-1] && i2 > max )
            {
                max = i2;
            }
    }
    return max;
}

