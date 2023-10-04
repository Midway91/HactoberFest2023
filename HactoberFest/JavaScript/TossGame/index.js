var random1 = Math.floor( Math.random()*6 ) + 1
var random2 = Math.floor( Math.random()*6 ) + 1
document.getElementById("img1").setAttribute("src" , "./images/dice" + random1 + ".png" )
document.getElementById("img1").setAttribute("alt" , random1 )
document.getElementById("img2").setAttribute("src" , "./images/dice" + random2 + ".png" )
document.getElementById("img2").setAttribute("alt" , random2 )
var win;
if(random1 > random2)
{
     win = "Player 1 Wins"
}
else if( random1 == random2)
{
     win = "It's a Draw, Try Again"
}
else
{
     win = "Player 2 Wins"
}
document.querySelector("h1").textContent = win