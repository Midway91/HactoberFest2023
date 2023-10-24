<!DOCTYPE html>
<html>
<head>
  <title>Dino Game</title>
  <style>
    body {
      margin: 0;
      overflow: hidden;
      background-color: #f7f7f7;
    }
    
    #game {
      width: 600px;
      height: 150px;
      margin: 50px auto;
      border: 1px solid #000;
      position: relative;
      background-color: #f7f7f7;
    }

    #dino {
      width: 40px;
      height: 40px;
      position: absolute;
      bottom: 0;
      left: 50px;
      background-color: #666;
    }

    #cactus {
      width: 20px;
      height: 40px;
      position: absolute;
      bottom: 0;
      right: 0;
      background-color: #222;
    }

    #score {
      position: absolute;
      top: 10px;
      right: 10px;
      font-size: 24px;
      font-weight: bold;
    }
  </style>
</head>
<body>
  <div id="game">
    <div id="dino"></div>
    <div id="cactus"></div>
  </div>
  <div id="score">0</div>

  <script>
    const dino = document.getElementById("dino");
    const cactus = document.getElementById("cactus");
    const scoreDisplay = document.getElementById("score");

    let isJumping = false;
    let score = 0;

    document.addEventListener("keydown", jump);

    function jump(event) {
      if (event.keyCode === 32 && !isJumping) {
        isJumping = true;
        let jumpHeight = 0;
        const jumpInterval = setInterval(() => {
          if (jumpHeight >= 150) {
            clearInterval(jumpInterval);
            let fallInterval = setInterval(() => {
              if (jumpHeight <= 0) {
                clearInterval(fallInterval);
                isJumping = false;
              } else {
                jumpHeight -= 20;
                dino.style.bottom = jumpHeight + "px";
              }
            }, 20);
          } else {
            jumpHeight += 20;
            dino.style.bottom = jumpHeight + "px";
          }
        }, 20);
      }
    }

    function checkCollision() {
      const dinoTop = parseInt(window.getComputedStyle(dino).getPropertyValue("top"));
      const cactusLeft = parseInt(window.getComputedStyle(cactus).getPropertyValue("left"));

      if (cactusLeft < 50 && cactusLeft > 0 && dinoTop >= 100) {
        alert("Game Over! Your score: " + score);
        score = 0;
        scoreDisplay.innerHTML = score;
        cactus.style.animation = "none";
      }
    }

    setInterval(checkCollision, 10);

    function updateScore() {
      score++;
      scoreDisplay.innerHTML = score;
    }

    let cactusSpeed = 10;
    setInterval(() => {
      const cactusLeft = parseInt(window.getComputedStyle(cactus).getPropertyValue("left"));
      if (cactusLeft <= -20) {
        updateScore();
        cactus.style.animation = "cactus 1s linear";
      }
      cactus.style.left = cactusLeft - cactusSpeed + "px";
    }, 20);
  </script>
</body>
</html>

