#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "structs.h"
#include "Menu_functions.h"

int main(){

    game game1;
    int run_game = 1;
    int play = 1;
    int menu_mode;
    matrix game_grid;

    while (run_game){
        menu_mode = main_menu();

        // menu options
        if (menu_mode == 1){
            game1.game_mode = mode_menu();
            game1.difficulty = difficulty_menu();
        }else if (menu_mode == 2) { //quand on creera la sauvegarde:
            ;
        }else if(menu_mode == 3){
                run_game = 0;
                continue;
        }

        game_grid = init_matrix();
        show_grid(game_grid);
//        while (play){
//
//        }
    }
}



