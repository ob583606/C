// First c program, which is now my testing ground for functions.
#include <stdio.h>

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

int main() {
    double V[] = {1, 2, 3, 4, 5};
    double W[] = {0, 1, 0, 1, 0};
    double X[] = {10, 20, 30, 3.5, 3.6, 3.1415, 1.7};
    double Y[] = {111, 116, 225, 230, 265, 370};
    double Z[] = {0, 0, 0, 999, 999};
    double Q[100];

    printf("Testing dot_product:\n");
    printf("Result (V dot W, size 3): %.2f\n", dot_product(3, V, W));
    printf("Result (V dot W, size 5): %.2f\n", dot_product(5, V, W));
    printf("Result (W dot X, size 5): %.2f\n", dot_product(5, W, X));
    printf("\n");

    return 0;
    
}