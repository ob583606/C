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

void print_column_vector(int size, double V[size]){
    for (int i = 0; i < size; i++)
        printf("%7.2f\n", V[i]);
}

int equidistant(int a, int b, int c) {
    if (a == (b+c)/2 || b == (a+c)/2 || c == (a+b)/2) {
        return 1;
    }
    return 0;
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

void print_vector(int size, double V[size]){
    for (int i = 0; i < size; i++)
        printf("%.2f ", V[i]);
    printf("\n");
}

void set_vector(int n, double V[n], double s) {
    int i;
    for (i = 0; i < n; i++) {
        V[i] = s;
    }
    
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

void matrix_vector_multiply(int n, int k, double A[n][k], double V[k], double Vout[n]){
   int r, c;
   double cT = 0;
   for (r = 0; r < n; r++) {
      for (c = 0; c < k; c++) {
         cT += A[r][c]*V[c];
      }
      Vout[r] = cT;
      cT = 0;
   }
}

void matrix_multiply(int m, int n, int k, double A[m][n], double B[n][k], double C[m][k]){
   int r, c, i, q, t, p;
   double cT = 0;
   i = 0;
   q = 0;
   t = 0;

   for (c = 0; c < m; c++) {
      for (r = 0; r < k; r++) {
         for (i = c; i < n + c; i++) {
            cT += A[(r + t) - q][i-t]*B[i-t][r];
         }
         C[c][r] = cT;
         cT = 0;
         q += 1;
      }  
      q = 0;
      t += 1;
   }
   t = 0;
}

void tile(int n, int k, double A[n][k], int s, int t, double B[s][t]) {
   int r, c;
   if (n > s && k > t) {
      for (r = 0; r < n; r++) {
         for (c = 0; c < k; c++) {
            B[r][c] = A[r][c];
         }
      }
   }
   if (s > n) {
      if (t > k) {
         for (r = 0; r < s; r++) {
            for (c = 0; c < t; c++) {
               B[r][c] = A[r%n][c%k];
            }
         }
      }
      if (t < k) {
         for (r = 0; r < s; r++) {
            for (c = 0; c < t; c++) {
               B[r][c] = A[r%n][c];
            }
         }
      }
   }
   if (t > k) {
      if (s > n) {
         for (r = 0; r < s; r++) {
            for (c = 0; c < t; c++) {
               B[r][c] = A[r%n][c%k];
            }
         }
      }
      if (s < n) {
         for (r = 0; r < s; r++) {
            for (c = 0; c < t; c++) {
               B[r][c] = A[r][c%k];
            }
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
    
    double Vout[100]; //This is deliberately too large so that we can use it as the output for multiple tests.
        

    double I3[3][3], I5[5][5];
    printf("Testing identity:\n");
    printf("3 x 3 identity matrix:\n");
    identity(3, I3);
    print_matrix(3, 3, I3);
    printf("\n");
    printf("5 x 5 identity matrix:\n");
    identity(5, I5);
    print_matrix(5, 5, I5);
    printf("\n");
    printf("\n");


    printf("Testing matrices_equal:\n");
    printf("Is M1 equal to itself? matrices_equal returns %d\n", matrices_equal(3,3,M1,M1));
    printf("Are M1 and M2 equal? matrices_equal returns %d\n", matrices_equal(3,3,M1,M2));
    printf("Are M7 and M8 equal? matrices_equal returns %d\n", matrices_equal(4,3,M7,M8));
    printf("Are M5 and M7 equal? matrices_equal returns %d\n", matrices_equal(4,3,M5,M7));
    printf("\n");
    printf("\n");

    
    double T1[3][3], T2[5][2];
    printf("Testing transpose:\n");
    printf("Transpose of M1:\n");
    transpose(3, 3, M1, T1);
    print_matrix(3, 3, T1);
    printf("\n");
    printf("Transpose of M3:\n");
    transpose(2, 5, M3, T2);
    print_matrix(5, 2, T2); //Note that that the row/column counts are swapped by transposing
    printf("\n");
    printf("\n");
    
    
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
    
    double Add1[3][3], Add2[4][3];
    printf("Testing add_matrices:\n");
    printf("M1 + M2:\n");
    add_matrices(3, 3, M1, M2, Add1);
    print_matrix(3, 3, Add1);
    printf("\n");
    printf("M5 + M7:\n");
    add_matrices(4, 3, M5, M7, Add2);
    print_matrix(4, 3, Add2);
    printf("\n");
    printf("\n");


    printf("Testing trace:\n");
    printf("Trace of M1: %.2f\n", trace(3, M1));
    printf("Trace of M2: %.2f\n", trace(3, M2));
    printf("Trace of M6: %.2f\n", trace(4, M6));
    printf("\n");
    printf("\n");
    
    
    printf("Testing matrix_vector_multiply:\n");
    printf("(The results of each part are printed as column vectors)\n");
    printf("M1 * V2:\n");
    matrix_vector_multiply(3, 3, M1, V2, Vout);
    print_column_vector(3, Vout);
    printf("\n");
    printf("M2 * V2:\n");
    matrix_vector_multiply(3, 3, M2, V2, Vout);
    print_column_vector(3, Vout);
    printf("\n");
    printf("M4 * V1:\n");
    matrix_vector_multiply(5, 2, M4, V1, Vout);
    print_column_vector(5, Vout);
    printf("\n");
    printf("M5 * V2:\n");
    matrix_vector_multiply(4, 3, M5, V2, Vout);
    print_column_vector(4, Vout);
    printf("\n");
    printf("M6 * V3:\n");
    matrix_vector_multiply(4, 4, M6, V3, Vout);
    print_column_vector(4, Vout);
    printf("\n");
    printf("M7 * V2:\n");
    matrix_vector_multiply(4, 3, M7, V2, Vout);
    print_column_vector(4, Vout);
    printf("\n");
    printf("\n");


    double Mul1[3][3], Mul2[2][2], Mul3[5][5], Mul4[4][4], Mul5[4][3];
    printf("Testing matrix_multiply:\n");
    printf("M1 * M2:\n");
    matrix_multiply(3, 3, 3, M1, M2, Mul1);
    print_matrix(3, 3, Mul1);
    printf("\n");
    printf("M3 * M4:\n");
    matrix_multiply(2, 5, 2, M3, M4, Mul2);
    print_matrix(2, 2, Mul2);
    printf("\n");
    printf("M4 * M3:\n");
    matrix_multiply(5, 2, 5, M4, M3, Mul3);
    print_matrix(5, 5, Mul3);
    printf("\n");
    printf("M6 * M6:\n");
    matrix_multiply(4, 4, 4, M6, M6, Mul4);
    print_matrix(4, 4, Mul4);
    printf("\n");
    printf("M6 * M5:\n");
    matrix_multiply(4, 4, 3, M6, M5, Mul5);
    print_matrix(4, 3, Mul5);
    printf("\n");
    printf("M6 * M7:\n");
    matrix_multiply(4, 4, 3, M6, M7, Mul5);
    print_matrix(4, 3, Mul5);
    printf("\n");
    printf("\n");


    double Tile1[6][6], Tile2[4][5];
    printf("Testing tile:\n");
    printf("Tiling M1 to be 6 x 6:\n");
    tile(3, 3, M1, 6, 6, Tile1);
    print_matrix(6, 6, Tile1);
    printf("\n");
    printf("Tiling M3 to be 6 x 6:\n");
    tile(2, 5, M3, 6, 6, Tile1);
    print_matrix(6, 6, Tile1);
    printf("\n");
    printf("Tiling M4 to be 6 x 6:\n");
    tile(5, 2, M4, 6, 6, Tile1);
    print_matrix(6, 6, Tile1);
    printf("\n");
    printf("Tiling M4 to be 4 x 5:\n");
    tile(5, 2, M4, 4, 5, Tile2);
    print_matrix(4, 5, Tile2);
    printf("\n"); 
}