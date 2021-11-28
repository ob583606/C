/* temperature_data.c


   B. Bird - 11/09/2021
*/

#include <stdio.h>
#include "temperature_data.h"

/* Do not copy the typedef statements for the structure types into this file
   (they should only be in the .h file)
*/


/* read_observation(input_file, obs)
   Given a file object input_file and a pointer obs to an Observation 
   structure, try to read a single observation from the file into the structure
   pointed to by obs. If the complete observation is read successfully, return 1.
   Otherwise, return 0.

   Parameters: input_file (FILE pointer), obs (pointer to Observation object)
   Return value (integer):
     - If the observation was read successfully, return 1
     - Otherwise, return 0
*/
int read_observation(FILE* input_file, Observation* obs){
   if (fscanf(input_file, "%99d", &obs->obs_date.year) == 0) {
      return 0;
   }
   if (fscanf(input_file, "%99d", &obs->obs_date.month) == 0) {
      return 0;
   }
   if (fscanf(input_file, "%99d", &obs->obs_date.day) == 0) {
      return 0;
   }
   if (fscanf(input_file, "%99d", &obs->hour) == 0) {
      return 0;
   }
   if (fscanf(input_file, "%99d", &obs->minute) == 0) {
      return 0;
   }
   if (fscanf(input_file, "%99d", &obs->station_id) == 0) {
      return 0;
   }
   if (fscanf(input_file, "%99f", &obs->temperature) == 0) {
      return 0;
   }
   return 1;   
}


/* count_observations(filename)
   Given a filename, count and return the number of temperature observations in
   the file. If the file cannot be opened, return -1.

   Parameters: filename (string)
   Return value (integer):
     - If the file cannot be opened for reading, return -1
     - Otherwise, return the number of temperature observations in the file.
*/
int count_observations(char filename[]){
   int values = 0;
   float inps;
   FILE* input_file = fopen(filename, "r");
   if (input_file == NULL) {
      return -1;
   }
   while(fscanf(input_file, "%99f", &inps) == 1) {
      values += 1;
   }
   fclose(input_file);
   return (values/7);
}

/* load_all_observations(filename, array_size, observation_array)
   Given a filename and an array of Observation objects, read as many 
   observations from the file as possible (up to the size of the array)
   and store each observation (in order) into the array.

   If the file cannot be opened, return -1. Otherwise, return the number of 
   observations read.

   If the file contains fewer observations then there are elements in the array,
   stop reading after the last observation in the file. Otherwise, stop reading
   once array_size observations are read.

   Parameters: filename (string), array_size (integer), observation_array (array of Observation)
   Return value (integer):
     - If the file could not be opened, return -1
     - Otherwise, return the total number of observations read and stored into 
       the array.
*/
int load_all_observations(char filename[], int array_size, Observation observation_array[array_size]){
   int values = 0;
   FILE* input_file = fopen(filename, "r");
   if (input_file == NULL) {
      return -1;
   }
   int obsSize = count_observations(filename);
   for(int i = 0; i < obsSize && i < array_size; i++) {
      values += 1;
      read_observation(input_file, &observation_array[i]);
   }
   fclose(input_file);
   return values;
}




/* print_station_extremes(num_observations, obs_array)
   Given an array of Observation objects, compute and print the
    _extreme observations_ (lowest temperature observed and highest
   temperature observed) for each station that has at least one
   observation in the dataset.

   The output will contain one line for each station with at least one 
   observation in the dataset, using a format equivalent to the following:
      Station 1: Minimum = -1.87 degrees (2021-11-21 06:10), Maximum = 10.6 degrees (2021-01-11 01:16)

   You should use the following printf format string to achieve the correct 
   output format.
      "Station %d: Minimum = %.2f degrees (%04d-%02d-%02d %02d:%02d), Maximum = %.2f degrees (%04d-%02d-%02d %02d:%02d)\n"
 
   The output must be ordered by station number (with lower numbered station 
   numbers appearing first). No more than one line of output should be 
   generated for a particular station number.

   In cases where multiple observations achieve the extreme value (e.g. if the
   minimum temperature at a particular station is -1.87, but there are several 
   observations with this temperature), print the date/time of the 
   chronologically earliest observation with that extreme temperature.

   You may assume that all observations contain a station number between 
   1 and 250 (inclusive).

   This function must _not_ use any file I/O features whatsoever.

   Parameters: num_observations (integer), observation_array (array of Observation)
   Return value: None
   Side Effect: A printed representation of station extremes is output to the user.
*/
void print_station_extremes(int num_observations, Observation obs_array[num_observations]){
   
}

/* print_daily_averages(num_observations, obs_array)
   Given an array of observation objects, compute and print the average 
   temperature for each day which has at least one observation in the 
   dataset.

   The output must contain only dates which actually appear in at least 
   one observation object in the array. The dates must be in ascending 
   chronological order (so an earlier date must be printed before a later 
   one) and each date may only appear once.

   Each line of output will have the form "year month day average", for 
   example "2021 11 20 10.6" (which would be interpreted to mean that 
   the average temperature on Nov. 21, 2021 was 10.6 degrees).

   Your code may assume that all dates are from years between 2015 and 2021 
   (inclusive) and that the month/day entries are all valid (that is, month
   will always be between 1 and 12 inclusive and day will always be between
   1 and 31 inclusive).
   
   This function must _not_ use any file I/O features whatsoever.

   Parameters: num_observations (integer), observation_array (array of Observation)
   Return value: None
   Side Effect: A printed representation of the average daily temperature is
                output to the user.
*/
void print_daily_averages(int num_observations, Observation obs_array[num_observations]){
   int lowest = 0;
   for (int i = 0; i <= num_observations; i++) {
      
   }
}