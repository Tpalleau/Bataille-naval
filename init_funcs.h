
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

void init_boat_list(boat *boat_list){
    for (int boat_n = 0; boat_n < 5; ++boat_n) {
        switch (boat_n) {
            case 0:
                boat_list[boat_n].size = 2;
                break;
            case 1 ... 2:
                boat_list[boat_n].size = 3;
                break;
            case 3:
                boat_list[boat_n].size = 4;
                break;
            case 4:
                boat_list[boat_n].size = 5;
                break;
        }
        boat_list[boat_n].direction = rand()%2;
    }
}

inventory init_inventory(int difficulty){
    inventory missile;

    switch (difficulty) {
        case 1:
            missile.artillery = 10;
            missile.bombs = 10;
            missile.tactical = 10;
            missile.normal = 10;
            break;

        case 2:
            missile.artillery = 3;
            missile.bombs = 5;
            missile.tactical = 5;
            missile.normal = 10;
            break;

        case 3:
            missile.artillery = 1;
            missile.bombs = 2;
            missile.tactical = 4;
            missile.normal = 15;
            break;
    }
    return missile;
}

matrix fill_matrix(matrix game_grid){
    int x;
    int y;


    x = rand() % game_grid.length;
    y = rand() % game_grid.length;



}

void show_grid(matrix game_matrix){
    //coord numbers
    printf("  ");
    for (int num = 0; num < game_matrix.length; ++num) {
        printf(" %d", num + 1);
    }
    printf("\n  ____________________\n");

    for (int column = 0; column < game_matrix.height; ++column) {
        // coord letters
        printf("%c| ", column + 97);

        for (int line = 0; line < game_matrix.length ; ++line) {
            printf("%c ",game_matrix.grid[line][column]);
        }
        printf("\n");
    }
}

#ifndef MAIN_C_INIT_FUNCS_H
#define MAIN_C_INIT_FUNCS_H

#endif //MAIN_C_INIT_FUNCS_H
