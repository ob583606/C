#include <stdio.h>
#include <stdlib.h>

void print_dot(){
	printf(".");
}

void print_x(){
	printf("X");
}

void print_newline(){
	printf("\n");
}

void print_pattern(){
    int i, dotCount, xCount;
    i = 0;
    dotCount = 5;
    xCount = 1;
    while (dotCount >= 0) {
        for (i = 0; i < dotCount; i++)
        {
            print_dot();
        }
        for ( i = 0; i < xCount; i++)
        {
            print_x();
        }
        for (i = 0; i < dotCount; i++)
        {
            print_dot();
        }
        dotCount -= 1;
        xCount += 2;
        print_newline();
    }
}

int main(){

	print_pattern();

	return 0;
}