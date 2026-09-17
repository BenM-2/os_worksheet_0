#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

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
    while (fscanf(fp, "%d", x) == 1)
    {
        sum += x[0];
    }
    printf("%d\n", sum);
    fclose(fp);
    return 0;
}

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

void print_array(int *arr, int width, int height)
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            int index = (r * width) + c;
            printf("%d,", arr[index]);
        }
        printf("\n");
    }
}

void print_test()
{
    int arr[] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12};

    print_array(arr, 4, 3);
}

// Tic tac toe
typedef enum
{
    EMPTY = 0,
    ZERO,
    CROSS,
} TTT_t;

char get_player_char(TTT_t const type)
{
    switch (type)
    {
    case EMPTY:
        return '_';
    case ZERO:
        return 'O';
    case CROSS:
        return 'X';
    }
}

void print_board(const TTT_t *const arr, const size_t grid_size)
{
    for (int r = 0; r < grid_size; r++)
    {
        for (int c = 0; c < grid_size; c++)
        {
            int index = (r * grid_size) + c;
            char x = get_player_char(arr[index]);
            printf("%c,", x);
        }
        printf("\n");
    }
}

void reset_board(TTT_t *arr, size_t length)
{
    memset(arr, EMPTY, length);
}

#define ROW_X_wincheck(arr, row, width)                     \
    ((arr)[(row) * (width)] != EMPTY && \
    (arr)[(row) * (width)] == (arr)[1 + (row) * (width)] && \
    (arr)[1 + (row) * (width)] == (arr)[2 + (row) * (width)])

TTT_t checkwin(const TTT_t *const arr, const int grid_size)
{
    for (int i = 0; i < grid_size; i++)
    {
        if (ROW_X_wincheck(arr, i, grid_size))
        {
            return arr[i];
        }
    }
    return EMPTY;
}

void TicTacToe(int grid_size)
{
    // Local vars
    TTT_t win = EMPTY;
    bool p1_turn = true;
    // Initalise board
    TTT_t *arr = malloc(sizeof(TTT_t) * grid_size * grid_size);
    reset_board(arr, sizeof(TTT_t) * grid_size * grid_size);
    // Play in loop
    while (win == EMPTY)
    {
        // Print board
        print_board(arr, grid_size);

        // Take input
        int player_input = 0;
        printf("Enter Position: ");
        scanf("%d", &player_input);
        arr[player_input] = p1_turn ? ZERO : CROSS;
        p1_turn = !p1_turn;
        // Checkwin
        win = checkwin(arr, grid_size);
    }
    // Print Winner
    printf("WINNER %c\n", get_player_char(win));
}

int main(void)
{
    // T1();
    // T2();
    // equal_tests();
    // T4();
    // swap_test();
    // print_test();
    TicTacToe(3);

    return 0;
}