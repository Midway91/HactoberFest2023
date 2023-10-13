# Hangman Game

This is a simple command-line implementation of the Hangman game written in Python. It allows the user to play the game by guessing letters to reveal a hidden word.

## Getting Started

1. Clone the repository to your local machine.
2. Install the required modules using the command

```
pip install -r requirements.txt
```

3. Run the game by running the `hangman.py` file using Python.

```
python hangman.py
```

### How to Play

1. When you start the game, you will be presented with a blank word with underscores representing each letter.

2. Guess a letter by typing it into the console and pressing Enter.

3. If the letter is in the word, it will be revealed in the appropriate places. If not, you will lose a life.

4. Keep guessing letters until you either guess the word correctly or run out of lives.

5. You have 6 lives to start with. If you lose all your lives, the game is over and you lose.

6. If you guess all the letters in the word before losing all your lives, you win!

#### Alternatives to the replit module

The `replit` library is used specifically for clearing the console in Replit. If you're using a different environment or IDE, there may be other ways to clear the console.

1. Using os module

```
import os
os.system('cls' if os.name == 'nt' else 'clear')
```

This will call the appropriate command to clear the console based on the operating system you're using.

2. Using ANSI escape sequences:

```
print('\033[H\033[J')
```

This will send a series of ANSI escape sequences that clear the console.

3. Using IPython magic command:
   If you're using IPython, you can use the `%clear` magic command to clear the console:

```
from IPython.display import clear_output
clear_output(wait=True)
```

This will clear the console in IPython and wait for new input to be entered.

**NB** Note that some of these methods may not work in certain environments or operating systems, so you may need to experiment to find the best solution for your specific use case.
