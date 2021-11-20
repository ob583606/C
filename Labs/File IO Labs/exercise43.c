#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

	FILE* input_file = fopen("some_text.txt", "r");

	if (input_file == NULL) {
        printf("File couldn't open properly, exiting");
        return 1;
    }

	int sum = 0;
	int alphabetSoup = 0;
    int totalChar = 0;
    int totalLine = 1;
	char input_buffer[10];
	while( fgets(input_buffer, 10, input_file) != NULL ){
		for (int i = 0; i < strlen(input_buffer); i++) {
			totalChar += 1;
			if (isalpha(input_buffer[i]) != 0) {
				alphabetSoup += 1;
			}
			input_buffer[i] = toupper(input_buffer[i]);
		}
		if (input_buffer[strlen(input_buffer) - 1] == '\n') {
            totalLine += 1;
        }
        printf("%s", input_buffer);
	}

	fclose(input_file);

	printf("\nTotal Characters: %i, Total alphabetical characters: %i, Total lines: %i", totalChar, alphabetSoup, totalLine);

    return 0;
}