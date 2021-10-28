#include <stdio.h>

void print_matrix(int rows, int columns, double M[rows][columns]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%7.2f ", M[i][j]);
        printf("\n");
    }
    printf("\n");
}

void algoVert(int rows, int columns, double M[rows][columns]) {
    int r, c, rL, rU, cL, cU, cT;
    cT = 0;

    for (c = 1; c < columns; c++) {
        if (M[0][c] == (rows-1)) {
            for (r = 1; r < rows; r++) {
                M[r][c] = 1;
            }
        }
        if (2*M[0][c] > (rows-1)) {
            cL = rows - M[0][c];
            cU = rows - (cL-1);
            for (r = cL; r < cU; r++) {
                M[r][c] = 1;
            }
        }
        for (r = 1; r < rows; r++) {
            if (M[r][1] != -1) {
                cT += M[r][1];
            }
        }
        if (cT == M[0][c]) {
            for (r =1; r < rows; r++) {
                if (M[r][1] == 0) {
                    M[r][1] = -1;
                }
            }
        }
    }
}

void algoHor(int rows, int columns, double M[rows][columns]) {
    int r, c, rL, rU, rT, cL, cU;
    rT = 0;
    for (r = 1; r < rows; r++) {
        if (M[r][0] == (columns-1)) {
            for (c = 1; c < columns; c++) {
                M[r][c] = 1;
            }
        }
        if (2*M[r][0] > (columns-1)) {
            rL = columns - M[r][0];
            rU = columns - (rL-1);
            for (c = rL; c < rU; c++) {
                M[r][c] = 1;
            }
        }
        for (c = 1; c < columns; c++) {
            if (M[1][c] != -1) {
                rT += M[1][c];
            }
        }
        if (rT == M[r][0]) {
            for (c =1; c < columns; c++) {
                if (M[1][c] == 0) {
                    M[1][c] = -1;
                }
            }
        }
    }
}

int main() {

    double M[11][11] = { 
        {0, 8, 10, 10, 10, 10, 10, 10, 10, 10, 10},
        {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        
    };
    
    algoVert(11, 11, M);
    print_matrix(11, 11, M);

    algoHor(11, 11, M);
    print_matrix(11, 11, M);

    algoVert(11, 11, M);
    print_matrix(11, 11, M);

    algoHor(11, 11, M);
    print_matrix(11, 11, M);

    return 0;
}