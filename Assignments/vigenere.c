/* vigenere.c
   CSC 111 - Fall 2021 - Assignment 6


   B. Bird - 10/23/2021
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* index_to_character(index)
   Given an index, which MUST be in the range 0 through 25 (inclusive), return
   the corresponding lowercase character of the English alphabet, where
   the index 0 refers to 'a' and the index 25 refers to 'z'.

   If the index is not in the range 0 through 25, the behavior of this function
   is undefined.

   Parameters: index (integer)
   Return value (char): The character of the English alphabet with the
                        provided index.
*/
char index_to_character(int index){
    return 'a' + index;
}


/* character_to_index(ch)
   Given a lowercase English letter, return the index of that character in the
   English alphabet, where 'a' has the index 0 and 'z' has the index 25.

   If the character is not a lowercase letter, the behavior of this function
   is undefined.

   Parameters: ch (character)
   Return value (int): The index of the provided character in the English
                       alphabet.
*/
int character_to_index(char ch){
    return ch - 'a';
}


int main(){

    FILE* input_file = fopen("input.txt", "r");

	if (input_file == NULL) {
        printf("File didn't open properly bozo");
        return 1;
    }

    char keyInput[100];
    char messageInput[100];

    fgets(keyInput, 100, input_file);
    fgets(messageInput, 100, input_file);

    fclose(input_file);

    printf("keyInput: %s, messageInput: %s \n", keyInput, messageInput);

    char key[100];
    char message[100];
    char encrypted[100];
    char decrypted[100];

    int kL = strlen(keyInput);
    int mL = strlen(messageInput);

    for (int i = 0; i < kL && keyInput[i] != '\n'; i++) {
        key[i] = keyInput[i];
    }
    key[kL - 1] = '\0';

    for (int i = 0; i < mL  && messageInput[i] != '\n'; i++) {
        message[i] = messageInput[i];
    }
    message[mL] = '\0';

    for (int i = 0; i < mL; i++) {
        encrypted[i] = (character_to_index(message[i]) + character_to_index(key[(i%kL)]))%26;

    }
    encrypted[mL] = '\0';

    for (int i = 0; i < mL; i++){
        decrypted[i] = (character_to_index(message[i]) - character_to_index(key[(i%kL)]) + 26)%26;
                
    }
    decrypted[mL] = '\0';

    for (int i = 0; i < mL; i++) {
        encrypted[i] = index_to_character(encrypted[i]);

    }

    for (int i = 0; i < mL; i++) {
        decrypted[i] = index_to_character(decrypted[i]);

    }

    //You can reuse this print statements isn your solution (assuming you store each string
    //in the same variables).
    printf("Message: [%s]\n",message);
    printf("Key: [%s]\n",key);
    printf("Encrypted: [%s]\n",encrypted);
    printf("Decrypted: [%s]\n",decrypted);

    return 0;
}