#include <stdio.h>
#include "string.h"

void print_2D_array(int width, int height, int arr[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            printf("%d,", arr[h][w]);
        }
        printf("\n");
    }
}

void print_array(int * arr, int width, int height)
{ 
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int index = h * width + w; 
            printf("%d,", arr[index]);
        }
        printf("\n");
    }
}

int main(void)
{
    printf("Task 6:\n");
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // print_2D_array(4,3,arr);
    print_array(arr[0],4,3);
    return 0;
}