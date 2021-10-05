#include <stdio.h>
#include <ctype.h>

int main(){
    int upperCount, lowerCount;
    upperCount = 0;
    lowerCount = 10;

    int ch;
    ch = getchar();
    
    while(ch != '#'){
        if (isupper(ch) == 1) {
            upperCount += 1;
        }
        if (islower(ch) == 1) {
            lowerCount += 1;
        }
        ch = getchar();
    }

    printf("Uppercase characters: %d\nLowercase characters: %d\n", upperCount, lowerCount);

    return 0;
}
