import random

def guess_the_number():
    secret_number = random.randint(1, 100)
    attempts = 0

    while True:
        guess = int(input("Enter your guess: "))
        attempts += 1

        if guess == secret_number:
            print(f"Congratulations! You guessed the number in {attempts} attempts.")
            break
        elif guess < secret_number:
            print("Try again. Go higher.")
        else:
            print("Try again. Go lower.")

# Uncomment the line below to play the game
# guess_the_number()
