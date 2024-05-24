#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool checkEmailForm(char email[100]) {
  bool state = false;
  for (size_t i = 0; i < strlen(email); i++) {
    if (email[i] == '@' && i != 0 && i != strlen(email) - 1) {
      state = true;
    }
  }
  return state;
}

int main(void) {
  char email[100] = "sqsd@";
  char email2[100] = "@";
  printf("the state of first email::%d\n", checkEmailForm(email));
  printf("the state of first email::%d\n", checkEmailForm(email2));
  return 0;
}