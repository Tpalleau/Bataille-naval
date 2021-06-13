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
    int boat_coord[1];
    int hit;

    //depending on bombe type different checking methode
    switch (bomb_type) {
        // normal, artillery, bomb
        case 1 ... 3:

            // check for every boat
            for (int boat_n = 0; boat_n < 5; ++boat_n) {
                //check for every element of the boat
                for (int element = 0; element < boat_list[boat_n].size; ++element) {
                    hit = 0;
                    //set boat coordinates
                    if (boat_list[boat_n].direction == 0) {
                        boat_coord[0] = boat_list[boat_n].spawn[0] + element;
                        boat_coord[1] = boat_list[boat_n].spawn[1];
                    } else {
                        boat_coord[0] = boat_list[boat_n].spawn[0];
                        boat_coord[1] = boat_list[boat_n].spawn[1] - element;
                    }

                    // check if hit depending on the bomb
                    switch (bomb_type) {
                        case 1://normal bomb
                            if (coord[0] == boat_coord[0] && coord[1] == boat_coord[1]) {
                                hit = 1;
                            }
                        case 2://artillery
                            if (coord[0] == boat_coord[0] || coord[1] == boat_coord[1]) {
                                hit = 1;
                            }
                    }

                    // update grid, if hit update boat
                    if (hit) {
                        boat_list[boat_n].state[element] = 'X';
                        player_grid->grid[coord[1]][coord[0]] = 'X';

                    } else {
                        player_grid->grid[coord[1]][coord[0]] = '0';
                    }

                }

            }
            break;
            // tactical bomb
        case 4:
            hit = 0;
            int boat_n = 0;

            do {
                for (int element = 0; element < boat_list[boat_n].size; ++element) {
                    // set coord
                    if (boat_list[boat_n].direction == 0) {
                        boat_coord[0] = boat_list[boat_n].spawn[0] + element;
                        boat_coord[1] = boat_list[boat_n].spawn[1];
                    } else {
                        boat_coord[0] = boat_list[boat_n].spawn[0];
                        boat_coord[1] = boat_list[boat_n].spawn[1] - element;
                    }
                    // check if boat is hit
                    if (boat_coord[0] == coord[0] && boat_coord[1] == coord[1]){
                        hit = 1;
                    }
                    boat_n++;
                }

            } while (!hit || boat_n<5);//exit only if a boat is hit or run through all boats

            if (hit){//if boat hit destroy all the boat
                for (int element = 0; element < boat_list[boat_n].size; ++element) {
                    boat_list[boat_n].state[element] = 'X';

                    if (boat_list[boat_n].direction == 0){
                        player_grid->grid[coord[1]][coord[0] + element] = 'X';
                    }else{
                        player_grid->grid[coord[1] + element][coord[0]] = 'X';
                    }
                }
            }
            break;


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

int ask_actions(boat *boat_list, matrix *grid,int bomb_type) {
    int action;
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
            get_coord(coord);
            apply_damage(boat_list,*&grid,bomb_type, coord);
            break;

        case 2:
            play = 0;
            break;
    }

    return play;
}

int get_missile() {
    int typemissile;
    do {
        printf("What type of missile do you want to use ?\n"
               "(Normal : 1 ; artillery : 2 ; bombs : 3 ; tactical : 4)\n");
        scanf("%d", &typemissile);
    } while (typemissile < 1 || typemissile > 4);

    return typemissile;
}

#ifndef MAIN_C_GAME_FUNC_H
#define MAIN_C_GAME_FUNC_H

#endif //MAIN_C_GAME_FUNC_H
