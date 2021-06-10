#include <stido.h>
#include <stdlib.h>

int save_file() {
    int i;
    FILE* save = fopen("save>.txt","w");
    // checking if we can open the file
    if(save != NULL) {
        for (i=0, i<5, ++i) { // write the coordinates of the boats, and separate them by a semi-colon
            fprintf(save, "%d ;\n %d ;\n %d ;\n",boat.size[i],boat.direction[i],boat.spawn[i][2]);
        }
    }
    // still checking if we can open the file
    if(save != NULL) { // write the mode and difficulty, still separated by a semi-colon
        fprintf(save, "%d ;\n %d ;\n", mode_choice, difficulty);
    }
    fclose(save); // close the file
    return 0;
}