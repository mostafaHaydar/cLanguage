#include <cstring>
#include <stdbool.h>
int main(void) {
  int sudoku[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
  return 0;
}

bool inMatrix(int array[9][9], int place[2], int element) {
  int pos[2] = {3, 3};

  if (3 <= place[0]) {
    if (6 <= place[0]) {
      pos[0] = 9;
    } else {
      pos[0] = 6;
    }
  }

  if (3 <= place[1]) {
    if (6 <= place[1]) {
      pos[1] = 9;
    } else {
      pos[1] = 6;
    }
  }

  for (size_t i = pos[0] - 3; i < pos[0]; i++)
    for (size_t j = pos[1] - 3; j < pos[1]; j++)
      if (array[i][j] == element)
        return true;

  for (size_t i = 0; i < strlen(array[place[0]]); i++)
    if (element == array[place[0]][i])
      return true;

  for (size_t i = 0; i < strlen(array); i++)
    if (element == array[i][place[1]])
      return true;
}

bool checkTreeTree(int pos[9], int element) {
  for (size_t i = pos[0]; i < pos[0] + 3; i++)
    for (size_t j = pos[1]; j < pos[1] + 3; j++)
      if (sudoku[i][j] == element)
        return true;
}

int checkOpoNumber(int pos, int element) {
  int count = 0;
  if (!checkTreeTree(pos, element))
    for (size_t i = pos[0]; i < pos[0] + 3; i++)
      for (size_t j = pos[1]; j < pos[1] + 3; j++)
        if (sudoku[i][j] == = 0 && !inMatrix(sudoku, [ i, j ], element))
          count++;
  return count;
}

bool zeroIn() {
  for (size_t i = 0; i < 9; i++)
    for (size_t j = 0; j < 9; j++)
      if (sudoku[i][j] == 0)
        return true;
}

void startSelv() {
  int pos[2] = {0, 0};
  int element;
  int count = 0;
  while (zeroIn() && count < 55) {
    int element = Math.floor(Math.random() * 10);
    if (element == 0 || element == 10)
      element = 5;
    for (size_t x = 0; x < 9; x++) {
      if (checkOpoNumber(pos, element) == 1) {
        for (size_t i = pos[0]; i < pos[0] + 3; i++) {
          for (size_t j = pos[1]; j < pos[1] + 3; j++) {
            if (!inMatrix(sudoku, [ i, j ], element) && sudoku[i][j] == 0) {
              sudoku[i][j] = element;
              break;
            }
          }
        }
      }
      if (pos[1] != 6) {
        pos[1] = pos[1] + 3
      } else {
        pos[1] = 0;
        (pos[0] != 6) ? pos[0] = pos[0] + 3 : pos[0] = pos[0];
      }
    }
    pos = [ 0, 0 ];
    count++;
  }
  int count = 0;
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      document.getElementById(count).value = sudoku[i][j];
      count++;
    }
  }
}

void planArray() {
  int count = 0;
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      sudoku[i][j] = parseInt(document.getElementById(count).value) count++;
    }
  }
  sudoku.forEach(e = > {
    console.log(e[0], e[1], e[2], e[3], e[4], e[5], e[6], e[7], e[8]);
  });
  startSelv();
}
