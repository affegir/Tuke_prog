#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ballsortpuzzle.h"



void generator(const int rows, const int columns, char field[rows][columns])
{
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            /* code */
            field[j][i] = 't';
        }
    }
    
    int rand_column1;
    int rand_column2;

    do {
        rand_column1 = rand()%columns + (1 - 1);
        rand_column2 = rand()%columns + (1 - 1);
    } while (rand_column1 == rand_column2);

    for (int i = 0; i < rows; i++)
    {
        field[i][rand_column1] = 32;
        field[i][rand_column2] = 32;
    }
    
    for (int i = 0; i < rows && columns > 2; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '@';
    }

    for (int i = 0; i < rows && columns > 3; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '+';
    }

    for (int i = 0; i < rows && columns > 4; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '*';
    }

    for (int i = 0; i < rows && columns > 5; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '^';
    }

    for (int i = 0; i < rows && columns > 6; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '$';
    }

    for (int i = 0; i < rows && columns > 7; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '#';
    }

    for (int i = 0; i < rows && columns > 8; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '&';
    }

    for (int i = 0; i < rows && columns > 9; i++)
    {
        /* code */
        int a, b = 0;
        do {
            a = rand() % rows + (2 - 2);
            b = rand() % columns + (2 - 2);
        } while (field[a][b] != 't');
        field[a][b] = '.';
    }
}

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){
    if (x > 0 && x <= columns && y > 0 && y <= columns && y != x) {
        int pos_x1 = x - 1;
        int pos_x2 = y - 1;

        int pos_y1 = 0;
        int pos_y2 = 0;

        for (int i = 0; i < rows; i++) {
            if (field[i][pos_x1] == 32) pos_y1+=1;
            else break;
        }

        for (int i = 0; i < rows; i++) {
            if (field[i][pos_x2] == 32) pos_y2+=1;
            else break;
        }

        if (pos_y2 == rows - 1) {
            if (field[pos_y2][pos_x2] == 0) {
                pos_y2+=1;
            }
            if (field[pos_y2][pos_x2] == 8) {
                pos_y2+=1;
            }
        }

        if (pos_y2 == rows) {
            field[pos_y2 - 1][pos_x2] = field[pos_y1][pos_x1];
            field[pos_y1][pos_x1] = ' ';
            if (field[pos_y2 - 1][pos_x2] == 0) field[pos_y2 - 1][pos_x2] = 32;
            if (field[pos_y2 - 1][pos_x2] == 8) field[pos_y2 - 1][pos_x2] = 32;
        } else if (pos_y2 == 0) {
            printf("Column is full!\n");
        } else if (field[pos_y2][pos_x2] == field[pos_y1][pos_x1]) {
            field[pos_y2 - 1][pos_x2] = field[pos_y1][pos_x1];
            field[pos_y1][pos_x1] = ' ';
            if (field[pos_y2 - 1][pos_x2] == 0) field[pos_y2 - 1][pos_x2] = 32;
            if (field[pos_y2 - 1][pos_x2] == 8) field[pos_y2 - 1][pos_x2] = 32;
        } else {
            printf("Colors must be same!\n");
        }
    } else {
        printf("Invalid position!\n");
    }
}

bool check(const int rows, const int columns, char field[rows][columns]) {
    int rcounter1 = 0;
    int ccounter2 = 0;

    for (int i = 0; i < columns; i++)
    {
        rcounter1 = 0;
        char cc = field[0][i];
        for (int j = 0; j < rows; j++) {
            if (field[j][i] == cc) rcounter1+=1;
        }
        if (rcounter1 == rows) ccounter2 +=1;
    }
    
    return ccounter2 == columns ? true : false;
}

void game_field(const int rows, const int columns, char field[rows][columns])
{
    printf("\n");
    for(int j = 0; j<rows; j++){
        printf(" %d | ", j+1);
        for(int i = 0; i<columns; i++){
            printf("%c | ", field[j][i]);        
        }
        printf("\n");
    }
    
    printf("    ");
    for(int j = 0; j<columns; j++){
        printf("--- ");

    }
    putchar('\n');
    printf("     ");
    for(int j = 0; j<columns; j++){
        printf("%d   ", j+1);
    }
    printf("\n");

}

void ball_sort_puzzle() {
    int rows= 4;
    int columns = 6;
    char field[rows][columns];
    generator(rows, columns, field);

    while (!check(rows, columns, field)) {
        game_field(rows, columns, field);
        int a, b = 0;

        printf("From: ");
        scanf("%d", &a);
        getchar();

        printf("To: ");
        scanf("%d", &b);
        getchar();

        down_possible(rows, columns, field, a, b);
    }
    game_field(rows, columns, field);
    printf("You won!\n");
}
