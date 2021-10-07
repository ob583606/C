#include <stdio.h>
#include <ctype.h>

int main(){

    int ch;
    ch = getchar();
    
    while(ch != '#'){
        printf("%c", toupper(ch));

        ch = getchar();
    }
      

    return 0;
}