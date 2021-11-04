/* 06_identity/main.c
   CSC 111 - Fall 2021 - Assignment 5


   B. Bird - 10/09/2021
*/


#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"


//print_matrix(rows, columns, M)
//Print the contents of the matrix M
static void print_matrix(int rows, int columns, double M[rows][columns]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%7.2f ", M[i][j]);
        printf("\n");
    }
}
    
// invalidate_matrix(rows, columns, M)
// Set every element of M to infinity
static void invalidate_matrix(int rows, int columns, double M[rows][columns]){
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            M[i][j] = INFINITY;
}

int main(){

    double M1[2][3] = { {1,   6, 111},
                        {10, 17, 187} };

    double M2[5][2] = { {2, 3},
                        {4, 5},
                        {6, 9},
                        {11, 13},
                        {98, 99} };
    
    double M3[3][6] = { {1, 1, 2, 3, 5, 8},
                        {3, 1, 4, 1, 5, 9},
                        {2, 7, 1, 8, 2, 8} };

    
    double T1[3][2], T2[4][2];
    
    printf("Testing tile:\n");
    printf("Input matrix M1:\n");
    print_matrix(2, 3, M1);
    printf("Input matrix M2:\n");
    print_matrix(5, 2, M2);
    printf("Input matrix M3:\n");
    print_matrix(3, 6, M3);
    printf("\n");
    
    printf("Tiling M1 to be 2 x 2 (third row of the result should be inf):\n");
    invalidate_matrix(3, 2, T1);
    tile(2, 3, M1, 2, 2, T1);
    print_matrix(3, 2, T1);
    printf("\n");
    
    printf("Tiling M2 to be 2 x 2 (third row of the result should be inf):\n");
    invalidate_matrix(3, 2, T1);
    tile(5, 2, M2, 2, 2, T1);
    print_matrix(3, 2, T1);
    printf("\n");
    
    printf("Tiling M3 to be 2 x 2 (third row of the result should be inf):\n");
    invalidate_matrix(3, 2, T1);
    tile(3, 6, M3, 2, 2, T1);
    print_matrix(3, 2, T1);
    printf("\n");
    
    printf("Tiling M1 to be 3 x 2 (fourth row of the result should be inf):\n");
    invalidate_matrix(4, 2, T2);
    tile(3, 2, M1, 3, 2, T2);
    print_matrix(4, 2, T2);
    printf("\n");
    
    printf("Tiling M2 to be 3 x 2 (fourth row of the result should be inf):\n");
    invalidate_matrix(4, 2, T2);
    tile(5, 2, M2, 3, 2, T2);
    print_matrix(4, 2, T2);
    printf("\n");
    
    printf("Tiling M3 to be 3 x 2 (fourth row of the result should be inf):\n");
    invalidate_matrix(4, 2, T2);
    tile(3, 6, M3, 3, 2, T2);
    print_matrix(4, 2, T2);
    printf("\n");
    
        
    
    
    printf("Printing input matrices/vectors (which should be unchanged):\n");
    printf("Input matrix M1:\n");
    print_matrix(2, 3, M1);
    printf("Input matrix M2:\n");
    print_matrix(5, 2, M2);
    printf("Input matrix M3:\n");
    print_matrix(3, 6, M3);
    printf("\n");
    
    
    return 0;
}