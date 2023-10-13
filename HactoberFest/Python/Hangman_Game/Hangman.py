import random  # import the random module to generate random words
# import the ASCII art for the hangman stages and game logo
from ascii_code import stages, logo
import List_of_words  # import the list of words to choose from
# import the clear function from replit module to clear the console
from replit import clear

print(logo)  # display the game logo
print("Welcome to Hangman")  # display a welcome message to the user
# choose a random word from the list of words
chosen_word = random.choice(List_of_words.word_list)

display = []  # create an empty list to hold the word to be guessed
for char in chosen_word:  # loop through each character in the chosen word
    # add a blank space to the display list for each character in the chosen word
    display.append("_")

lives = 6  # set the number of lives the user has

end_of_game = False  # set a flag to indicate if the game has ended
while end_of_game == False:  # loop until the game has ended
    # prompt the user to guess a letter and convert to lowercase
    guess = input("Guess a Letter: ").lower()
    clear()  # clear the console

    if guess in display:  # check if the user has already guessed the letter
        print(f"You've already guessed {guess}")

    # loop through each character in the chosen word
    for position in range(len(chosen_word)):
        # get the character at the current position
        letter = chosen_word[position]
        if letter == guess:  # check if the guessed letter matches the current character
            # update the display list with the guessed letter
            display[position] = letter

    if guess not in chosen_word:  # check if the guessed letter is not in the chosen word
        print(f"You guessed {guess}, that's not in the word. You lose a life.")
        lives -= 1  # decrease the number of lives the user has
        if lives == 0:  # check if the user has no more lives
            end_of_game = True  # end the game
            print('You Lose')

    # display the current state of the word to be guessed
    print(f"{''.join(display)}")

    if "_" not in display:  # check if all the letters have been guessed correctly
        end_of_game = True  # end the game
        print("You win")
    # display the current hangman stage based on the number of lives remaining
    print(stages[lives])