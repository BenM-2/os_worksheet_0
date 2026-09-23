#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage task_4 fp");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("Unable to open file.");
        return 1;
    }

    int x[1];
    int sum = 0;
    while (fscanf(fp, "%d", x) == 1)
    {
        sum += x[0];
    }
    printf("%d\n", sum);
    fclose(fp);
    return 0;
}