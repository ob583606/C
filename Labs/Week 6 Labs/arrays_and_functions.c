#include <stdio.h>

/* find_minimum_element( size, the_array )
   Given an array of the specified size, find and return
   the minimum element of the array.
*/
int find_minimum_element(int size, int the_array[size]){
    int smallest = the_array[0];
    int* ps = &smallest;
    int n = 0;
    while (n <= size) {
        if(the_array[n] < smallest) {
            *ps = the_array[n];
        }
        n += 1;
    }
    return smallest;
}
/* search_for_element( size, the_array, search_value )
   Given an array of the specified size, along with a value
   to search for, return 1 if the provided value is found
   somewhere in the array and 0 otherwise.
*/
int search_for_element(int size, int the_array[size], int search_value){
    int n = 0;
    while (n <= size){
        if(the_array[n] == search_value) {
            return 1;
        }
        n += 1;
    }
    return 0;   
}

/* clamp( size, the_array, lower_bound, upper_bound )
   Given an array of the specified size, along with two
   bounds lower_bound and upper_bound, do the following:
    - Set any element with a value less than lower_bound to equal lower_bound
    - Set any element with a value greater than upper_bound to equal upper_bound
    - Leave all other elements intact.
*/
void clamp( int size, int the_array[size], int lower_bound, int upper_bound ){
    int n = 0;
    while (n <= size) {
        if (the_array[n] < lower_bound) {
            the_array[n] = lower_bound;
        }
        if (the_array[n] > upper_bound) {
            the_array[n] = upper_bound;
        }
        n += 1;
    }
}

/* print_array( size, the_array )
   Given an array of the specified size, print every element of the array,
   followed by a newline.
*/
void print_array( int size, int the_array[size] ){
    int i;
    for (i = 0; i < size; i++){
	printf("%d ", the_array[i]);
    }
    printf("\n");
}

/* Do not modify anything below here */
int main(){

    int A1[5] = {31, -41, 59, 2, 65};
    int A2[7] = {3, 58, 9, 79, 323, -8, 4};

    printf("A1 is ");
    print_array(5,A1);
    printf("A2 is ");
    print_array(7,A2);

    printf("Minimum element of A1: %d\n", find_minimum_element(5, A1));
    printf("Minimum element of A2 (first four elements): %d\n", find_minimum_element(4, A2));
    printf("Minimum element of A2 (all elements): %d\n", find_minimum_element(7, A2));

    printf("Does A1 contain the element 2? search_for_element returns %d\n", search_for_element(5, A1, 2));
    printf("Does A1 contain the element 6? search_for_element returns %d\n", search_for_element(5, A1, 6));
    printf("Does A2 contain the element 6? search_for_element returns %d\n", search_for_element(7, A2, 6));
    printf("Does A2 contain the element 4? search_for_element returns %d\n", search_for_element(7, A2, 4));

    printf("Clamping A1 to the range [0, 50]\n");
    clamp(5, A1, 0, 50);
    printf("A1 is ");
    print_array(5, A1);

    printf("Clamping A2 to the range [10, 100]\n");
    clamp(7, A2, 10, 100);
    printf("A2 is ");
    print_array(7, A2);


    return 0;
}