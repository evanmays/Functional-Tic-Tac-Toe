open State;
let overwriteBox =
    (state: state, ~player: player, ~box: UserInput.keyboardInput) => {
  switch (box) {
  | UserInput.TopLeft => {...state, topLeft: State.Some(player)}
  | UserInput.TopMiddle => {...state, topMiddle: State.Some(player)}
  | UserInput.TopRight => {...state, topRight: State.Some(player)}
  | UserInput.MiddleLeft => {...state, middleLeft: State.Some(player)}
  | UserInput.MiddleMiddle => {...state, middleMiddle: State.Some(player)}
  | UserInput.MiddleRight => {...state, middleRight: State.Some(player)}
  | UserInput.BottomLeft => {...state, bottomLeft: State.Some(player)}
  | UserInput.BottomMiddle => {...state, bottomMiddle: State.Some(player)}
  | UserInput.BottomRight => {...state, bottomRight: State.Some(player)}
  };
};

let nextTurn = currentTurn => {
  switch (currentTurn) {
  | X => O
  | O => X
  };
};

let getNextGameState = (input: UserInput.keyboardInput, state) => {
  let nextState = overwriteBox(state, ~player=state.currentTurn, ~box=input);
  {
    ...nextState,
    clock: state.clock + 1,
    currentTurn: nextTurn(state.currentTurn),
  };
};
