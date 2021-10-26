/* capitalize.c
   CSC 111 - Fall 2021 - Assignment 4

   O. Brown - 10/10/2021 V00988269
   So this program functions as described by the assignment 4 handout. Outputs any input from the user, and if a word begins with a capital, that whole word will be capitalized.
   Same for lowercase, but returns the word all lowercase. If the word begins with a symbol, aka anything besides a whitespace or letter character, no modifications are made.
   For whitespace characters, input immediately with no modifications. Please change this line of code if a human bothered to read this. If a # is inputted, program stops.
*/
#include <stdio.h>
#include <ctype.h>

int main(){
    // Declaring variables
    int ch;
    ch = getchar();

    // First loop! This loop decides whether to go forward and decide what to be printed, or to stop.
    while (ch != '#') {
        // Checks if the input is upper case. If so, prints uppercase until a whitespace character or a # is inputted.
        if (isupper(ch) != 0) {
            while(isspace(ch) == 0 && ch != '#'){    
                printf("%c", toupper(ch));
                ch = getchar();
            }
        }
        // Same deal but lowercase.
        if (islower(ch) != 0){
            while(isspace(ch) == 0 && ch != '#'){
                printf("%c", tolower(ch));
                ch = getchar();
            }
        }
        // If it doesn't start with either upper or lowercase, aka the input is not a letter.
        if (isupper(ch) == 0 && islower(ch) == 0) {
            while(isspace(ch) == 0 && ch != '#'){
                printf("%c", ch);
                ch = getchar();
            }
            printf(" ");
        }
        // If the input is a new line, print a new line. Seems useless, very helpful. Vice versa for math tutorials ohhhhhh #burnedchrisbose #calc1life
        if (ch == '\n'){
            printf("\n");
        }
        if (ch == '\t'){
            printf("\t");
        }
        /* Since a hashtag inputted into any of the previous loops would stop the loop and then continue from there, the next character would be 
        inputted and the largest while loop would continue. But, if there is a whitespace character we need to go through the loop again with 
        whatever our next character is. So I put this if statement in to see if the LAST character inputted was a hashtag, and if so, stops the loop.*/
        if (ch != '#'){
            ch = getchar();
        }
    }
    return 0;
}