#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ballsortpuzzle.h"

// Colors Library
// Created by Teslasoft (Dmytro Ostapenko) on 11/11/2021. (v1.0)
//

/* Uncomment if you are using this code as separated library (importing as "colors.h" instead of putting this code directly to your C file)
#ifndef COLORS_COLORS_H
#define COLORS_COLORS_H
#endif //COLORS_COLORS_H
*/

const char RED[8] = "\033[0;31m\0";
 const char YELLOW[8] = "\033[0;33m\0";
 const char GREEN[8] = "\033[0;32m\0";
//const char BLUE[8] = "\033[0;34m\0";
 const char MAGENTA[8] = "\033[0;35m\0";
 const char CYAN[8] = "\033[0;36m\0";
// const char BLACK[8] = "\033[0;30m\0";
// const char WHITE[8] = "\033[0;37m\0";
// 
// const char BOLD_RED[8] = "\033[1;31m\0";
// const char BOLD_YELLOW[8] = "\033[1;33m\0";
// const char BOLD_GREEN[8] = "\033[1;32m\0";
 //const char BOLD_BLUE[8] = "\033[1;34m\0";
// const char BOLD_MAGENTA[8] = "\033[1;35m\0";
// const char BOLD_CYAN[8] = "\033[1;36m\0";
// const char BOLD_BLACK[8] = "\033[1;30m\0";
// const char BOLD_WHITE[8] = "\033[1;37m\0";
// 
 const char RESET[5] = "\033[0m\0";



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
            printf("%sColumn is full!%s\n", RED, RESET);
        } else if (field[pos_y2][pos_x2] == field[pos_y1][pos_x1]) {
            field[pos_y2 - 1][pos_x2] = field[pos_y1][pos_x1];
            field[pos_y1][pos_x1] = ' ';
            if (field[pos_y2 - 1][pos_x2] == 0) field[pos_y2 - 1][pos_x2] = 32;
            if (field[pos_y2 - 1][pos_x2] == 8) field[pos_y2 - 1][pos_x2] = 32;
        } else {
            printf("%sColors must be same!%s\n", RED, RESET);
        }
    } else {
        printf("%sInvalid position!%s\n", RED, RESET);
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
    printf("   %sX%s", CYAN, RESET);
    for(int i = 0; i<columns; i++){
        printf("   %sX%s", CYAN, RESET);
    }
    printf("\n");
    for(int j = 0; j<rows; j++){
        printf(" %s%d | %s",CYAN, j+1, RESET);
        for(int i = 0; i<columns; i++){
            printf("%s%c%s %s| %s",YELLOW, field[j][i],RESET, CYAN, RESET);
           
                  
        }
        printf("\n");
    }
    
    printf("    ");
    for(int j = 0; j<columns; j++){
        printf("%s--- %s", CYAN, RESET);

    }
    putchar('\n');
    printf("     ");
    for(int j = 0; j<columns; j++){
        printf("%s%d   %s",CYAN, j+1, RESET);
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

        printf("%sFrom: %s",MAGENTA, RESET);
        scanf("%d", &a);
        getchar();

        printf("%sTo: %s",MAGENTA, RESET);
        scanf("%d", &b);
        getchar();

        down_possible(rows, columns, field, a, b);
    }
    game_field(rows, columns, field);
    printf("%sYou won!%s\n", RED, RESET);
}
