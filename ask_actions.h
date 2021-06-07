#include <stido.h>
#include <stdlib.h>

int ask.actions() {
    int action;
    //error control and asking the user what action he'll do next
    do {
        printf("What do you want to do now ?\n"
               "Shoot a missile (1) or save and quit (2) ?\n");
        scanf("%d",&action);
    } while (action < 1 || action > 2);
        return action;
}

int shoot_missile() {
    int coordinates_1,coordinates_2;
    //creating an array that will stock our coordinates so we can display them
    int coordinates[1]
    // error control with the coordinates, we use the ASCII code for the coordinates in A,B,C...
    do {
        printf("Where are you aiming (A,B,C... ?\n");
        scanf("%d",&coordinates_1);
    } while ( coordinates_1 < 65 || coordinates_1 > 74)
        do {
            printf("Where are you aiming (1,2,3... ?\n");
            scanf("%d",&coordinates_2);
        } while (coordinates_2 < 1 || coordinates_2 > 10);
        coordinates[0]=coordinates_1
        coordinates[1]=coordinates_2
        return coordinates;

}