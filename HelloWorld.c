// First c program, which is now my testing ground for functions.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct {
    int year, month, day;
} Date;

typedef struct {
    Date obs_date;
    int hour, minute;
    int station_id;
    float temperature;
} Observation;

int read_observation(FILE* input_file, Observation* obs){
   int input = 0;
   for(int i = 0; i <= 5; i++) {
      fscanf(input_file, "%99i", &input);
      if(i == 0) {
         obs->obs_date.year = input;
      }
      if(i == 1) {
         obs->obs_date.month = input;
      }
      if(i == 2) {
         obs->obs_date.day = input;
      }
      if(i == 3) {
         obs->hour = input;
      }
      if(i == 4) {
         obs->minute = input;
      }
      if(i == 5) {
         obs->station_id = input;
         if (fscanf(input_file, "%99f", &obs->temperature) == 1) {
            fclose(input_file);
            return 1;
         }
      }
   }
   fclose(input_file);
   return 0;   
}

int count_observations(char filename[]){
   int values = 0;
   FILE* input_file = fopen(filename, "r");
   if (input_file == NULL) {
      return -1;
   }
   while(fscanf(input_file, "%99s") == 1) {
      values += 1;
   }
   fclose(input_file);
   return (values/7);
}

int load_all_observations(char filename[], int array_size, Observation observation_array[array_size]){
   int values = 0;
   FILE* input_file = fopen(filename, "r");
   if (input_file == NULL) {
      return -1;
   }
   int obsSize = count_observations(filename);
   for(int i = 0; i <= obsSize && i <= array_size; i++) {
      values += 1;
      read_observation(filename, &observation_array[i]);
   }
   fclose(input_file);
   return values;
}

int main() {
   char a1[] = "dontreadmelol.txt";
   printf("count observations: %i\n", count_observations(a1));
   printf("Observation 1: %i %i %i %i %i %i %i %i %i");
   return 0;
}