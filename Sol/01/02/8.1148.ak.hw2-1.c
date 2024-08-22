#include <stdio.h>
#include <stdint.h>
typedef struct list
{
//    void *address;
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
}list;
size_t totalMemoryUsage(list *);

void print_elem(list * );

int main()
{
    int n=0;
    scanf("%d", &n);
    list test_v[n] ;
    if (n > 0) {
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%zu", &test_v[i].address,&test_v[i].size);
            test_v[i].comment[0] = 0;
        }
        for (int i = 0; i < n-1; i++)
            test_v[i].next = test_v+i+1;
        test_v[n-1].next = NULL;
        //~ for (list* i = test_v ; i; i = i->next)
            //~ print_elem(i);
        //~ for (int i = 0; i < n; i++)
            //~ print_elem(test_v+i);
        printf("%llu",(uint64_t)totalMemoryUsage(test_v));
    }
    else if (n==0){
        printf("%d", 0);
    }
}
size_t totalMemoryUsage(list *head)
{
    size_t res=0;

    while((struct list *)NULL != head)
    {
        res+=head->size;
        head = head->next;
    }

  return res;
}


void print_elem(struct list * elem)
{
    if(elem != NULL)
    {
        printf("\
    Real address: 0x%zu\n\
    Int  address: 0x%zu\n\
    Size:         %u\n\
    Comment:      %s\n\
    Next:         0x%zu\n", elem, elem->address, elem->size, elem->comment, elem->next);
    }
    else
    {
        printf("(NULL)\n");
    }
}
