#include <stdio.h>
#include <stdbool.h>

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
        printf("Index: %d,Value: %d,Ptr Value: %p\n", i, *ptr_to_arr, (void *)ptr_to_arr);
        ptr_to_arr++;
    }
}

bool equal(int *x, int *y, int length)
{
    // Take pointers
    // int  = 4 bytes -> read slice by casting to unsigned char
    if (length > sizeof(int))
        length = 4;

    unsigned char *c1 = (unsigned char *)x;
    unsigned char *c2 = (unsigned char *)y;

    for (int i = 0; i < length; i++)
    {
        if (!(*c1 == *c2))
        {
            return false;
        }
        c1++;
        c2++;
    }

    return true;
}

#define EQ_PRINT(x, y, l) printf("%d and %d equal=%s\n", x, y, equal(&x, &y, l) ? "true" : "false")

void equal_tests()
{
    int x = -1;              // 0xFF FF FF FF (signed)
    unsigned int y = 0xFFFF; // 0x00 00 FF FF (unsigned)

    for (int i = 0; i < 4; i++)
    {
        EQ_PRINT(x, y, i);
    }
}

int T4()
{
    FILE *fp = fopen("foo.txt", "r");
    char ch;

    if (fp == NULL)
    {
        printf("Unable to open file.");
        return 1;
    }

    int x[1];
    int sum = 0;
    while (fscanf(fp,"%d",x)==1){
        sum += x[0];
    }
    printf("%d\n",sum);
    fclose(fp);
    return 0;
}

void swap(int *x, int *y)
{
    // Typecasting to an int 
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void swap_test()
{
    int x = 5;
    int y = 10;
    printf("x:%d,y:%d\n",x,y);
    swap(&x,&y);
    printf("x:%d,y:%d\n",x,y);
}

int main(void)
{
    // T1();
    // T2();
    // equal_tests();
    // T4();
    // swap_test();

    return 0;
}