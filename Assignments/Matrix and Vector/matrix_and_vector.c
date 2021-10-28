/* matrix_and_vector.c
   CSC 111 - Fall 2021 - Assignment 5

   O. Brown - 27/10/2021
*/
#include <stdio.h>
#include <math.h>
#include "matrix_and_vector.h"

/****************************** VECTOR FUNCTIONS ******************************/

/* set_vector(n, V, s)
   Given an integer n, a vector V with n elements, and a scalar s,
   set every index of V to equal the value of s.
   
   Do not set any other indices of the vector.

   Parameters: n (integer), V (array of double), s (double)
   Return value: None
*/
void set_vector(int n, double V[n], double s) {
    int i;
    for (i = 0; i < n; i++) {
        V[i] = s;
    }
    
}

/* add_scalar_to_vector(n, Vin, Vout, s)
   Given an integer n, an input vector Vin (with size n), an output vector
   Vout (with size n) and a scalar value s, set the vector Vout to contain
   the result of adding the scalar s to the vector Vin.

   Do not modify any elements of the input vector Vin.

   Parameters: n (integer), Vin (array of double), Vout (array of double), s (double)
   Return value: None
*/
void add_scalar_to_vector(int n, double Vin[n], double Vout[n], double s) {
    int i;
    for(i = 0; i < n; i++) {
        Vout[i] =  Vin[i] + s;
    }
}

/* dot_product(n, V1, V2)
   Given an integer n and two n-element vectors V1 and V2, compute and return
   the dot product of V1 and V2.

   Do not modify any elements of the input vectors V1 and V2.

   Parameters: n (integer), V1 (array of double), V2 (array of double)
   Return value (double): Dot product of V1 and V2
*/

double dot_product(int n, double V1[n], double V2[n]) {
    int i;
    double total = 0;
    for(i = 0; i < n; i++){
        total += V1[i] * V2[i];
    }
    return total;
}

/* norm(n, V)
   Given an integer n and a vector V of size n, return the norm (length) of V.

   Recall that the length of a vector V is the square root of the dot product 
   of V with itself.

   Do not modify any elements of the input vector V.

   Parameters: n (integer), V (array of double)
   Return value (double): Norm (length) of the vector V
*/
double norm(int n, double V[n]) {
    int i;
    double total = 0;
    for(i = 0; i < n; i++){
        total += V[i] * V[i];
    }
    return sqrt(total);
}

/* add_vectors(n, V1, V2, Vout)
   Given an integer n, two input vectors V1 and V2 (of size n) and an output 
   vector Vout (also of size n), compute the (elementwise) vector sum V1 + V2 
   and store the result into Vout.

   Do not modify any elements of the input vectors V1 and V2.

   Parameters: n (integer), V1 (array of double), V2 (array of double), Vout (array of double)
   Return value: None
*/
void add_vectors(int n, double V1[n], double V2[n], double Vout[n]) {
   int i;
   for (i = 0; i < n; i++) {
      Vout[i] = V1[i] + V2[i];
   }
}




/****************************** MATRIX FUNCTIONS ******************************/


/* identity(size, M)
   Given an integer n and an n x n output matrix M, set M to be the n x n
   identity matrix.

   Parameters: n (integer), M (2d array of double)
   Return value: None
*/
void identity(int n, double M[n][n]) {
   int i;
   for (i = 0; i < n; i++) {
      M[i][i] = 1;
   }
}

/* matrices_equal(rows, cols, A, B)
   Given two input matrices A and B (both with the number of rows/columns provided),
   return 1 if they are equal and 0 otherwise.

   (As a simplification, you may assume that two matrices are equal if their elements are
    exactly the same. In practice, matrices would normally be considered equal if elements
    were within some small tolerance value to account for things like rounding errors).

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double)
   Return value (integer):
     - Return 1 if the two matrices are equal (that is, if each element of A is equal to the corresponding element of B)
     - Return 0 otherwise 
*/
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

/* add_matrices(rows, cols, A, B, C)
   Given two input matrices A and B (both with the number of rows/columns provided),
   set C to be the elementwise sum of A and B.
   Do not modify any elements of the input matrices A and B.

   Parameters: rows (integer), cols (integer), A (2d array of double), B (2d array of double), C (2d array of double)
   Return value: None
*/
void add_matrices(int rows, int cols, double A[rows][cols], double B[rows][cols], double C[rows][cols]) {
   int r, c;
   for (r = 0; r < rows; r++) {
      for (c = 0; c < cols; c++) {
         C[r][c] = A[r][c] + B[r][c];
      }
   }
}

/* trace(n, A)
   Given an integer n and a matrix A with n rows and n columns, compute the 
   trace of A.

   The trace of a matrix is the sum of the entries along the forward diagonal.
   For example, consider the matrix
          7 -1 -2 
     A =  6 10 17
          9 20 111
   the trace of A is 7 + 10 + 111 = 128

   Parameters: n (integer), A (2d array of double)
   Return value (double): The trace of A
*/
double trace(int n, double A[n][n]) {
   int i;
   double total = 0;
   for (i = 0; i < n; i++) {
      total += A[i][i];
   }
   return total;
}

/* transpose(n, k, A, T)
   Given integers n and k, along with an n x k input matrix A
   and a k x n output matrix T, set T to be the transpose of A. 

   Do not modify any elements of the input matrix A.

   Parameters: n (integer), k (integer), A (2d array of double), T (2d array of double)
   Return value: None
*/
void transpose(int n, int k, double A[n][k], double T[k][n]) {
   int r, c;
   for (r = 0; r < k; r++) {
      for (c = 0; c < n; c++) {
         T[r][c] = A[c][r];
      }
   } 
}

/* omit_row(n, k, A, B, omit_idx)
   Given integers n and k, along with an n x k input matrix A, an (n-1) x k
   output matrix B and an integer omit_idx, copy the elements of A into B, 
   completely omitting the row with index omit_idx (and shifting the remaining
   rows to fill in the empty space in B created by the omission).
   
   Notice that the dimensions of B has one fewer row than A, since the omitted
   row will not be present in B.

   Do not modify any elements of the input matrix A.

   Parameters: n (integer), k (integer), A (2d array of double), 
               B (2d array of double), omit_idx (integer)
   Return value: None
*/
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

/* omit_column(n, k, A, B, omit_idx)
   Given integers n and k, along with an n x k input matrix A, an n x (k-1)
   output matrix B and an integer omit_idx, copy the elements of A into B, 
   completely omitting the column with index omit_idx (and shifting the remaining
   columns to fill in the empty space in B created by the omission).
   
   Notice that the dimensions of B has one fewer column than A, since the omitted
   column will not be present in B.

   Do not modify any elements of the input matrix A.

   Parameters: n (integer), k (integer), A (2d array of double), 
               B (2d array of double), omit_idx (integer)
   Return value: None
*/
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

/* matrix_vector_multiply(n, k, A, V, Vout)
   Given integers n and k, multiply the n x k matrix A by the k-element vector V, 
   producting an n-element vector Vout.

   Note that the product AV where A is an n x k matrix and V is a k-element vector 
   can be computed with the usual matrix multiplication algorithm by treating V 
   as a k x 1 matrix.

   Do not modify any elements of the input matrices A and B or the input vector V.

   Parameters: n (integer), k (integer), A (2d array of double), 
               V (array of double), Vout (array of double)
   Return value: None
*/
void matrix_vector_multiply(int n, int k, double A[n][k], double V[k], double Vout[n]){
   printf("poop hole");
}

/* matrix_multiply(m, n, k, A, B, C)
   Given integers m, n and k, compute the matrix product C = A*B.
   The input matrix A will be m x n and the input matrix B will be n x k.
   The output matrix C will be m x k.
   
   Do not modify any elements of the input matrices A and B.

   If you are unfamiliar with matrix multiplication, a tutorial on basic 
   linear algebra (recorded in Fall 2020) has been posted at
     https://www.youtube.com/watch?v=gxwten_khso
   (for specific details about matrix multiplication, skip to 10:45 in the video)

   You can also take a look at the Wikipedia article
     https://en.wikipedia.org/wiki/Matrix_multiplication

   Parameters: 
      m, n, k (all integers)
      A, B, C (all 2d arrays of double, note the different dimensions in the signature)
   Return value: None
*/
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

/* tile(n, k, A, s, t, B)
   This function takes the following parameters:
    - Integers n and k, and an n x k input matrix A
    - Integers s and t, and an s x t output matrix B
   
   The function will fill the output matrix B with copies of the input matrix
   A, with copies repeating if the input matrix is smaller than the output
   matrix. In the event that the dimensions of A do not evenly divide
   the dimensions of B, some parts of a copy of A may be cut off by the edges
   of B (see example below).

   Example 1: If A is the 2 x 3 matrix 
     6  10  17
    -1  -2  -5
   and B has dimensions 9 x 5, the contents of B after the function 
   completes will be
      6  10  17   6  10
     -1  -2  -5  -1  -2
      6  10  17   6  10
     -1  -2  -5  -1  -2
      6  10  17   6  10
     -1  -2  -5  -1  -2
      6  10  17   6  10
     -1  -2  -5  -1  -2
      6  10  17   6  10

   Example 2: If A is the 2 x 2 matrix 
    111  116
    349  445
   and B has dimensions 4 x 3, the contents of B after the function 
   completes will be
    111  116  111
    349  445  349
    111  116  111
    349  445  349

   Example 3: If A is the 3 x 3 matrix 
      6   10   17
      1    8    7
      4    4    5
   and B has dimensions 2 x 2, the contents of B after the function 
   completes will be
      6   10
      1    8

   Do not modify any indices of B outside of its provided dimensions.
   Do not modify any elements of the input matrix A.

   Parameters: n (integer), k (integer), A (2d array of double)
               s (integer), t (integer), B (2d array of double)
   Return value: None
*/
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