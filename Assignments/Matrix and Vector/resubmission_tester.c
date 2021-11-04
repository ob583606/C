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

    double M1[3][3] = { {1, 1, 1},
                        {0, 2, 2},
                        {0, 0, 3} };

    double M2[5][2] = { {2, 3},
                        {4, 5},
                        {6, 9},
                        {11, 13},
                        {98, 99} };
    
    double M3[4][3] = { {1, 0.5, 0.33},
                        {0.5, 0.33, 0.25},
                        {0.33, 0.25, 0.2},
                        {0.25, 0.2, 0.16} };
    
    
    printf("Testing transpose:\n");
    printf("Input matrix M1:\n");
    print_matrix(3, 3, M1);
    printf("Input matrix M2:\n");
    print_matrix(5, 2, M2);
    printf("Input matrix M3:\n");
    print_matrix(4, 3, M3);
    printf("\n");
    
    double R1[3][3];
    printf("Omitting row 1 from M1 (third row should be inf):\n");
    invalidate_matrix(3, 3, R1);
    omit_row(3, 3, M1, R1, 1);
    print_matrix(3, 3, R1);
    printf("\n");

    printf("Omitting row 2 from M1 (third row should be inf):\n");
    invalidate_matrix(3, 3, R1);
    omit_row(3, 3, M1, R1, 2);
    print_matrix(3, 3, R1);
    printf("\n");
    
    double R2[5][2];
    printf("Omitting row 0 from M2 (fifth row should be inf):\n");
    invalidate_matrix(5, 2, R2);
    omit_row(5, 2, M2, R2, 0);
    print_matrix(5, 2, R2);
    printf("\n");
    
    printf("Omitting row 4 from M2 (fifth row should be inf):\n");
    invalidate_matrix(5, 2, R2);
    omit_row(5, 2, M2, R2, 4);
    print_matrix(5, 2, R2);
    printf("\n");

    
    double R3[4][3];
    printf("Omitting row 3 from M3 (fourth row should be inf):\n");
    invalidate_matrix(4, 3, R3);
    omit_row(4, 3, M2, R3, 3);
    print_matrix(4, 3, R3);
    printf("\n");
    
    
    
    printf("Printing input matrices (which should be unchanged):\n");
    printf("Input matrix M1:\n");
    print_matrix(3, 3, M1);
    printf("Input matrix M2:\n");
    print_matrix(5, 2, M2);
    printf("Input matrix M3:\n");
    print_matrix(4, 3, M3);
    printf("\n");
    
    
    return 0;
}