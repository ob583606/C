#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hour, minute;
} Time; 

typedef struct {
    int flight_number;
    char from_city[100]; //Name of a city (e.g. "Victoria")
    char to_city[100]; 
    Time departure_time;
    int total_seats;
} Flight;

/* read_flight(input_file, flight_ptr)
   Given an input file pointer and a pointer to a Flight structure, 
   try to read the data for one flight from the input file.

   If a flight is read successfully, the function returns 1. 
   Otherwise, the return value is 0.

   Parameters: input_file (pointer to FILE), flight_ptr (pointer to a Flight object)
   Return value (integer):
      - If a flight is read successfully, return 1.
      - Otherwise, return 0.
*/
// The code for this function is not shown, but you 
// may assume that the function behaves as described above.
int read_flight(FILE* input_file, Flight* flight_ptr);


/* print_all_flights(input_file)
   Given an input file pointer, which you may assume refers to a valid file which 
   has been opened in mode "r", read all flights in the file (using the 
   read_flight function above) and print out each flight's data to the user
   in the following format (with one flight per line):
     Flight 187: Victoria -> Vancouver, departs at 06:10, 17 passengers

   You can use the following printf format string to achieve the format above.
    "Flight %d: %s -> %s, departs at %02d:%02d, %d passengers\n"

   Your solution must use the read_flight function above or it will not
   be marked.

   Parameters: input_file (pointer to FILE)
   Return value: None
*/
/* Your answer from below would be placed here */
