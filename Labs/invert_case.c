#include <stdio.h>
#include <ctype.h>

int main(){
    int ch;
    ch = getchar();
    
    while(ch != '#'){
        if (isupper(ch) == 1) {
            printf("%c", tolower(ch));
        }
        if (islower(ch) == 2) {
            printf("%c", toupper(ch));
        }
        if (isupper(ch) != 1 && islower(ch) != 2) {
            printf("%c", ch);
        }

        ch = getchar();
    }
    return 0;
}
