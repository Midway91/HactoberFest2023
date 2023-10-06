let gameData = [
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0],
]

let player = 0;
let active = 0;
let round = 1;
let gameOver = false;

const players = [
  {
    name: "",
    symbol: "X"
  },
  {
    name: "",
    symbol: "O"
  },
]

const ovrl = document.getElementById("ovrl");
const backdrop = document.getElementById("backdrop");
const form = document.querySelector("form");
const error = document.getElementById("error");
const game = document.getElementById("game");
const fields = document.querySelectorAll("#board li");
const activePlayer = document.getElementById("player");
const overG = document.getElementById("over");
const winner = document.getElementById("winner")

const ex = document.getElementById("ex");
const ey = document.getElementById("ey");
const cancel = document.getElementById("cancel");
const start = document.getElementById("start");

ex.addEventListener("click", openConfig);
ey.addEventListener("click", openConfig);

cancel.addEventListener("click", closeConfig);
backdrop.addEventListener("click", closeConfig);

form.addEventListener("submit", saveConfig);

start.addEventListener("click", startGame);

for (const field of fields) {
  field.addEventListener("click", sfield);
}
