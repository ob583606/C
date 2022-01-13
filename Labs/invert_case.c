#include <stdio.h>
#include <ctype.h>

int main(){
    int ch;
    ch = getchar();
    
    while(ch != '#'){
        if (isupper(ch) != 0) {
            printf("%c", tolower(ch));
        }
        if (islower(ch) != 0) {
            printf("%c", toupper(ch));
        }
        if (isupper(ch) == 0 && islower(ch) == 0) {
            printf("%c", ch);
        }

        ch = getchar();
    }
    return 0;
}
