#include "stdio.h"

int main(void)
{
    printf("Task 2: \n");
    int arr[3] = {10, 20, 30};
    int *ptr_to_arr = arr;
    for (int i = 0; i < 3; i++)
    {
        printf("Index: %d,Value: %d,Ptr Value: %p\n", i, *ptr_to_arr, (void *)ptr_to_arr);
        ptr_to_arr++;
    }
    return 0;
}