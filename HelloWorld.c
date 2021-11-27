// First c program, which is now my testing ground for functions.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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

int count_observations(char filename[]){
   int values = 0;
   char filechars[100];
   FILE* input_file = fopen(filename, "r");
   if (input_file == NULL) {
      return -1;
   }
   while(fscanf(input_file, "%99s", &filechars) == 1) {
      values += 1;
   }
   return (values/7);
}

int main() {
   char a1[] = "dontreadmelol.txt";
   printf("%i", count_observations(a1));

   return 0;
}