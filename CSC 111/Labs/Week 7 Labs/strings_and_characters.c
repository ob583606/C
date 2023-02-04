#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_characters(char str[]){
	int total = 0;
    int* p = &total;
    for (int i = 0; str[i] != '\0'; i++) {
        *p += 1;
    }

    return total;
}

int count_words(char str[]){
	int total = 0;
    int* p = &total;
    int spaced = 0;
    int* ps = &spaced;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i]) != 0 || (isspace(str[i]) == 0 && i == 0)) {
            *ps = 1;
        }
        if (isspace(str[i]) == 0 && *ps == 1) {
            *p += 1;
            *ps = 0;
        }
    }

    return total;
}

void capitalize(char str[]){
	for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void invert_capitalization(char str[]){
	for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(){

	char S1[] = "Raspberry";
	char S2[] = "      "; //Contains 0 words, 6 characters
	char S3[] = "CSc 111 FaLL 2021";
	char S4[] = "   raspberry pear pineapple banana";
	char S5[] = "   <-- spaces at the beginning, spaces at the end --> ";

	//Make a new array (initialized to an empty string) to use as temporary storage.
	char W[1000] = "";

	printf("S1: \"%s\"\n", S1 );
	printf("Characters: %d\n", count_characters(S1) );
	printf("Words: %d\n", count_words(S1) );
	strcpy(W, S1);
	capitalize(W);
	printf("Capitalized: \"%s\"\n", W );
	strcpy(W, S1);
	invert_capitalization(W);
	printf("Inverted Capitalization: \"%s\"\n", W );
	printf("\n");

	printf("S2: \"%s\"\n", S2 );
	printf("Characters: %d\n", count_characters(S2) );
	printf("Words: %d\n", count_words(S2) );
	strcpy(W, S2);
	capitalize(W);
	printf("Capitalized: \"%s\"\n", W );
	strcpy(W, S2);
	invert_capitalization(W);
	printf("Inverted Capitalization: \"%s\"\n", W );
	printf("\n");

	printf("S3: \"%s\"\n", S3);
	printf("Characters: %d\n", count_characters(S3) );
	printf("Words: %d\n", count_words(S3) );
	strcpy(W, S3);
	capitalize(W);
	printf("Capitalized: \"%s\"\n", W );
	strcpy(W, S3);
	invert_capitalization(W);
	printf("Inverted Capitalization: \"%s\"\n", W );
	printf("\n");

	printf("S4: \"%s\"\n", S4 );
	printf("Characters: %d\n", count_characters(S4) );
	printf("Words: %d\n", count_words(S4) );
	strcpy(W, S4);
	capitalize(W);
	printf("Capitalized: \"%s\"\n", W );
	strcpy(W, S4);
	invert_capitalization(W);
	printf("Inverted Capitalization: \"%s\"\n", W );
	printf("\n");

	printf("S5: \"%s\"\n", S5 );
	printf("Characters: %d\n", count_characters(S5) );
	printf("Words: %d\n", count_words(S5) );
	strcpy(W, S5);
	capitalize(W);
	printf("Capitalized: \"%s\"\n", W );
	strcpy(W, S5);
	invert_capitalization(W);
	printf("Inverted Capitalization: \"%s\"\n", W );
	printf("\n");

    return 0;
}