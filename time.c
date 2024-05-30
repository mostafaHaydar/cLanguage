#include <stdio.h>
#include <time.h>

int main() {
  time_t currentTime;

  time(&currentTime);

  struct tm *localTime = localtime(&currentTime);

  char formattedTime[100];

  strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S",
           localTime);
  printf("Date et heure formatées : %s\n", formattedTime);

  return 0;
}
