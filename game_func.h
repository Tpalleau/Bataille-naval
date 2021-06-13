void show_grid(matrix grid){
    //coord numbers
    printf("  ");
    for (int num = 0; num < grid.length; ++num) {
        printf(" %d", num + 1);
    }
    printf("\n  ____________________\n");

    for (int column = 0; column < grid.height; ++column) {
        // coord letters
        printf("%c| ", column + 97);

        for (int line = 0; line < grid.length ; ++line) {
            printf("%c ",grid.grid[line][column]);
        }
        printf("\n");
    }
}

int apply_damage(boat *boat_list,matrix *player_grid, int bomb_type, int *coord) {
    int hit = 0;
    int boat_n = 0;
    int boat_x;
    int boat_y;

    if (bomb_type == 2) {
        for (int i = 0; i < 10; ++i) { // set all lines artillery applies to, to miss
            player_grid->grid[coord[0]][i] = 'O';
            player_grid->grid[i][coord[1]] = 'O';
        }

        for (int boat_n = 0; boat_n < 5; ++boat_n) { //check for every boat
            boat_x = boat_list[boat_n].spawn[0];
            boat_y = boat_list[boat_n].spawn[1];

            for (int element = 0; element < boat_list[boat_n].size; ++element) { //for length of boat
                if (boat_list[boat_n].direction == 0) { // x axis
                    if (coord[0] == boat_x + element || coord[1] == boat_y) { //if coord is same as boat element update grid and boat state
                        player_grid->grid[boat_x + element][boat_y] = 'X';
                        boat_list[boat_n].state[element] = 1;
                    }
                }else { // y axis
                    if (coord[0] == boat_x || coord[1] == boat_y + element) {
                        player_grid->grid[boat_x][boat_y + element] = 'X';
                        boat_list[boat_n].state[element] = 1;
                    }
                }
            }
        }

    }else if (bomb_type == 3) {
        for (int y = -2; y < 3; ++y) { // start at the bottom
            for (int x = abs(y) - 2; x < -(abs(y) - 2) + 1; ++x) { // algo to only check necessary squares

                // check if x and y are in grid
                if (coord[1]+y>= 0 && coord[1]+y<= player_grid->length-1 && coord[0]+x>= 0 && coord[0]+x<= player_grid->length-1) {
                    player_grid->grid[coord[0] + x][coord[1] + y] = 'o'; //set by default to miss

                    for (int boat_n = 0; boat_n < 5; ++boat_n) { //check every boat
                        for (int element = 0; element < boat_list[boat_n].size; ++element) { //check all element of boat
                            boat_x = boat_list[boat_n].spawn[0];
                            boat_y = boat_list[boat_n].spawn[1];

                            if (boat_list[boat_n].direction == 0) { //x axis
                                if (coord[0] + x == boat_x + element && coord[1] + y == boat_y) {
                                    player_grid->grid[coord[0] + x][coord[1] + y] = 'x';
                                    boat_list[boat_n].state[element] = 1;

                                }
                            } else { //y axis
                                if (coord[0] + x == boat_x && coord[1] + y == boat_y + +element) {
                                    player_grid->grid[coord[0] + x][coord[1] + y] = 'x';
                                    boat_list[boat_n].state[element] = 1;
                                }
                            }

                        }
                    }
                }
            }
        }


    }else{
        player_grid->grid[coord[0]][coord[1]] = 'O';

        while (boat_n < 5 && !hit) { //if all boats checked and nothing or hit a boat then quit
            boat_x = boat_list[boat_n].spawn[0];
            boat_y = boat_list[boat_n].spawn[1]; //make things more readable

            for (int element = 0; element < boat_list[boat_n].size; ++element) { //check all coord of boat

                if (boat_list[boat_n].direction == 0) { //x oriented boats
                    if (hit && bomb_type == 4) { //update grid and boat state
                        player_grid->grid[boat_x + element][boat_y] = 'X';
                        boat_list[boat_n].state[element] = 1;

                    } else if (coord[0] == boat_x + element && coord[1] == boat_y) {
                        hit = 1;

                        if (bomb_type == 4) { //reset loop so that it fills everything
                            element = -1;
                        } else { //if bomb type 1 update grid and boat state
                            player_grid->grid[boat_x + element][boat_y] = 'X';
                            boat_list[boat_n].state[element] = 1;
                        }
                    }
                } else { //y oriented boat
                    if (hit && bomb_type == 4) {
                        player_grid->grid[boat_x][boat_y + element] = 'X';
                        boat_list[boat_n].state[element] = 1;

                    } else if (coord[0] == boat_x && coord[1] == boat_y + element) {
                        hit = 1;

                        if (bomb_type == 4) {
                            element = -1;
                        } else {
                            player_grid->grid[boat_x][boat_y + element] = 'X';
                            boat_list[boat_n].state[element] = 1;
                        }
                    }
                }
            }
            boat_n++;
        }
    }
}


void get_coord(int *coord) {
    int coordinates_1,coordinates_2;
    char c;
    //creating an array that will stock our coordinates so we can display them
    // error control with the coordinates, we use the ASCII code for the coordinates in A,B,C...
    do {
        printf("Where are you aiming (1,2,3... ?\n");
        scanf("%d",&coordinates_1);
    } while (coordinates_1 < 1 || coordinates_1 > 10);

    do {
        printf("Where are you aiming (A,B,C... ?\n");
        scanf("%c",&c);
        coordinates_2 = toupper(c);

    } while ( coordinates_2 < 65 || coordinates_2 > 74);

    coord[0]=coordinates_1 - 1;
    coord[1]=coordinates_2 - 65;
}

int get_missile(inventory *missiles) {
    int bomb_type;
    do {
        printf("What type of missile do you want to use ?\n"
               "(Normal : 1 ; artillery : 2 ; bombs : 3 ; tactical : 4)\n");
        scanf("%d", &bomb_type);
    } while (bomb_type < 1 || bomb_type > 4);

    switch (bomb_type) {
        case 1:
            missiles->normal - 1;
            break;
        case 2:
            missiles->artillery - 1;
            break;
        case 3:
            missiles->bombs - 1;
            break;
        case 4:
            missiles->tactical - 1;
            break;
    }

    return bomb_type;
}

int ask_actions(boat *boat_list, matrix *grid,inventory *missiles) {
    int action;
    int bomb_type;
    int coord[1];
    int play = 1;

    //error control and asking the user what action he'll do next
    do {
        printf("What do you want to do now ?\n"
               "Shoot a missile (1) or save and quit (2) ?\n");
        scanf("%d",&action);
    } while (action < 1 || action > 2);

    switch (action) {
        case 1:
            bomb_type = get_missile(*&missiles);
            get_coord(coord);
            apply_damage(boat_list,*&grid,bomb_type, coord);
            break;

        case 2:
            play = 0;
            break;
    }

    return play;
}

#ifndef MAIN_C_GAME_FUNC_H
#define MAIN_C_GAME_FUNC_H

#endif //MAIN_C_GAME_FUNC_H
