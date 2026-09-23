#include "stdio.h"

int main(void)
{
    printf("Task 1: \n");
    int n = 0;
    int *ptr_to_n = &n;

    // Inrement n by 1
    *ptr_to_n += 1;
    printf("%d\n", n);
    return 0;
}