int save_file(int game_mode, int difficulty_mode, matrix grid, boat *boat_list) {
    FILE *save;

    save = fopen("save", "w");

    //write the data on the file
    if (save != 0){
        fprintf(save, "%d\n", game_mode);
        fprintf(save, "%d\n", difficulty_mode);

        for (int boat_n = 0; boat_n < 5; ++boat_n) {
            fprintf(save, "%d;%d;%d;%d;%d\n", boat_list[boat_n]);
            fprintf(save, "%d",matrix.size);

        }
        for (int line = 0; line < matrix.size; ++line) {
            fprintf(save, "\n");
            for (int column = 0; column < matrix.size; ++column) {
                fprintf(save ,"%c", matrix.list[line][column]);
            }
        }
    }else{
        printf("error saving\n");
    }

    fclose(save);
}
