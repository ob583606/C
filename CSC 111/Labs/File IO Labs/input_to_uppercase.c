#include <stdio.h>
#include <ctype.h>


int main(){

	FILE* output_file = fopen("uppercase_text.txt", "w");

    /* By using modee 'a' instead of 'w' in our fopen function, it Appends rather than Writes. That means it just adds on each time instead of making a new file.
    Probably quite useful for stuff like crash logs. */
    
	char ch = getchar();

    while (ch != '#') {
        ch = toupper(ch);
        fprintf(output_file, "%c", ch);
        ch = getchar();
    }

	fclose(output_file);

    return 0;
}