#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

	FILE* input_file = fopen("some_text.txt", "r");

	if (input_file == NULL) {
        printf("File didn't open properly bozo");
        return 1;
    }

	int sum = 0;
	int alphabetSoup = 0;
    int totalChar = 0;
    int totalLine = 0;
	char input_buffer[100];
	while( fgets(input_buffer, 100, input_file) != NULL ){
		for (int i = 0; i < strlen(input_buffer); i++) {
			totalChar += 1;
			if (isalpha(input_buffer[i]) != 0) {
				alphabetSoup += 1;
			}
			input_buffer[i] = toupper(input_buffer[i]);
		}
		totalLine += 1;
        printf("%s", input_buffer);
	}

	fclose(input_file);

	printf("\nTotal Characters: %i, Total alphabetical characters: %i, Total lines: %i", totalChar, alphabetSoup, totalLine);

    return 0;
}