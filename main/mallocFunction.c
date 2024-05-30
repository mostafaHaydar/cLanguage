#include <stdio.h>
#include <stdlib.h>

typedef struct Horse Horse;

struct Horse {
  int id;
  Horse *next;
};

int main(void) {

  Horse *first = NULL;
  Horse *current = NULL;
  Horse *previous = NULL;

  for (;;) {

    current = (Horse *)malloc(sizeof(Horse));

    if (first == NULL)
      first = current;

    if (previous != NULL)
      previous->next = current;

    printf_s("How old is you ? ");
    scanf_s("%d", &current->id);

    current->next = NULL;
    previous = current;
  }

  first = NULL;
  return 0;
}