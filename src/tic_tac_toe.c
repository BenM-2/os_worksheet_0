#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

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
    default:
        return '_';
    }
}

void print_board(const TTT_t *const arr, const size_t grid_size)
{
    for (size_t r = 0; r < grid_size; r++)
    {
        for (size_t c = 0; c < grid_size; c++)
        {
            int index = (r * grid_size) + c;
            char x = get_player_char(arr[index]);
            printf("\t%c\t", x);
        }
        printf("\n\n");
    }
}

void reset_board(TTT_t *arr, size_t length)
{
    memset(arr, EMPTY, length);
}

#define ROW_X_wincheck(arr, row, width)                      \
    ((arr)[(row) * (width)] != EMPTY &&                      \
     (arr)[(row) * (width)] == (arr)[1 + (row) * (width)] && \
     (arr)[1 + (row) * (width)] == (arr)[2 + (row) * (width)])

#define COL_X_wincheck(arr, col, width)        \
    ((arr)[(col)] != EMPTY &&                  \
     (arr)[(col)] == (arr)[(col) + (width)] && \
     (arr)[(col) + (width)] == (arr)[(col) + (2) * (width)])

TTT_t checkwin(const TTT_t *const arr, const int grid_size)
{
    for (int i = 0; i < grid_size; i++)
    {
        if (ROW_X_wincheck(arr, i, grid_size) || COL_X_wincheck(arr, i,grid_size))
        {
            return arr[i];
        }
    }
    return EMPTY;
}

int main(int argc,char * argv[])
{
    if (argc != 2){
        printf("Usage ./TTT grid_size\n");
        return 1;
    }

    printf("Tic Tac Toe: \n");
    int grid_size = atoi(argv[1]);

    // Local vars
    TTT_t win = EMPTY;
    bool p1_turn = true;
    // Initalise board
    TTT_t *arr = malloc(sizeof(TTT_t) * grid_size * grid_size);
    reset_board(arr, sizeof(TTT_t) * grid_size * grid_size);
    // Play in loop
    while (win == EMPTY)
    {

        // Take input
        int player_input = -1;
        int fail_count = 0;
        bool input_valid = false;

        while (!input_valid)
        {
            // Print board
            print_board(arr, grid_size);

            if (fail_count > 0)
            {
                printf("\nINVALID INPUT\n\n");
            }
            printf("Player %c\n", get_player_char(p1_turn ? ZERO : CROSS));
            printf("Enter Position: ");
            scanf("%d", &player_input);

            if (arr[player_input] == EMPTY && (player_input > 0 || player_input < grid_size * grid_size))
            {
                input_valid = true;
            }

            fail_count++;
        }
        arr[player_input] = p1_turn ? ZERO : CROSS;
        p1_turn = !p1_turn;
        // Checkwin
        win = checkwin(arr, grid_size);
    }
    // Print Winner
    printf("\n\n\n\t\tWINNER %c\n\n\n", get_player_char(win));
}
