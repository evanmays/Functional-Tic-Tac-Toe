// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var State$FunctionalTicTacToe = require("./State.bs.js");

function overwriteBox(state, player, box) {
  switch (box) {
    case /* TopLeft */0 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */player,
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */state[/* topRight */4],
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* TopMiddle */1 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */player,
                /* topRight */state[/* topRight */4],
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* TopRight */2 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */player,
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* MiddleLeft */3 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */state[/* topRight */4],
                /* middleLeft */player,
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* MiddleMiddle */4 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */state[/* topRight */4],
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */player,
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* MiddleRight */5 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */state[/* topRight */4],
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */player,
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* BottomLeft */6 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */state[/* topRight */4],
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */player,
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* BottomMiddle */7 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */state[/* topRight */4],
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */player,
                /* bottomRight */state[/* bottomRight */10]
              ];
    case /* BottomRight */8 :
        return /* record */[
                /* clock */state[/* clock */0],
                /* currentTurn */state[/* currentTurn */1],
                /* topLeft */state[/* topLeft */2],
                /* topMiddle */state[/* topMiddle */3],
                /* topRight */state[/* topRight */4],
                /* middleLeft */state[/* middleLeft */5],
                /* middleMiddle */state[/* middleMiddle */6],
                /* middleRight */state[/* middleRight */7],
                /* bottomLeft */state[/* bottomLeft */8],
                /* bottomMiddle */state[/* bottomMiddle */9],
                /* bottomRight */player
              ];
    
  }
}

function nextTurn(currentTurn) {
  if (currentTurn) {
    return /* X */0;
  } else {
    return /* O */1;
  }
}

function getNextGameState(input, state) {
  var nextState = overwriteBox(state, state[/* currentTurn */1], input);
  return /* record */[
          /* clock */state[/* clock */0] + 1 | 0,
          /* currentTurn */state[/* currentTurn */1] ? /* X */0 : /* O */1,
          /* topLeft */nextState[/* topLeft */2],
          /* topMiddle */nextState[/* topMiddle */3],
          /* topRight */nextState[/* topRight */4],
          /* middleLeft */nextState[/* middleLeft */5],
          /* middleMiddle */nextState[/* middleMiddle */6],
          /* middleRight */nextState[/* middleRight */7],
          /* bottomLeft */nextState[/* bottomLeft */8],
          /* bottomMiddle */nextState[/* bottomMiddle */9],
          /* bottomRight */nextState[/* bottomRight */10]
        ];
}

var playerToString = State$FunctionalTicTacToe.playerToString;

var optionalPlayerToString = State$FunctionalTicTacToe.optionalPlayerToString;

var addGridToRow = State$FunctionalTicTacToe.addGridToRow;

var stateAsString = State$FunctionalTicTacToe.stateAsString;

exports.playerToString = playerToString;
exports.optionalPlayerToString = optionalPlayerToString;
exports.addGridToRow = addGridToRow;
exports.stateAsString = stateAsString;
exports.overwriteBox = overwriteBox;
exports.nextTurn = nextTurn;
exports.getNextGameState = getNextGameState;
/* No side effect */
