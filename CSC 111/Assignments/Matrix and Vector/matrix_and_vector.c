/* Yo yo yo
I figured that I shouldn't bother commenting on my code because all of the function descriptions are given in the matrix_and_vector.h file.
Created October 26, 2021 by O. Brown, student number V00988269
*/
#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"

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
   int r, c;
   for (r = 0; r < n; r++) {
      for (c = 0; c < n; c++) {
         M[r][c] = 0;

         if (r == c) {
            M[r][c] = 1;
         }
      }
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
   for (r = 0; r < n - 1; r++) {
      for (c = 0; c < k; c++) {
         if (r < omit_idx) {
            B[r][c] = A[r][c];
         }
         if (r >= omit_idx || omit_idx == 0) {
             B[r][c] = A[r+1][c];
         }
      }
   }
}

void omit_column(int n, int k, double A[n][k], double B[n][k-1], int omit_idx) {
   int r, c;
   for (r = 0; r < n; r++) {
      for (c = 0; c < k - 1; c++) {
         if (c < omit_idx) {
            B[r][c] = A[r][c];
         }
         if (c >= omit_idx || omit_idx == 0) {
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
   int r, c, i, q, t;
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
   if (n >= s && k >= t) {
      for (r = 0; r < s; r++) {
         for (c = 0; c < t; c++) {
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
      if (t <= k) {
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
      if (s <= n) {
         for (r = 0; r < s; r++) {
            for (c = 0; c < t; c++) {
               B[r][c] = A[r][c%k];
            }
         }
      }
   }
}