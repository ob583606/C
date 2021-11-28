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

void print_station_extremes(int num_observations, Observation obs_array[num_observations]){
   float lowest = obs_array[0].temperature;
   float highest = obs_array[0].temperature;
   int lF = 0;
   int hF = 0;
   for(int i = 0; i <= num_observations; i++) {
      int iMinDate = minDate(num_observations, &obs_array[num_observations], i);
      if (obs_array[i].temperature <= lowest) {
         if (iMinDate < minDate(num_observations, &obs_array[num_observations], lF)) {
            lowest = obs_array[i].temperature;
            lF = i;
         }
      }
      if (obs_array[i].temperature >= highest) {
         if (iMinDate < minDate(num_observations, &obs_array[num_observations], hF)) {
            highest = obs_array[i].temperature;
            hF = i;
         }
      }
   }
   printf("Station %d: Minimum = %.2f degrees (%04d-%02d-%02d %02d:%02d), Maximum = %.2f degrees (%04d-%02d-%02d %02d:%02d)\n", obs_array[lF].station_id, lowest, 
   obs_array[lF].obs_date.year, obs_array[lF].obs_date.month, obs_array[lF].obs_date.day, obs_array[lF].hour, obs_array[lF].minute, highest, 
   obs_array[hF].obs_date.year, obs_array[hF].obs_date.month, obs_array[hF].obs_date.day, obs_array[hF].hour, obs_array[hF].minute);
}

int minDate (int num_observations, Observation obs_array[num_observations], int i) {
   int total = ((365*24*60*obs_array[i].obs_date.year) + (30*24*60*obs_array[i].obs_date.month) + (24*60*obs_array[i].obs_date.day));
   return total;
}

int main() {
   char a1[] = "dontreadmelol.txt";
   printf("count observations: %i\n", count_observations(a1));
   printf("Observation 1: %i %i %i %i %i %i %i %i %i");
   return 0;
}