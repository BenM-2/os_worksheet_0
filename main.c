#include <stdio.h>

void T1()
{
    int n = 0;
    int *ptr_to_n = &n;

    // Inrement n by 1
    *ptr_to_n += 1;
    printf("%d\n", n);
}

void T2()
{
    int arr[3] = {10, 20, 30};
    int *ptr_to_arr = arr;
    for (int i = 0; i < 3; i++)
    {
        printf("Index: %d,Value: %d,Ptr Value: %p\n",i,*ptr_to_arr,(void *)ptr_to_arr);
        ptr_to_arr++;
    }
}

int main(void)
{
    T1();
    T2();
    return 0;
}