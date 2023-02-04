#include <stdio.h>
#include <ctype.h>

int main(){
    int upperCount, lowerCount;
    upperCount = 0;
    lowerCount = 0;

    int ch;
    ch = getchar();
    
    while(ch != '#'){
        if (isupper(ch) == 1) {
            upperCount += 1;
        }
        if (islower(ch) == 2) {
            lowerCount += 1;
        }
        ch = getchar();
    }

    printf("Uppercase characters: %d\nLowercase characters: %d\n", upperCount, lowerCount);

    return 0;
}
