#include "stdio.h"

int main(void)
{
    printf("Task 1: \n");
    int n = 0;
    int *ptr_to_n = &n;
    printf("n = %d\n",n);
    printf("ptr_to_n = %p\n",(void *)ptr_to_n);

    // Inrement n by 1
    *ptr_to_n += 1;
    printf("*ptr_to_n += 1;\n");
    printf("n = %d\n", n);
    return 0;
}