//first code in js// a beginner //spam is a friend group, go and press a number between 0 to 9 to know about them
console.log("Hey! Choose your choice: ");
const spam = prompt("Enter a number between 0 and 9");
const spamNumber = parseInt(spam);

switch (spamNumber) {
  case 1:
    console.log("Adwaith, python pro");
    break;
  case 2:
    console.log("Ashton, math expert");
    break;
  case 3:
    console.log("Ashel, pretty lady");
    break;
  case 4:
    console.log("Aatul, the piggy man");
    break;
  case 5:
    console.log("Ebey, the clown");
    break;
  case 6:
    console.log("Aju, Annoying ass");
    break;
  case 7:
    console.log("Ian, Kuwait guy");
    break;
  case 8:
    console.log("Ahnaf, football player");
    break;
  default:
    console.log("Not a spam member");
}
