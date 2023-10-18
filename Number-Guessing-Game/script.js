const randomNumber = Math.floor(Math.random() * 100) + 1;
let attempts = 0;

const inputBox = document.getElementById("inputBox");
const checkButton = document.getElementById("checkButton");
const message = document.getElementById("message");

checkButton.addEventListener("click", function () {
  const userGuess = parseInt(inputBox.value);

  if (isNaN(userGuess) || userGuess < 1 || userGuess > 100) {
    message.textContent = "Please enter a valid number between 1 and 100.";
  } else {
    attempts++;
    if (userGuess === randomNumber) {
      message.textContent = `Congratulations! You guessed the number ${randomNumber} in ${attempts} attempts.`;
      checkButton.disabled = true;
      checkButton.style.backgroundColor = "#ccc";
      setTimeout(() => {
        location.reload();
      }, 1000);
    } else if (userGuess < randomNumber) {
      message.textContent = "Try a higher number.";
    } else {
      message.textContent = "Try a lower number.";
    }
  }
});
inputBox.addEventListener("keyup", function (event) {
  if (event.keyCode === 13) {
    event.preventDefault();
    checkButton.click();
  }
});
