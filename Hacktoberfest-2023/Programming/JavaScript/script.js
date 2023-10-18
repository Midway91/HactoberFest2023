
const quotes = [
    "The only way to do great work is to love what you do. - Steve Jobs",
    "In the end, we will remember not the words of our enemies, but the silence of our friends. - Martin Luther King Jr.",
    "The future belongs to those who believe in the beauty of their dreams. - Eleanor Roosevelt",
    "Success is not final, failure is not fatal: It is the courage to continue that counts. - Winston Churchill",
    "Life is what happens when you're busy making other plans. - John Lennon",
    "The only thing necessary for the triumph of evil is for good men to do nothing. - Edmund Burke",
    "The best way to predict the future is to invent it. - Alan Kay",
    "The greatest glory in living lies not in never falling, but in rising every time we fall. - Nelson Mandela"
];


function generateRandomQuote() {
    const randomIndex = Math.floor(Math.random() * quotes.length);
    return quotes[randomIndex];
}


function displayQuote() {
    const quoteText = generateRandomQuote();
    const quoteContainer = document.getElementById("quote-text");
    quoteContainer.textContent = quoteText;
}


document.addEventListener("DOMContentLoaded", function () {
    const generateButton = document.getElementById("generate-button");
    
   
    generateButton.addEventListener("click", displayQuote);
});
