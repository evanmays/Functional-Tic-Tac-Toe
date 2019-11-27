type player =
  | X
  | O;

type option('player) =
  | None
  | Some('player);

type state = {
  clock: int,
  currentTurn: player,
  topLeft: option(player),
  topMiddle: option(player),
  topRight: option(player),
  middleLeft: option(player),
  middleMiddle: option(player),
  middleRight: option(player),
  bottomLeft: option(player),
  bottomMiddle: option(player),
  bottomRight: option(player),
};

let playerToString = (player: player) => {
  switch (player) {
  | X => "X"
  | O => "O"
  };
};

let optionalPlayerToString = (player: option(player)) => {
  switch (player) {
  | Some(player) => playerToString(player)
  | None => " "
  };
};

let boardRowAsString = boardRow => {
  Array.fold_left((a, b) => a ++ "|" ++ b, "", boardRow) ++ "|";
};

let stateAsString = state => {
  let row1 =
    boardRowAsString([|
      optionalPlayerToString(state.topLeft),
      optionalPlayerToString(state.topMiddle),
      optionalPlayerToString(state.topRight),
    |]);
  let row2 =
    boardRowAsString([|
      optionalPlayerToString(state.middleLeft),
      optionalPlayerToString(state.middleMiddle),
      optionalPlayerToString(state.middleRight),
    |]);
  let row3 =
    boardRowAsString([|
      optionalPlayerToString(state.bottomLeft),
      optionalPlayerToString(state.bottomMiddle),
      optionalPlayerToString(state.bottomRight),
    |]);
  let rows = [|row1, row2, row3|];
  Array.fold_right((a, b) => a ++ "\n" ++ b, rows, "");
};
