#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct USER {
    int id;
    struct USER *next;
  };

  struct USER *first = NULL;
  struct USER *current = NULL;
  struct USER *previous = NULL;

  // i will allocate the memory of three struct instance

  for (int i = 0; i < 3; i++) {
    current = (struct USER *)malloc(sizeof(struct USER));
    if (first == NULL) {
      first = current;
    }
    if (previous != NULL) {
      previous->next = current;
    }

    printf("please entre the user id::");
    int id;
    scanf("%d", &id);
    current->id = id;
    current->next = NULL;
    previous = current;
  }

  current = first;
  while (current != NULL) {
    printf("im the id %d\n", current->id);
    previous = current;
    current = current->next;
    free(previous);
    previous = NULL;
  }
  return 0;
}