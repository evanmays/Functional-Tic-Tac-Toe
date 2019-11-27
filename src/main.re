/* Constants */

let startingPlayer = State.X;

let startState: State.state = {
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
};

/* Mutables :( */

let state: ref(State.state) = ref(startState);

/* Main game loop */

let processPlayerMove = (inputString: string) =>
  if (UserInput.isValidInputString(inputString)) {
    let input = UserInput.gatherInput(inputString);
    let validInput = StateValidator.isValidInput(input, state^);
    validInput
      ? {
        state := StateConverter.getNextGameState(input, state^);
        Js.log(State.stateAsString(state^));
        let winner: State.option(State.player) =
          StateValidator.theWinnerIs(state^);
        switch (winner) {
        | Some(winner) =>
          Js.log("Game over, " ++ State.playerToString(winner) ++ " Wins!");
          Readline.close();
        | None =>
          Js.log(
            "Please go player " ++ State.playerToString(state^.currentTurn),
          )
        };
      }
      : {
        Js.log("That move is invalid :(");
      };
  } else {
    Js.log("That move is not on the grid");
  };

let main = () => {
  Js.log("Welcome to Functional Tic Tac Toe");
  Js.log(
    "When it is your turn, please enter the position you would like to mark.",
  );
  Js.log("Please go player " ++ State.playerToString(state^.currentTurn));
  Readline.readline(input => processPlayerMove(input));
};

main();
