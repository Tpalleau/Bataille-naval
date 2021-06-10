typedef struct{
    int artillery;
    int bombs;
    int tactical;
    int normal;

}inventory;

typedef struct{
    char grid[10][10];
    int height;
    int length;

}matrix;

typedef struct{
    int size;
    int direction;
    int spawn[2];
    int *state;
}boat;



#ifndef BATAILLE_NAVAL_STRUCTS_H
#define BATAILLE_NAVAL_STRUCTS_H

#endif //BATAILLE_NAVAL_STRUCTS_H
