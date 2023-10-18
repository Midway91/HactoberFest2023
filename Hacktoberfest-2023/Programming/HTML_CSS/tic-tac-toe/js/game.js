function reset() {
  active = 0;
  round = 1;
  gameOver = false;
  overG.firstElementChild.innerHTML = "You Won! <span id=\"winner\">Name</span>";
  overG.style.display = "none";

  let field = 0;
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      gameData[i][j] =0;
      fields[field].textContent = "";
      fields[field].classList.remove("del");
      field++;
    }
  }
}

function startGame() {
	if (players[0].name === "" || players[1].name === "") {
		alert("Please Set names before Starting a Game!");
		console.log("No Player on Board!");
		return;
	}

  reset();
  
	activePlayer.textContent = players[active].name;
	game.style.display = "block";
  console.log("The Game has Started! Let's Enjoy!");
}

function switchP() {
	if (active === 0) {
		active = 1;
	} else {
		active = 0;
	}
	activePlayer.textContent = players[active].name;
}

function sfield(event) {
  if (gameOver) {
    return;
  }

	const setField = event.target;
	const setCol = setField.dataset.col - 1;
	const setRow = setField.dataset.row - 1;

	if (gameData[setRow][setCol] > 0) {
		alert("Please select an Empty Field!");
		console.log("Invalid Selection! Try Again!");
		return;
	}

	setField.textContent = players[active].symbol;
	setField.classList.add("del");

	gameData[setRow][setCol] = active + 1;

  const win = over();

  if (win !== 0) {
    console.log("Checking for a Winner!")
    end(win);
  }

	console.log(`${players[active].name} has Played!`);

  round++;
	switchP();
}

function over() {
  // Check Rows
  for (let i = 0; i < 3; i++){
    if (
      gameData[i][0] > 0 && 
      gameData[i][0] === gameData[i][1] && 
      gameData[i][0] === gameData[i][2]
      ) {
      return gameData[i][0];
    }
  }

  // Check Cols
  for (let i = 0; i < 3; i++){
    if (
      gameData[0][i] > 0 && 
      gameData[0][i] === gameData[1][i] && 
      gameData[0][i] === gameData[2][i]
      ) {
      return gameData[0][i];
    }
  }

  // Check \
  if (
    gameData[0][0] > 0 && 
    gameData[0][0] === gameData[1][1] && 
    gameData[0][0] === gameData[2][2]
    ) {
      return gameData[0][0];
    }

    // Check /
  if (
    gameData[2][0] > 0 && 
    gameData[2][0] === gameData[1][1] && 
    gameData[2][0] === gameData[0][2]
    ) {
      return gameData[2][0];
    }

    if (round === 9) {
      return -1;
    }

    return 0;
}

function end(win) {
  gameOver = true;
  overG.style.display = "block";

  if (win > 0) {
    overG.firstElementChild.firstElementChild.textContent = players[win - 1].name + "!";
    console.log(`${players[win - 1].name} has Won! Congrats!`);
  } else {
    overG.firstElementChild.textContent = "It's A Draw";
    console.log("Winner can't be Found!");
  }
  
}
