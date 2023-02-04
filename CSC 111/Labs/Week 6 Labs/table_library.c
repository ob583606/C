#include "table_library.h"

int find_minimum_element( int rows, int cols, int T[rows][cols] ) {
    int tSmallest = T[0][0];
    int* psm = &tSmallest;
    int r = 0;
    int c = 0;
    while (r < rows) {
        while (c < cols){
            if(T[r][c] < *psm) {
                *psm = T[r][c];
            }
            c += 1;
        }
        c = 0;
        r += 1;
    }
    return tSmallest;
}

void print_table( int rows, int cols, int T[rows][cols] ) {
    int r = 0;
    int c = 0;
    while (r < rows) {
        while (c < cols) {
            printf("%i ", T[r][c]);
            c += 1;
        }
        printf("\n");
        c = 0;
        r += 1;
    }
}
