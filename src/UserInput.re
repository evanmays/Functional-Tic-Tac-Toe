type keyboardInput =
  | TopLeft
  | TopMiddle
  | TopRight
  | MiddleLeft
  | MiddleMiddle
  | MiddleRight
  | BottomLeft
  | BottomMiddle
  | BottomRight;

let isValidInputString = (input: string) => {
  switch (input) {
  | "top left" => true
  | "top middle" => true
  | "top right" => true
  | "middle left" => true
  | "middle middle" => true
  | "middle right" => true
  | "bottom left" => true
  | "bottom middle" => true
  | "bottom right" => true
  | _ => false
  };
};

let gatherInput = (input: string) => {
  switch (input) {
  | "top left" => TopLeft
  | "top middle" => TopMiddle
  | "top right" => TopRight
  | "middle left" => MiddleLeft
  | "middle middle" => MiddleMiddle
  | "middle right" => MiddleRight
  | "bottom left" => BottomLeft
  | "bottom middle" => BottomMiddle
  | "bottom right" => BottomRight
  | _ => BottomRight
  };
};
