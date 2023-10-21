function openConfig(event) {
  player = +event.target.dataset.player;
  ovrl.style.display = "block";
  backdrop.style.display = "block";
  console.log("Input Box Opened!")
}

function closeConfig() {
  ovrl.style.display = "none";
  backdrop.style.display = "none";
  form.firstElementChild.classList.remove("error");
  error.textContent = "";
  form.firstElementChild.lastElementChild.value = "";
  console.log("Input Box Closed!")
}

function saveConfig(event) {
  event.preventDefault();
  const data = new FormData(event.target);
  const uname = data.get("uname").trim();

  if (!uname) {
    event.target.firstElementChild.classList.add("error");
    error.textContent = "Please Enter a Valid Name";
    console.log("The Input is Invalid!");
    return;
  }

  const updatePlayer = document.getElementById(`p${player}`);
  updatePlayer.children[1].textContent = uname;

  players[player - 1].name = uname;

  const playerGreet = {
    1 : "X",
    2 : "Y",
  };

  console.log(`Welcome to the Board! ${uname}!\n You are now Player ${playerGreet[player]}! Happy Gaming!`);

  closeConfig();
}
