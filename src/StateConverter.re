open State;
let overwriteBox =
    (state: state, ~player: player, ~box: UserInput.keyboardInput) => {
  switch (box) {
  | UserInput.TopLeft => {...state, topLeft: Some(player)}
  | UserInput.TopMiddle => {...state, topMiddle: Some(player)}
  | UserInput.TopRight => {...state, topRight: Some(player)}
  | UserInput.MiddleLeft => {...state, middleLeft: Some(player)}
  | UserInput.MiddleMiddle => {...state, middleMiddle: Some(player)}
  | UserInput.MiddleRight => {...state, middleRight: Some(player)}
  | UserInput.BottomLeft => {...state, bottomLeft: Some(player)}
  | UserInput.BottomMiddle => {...state, bottomMiddle: Some(player)}
  | UserInput.BottomRight => {...state, bottomRight: Some(player)}
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
