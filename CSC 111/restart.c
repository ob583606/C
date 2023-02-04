#include <stdio.h>

int main() {
int restart, loops;
restart = 1;
loops = 0;
while (restart != 0 & loops <50) {
    //input the shit that you want to loop here

    printf("Would you like to restart? Type \"0\" for no, any other number is yes. Please type a number. Retype any null inputs.\n");
    scanf("%i", &restart);
        
    loops +=1;
    }
}