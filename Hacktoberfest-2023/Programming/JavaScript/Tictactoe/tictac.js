const div1 = document.querySelector("#one");
const div2 = document.querySelector("#two");
const div3 = document.querySelector("#three");
const div4 = document.querySelector("#four");
const div5 = document.querySelector("#five");
const div6 = document.querySelector("#six");
const div7 = document.querySelector("#seven");
const div8 = document.querySelector("#eight");
const div9 = document.querySelector("#nine");
const h2 = document.querySelector("h2");

let matchWonX = 0;
let matchWonO = 0;
let length = 0;
let turn = 0;
let p = "";
let round = 1;
const checkP = (divtag) => {
  const pAlready = divtag.querySelectorAll("p");

  length = pAlready.length;
  return length;
};
const createP = () => {
  p = document.createElement("p");

  if (turn % 2 == 0) {
    turn++;
    console.log("turn", turn);
    p.innerText = "X";
    return p;
  } else {
    turn++;
    console.log("turn", turn);
    p.innerText = "O";
    return p;
  }
};
div1.addEventListener("click", (e) => {
  if (checkP(div1) >= 1) {
    return;
  }
  pAll = div1.append(createP());
  winner(div1);
  wonOrLoss();
});

div2.addEventListener("click", () => {
  if (checkP(div2) >= 1) {
    return;
  }
  pAll = div2.append(createP());
  winner(div2);
  wonOrLoss();
});
div3.addEventListener("click", () => {
  if (checkP(div3) >= 1) {
    return;
  }
  div3.append(createP());
  winner(div3);
  wonOrLoss();
});
div4.addEventListener("click", () => {
  if (checkP(div4) >= 1) {
    return;
  }
  div4.append(createP());
  winner(div4);
  wonOrLoss();
});

div5.addEventListener("click", () => {
  if (checkP(div5) >= 1) {
    return;
  }
  div5.append(createP());
  winner(div5);
  wonOrLoss();
});

div6.addEventListener("click", () => {
  if (checkP(div6) >= 1) {
    return;
  }
  div6.append(createP());
  winner(div6);
  wonOrLoss();
});

div7.addEventListener("click", () => {
  if (checkP(div7) >= 1) {
    return;
  }
  div7.append(createP());
  winner(div7);
  wonOrLoss();
});
div8.addEventListener("click", () => {
  if (checkP(div8) >= 1) {
    return;
  }
  div8.append(createP());
  winner(div8);
  wonOrLoss();
});
div9.addEventListener("click", () => {
  if (checkP(div9) >= 1) {
    return;
  }
  div9.append(createP());
  winner(div9);
  wonOrLoss();
});

//<<------------------------  LOGIC COLUMN  ---------------------------->>
const h4 = document.querySelector(".XWon");
const h4O = document.querySelector(".OWon");

console.log(h4);
console.log(h4O);

//Function to add who won at the bottom of grid 
const winner = (divtag) => {
  const val1 = div1.innerText;
  const val2 = div2.innerText;
  const val3 = div3.innerText;
  const val4 = div4.innerText;
  const val5 = div5.innerText;
  const val6 = div6.innerText;
  const val7 = div7.innerText;
  const val8 = div8.innerText;
  const val9 = div9.innerText;
  if (h2.innerText.length < 5) {
    if (val1 == "X" && val2 == "X" && val3 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val4 == "X" && val5 == "X" && val6 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val7 == "X" && val8 == "X" && val9 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val1 == "X" && val5 == "X" && val9 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val3 == "X" && val5 == "X" && val7 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val2 == "X" && val5 == "X" && val8 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val3 == "X" && val6 == "X" && val9 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val1 == "X" && val4 == "X" && val7 == "X") {
      console.log("you won");
      h2.innerText = "X WON!!!";
      matchWonX++;
      return;
    }
    if (val1 == "O" && val2 == "O" && val3 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;
      return;
    }
    if (val4 == "O" && val5 == "O" && val6 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;

      return;
    }
    if (val7 == "O" && val8 == "O" && val9 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;

      return;
    }
    if (val1 == "O" && val5 == "O" && val9 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;

      return;
    }
    if (val3 == "O" && val5 == "O" && val7 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;

      return;
    }
    if (val1 == "O" && val4 == "O" && val7 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;
      return;
    }
    if (val2 == "O" && val5 == "O" && val8 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;
      return;
    }
    if (val3 == "O" && val6 == "O" && val9 == "O") {
      console.log("you won");
      h2.innerText = "O WON!!!";
      matchWonO++;
      return;
    }
    if (turn == 9 && h2.innerText == "") {
      console.log("DRAW");
      h2.innerText = "DRAW :(";
    }
  }
};

// REMOVES ALL P TAGS FROM DIVS
const removeAllp = () => {
  const divsWithP = document.querySelectorAll("div > p");

  // Loop through and remove each <p> element
  divsWithP.forEach((pElement) => {
    pElement.remove();
  });
};


//    CALCULATION AAND PRINTING OF WIN's
const wonOrLoss = () => {
  if (h2.innerText == "X WON!!!" || h2.innerText.length == 8) {
    console.log("match won X", matchWonX);
    h4.innerText = `win :${matchWonX}`;
  }
  if (h2.innerText == "O WON!!!" || h2.innerText.length > 4) {
    const h4 = document.querySelector(".OWon");
    console.log("match won O", matchWonO);
    h4O.innerText = `win :${matchWonO}`;
  }
  return;
};

//            RESETS THE ENTIRE GAME
const removeButton = document.querySelector(".reset");
removeButton.addEventListener("click", (e) => {
  // console.log("matchWonX :", matchWonX);
  // console.log("matchWonO :", matchWonO);
  // console.log("turn :", turn);
  // console.log("length :", length);
  // console.log("h2.innerText  (you won!!) :", h2.innerText);
  // console.log("h4.innerText :", h4.innerText);
  // console.log("p :", p);
  removeAllp();

  matchWonX = 0;
  matchWonO = 0;
  turn = 0;
  length = 0;
  h2.innerText = "";
  h4.innerText = `win : ${matchWonX}`;
  h4O.innerText = `win : ${matchWonO}`;

  console.log("matchWonX :", matchWonX);
  console.log("matchWonO :", matchWonO);
  console.log("turn :", turn);
  console.log("length :", length);
  console.log("h2.innerText (you won!!) :", h2.innerText);
  console.log("h4.innerText :", h4.innerText);
  console.log("p :", p);
});


const h5 = document.querySelector("h5");

//            NEW ROUND 
const playAgain = document.querySelector(".playAgain");
playAgain.addEventListener("click", (e) => {
  turn = 0;
  length = 0;
  h2.innerText = ""; //you won!!!
  removeAllp();
  round++;
  h5.innerText = `Round ${round}`;
});


//chat gpt optimized one

// const divs = Array.from(document.querySelectorAll(".children"));
// const h2 = document.querySelector("h2");
// const h4 = document.querySelector(".XWon");
// const h4O = document.querySelector(".OWon");
// const h5 = document.querySelector("h5");

// let matchWonX = 0;
// let matchWonO = 0;
// let turn = 0;
// let round = 1;

// const checkWinner = () => {
//   const winPatterns = [
//     [0, 1, 2],
//     [3, 4, 5],
//     [6, 7, 8],
//     [0, 3, 6],
//     [1, 4, 7],
//     [2, 5, 8],
//     [0, 4, 8],
//     [2, 4, 6],
//   ];

//   for (const pattern of winPatterns) {
//     const [a, b, c] = pattern;
//     if (divs[a].innerText && divs[a].innerText === divs[b].innerText && divs[b].innerText === divs[c].innerText) {
//       return divs[a].innerText;
//     }
//   }

//   return turn === 9 ? "DRAW" : null;
// };

// const createP = () => {
//   const currentPlayer = turn % 2 === 0 ? "X" : "O";
//   turn++;
//   const p = document.createElement("p");
//   p.innerText = currentPlayer;
//   return p;
// };

// const handleClick = (div, index) => {
//   if (div.innerText || h2.innerText) return;

//   div.appendChild(createP());
//   const winner = checkWinner();
//   if (winner) {
//     h2.innerText = winner === "DRAW" ? "DRAW :(" : `${winner} WON!!!`;
//     if (winner === "X") matchWonX++;
//     if (winner === "O") matchWonO++;
//     updateScore();
//   }
// };

// const removeAllp = () => {
//   divs.forEach((div) => {
//     div.innerHTML = "";
//   });
// };

// const updateScore = () => {
//   h4.innerText = `Win: ${matchWonX}`;
//   h4O.innerText = `Win: ${matchWonO}`;
// };

// divs.forEach((div, index) => {
//   div.addEventListener("click", () => {
//     handleClick(div, index);
//   });
// });

// const resetButton = document.querySelector(".reset");
// resetButton.addEventListener("click", () => {
//   removeAllp();
//   matchWonX = 0;
//   matchWonO = 0;
//   turn = 0;
//   h2.innerText = "";
//   updateScore();
// });

// const playAgainButton = document.querySelector(".playAgain");
// playAgainButton.addEventListener("click", () => {
//   removeAllp();
//   turn = 0;
//   h2.innerText = "";
//   round++;
//   h5.innerText = `Round ${round}`;
// });

// updateScore();
