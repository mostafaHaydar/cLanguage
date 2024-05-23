#include <stdbool.h>
#include <stdio.h>
#include <string.h>
// void putDataIntoFile() {
//   FILE *pFile = NULL;

//   pFile = fopen("myFile.txt", "a");
//   if (pFile != NULL) {
//     fprintf(pFile, "id:0,name:mostafa|");
//     fclose(pFile);
//     pFile = NULL;
//   }

//   fclose(pFile);
//   pFile = NULL;
// }
void getDataFromFile() {
  FILE *pFile = NULL;

  char myString[1000];
  char subString[100];

  const char delimiter[] = "|";
  pFile = fopen("myFile.txt", "r");

  fgets(myString, 1000, pFile);

  char *outer_saveptr = NULL;
  char *inner_saveptr = NULL;

  char *token = strtok_s(myString, delimiter, &outer_saveptr);

  const char subDelimiter[] = ":,";
  enum dataElements { id, idVal, name, namVal };
  enum dataElements state = id;
  while (token != NULL) {
    // printf("%s\n", token);
    strcpy(subString, token);
    char *subToken = strtok_s(subString, subDelimiter, &inner_saveptr);
    state = 0;
    while (subToken != NULL) {
      switch (state) {
      case 0:
        printf("im an id%s\n", subToken);

        break;
      case 1:
        printf("im an id value%s\n", subToken);

        break;
      case 2:
        printf("im an name%s\n", subToken);

        break;
      case 3:
        printf("im an name value%s\n", subToken);
        break;
      }
      state = state + 1;
      subToken = strtok_s(NULL, subDelimiter, &inner_saveptr);
    }
    // printf("%s\n", token);
    token = strtok_s(NULL, delimiter, &outer_saveptr);
  }

  fclose(pFile);
  pFile = NULL;
}

int main(void) {
  // FILE *pFile = NULL;

  // char myString[1000];
  // char subString[100];

  // const char delimiter[] = "|";
  // pFile = fopen("myFile.txt", "r");

  // fgets(myString, 1000, pFile);

  // char *outer_saveptr;
  // char *inner_saveptr;

  // char *token = strtok_s(myString, delimiter, &outer_saveptr);

  // const char subDelimiter[] = ":,";
  // enum dataElements { id, idVal, name, namVal };
  // enum dataElements state = id;
  // while (token != NULL) {
  //   printf("%s\n", token);
  //   strcpy(subString, token);
  //   char *subToken = strtok_s(subString, subDelimiter, &inner_saveptr);
  //   state = 0;
  //   while (subToken != NULL) {
  //     switch (state) {
  //     case 0:
  //       printf("im an id%s\n", subToken);

  //       break;
  //     case 1:
  //       printf("im an id value%s\n", subToken);

  //       break;
  //     case 2:
  //       printf("im an name%s\n", subToken);

  //       break;
  //     case 3:
  //       printf("im an name value%s\n", subToken);

  //       break;
  //     }
  //     state = state + 1;
  //     subToken = strtok_s(NULL, subDelimiter, &inner_saveptr);
  //   }
  //   printf("%s\n", token);
  //   token = strtok_s(NULL, delimiter, &outer_saveptr);
  // }

  // fclose(pFile);
  // pFile = NULL;
  // putDataIntoFile();
  // putDataIntoFile();
  getDataFromFile();
  return 0;
}
