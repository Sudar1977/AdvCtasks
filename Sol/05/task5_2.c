#include <stdio.h>

#define max_stack 500
typedef struct stack_t
{
    unsigned int numbers[max_stack+1];
    int size;
} stack_t;

stack_t stack;
stack_t * st = &stack;
unsigned int pop();
int push( unsigned int );

int main ()
{
    st->size = 0;
    int ch;
    int res=0;
    unsigned int a=0, b=0;
    while(EOF != (ch = getchar()))
    {
        switch(ch)
        {
            case '+':
                a = pop();
                b = pop();
                push(a+b);
                break;
            case '-':
                a = pop();
                b = pop();
                push(b-a);
                break;
            case '*':
                a = pop();
                b = pop();
                push(a*b);
                break;
            case '/':
                a = pop();
                b = pop();
                push(b/a);
                break;
            case '\n':
            case ' ':
            case '.':
                break;
            default:
                ungetc(ch,stdin);
                scanf("%u", &a);
                push(a);
        }
        if(ch == '\n' || ch == '.')
        {
            break;
        }
    }
    printf("%d\n", pop());
}


unsigned int pop()
{
    if(st->size)
    {
        st->size--;
#ifdef DEBUG
        printf("Popped %u\n", st->numbers[st->size]);
#endif
        return st->numbers[st->size];
    }
    return 0;
}

int push( unsigned int n)
{
    if((st->size) < max_stack )
    {
        st->numbers[st->size] = n;
        unsigned int res = (st->size);
        st->size ++;
#ifdef DEBUG
        printf("Pushed %u, stack size = %d\n", st->numbers[st->size], st->size);
#endif

        return st->size;
    }
    else
    {
        return -1;
    }
}

