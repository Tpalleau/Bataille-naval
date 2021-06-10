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

//int apply_damage(boat *boat_list,matrix *player_grid, int bomb_type, int *coord, int flag_show){
//    int boat_coord[1];
//
//    //check for every boat
//    for (int boat_n = 0; boat_n < 5; ++boat_n) {
//        for (int element = 0; element < boat_list[boat_n].size; ++element) {
//            //set boat coordinates
//            if (boat_list[boat_n].direction == 0){
//                boat_coord[0] = boat_list[boat_n].spawn[0] + element;
//                boat_coord[1] = boat_list[boat_n].spawn[1];
//            }else{
//                boat_coord[0] = boat_list[boat_n].spawn[0];
//                boat_coord[1] = boat_list[boat_n].spawn[1] - element;
//            }
//
//            switch (bomb_type) {
//                case 1:
//
//            }
//        }
//
//    }
//}

void get_coord(int *coord) {
    int coordinates_1,coordinates_2;
    //creating an array that will stock our coordinates so we can display them
    // error control with the coordinates, we use the ASCII code for the coordinates in A,B,C...
    do {
        printf("Where are you aiming (A,B,C... ?\n");
        scanf("%d",&coordinates_1);
    } while ( coordinates_1 < 65 || coordinates_1 > 74);

    do {
        printf("Where are you aiming (1,2,3... ?\n");
        scanf("%d",&coordinates_2);
    } while (coordinates_2 < 1 || coordinates_2 > 10);

    coord[0]=coordinates_1 - 65;
    coord[1]=coordinates_2;
}

int ask_actions() {
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
