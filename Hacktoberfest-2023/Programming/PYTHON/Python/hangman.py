import random

def choose_word():
    words = ["python", "hangman", "programming", "computer", "keyboard", "debugging"]
    return random.choice(words)

def display_word(word, guessed_letters):
    display = ""
    for letter in word:
        if letter in guessed_letters:
            display += letter
        else:
            display += "_"
    return display

def hangman():
    print("Welcome to Hangman!")
    secret_word = choose_word()
    guessed_letters = []
    attempts_left = 6  # Number of attempts allowed

    while attempts_left > 0:
        print("\nAttempts left:", attempts_left)
        current_display = display_word(secret_word, guessed_letters)
        print("Current Word:", current_display)

        guess = input("Enter a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Please enter a single letter.")
            continue

        if guess in guessed_letters:
            print("You've already guessed that letter. Try again.")
            continue

        guessed_letters.append(guess)

        if guess not in secret_word:
            print("Incorrect guess!")
            attempts_left -= 1

        if "_" not in display_word(secret_word, guessed_letters):
            print("\nCongratulations! You guessed the word:", secret_word)
            break

    if "_" in display_word(secret_word, guessed_letters):
        print("\nSorry, you're out of attempts. The word was:", secret_word)

if __name__ == "__main__":
    hangman()
