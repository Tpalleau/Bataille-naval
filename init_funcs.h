
matrix init_matrix(){
    matrix grid;
    grid.length = 10;
    grid.height = 10;

    // fill grid with '_'
    for (int line = 0; line < grid.length; ++line) {
        for (int column = 0; column < grid.height; ++column) {

            grid.grid[line][column] = '_';
        }
    }

    return grid;
}

void init_boat_list(boat *boat_list) {
    boat_list[0].size = 2;
    boat_list[1].size = 3;
    boat_list[2].size = 3;
    boat_list[3].size = 4;
    boat_list[4].size = 5;

    for (int boat_n = 0; boat_n < 5; ++boat_n) {
        boat_list[boat_n].direction = rand() % 2;

        // state of boat
        char boat_state[boat_list[boat_n].size];
        boat_list[boat_n].state = boat_state;
        for (int i = 0; i < boat_list[boat_n].size; ++i) {
            boat_state[i] = 'O';

        }
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


matrix fill_AI_grid(matrix *AI_grid, boat *boat_list){
    int x;
    int y;
    int space_free;

    for (int boat_n = 0; boat_n < 5; ++boat_n) {

        //generate new coordinates depending on direction and size while not found space
        do {
            if (boat_list[boat_n].direction){
                x = rand() % (AI_grid->length - boat_list[boat_n].size);
                y = rand() % AI_grid->height;
            }else{
                x = rand() % AI_grid->length;
                y = rand() % (AI_grid->height - boat_list[boat_n].size);
            }

            space_free = 1;
            for (int element = 0; element < boat_list[boat_n].size - 1; ++element) {
                if (boat_list[boat_n].direction){

                    //check on x axis if space is free to place a boat
                    if (AI_grid->grid[element][y] != AI_grid->grid[element + 1][y]){
                        space_free = 0;
                    }
                }else{
                    //check on x axis if space is free to place a boat
                    if (AI_grid->grid[x][element] != AI_grid->grid[x][element + 1]){
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
                        AI_grid->grid[element][y] = 118 + boat_n;
                    }
                }else{
                    for (int element = y; element < y + boat_list[boat_n].size; ++element) {
                        AI_grid->grid[x][element] = 118 + boat_n;
                    }
                }

            }
        } while (!space_free);
    }
    printf("grid\n");
    printf("\n\n\n");
}



#ifndef MAIN_C_INIT_FUNCS_H
#define MAIN_C_INIT_FUNCS_H

#endif //MAIN_C_INIT_FUNCS_H
