#include <stdio.h>
// True swap But done through a macro to avoid loss of data of the size of data due to void *
// #define swap_val(x,y) swap_values(&(x),&(y),sizeof((x)))
// void swap_values(void *x,void *y, int length){
//     unsigned char tmp[length];   // max object size allowed
//     memcpy(tmp, x, length);
//     memcpy(x, y, length);
//     memcpy(y, tmp, length);
// }

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
    printf("x:%d,y:%d\n", x, y);
    swap(&x, &y);
    printf("x:%d,y:%d\n", x, y);
}

int main()
{
    swap_test();
    return 0;
}