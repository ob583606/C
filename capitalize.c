#include <stdio.h>
#include <ctype.h>

int main(){
    int ch;
    ch = getchar();

    while (ch != '#') {
        
        if (isupper(ch) == 1) {
            while(isspace(ch) != 1 && ch != '#'){    
                printf("%c", toupper(ch));
                ch = getchar();
            }
        }
            
        if (islower(ch) == 1){
            while(isspace(ch) != 1 && ch != '#'){
                printf("%c", tolower(ch));
                ch = getchar();
            }        
        }
            
        if (isupper(ch) != 1 && islower(ch) != 1) {
            while(isspace(ch) != 1 && ch != '#'){
                printf("%c", ch);
                ch = getchar();
            }
        }
        ch = getchar();
      
    }
    return 0;
}