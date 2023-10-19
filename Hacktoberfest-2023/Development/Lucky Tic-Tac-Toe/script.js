console.log("Welcome");
let bgmusic = new Audio('music.mp3');
let turnmusic = new Audio('ting.mp3');
let gameovermusic = new Audio('gameover.mp3');
let turn = "X";
let gameover = false;

// Function to change the turn
const changeTurn = () => {
    return turn === "X" ? "O" : "X";
}

// Function to check for a win
const checkWin = () => {
    let boxText = document.getElementsByClassName('boxText');
    let wins = [
        [0, 1, 2, 5, 5, 0],
        [3, 4, 5, 5, 15, 0],
        [6, 7, 8, 5, 25, 0],
        [0, 3, 6, -5, 15, 90],
        [1, 4, 7, 5, 15, 90],
        [2, 5, 8, 15, 15, 90],
        [0, 4, 8, 5, 15, 45],
        [2, 4, 6, 5, 15, 135],
    ]
    wins.forEach(e => {
        if ((boxText[e[0]].innerText === boxText[e[1]].innerText) && (boxText[e[0]].innerText === boxText[e[2]].innerText) && (boxText[e[0]].innerText !== '')) {
            document.querySelector('.info').innerText = boxText[e[0]].innerText + " Won";
            gameover = true;
            gameovermusic.play();
            document.querySelector('.imgbox').getElementsByTagName('img')[0].style.opacity = 1;

            // Line
            document.querySelector('.line').style.width = "20vw";
            document.querySelector('.line').style.transform = `translate(${e[3]}vw, ${e[4]}vw) rotate(${e[5]}deg)`;
        }
    })
}

// Game logic
let boxes = document.getElementsByClassName("box");
Array.from(boxes).forEach(element => {
    let boxText = element.querySelector('.boxText');
    element.addEventListener('click', () => {
        bgmusic.play();
        if (boxText.innerText === "") {
            haha()
            boxText.innerText = turn;
            turn = changeTurn();
            turnmusic.play();
            checkWin();
            if (!gameover) {
                document.getElementsByClassName("info")[0].innerText = "Turn for " + turn;
            }
        }
    })
})

// Reset button
reset.addEventListener('click', () => {
    let boxText = document.querySelectorAll('.boxText');
    Array.from(boxText).forEach(element => {
        element.innerText = "";
    })
    turn = "X";
    gameover = false;
    document.querySelector('.line').style.width = "0vw";
    document.getElementsByClassName("info")[0].innerText = "Turn for " + turn;
    document.querySelector('.imgbox').getElementsByTagName('img')[0].style.opacity = 0;
    gameovermusic.pause();
})

function getRandomInt() {

    return Math.floor(Math.random() * 3);
}

function haha() {
    let p = getRandomInt();
    if(p===0){
        var n="X";
    }
    else if(p===1){
        var n="O";
    }
    else{
        var n="";
    }

    let boxes = document.getElementsByClassName("box");
    Array.from(boxes).forEach(element => {
        let boxText = element.querySelector('.boxText');
        if(boxText.innerText==="X"){
            boxText.innerText=n;
        }
        else if(boxText.innerText==="O"){
            boxText.innerText=n;
        }
    })
}

function darkmode() {
    // var p = document.getElementById("css").href;
    if (document.getElementById("css").href="style.css"){
        document.getElementById("css").href="style2.css";
    }
    // if(document.getElementById("css").href="style2.css"){
    //     document.getElementById("css").href="style.css";
    // }
}