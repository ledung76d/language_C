#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main()
{
    Stack st = NULL;
    st = push(st, 1);
    st = push(st, 2);
    printf("%d\t%d\n", st->data, st->next->data);
    int a;
    st = pop(st, &a);
    printf("%d\t%d\n", a, st->data);
    return 0;
}
