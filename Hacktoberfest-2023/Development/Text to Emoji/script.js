// script.js
document.getElementById("convertButton").addEventListener("click", function() {
    const inputText = document.getElementById("inputText").value;
    const outputEmoji = document.getElementById("outputEmoji");

    // Function to convert text to emoji
    fetchEmojiMap((emojiMap) => {
        const emojiText = convertToEmoji(inputText, emojiMap);
        outputEmoji.textContent = emojiText;
    });
});

// Function to fetch the emoji mapping from emojis.json
function fetchEmojiMap(callback) {
    fetch('emojis.json') // Assuming the JSON file is in the same directory
        .then(response => response.json())
        .then(emojiMap => {
            callback(emojiMap);
        })
        .catch(error => {
            console.error('Error fetching emojis.json: ', error);
        });
}

// Function to convert text to emoji
function convertToEmoji(text, emojiMap) {
    text = text.toLowerCase(); // Ensure lowercase for word comparisons
    const words = text.split(' ');

    for (let i = 0; i < words.length; i++) {
        if (emojiMap[words[i]]) {
            words[i] = emojiMap[words[i]];
        }
    }

    return words.join(' ');
}
