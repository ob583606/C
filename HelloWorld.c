// First c program, which is now my testing ground for functions.
#include <stdio.h>
#include <ctype.h>
#include <math.h>

void print_matrix(int rows, int columns, double M[rows][columns]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%7.2f ", M[i][j]);
        printf("\n");
    }
}

void staircase(int n){
    int x = 0;
    printf("X");
    while (x < n) {
        while(0 < x);
        printf("-");
    }
    printf("x");
        x -= 1;
}

void set_vector(int n, double V[n], double s) {
    int i;
    for (i = 0; i < n; i++) {
        V[i] = s;
    }
    
}

int equidistant(int a, int b, int c) {
    if (a == (b+c)/2 || b == (a+c)/2 || c == (a+b)/2) {
        return 1;
    }
    return 0;
}

void print_vector(int size, double V[size]){
    for (int i = 0; i < size; i++)
        printf("%.2f ", V[i]);
    printf("\n");
}

void add_scalar_to_vector(int n, double Vin[n], double Vout[n], double s) {
    int i;
    for(i = 0; i < n; i++) {
        Vout[i] =  Vin[i] + s;
    }
}

double dot_product(int n, double V1[n], double V2[n]) {
    int i;
    double total = 0;
    for(i = 0; i < n; i++){
        total += V1[i] * V2[i];
    }
    return total;
}

double norm(int n, double V[n]) {
    int i;
    double total = 0;
    for(i = 0; i < n; i++){
        total += V[i] * V[i];
    }
    return sqrt(total);
}

void add_vectors(int n, double V1[n], double V2[n], double Vout[n]) {
   int i;
   for (i = 0; i < n; i++) {
      Vout[i] = V1[i] + V2[i];
   }
}

void identity(int n, double M[n][n]) {
   int i;
   for (i = 0; i < n; i++) {
      M[i][i] = 1;
   }
}

int matrices_equal(int rows, int cols, double A[rows][cols], double B[rows][cols]) {
   int r, c, total;
   total = 1;
   for (r = 0; r < rows; r ++) {
      for (c = 0; c < cols; c++){
         if (A[r][c] != B[r][c]) {
            total = 0;
         }
      }
   }
   return total;
}

void add_matrices(int rows, int cols, double A[rows][cols], double B[rows][cols], double C[rows][cols]) {
   int r, c;
   for (r = 0; r < rows; r++) {
      for (c = 0; c < cols; c++) {
         C[r][c] = A[r][c] + B[r][c];
      }
   }
}

double trace(int n, double A[n][n]) {
   int i;
   double total = 0;
   for (i = 0; i < n; i++) {
      total += A[i][i];
   }
   return total;
}

void transpose(int n, int k, double A[n][k], double T[k][n]) {
   int r, c;
   for (r = 0; r < k; r++) {
      for (c = 0; c < n; c++) {
         T[r][c] = A[c][r];
      }
   } 
}

void omit_row(int n, int k, double A[n][k], double B[n-1][k], int omit_idx) {
   int r, c;
   for (r = 0; r < n; r++) {
      for (c = 0; c < k; c++) {
         if (r < omit_idx) {
            B[r][c] = A[r][c];
         }
         if (r >= omit_idx) {
             B[r][c] = A[r+1][c];
         }
      }
   }
}

void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx) {
   int r, c;
   for (r = 0; r < n; r++) {
      for (c = 0; c < k; c++) {
         if (c < omit_idx) {
            B[r][c] = A[r][c];
         }
         if (c >= omit_idx) {
             B[r][c] = A[r][c+1];
         }
      }
   }
}

int main() {
    double M1[3][3] = { {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9} };

    double M2[3][3] = { {1, 1, 1},
                        {0, 2, 2},
                        {0, 0, 3}	};

    double M3[2][5] = { {6, 10, 17, 187, 225},
                        {0.5, 0.25, 0.5, 0.25, 0.5} };

    double M4[5][2] = { {1, 0},
                        {0, 1},
                        {1, 1},
                        {-1, 1},
                        {0, 0} };
    
    double M5[4][3] = { {1, 0.5, 0.33},
                        {0.5, 0.33, 0.25},
                        {0.33, 0.25, 0.2},
                        {0.25, 0.2, 0.16} };

    double M6[4][4] = { {1, 0.5, 0.33, 0.25},
                        {0.5, 0.33, 0.25, 0.2},
                        {0.33, 0.25, 0.2, 0.16},
                        {0.25, 0.2, 0.16, 0.14} };
    
    double M7[4][3] = { {1, 1, 1},
                        {1, 2, 2},
                        {1, 2, 3},
                        {1, 2, 3} };
    
    //M8 is deliberately identical to M7
    double M8[4][3] = { {1, 1, 1},
                        {1, 2, 2},
                        {1, 2, 3},
                        {1, 2, 3} };

    double V1[] = {-0.5, 0.5};
    double V2[] = {9, -9, 1};
    double V3[] = {1, 2, 3, 4};
    
    double Vout[100];

    double I3[3][3], I5[5][5];

    double OmitRow1[3][4], OmitRow2[4][2];
    printf("Testing omit_row:\n");
    printf("Omitting row 0 from M6:\n");
    omit_row(4, 4, M6, OmitRow1, 0);
    print_matrix(3, 4, OmitRow1);
    printf("\n");
    printf("Omitting row 2 from M6:\n");
    omit_row(4, 4, M6, OmitRow1, 2);
    print_matrix(3, 4, OmitRow1);
    printf("\n");
    printf("Omitting row 3 from M4:\n");
    omit_row(5, 2, M4, OmitRow2, 3);
    print_matrix(4, 2, OmitRow2);
    printf("\n");
    
    
    double OmitCol1[4][3], OmitCol2[2][4];
    printf("Testing omit_column:\n");
    printf("Omitting column 0 from M6:\n");
    omit_column(4, 4, M6, OmitCol1, 0);
    print_matrix(4, 3, OmitCol1);
    printf("\n");
    printf("Omitting column 3 from M6:\n");
    omit_column(4, 4, M6, OmitCol1, 3);
    print_matrix(4, 3, OmitCol1);
    printf("\n");
    printf("Omitting column 3 from M3:\n");
    omit_column(2, 5, M3, OmitCol2, 3);
    print_matrix(2, 4, OmitCol2);
    printf("\n");

    return 0;
    
}