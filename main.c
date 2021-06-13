#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "structs.h"
#include "Menu_functions.h"
#include "game_func.h"
#include "init_funcs.h"

int main(){

    int run_game = 1;
    int play;
    int menu_mode;
    int game_mode;
    int difficulty_mode;

    matrix player_grid;
    inventory missiles;
    boat boat_list[5];

    srand(time(0));

    while (run_game){
        play = 1;
        menu_mode = main_menu();

        // menu options
        if (menu_mode == 1){
            game_mode = mode_menu();
            difficulty_mode = difficulty_menu();
        }else if (menu_mode == 2) { //quand on creera la sauvegarde:
            ;
        }else if(menu_mode == 3){
                run_game = 0;
                continue;
        }

        //init structs
        init_boat_list(boat_list);
        player_grid = init_matrix();
        missiles = init_inventory(difficulty_mode);


        fill_AI_grid(boat_list);
        show_grid(player_grid);

        while (play){
            play = ask_actions(boat_list, &player_grid, &missiles);
            show_grid(player_grid);

        }

    }

}



