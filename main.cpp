#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <iostream>

struct Time {

  int hr;
  int min;
  int sec;
  int ms;

};

Time split_timestamp(char * s) {

  Time time;

  char buff[3];
  int j = 0;
  int k = 0;

  for (int i = 0; i < 12; i++) {

    if (s[i] != ':' && s[i] != '.' && j != 3) {

      buff[j] = s[i];

      j++;

    } else {

      j = 0;

      switch(k) {
        case 0:
          buff[2] = '\0';
          time.hr = atoi(buff);
          break;
        case 1:
          buff[2] = '\0';
          time.min = atoi(buff);
          break;
        case 2:
          buff[2] = '\0';
          time.sec = atoi(buff);
          break;
        case 3:
          buff[3] = '\0';
          time.ms = atoi(buff);
          break;
      }

      k++;

    }
    
  }

  time.ms = atoi(buff);

  //printf("The time was %i:%i:%i.%i\n", time.hr, time.min, time.sec, time.ms);

  return time;

}

int time_to_epoch(Time intime) {

  int epoch_time = 0;

  epoch_time += intime.hr * 60 * 60 * 1000;
  epoch_time += intime.min * 60 * 1000;
  epoch_time += intime.sec * 1000;
  epoch_time += intime.ms;

  return epoch_time;

}

int main(int argc, char *argv[]) {

  if (argc != 3) {

    std::cerr << "Incorrect number of parameters" << std::endl;
    return 1;

  }

  char * first_time = argv[1];
  char * second_time = argv[2];

  Time first_time_struct = split_timestamp(first_time);
  Time second_time_struct = split_timestamp(second_time);

  int epoch_first = time_to_epoch(first_time_struct);
  int epoch_second = time_to_epoch(second_time_struct);

  printf("%i\n", epoch_first - epoch_second);

  return 0;

}

