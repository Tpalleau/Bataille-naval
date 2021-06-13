int save_file(int game_mode, int difficulty_mode, matrix grid) {
    int boat_n;
    FILE* save = fopen("save>.txt","w");
    // checking if we can open the file
    if(save != NULL) {
        for (boat_n=0; boat_n<5; ++boat_n) { // write the coordinates of the boats, and separate them by a semi-colon
            fprintf(save, "%d ; %d ; %d ; %d ;\n",&boat.size[boat_n],&boat.direction[boat_n],&boat.spawn[boat_n][2],&boat.state[boat_n][4]);

        }
    }
    // still checking if we can open the file
    if(save != NULL) { // write the mode and difficulty, still separated by a semi-colon
        fprintf(save, "%d ;\n %d ;\n", game_mode, difficulty_mode);
    }
    // writing the grid in the file
    for ( int y=0 ; y<10 ; ++y) {
        for (int x = 0; x < 10; ++x)
            fprintf(save, "%c %c \n", grid.length[x], grid.height[y])
        }
    }
    fclose(save); // close the file
    return 0;
}
