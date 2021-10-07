#include <stdio.h>
#include <ctype.h>

int main(){
    int ch, spc;
    ch = getchar();
    spc = 0;

    while(ch != '#'){
        if (isspace(ch) == 8 && spc != 1) {
            spc = 1;
            printf("%c", ch);
        }
        if (isspace(ch) != 8) {
            spc = 0;
            printf("%c", ch);
        }

        ch = getchar();
    }
    return 0;
}
