#include <stdbool.h>
#include <stdio.h>
int sudokuArray[9][9] = {
    {0, 8, 0, 0, 0, 5, 1, 7, 9}, {0, 0, 0, 2, 0, 6, 0, 8, 4},
    {9, 0, 3, 8, 0, 0, 6, 0, 0}, {2, 7, 0, 0, 8, 0, 5, 0, 3},
    {4, 0, 0, 0, 5, 0, 8, 1, 2}, {0, 0, 8, 0, 4, 2, 0, 0, 7},
    {8, 0, 0, 0, 0, 3, 0, 0, 1}, {3, 5, 4, 0, 1, 0, 0, 9, 0},
    {0, 9, 6, 0, 2, 4, 7, 0, 0},
};

bool checkIfTheNumberExistsOnVerticalLine(int lineNumber, int element) {
  bool state = false;
  for (size_t i = 0; i < 9; i++) {
    int loopElement = sudokuArray[lineNumber][i];
    if (loopElement == element) {
      state = true;
      break;
    }
  }
  return state;
}

bool checkIfTheNumberExistsOnHorizentalLine(int lineNumber, int element) {
  bool state = false;
  for (size_t i = 0; i < 9; i++) {
    int loopElement = sudokuArray[i][lineNumber];
    if (loopElement == element) {
      state = true;
      break;
    }
  }
  return state;
}

int fromWichBlockIsTheElement(int positionNumberVertical,
                              int positionNumberHorizental) {
  if (positionNumberVertical < 3) {
    if (positionNumberHorizental < 3) {
      return 0;
    } else if (positionNumberHorizental < 6) {
      return 1;
    } else if (positionNumberHorizental < 9) {
      return 2;
    }
  } else if (positionNumberVertical < 6) {
    if (positionNumberHorizental < 3) {
      return 3;
    } else if (positionNumberHorizental < 6) {
      return 4;
    } else if (positionNumberHorizental < 9) {
      return 5;
    }
  } else if (positionNumberVertical < 9) {
    if (positionNumberHorizental < 3) {
      return 6;
    } else if (positionNumberHorizental < 6) {
      return 7;
    } else if (positionNumberHorizental < 9) {
      return 8;
    }
  }
}
bool checkIfExistsInBlock(int positionNumberVertical,
                          int positionNumberHorizental, int element) {
  int blockNumber = fromWichBlockIsTheElement(positionNumberVertical,
                                              positionNumberHorizental);

  if (positionNumberVertical == 0 && positionNumberHorizental == 3) {
    printf("BOLCK =%d\n", blockNumber);
  }
  if (blockNumber == 0) {
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 0; j < 3; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 1) {
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 3; j < 6; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 2) {
    for (size_t i = 0; i < 3; i++) {
      for (size_t j = 6; j < 9; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 3) {
    for (size_t i = 3; i < 6; i++) {
      for (size_t j = 0; j < 3; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 4) {
    for (size_t i = 3; i < 6; i++) {
      for (size_t j = 3; j < 6; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 5) {
    for (size_t i = 3; i < 6; i++) {
      for (size_t j = 6; j < 9; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 6) {
    for (size_t i = 6; i < 9; i++) {
      for (size_t j = 0; j < 3; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 7) {
    for (size_t i = 6; i < 9; i++) {
      for (size_t j = 3; j < 6; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  if (blockNumber == 8) {
    for (size_t i = 6; i < 9; i++) {
      for (size_t j = 6; j < 9; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }
  return false;
}

void startSolving(void) {
  int howManyElementsCanBeInOneBox = 0;
  int firstNumberCanBeInTheBox = 0;
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      if (i == 0 && j == 3) {
        printf("im here%d\n", sudokuArray[i][j]);
      }
      if (sudokuArray[i][j] == 0) {
        for (int x = 1; x < 10; x++) {
          if (!checkIfExistsInBlock(i, j, x) &&
              !checkIfTheNumberExistsOnVerticalLine(i, x) &&
              !checkIfTheNumberExistsOnHorizentalLine(j, x)) {
            if (i == 0 && j == 3) {
              printf("X =%d\n", x);
            }
            firstNumberCanBeInTheBox = x;
            howManyElementsCanBeInOneBox = howManyElementsCanBeInOneBox + 1;
          }
        }
        if (i == 0 && j == 3) {
          printf("im here =%d\n", howManyElementsCanBeInOneBox);
        }
        if (howManyElementsCanBeInOneBox == 1) {
          sudokuArray[i][j] = firstNumberCanBeInTheBox;
        }
      }
      firstNumberCanBeInTheBox = 0;
      howManyElementsCanBeInOneBox = 0;
    }
  }
}

bool checkIfexistsZeroInTheSudokuArray(void) {
  int state = false;
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      if (sudokuArray[i][j] == 0) {
        state = true;
        return state;
      }
    }
  }
}

int numberOfEmptyBoxes() {
  int number = 0;
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      if (sudokuArray[i][j] == 0) {
        number = number + 1;
      }
    }
  }
  return number;
}

void solvigUntilCompletSolve(void) {
  int i = 0;
  int emptyBoxesBefore = 0;
  int emptyBoxesAfter = 0;
  while (checkIfexistsZeroInTheSudokuArray()) {
    emptyBoxesBefore = numberOfEmptyBoxes();
    startSolving();
    emptyBoxesAfter = numberOfEmptyBoxes();

    if (emptyBoxesBefore == emptyBoxesAfter) {
      break;
    }
    i++;
  }
  for (size_t i = 0; i < 9; i++) {
    printf("%d%d%d%d%d%d%d%d%d\n", sudokuArray[i][0], sudokuArray[i][1],
           sudokuArray[i][2], sudokuArray[i][3], sudokuArray[i][4],
           sudokuArray[i][5], sudokuArray[i][6], sudokuArray[i][7],
           sudokuArray[i][8]);
  }
}
int main(void) {
  solvigUntilCompletSolve();
  return 0;
}
