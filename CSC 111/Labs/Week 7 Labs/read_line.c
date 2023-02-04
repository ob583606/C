#include <stdio.h>

int read_line(int size, char output_array[size]){
	char ch;
    ch = getchar();
    int i = 0;
    int* p = &i;

    while (ch != '\n' && *p < size - 1) {
        output_array[*p] = ch;

        *p += 1;
        ch = getchar();
    }

    output_array[i] = '\0';

    return *p;
}

int main(){

	char the_line[1000];

	int num_read = 0;

	printf("Enter a line of input:\n");
	num_read = read_line(1000, the_line);

	printf("Characters read: %d\n", num_read);
	printf("You entered: %s\n", the_line);

	printf("Enter another line (of at most 4 characters):\n");
	num_read = read_line(5, the_line);

	printf("Characters read: %d\n", num_read);
	printf("You entered: %s\n", the_line);

    return 0;
}