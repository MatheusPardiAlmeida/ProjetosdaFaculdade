#include <stdio.h>

int main()
{
    int a = 17;
    int *ptr1 = &a;
    void **ptr2 = (void **) &ptr1;

    //printf("ptr2: %d", *(int*)*ptr2);

    printf("ptr2: %d", *ptr2);

    return 0;
}