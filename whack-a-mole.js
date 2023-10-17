---------------------------------------------------------------------------------------------------index.html-------------------------------------------------------------------------------------------------


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="styles.css">
    <title>Whack a Mole!</title>
</head>

<body>
    <h1>Whack-a-mole!</h1><span class="score">0</span>
    <button onClick="startGame()">Start!</button>

    <div class="game">
        <div class="hole hole1">
            <div class="mole"></div>
        </div>

        <div class="hole hole2">
            <div class="mole"></div>
        </div>

        <div class="hole hole3">
            <div class="mole"></div>
        </div>

        <div class="hole hole4">
            <div class="mole"></div>
        </div>

        <div class="hole hole5">
            <div class="mole"></div>
        </div>

        <div class="hole hole6">
            <div class="mole"></div>
        </div>

    </div>
    <script src="script.js"></script>
</body>

</html>



  ----------------------------------------------------------------------------------------------script.js---------------------------------------------------------------------------------------------------

    const holes = document.querySelectorAll('.hole');
const scoreBoard = document.querySelector('.score');
const moles = document.querySelectorAll('.mole');
let lastHole;
let timeUp = false;
let score = 0;

//create a function to make a random time for mole to pop from the hole
function randomTime(min, max) {
    return Math.round(Math.random() * (max - min) + min);
}

function randomHole(holes){
    const index  = Math.floor(Math.random() * holes.length);
    const hole = holes[index];

    //prevent same hole from getting the same number
    if (hole === lastHole){
        return randomHole(holes);
    }
    lastHole = hole;
    return hole;
}

function peep() {
    const time = randomTime(500, 1000); //get a random time to determine how long mole should peep
    const hole = randomHole(holes); //get the random hole from the randomHole function
    hole.classList.add('up'); //add the CSS class so selected mole can "pop up"
    setTimeout(() => {
        hole.classList.remove('up'); //make the selected mole "pop down" after a random time
        if(!timeUp) {
            peep();
        }
    }, time);
}

function startGame() {
    scoreBoard.textContent = 0;
    timeUp = false;
    score = 0;
    peep();
    setTimeout(() => timeUp = true, 15000) //show random moles for 15 seconds
}

function wack(e){
    if(!e.isTrusted) return; //** new thing I learned */
    score++;
    this.parentNode.classList.remove('up'); //this refers to item clicked
    scoreBoard.textContent = score;
}

moles.forEach(mole => mole.addEventListener('click', wack))


------------------------------------------------------------------------------------------------styles.css-------------------------------------------------------------------------------------------------


  html {
    font-size: 35px;
    background: #98BCF4;
}

body {
    padding: 0;
    margin: 0;
    text-align: center;
}

h1 {
    text-align: center;
    font-size: 100px;
    line-height: 1;
    margin-bottom: 0;
}

.score {
    background:blue;
    padding: 0 48px;
    line-height: 1;
    border-radius: 16px;
    color: #fff;
    margin-left: 15px;
}

.game {
    width: 600px;
    height: 400px;
    display:flex;
    flex-wrap:wrap;
    margin: 0 auto;
    
}

.hole{
    flex: 1 0 33.33%;
    overflow: hidden;
    position: relative;
}

.hole:after{
    display:block;
    background: url(dirt.png) bottom center no-repeat;
    background-size:contain;
    content: '';
    width: 100%;
    height: 90px;
    position: absolute;
    z-index: 2;
    bottom: -30px;
}

.mole {
    background: url('mole.png') bottom center no-repeat;
    background-size: 80%;
    position: absolute;
    top: 100%;
    width: 100%;
    height: 100%;
    transition: all 0.4s;
}

.hole.up .mole{
    top:0;
}

button{
    width:175px;
    font-size: 35px;
    height: 70px;
    color: #fff;
    background-color: blue;
    border-radius: 10px;
    margin-left: 20px;
    margin-top: 90px;
}

@media (min-width: 667px) and (max-width: 1024px){
    
    h1 {
        display: none;
    }
    .score {
    background:blue;
    padding: 0 12px;
    line-height: 1;
    border-radius: 16px;
    color: #fff;
    font-size: 40px;
    margin-left: 20px;
}

    .hole.up .mole{
        top:17px;
    }
}

@media (max-width: 667px){

    .game {
        width: 667px;
        height: 300px;
        display:flex;
        flex-wrap:wrap;
        margin: 0 auto;
    }

    .score{
        width:35px;
        font-size: 15px;
        height: 40px;
        color: #fff;
        background-color: blue;
        border-radius: 10px;
        margin-left: 10px;
        margin-top: 10px;
        padding: 5px;
        }

        button{
            margin: 10px 10px 10px 10px;
            height: 40px;
            width: 75px;
            font-size: 15px;
        }

    .hole:after{
        display:block;
        background: url(dirt.png) bottom center no-repeat;
        background-size:contain;
        content: '';
        max-width: 70%;
        height: 60px;
        position: absolute;
        z-index: 2;
        bottom: -30px;
    }

    .mole {
        background: url('mole.png') bottom center no-repeat;
        background-size: 60%;
        position: absolute;
        top: 100%;
        max-width: 70%;
        height: 70%;
        transition: all 0.4s;
    }

    .hole.up .mole{
        top:50px;
    }
}



-----------------------------dirt.png, mole.jpg, mole.png are just images, which are not included here--------------------------------------------------------- 






    
