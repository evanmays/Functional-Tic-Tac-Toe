let isValidInput = (input, state: State.state) => {
  let pieceAtPosition =
    switch (input) {
    | UserInput.TopLeft => state.topLeft
    | UserInput.TopMiddle => state.topMiddle
    | UserInput.TopRight => state.topRight
    | UserInput.MiddleLeft => state.middleLeft
    | UserInput.MiddleMiddle => state.middleMiddle
    | UserInput.MiddleRight => state.middleRight
    | UserInput.BottomLeft => state.bottomLeft
    | UserInput.BottomMiddle => state.bottomMiddle
    | UserInput.BottomRight => state.bottomRight
    };
  if (pieceAtPosition == None) {
    true;
  } else {
    false;
  };
};

let allAreOnePlayer = (positions: list(State.option(State.player))) => {
  List.for_all(value => value == State.Some(State.X), positions)
  || List.for_all(value => value == State.Some(State.O), positions);
};

let theWinnerIs = (state: State.state) => {
  let firstRow = [state.topLeft, state.topMiddle, state.topRight];
  let secondRow = [state.middleLeft, state.middleMiddle, state.middleRight];
  let thirdRow = [state.bottomLeft, state.bottomMiddle, state.bottomRight];
  let firstColumn = [state.topLeft, state.middleLeft, state.bottomLeft];
  let secondColumn = [
    state.topMiddle,
    state.middleMiddle,
    state.bottomMiddle,
  ];
  let thirdColumn = [state.topRight, state.middleRight, state.bottomRight];
  let leftDiagonal = [state.topLeft, state.middleMiddle, state.middleRight];
  let rightDiagonal = [state.topRight, state.middleMiddle, state.bottomLeft];
  let possibleCombinationsOfThree = [
    firstRow,
    secondRow,
    thirdRow,
    firstColumn,
    secondColumn,
    thirdColumn,
    leftDiagonal,
    rightDiagonal,
  ];
  let winnerExists =
    List.exists(
      value => allAreOnePlayer(value),
      possibleCombinationsOfThree,
    );
  winnerExists
    ? {
      List.find(value => allAreOnePlayer(value), possibleCombinationsOfThree)
      ->List.hd;
    }
    : {
      None;
    };
};
