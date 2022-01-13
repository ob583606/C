#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* get_flavour(filename, index, flavour)
   Given a filename of a text file, which will contain a list 
   of flavours of ice cream (one per line), along with an integer 
   index and an output buffer (called "flavour"), read the text 
   file and store the line at the given index into the output buffer 
   as a string.

   Index 0 should be interpreted to mean the first line of the file.
   If the provided index is negative or if it is greater than or equal
   to the number of lines in the file, the function will copy the string
   "Invalid" into the output buffer and return.

   If the file cannot be opened, the function will return without 
   modifying the output buffer.

   The last line of the file will not necessarily end in a newline (\n) character.

   Don't forget to close all files that are opened during the function.

   You may assume that each line of the file contains at most 100 characters.

   Parameters: filename (string), index (integer), flavour (array of char)
   Return value: None 
*/
/* Your answer from below would be placed here */
void get_flavour(char filename[], int index, char flavour[]) {
    FILE* input_file = fopen(filename, "r");

    char garbage[1000];

    if (input_file == NULL) {
        exit(0);
    }

    for (int i = 0; i < index; i++) {
        fgets(garbage, 99, input_file);
    }

    if (fgets(flavour, 99, input_file) == NULL) {
        flavour[0] = 'I';
        flavour[1] = 'n';
        flavour[2] = 'v';
        flavour[3] = 'a';
        flavour[4] = 'l';
        flavour[5] = 'i';
        flavour[6] = 'd';
        flavour[7] = '\0';   
    }
    if (flavour[0] != 'I') {
        for (int i = 0; flavour[i] != '\0'; i++) {
            if (flavour[i] == '\n') {
                flavour[i] = '\0';
            }
        }
    }
    fclose(input_file);
}

int main(){
    char filename[] = "ice_cream.txt";

    char the_flavour[101];
    get_flavour(filename, 6, the_flavour);
    printf("Flavour 6 is [%s]\n", the_flavour);
    get_flavour(filename, 10, the_flavour);
    printf("Flavour 10 is [%s]\n", the_flavour);
    get_flavour(filename, 17, the_flavour);
    printf("Flavour 17 is [%s]\n", the_flavour);

    return 0;
}
