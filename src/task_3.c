#include "stdbool.h"
#include "stdio.h"

bool equal(const void *const x, const  void *const y, size_t length)
{
    // Take pointers
    unsigned char *c1 = (unsigned char *)x;
    unsigned char *c2 = (unsigned char *)y;

    for (size_t i = 0; i < length; i++)
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

int main(void)
{
    printf("Task 3: \n");
    equal_tests();
    return 0;
}