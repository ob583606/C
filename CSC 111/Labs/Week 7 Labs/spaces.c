#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* condense_spaces(str, output)
   Given a string str, copy the contents into 
   the string output, deleting any runs of consecutive
   spaces. For example, multiple spaces between words
   should be condensed into a single space.
   Multiple spaces at the beginning and end of the string
   should also be condensed into a single space.
   Use the isspace() function to detect whether a character
   is a space.
*/
void condense_spaces(char str[], char output[]){
	int spaced = 0;
    int* ps = &spaced;
    int length = 0;
    int* pn = &length;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i]) != 0 && *ps < 2) {
            output[*pn] = str[i];
            *pn += 1;
            *ps += 1;
        }
        if (isspace(str[i]) == 0){
            output[*pn] = str[i];
            *pn += 1;
            if (*ps > 0) {
                *ps -= 1;
            }
        }
        if (isspace(str[i]) != 0 && *ps < 2) {
            *ps += 1;
        }
    }
    output[length + 1] = '\0';
}

/* remove_leading_spaces(str, output)
   Given a string str, copy the contents into 
   the string output, ignoring any leading
   spaces (spaces at the beginning of the string).
*/
void remove_leading_spaces(char str[], char output[]){
	int spaced = 1;
    int* ps = &spaced;
    int n = 0;
    int* pn = &n;
    int length = strlen(str);

    for (int r = 0; r < strlen(str); r++) {
        output[r] = str[r];
    }
    for (int i = 0; isspace(str[i]) != 0; i++) {
        *pn += 1;
    }
    for (int w = 0; w < n; w++) {
        output[w] = str[w+n];

        if ( w >= (n-1)) {
            for (int r = w+1; r < length; r++) {
                output[r] = str[r+n];
            }
        }
    }
    output[(length - n) + 1] = '\0';
}

/* remove_trailing_spaces(str, output)
   Given a string str, copy the contents into 
   the string output, ignoring any trailing
   spaces (spaces at the end of the string).
*/
void remove_trailing_spaces(char str[], char output[]){
    for (int r = 0; r < strlen(str); r++) {
        output[r] = str[r];
    }
    for (int i = strlen(str); isspace(str[i]) != 0; i -= 1) {
        output[i+1] = '\0';
    }

}
int main(){

	char S1[] = "Hello         World ";
	char S2[] = "      "; //Contains 0 words, 6 characters
	char S3[] = "CSC    111    Fall 2021";
	char S4[] = "   raspberry    pear pineapple    banana  ";
	char S5[] = "   <-- spaces at the beginning, spaces at the end --> ";

	//Make a new array (initialized to an empty string) to use for the output.
	char W[1000] = "";

	printf("S1: \"%s\"\n", S1);
	condense_spaces(S1, W);
	printf("With spaces condensed: \"%s\"\n", W);
	remove_leading_spaces(S1, W);
	printf("With leading spaces removed: \"%s\"\n", W);
	remove_trailing_spaces(S1, W);
	printf("With trailing spaces removed: \"%s\"\n", W);
	printf("\n");

	printf("S2: \"%s\"\n", S2);
	condense_spaces(S2, W);
	printf("With spaces condensed: \"%s\"\n", W);
	remove_leading_spaces(S2, W);
	printf("With leading spaces removed: \"%s\"\n", W);
	remove_trailing_spaces(S2, W);
	printf("With trailing spaces removed: \"%s\"\n", W);
	printf("\n");

	printf("S3: \"%s\"\n", S3);
	condense_spaces(S3, W);
	printf("With spaces condensed: \"%s\"\n", W);
	remove_leading_spaces(S3, W);
	printf("With leading spaces removed: \"%s\"\n", W);
	remove_trailing_spaces(S3, W);
	printf("With trailing spaces removed: \"%s\"\n", W);
	printf("\n");

	printf("S4: \"%s\"\n", S4);
	condense_spaces(S4, W);
	printf("With spaces condensed: \"%s\"\n", W);
	remove_leading_spaces(S4, W);
	printf("With leading spaces removed: \"%s\"\n", W);
	remove_trailing_spaces(S4, W);
	printf("With trailing spaces removed: \"%s\"\n", W);
	printf("\n");

	printf("S5: \"%s\"\n", S5);
	condense_spaces(S5, W);
	printf("With spaces condensed: \"%s\"\n", W);
	remove_leading_spaces(S5, W);
	printf("With leading spaces removed: \"%s\"\n", W);
	remove_trailing_spaces(S5, W);
	printf("With trailing spaces removed: \"%s\"\n", W);
	printf("\n");

    return 0;
}