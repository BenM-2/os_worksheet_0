#include <stdio.h>

void T1(){
    int n = 0;
    int *ptr_to_n = &n;

    // Inrement n by 1 
    *ptr_to_n += 1;


}

int main(void)
{
    T1();
    return 0;
}