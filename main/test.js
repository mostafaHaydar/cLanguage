var sudokuArray = [
  [0, 8, 0, 0, 0, 5, 1, 7, 9],

  [0, 0, 0, 2, 0, 6, 0, 8, 4],

  [9, 0, 3, 8, 0, 0, 6, 0, 0],

  [2, 7, 0, 0, 8, 0, 5, 0, 3],

  [4, 0, 0, 0, 5, 0, 8, 1, 2],

  [0, 0, 8, 0, 4, 2, 0, 0, 7],

  [8, 0, 0, 0, 0, 3, 0, 0, 1],

  [3, 5, 4, 0, 1, 0, 0, 9, 0],

  [0, 9, 6, 0, 2, 4, 7, 0, 0],
];

function checkIfTheNumberExistsOnVerticalLine(lineNumber, element) {
  var state = false;
  for (let i = 0; i < 9; i++) {
    const loopElement = sudokuArray[lineNumber][i];
    if (loopElement == element) {
      state = true;
      break;
    }
  }
  return state;
}

function checkIfTheNumberExistsOnHorizentalLine(lineNumber, element) {
  var state = false;
  for (let i = 0; i < 9; i++) {
    const loopElement = sudokuArray[i][lineNumber];
    if (loopElement == element) {
      state = true;
      break;
    }
  }
  return state;
}

function fromWichBlockIsTheElement(
  positionNumberVertical,
  positionNumberHorizental
) {
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
function checkIfExistsInBlock(
  positionNumberVertical,
  positionNumberHorizental,
  element
) {
  var blockNumber = fromWichBlockIsTheElement(
    positionNumberVertical,
    positionNumberHorizental
  );

  // block 0
  if (blockNumber == 0) {
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 1
  if (blockNumber == 1) {
    for (let i = 0; i < 3; i++) {
      for (let j = 3; j < 6; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 2
  if (blockNumber == 2) {
    for (let i = 0; i < 3; i++) {
      for (let j = 6; j < 9; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 3
  if (blockNumber == 3) {
    for (let i = 3; i < 6; i++) {
      for (let j = 0; j < 3; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 4
  if (blockNumber == 4) {
    for (let i = 3; i < 6; i++) {
      for (let j = 3; j < 6; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 5
  if (blockNumber == 5) {
    for (let i = 3; i < 6; i++) {
      for (let j = 6; j < 9; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 6
  if (blockNumber == 6) {
    for (let i = 6; i < 9; i++) {
      for (let j = 0; j < 3; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 7
  if (blockNumber == 7) {
    for (let i = 6; i < 9; i++) {
      for (let j = 3; j < 6; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }

  // block 8
  if (blockNumber == 8) {
    for (let i = 6; i < 9; i++) {
      for (let j = 6; j < 9; j++) {
        if (element == sudokuArray[i][j]) {
          return true;
        }
      }
    }
  }
}

function startSolving() {
  var howManyElementsCanBeInOneBox = 0;
  var firstNumberCanBeInTheBox = 0;
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      //   check first if the box is empty or not
      if (sudokuArray[i][j] == 0) {
        // this loop just for getting numbers for sudoku game
        for (let x = 1; x < 10; x++) {
          if (
            !checkIfExistsInBlock(i, j, x) &&
            !checkIfTheNumberExistsOnVerticalLine(i, x) &&
            !checkIfTheNumberExistsOnHorizentalLine(j, x)
          ) {
            firstNumberCanBeInTheBox = x;
            howManyElementsCanBeInOneBox = howManyElementsCanBeInOneBox + 1;
          }
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

function checkIfexistsZeroInTheSudokuArray() {
  var state = false;
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (sudokuArray[i][j] == 0) {
        state = true;
        return state;
      }
    }
  }
}
function numberOfEmptyBoxes() {
  var number = 0;
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (sudokuArray[i][j] == 0) {
        number = number + 1;
      }
    }
  }
  return number;
}

function solvigUntilCompletSolve() {
  var i = 0;
  var emptyBoxesBefore = 0;
  var emptyBoxesAfter = 0;
  while (checkIfexistsZeroInTheSudokuArray) {
    emptyBoxesBefore = numberOfEmptyBoxes();
    startSolving();
    emptyBoxesAfter = numberOfEmptyBoxes();

    if (emptyBoxesBefore == emptyBoxesAfter) {
      //becouse that maen the algo cant find another elements so it is useless to complete the same proccess
      break;
    }
    i++;
  }
  for (let i = 0; i < 9; i++) {
    console.log(
      sudokuArray[i][0],
      sudokuArray[i][1],
      sudokuArray[i][2],
      sudokuArray[i][3],
      sudokuArray[i][4],
      sudokuArray[i][5],
      sudokuArray[i][6],
      sudokuArray[i][7],
      sudokuArray[i][8]
    );
  }
}
solvigUntilCompletSolve();
