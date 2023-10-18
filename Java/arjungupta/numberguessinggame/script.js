'use strict';

let secretNumber = Math.trunc(Math.random() * 20) + 1;
let score = 20;
let highScore = 0;
const displayMessage = function (message) {
  document.querySelector('.message').textContent = message;
};

document.querySelector('.check').addEventListener('click', function () {
  const value = Number(document.querySelector('.guess').value);

  if (!value) {
    displayMessage('😕 no number ');
  } else if (secretNumber === value) {
    // All things should happen if input is equal to secren number
    displayMessage('🎉 Correct Number ');
    document.querySelector('.number').textContent = secretNumber;

    document.querySelector('body').style.backgroundColor = '#60b347';

    document.querySelector('.number').style.width = '30rem';
    if (score > highScore) {
      highScore = score;
      document.querySelector('.highscore').textContent = highScore;
    }
  } else if (value !== secretNumber) {
    // all things should happen if input is not equal to secret number
    if (score > 1) {
      displayMessage(value > secretNumber ? '📈 Too high' : '📉 Too low');
      score--;

      document.querySelector('.score').textContent = score;
      //when input isn't between 1 and 20
      if (value > 20 || value < 1) {
        displayMessage('your number is not between 1 and 20🤨');
      }
    } else {
      displayMessage("☹ you're lost.");
      document.querySelector('.score').textContent = 0;
    }
  }
});

document.querySelector('.again').addEventListener('click', function () {
  // reset everything after clicking again button
  score = 20;
  secretNumber = Math.trunc(Math.random() * 20) + 1;

  displayMessage(' Start guessing...');

  document.querySelector('.score').textContent = score;
  document.querySelector('.number').textContent = '?';

  document.querySelector('.guess').value = '';

  document.querySelector('body').style.backgroundColor = '#222';
  document.querySelector('.number').style.width = '15rem';
});
