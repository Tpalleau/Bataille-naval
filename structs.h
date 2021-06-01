#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct game{
    int difficulty;
    int game_mode;

}game;

typedef struct matrix{
    char grid[10][10];
    int height;
    int length;

}matrix;

typedef struct boat{
    int size;
    char direction;
    int spawn[1];
}boat;

matrix init_matrix(){
    matrix game_grid;
    game_grid.length = 10;
    game_grid.height = 10;

    // fill grid with '_'
    for (int line = 0; line < game_grid.length; ++line) {
        for (int column = 0; column < game_grid.height; ++column) {

            game_grid.grid[line][column] = '_';
        }
    }

    return game_grid;
}

void show_grid(matrix game_matrix){
    //coord title
    printf("  ");
    for (int num = 0; num < game_matrix.length; ++num) {
        printf(" %d", num + 1);
    }
    printf("\n  ____________________\n");

    for (int column = 0; column < game_matrix.height; ++column) {
        printf("%c| ", column + 97);

        for (int line = 0; line < game_matrix.length ; ++line) {
            printf("%c ",game_matrix.grid[line][column]);
        }
        printf("\n");
    }
}


#ifndef BATAILLE_NAVAL_STRUCTS_H
#define BATAILLE_NAVAL_STRUCTS_H

#endif //BATAILLE_NAVAL_STRUCTS_H
