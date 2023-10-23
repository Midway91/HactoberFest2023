// Sample quotes for the typing test
const quotes = [
    "The quick brown fox jumps over the lazy dog.",
    "Coding is fun and challenging at the same time.",
    "Practice makes perfect.",
    "Keep calm and code on.",
    "JavaScript is a powerful programming language.",
    "Programming is a way of thinking.",
    "Learn to code and change the world.",
    "Software development is an art and a science."
];

let currentQuoteIndex = 0;
let startTime, endTime;

const quoteElement = document.getElementById("sentence");
const inputElement = document.getElementById("input");
const resultElement = document.getElementById("result");
const wpmElement = document.getElementById("wpm");
const startButton = document.getElementById("startButton");
const typingSection = document.getElementById("typing-section");
let totalTypedWords = 0; // Keep track of total typed words

function generateRandomQuote() {
    const randomIndex = Math.floor(Math.random() * quotes.length);
    return quotes[randomIndex];
}

function startTest() {
    startButton.style.display = "none";
    typingSection.style.display = "block"; // Show typing section
    currentQuoteIndex = 0;
    inputElement.value = "";
    quoteElement.textContent = generateRandomQuote();
    totalTypedWords=0;
    inputElement.focus();
    startTime = new Date();
}

function endTest() {
    endTime = new Date();
    const elapsedTimeInSeconds = (endTime - startTime) / 1000;
    const wordsPerMinute = Math.round((totalTypedWords / elapsedTimeInSeconds) * 60);

    resultElement.style.display = "block";
    wpmElement.textContent = wordsPerMinute;
    startButton.style.display = "block";
    startButton.textContent = "Restart";
}

inputElement.addEventListener("input", function () {
    if (inputElement.value === quoteElement.textContent) {
        currentQuoteIndex++;
        if (currentQuoteIndex < quotes.length) {
            totalTypedWords += inputElement.value.split(/\s+/).length;
            quoteElement.textContent = quotes[currentQuoteIndex];
            inputElement.value = "";
        } else {
            endTest();
        }
    }
});

startButton.addEventListener("click", function () {
    if (startButton.textContent === "Start") {
        startTest();
    } else {
        startButton.textContent = "Start";
        resultElement.style.display = "none";
        typingSection.style.display = "none"; // Hide typing section on restart
    }
}); 