include StateConverter;
include StateValidator;
include UserInput;

/* Constants */

let startingPlayer = X;

/* Mutables :( */

let state: ref(state) =
  ref({
    clock: 0,
    currentTurn: startingPlayer,
    topLeft: None,
    topMiddle: None,
    topRight: None,
    middleLeft: None,
    middleMiddle: None,
    middleRight: None,
    bottomLeft: None,
    bottomMiddle: None,
    bottomRight: None,
  });

/* Main game loop */

let runOnce = (inputString: string) =>
  if (UserInput.isValidInputString(inputString)) {
    let input = gatherInput(inputString);
    let validInput = isValidInput(input, state^);
    validInput
      ? {
        state := getNextGameState(input, state^);
        Js.log(stateAsString(state^));
        let winner: option(player) = theWinnerIs(state^);
        switch (winner) {
        | Some(winner) =>
          Js.log("Game over, " ++ playerToString(winner) ++ " Wins!");
          Readline.close();
        | None =>
          Js.log("Please go player " ++ playerToString(state^.currentTurn))
        };
      }
      : {
        Js.log("That move is invalid :(");
      };
  } else {
    Js.log("That move is not on the grid");
  };

Js.log("Welcome to Functional Tic Tac Toe");
Js.log(
  "When it is your turn, please enter the position you would like to mark.",
);
Js.log("Please go player " ++ playerToString(state^.currentTurn));
Readline.readline(input => runOnce(input));
