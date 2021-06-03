
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

void init_boat_list(boat *boat_list) {
    boat_list[0].size = 2;
    boat_list[1].size = 3;
    boat_list[2].size = 3;
    boat_list[3].size = 4;
    boat_list[4].size = 5;

    for (int boat_n = 0; boat_n < 5; ++boat_n) {
        boat_list[boat_n].direction = rand() % 2;
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

matrix fill_grid(matrix AI_grid, boat *boat_list){
    int x;
    int y;
    int space_free;

    for (int boat_n = 0; boat_n < 5; ++boat_n) {

        //generate new coordinates depending on direction and size while not found space
        do {
            if (boat_list[boat_n].direction){
                x = rand() % (AI_grid.length - boat_list[boat_n].size);
                y = rand() % AI_grid.height;
            }else{
                x = rand() % AI_grid.length;
                y = rand() % (AI_grid.height - boat_list[boat_n].size);
            }

            space_free = 1;
            for (int element = 0; element < boat_list[boat_n].size - 1; ++element) {
                if (boat_list[boat_n].direction){

                    //check on x axis if space is free to place a boat
                    if (AI_grid.grid[element][y] != AI_grid.grid[element + 1][y]){
                        space_free = 0;
                    }
                }else{
                    //check on x axis if space is free to place a boat
                    if (AI_grid.grid[x][element] != AI_grid.grid[x][element + 1]){
                        space_free = 0;
                    }
                }
            }
            //if space is free put the coord in the boat struct
            if (space_free){
                boat_list[boat_n].spawn[0] = x;
                boat_list[boat_n].spawn[1] = y;

                //fill the grid for the next check
                if (boat_list[boat_n].direction){
                    for (int element = x; element < x + boat_list[boat_n].size; ++element) {
                        AI_grid.grid[element][y] = 'X';
                    }
                }else{
                    for (int element = y; element < y + boat_list[boat_n].size; ++element) {
                        AI_grid.grid[x][element] = 'X';
                    }
                }

            }
        } while (!space_free);
    }for (int n = 0; n < 5; ++n) {
        printf("%d:%d and size %d,%d\n",boat_list[n].spawn[0], boat_list[n].spawn[1],
               boat_list[n].size, boat_list[n].direction);
        }
    printf("grid\n");
    show_grid(AI_grid);
    printf("\n\n\n");
}



#ifndef MAIN_C_INIT_FUNCS_H
#define MAIN_C_INIT_FUNCS_H

#endif //MAIN_C_INIT_FUNCS_H
