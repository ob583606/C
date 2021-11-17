#include <stdio.h>
#include <ctype.h>


int main(){

	FILE* input_file = fopen("some_text.txt", "r");

	if (input_file == NULL) {
        printf("File didn't open properly bozo");
        return 1;
    }

	char input_buffer[100];
	while( fgets(input_buffer, 100, input_file) != NULL ){
		//Do something with the contents of input_buffer...
	}

	fclose(input_file);

    return 0;
}