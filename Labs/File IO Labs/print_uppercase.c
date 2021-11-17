#include <stdio.h>
#include <ctype.h>


int main(){

	FILE* input_file = fopen("some_text.txt", "r");

    /* By using modee 'a' instead of 'w' in our fopen function, it Appends rather than Writes. That means it just adds on each time instead of making a new file.
    Probably quite useful for stuff like crash logs. */
    
	int ch = fgetc(input_file);
    int alphabetSoup = 0;
    int totalChar = 0;

    while (ch != EOF) {
        totalChar += 1;
        if (isalpha(ch) != 0) {
            alphabetSoup += 1;
        }

        ch = toupper(ch);
        printf("%c", ch);
        ch = fgetc(input_file);
    }

	fclose(input_file);

    printf("\nTotal Characters: %i, Total alphabetical characters: %i", totalChar, alphabetSoup);

    return 0;
}