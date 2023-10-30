#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to clear the screen
void clearScreen() {
    cout << "\033[H\033[2J";
}

// Function to display the game title
void displayTitle() {
    cout << "******************************" << endl;
    cout << "Rock, Paper, Scissors Game!" << endl;
    cout << "******************************" << endl << endl;
}

// Function to display the game menu
void displayMenu() {
    cout << "Choose your move:" << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    int playerScore = 0;
    int computerScore = 0;

    while (true) {
        clearScreen();
        displayTitle();
        displayMenu();

        int playerChoice, computerChoice;

        cout << "Enter your choice (1-4): ";
        cin >> playerChoice;

        if (playerChoice == 4) {
            break;
        }

        if (playerChoice < 1 || playerChoice > 4) {
            cout << "Invalid choice. Please enter a valid option." << endl;
            continue;
        }

        // Generate a random choice for the computer (1-3)
        srand(time(0));
        computerChoice = rand() % 3 + 1;

        // Display player and computer choices
        clearScreen();
        displayTitle();
        cout << "Your choice: ";
        switch (playerChoice) {
            case 1:
                cout << "Rock";
                break;
            case 2:
                cout << "Paper";
                break;
            case 3:
                cout << "Scissors";
                break;
        }
        cout << endl;
        cout << "Computer's choice: ";
        switch (computerChoice) {
            case 1:
                cout << "Rock";
                break;
            case 2:
                cout << "Paper";
                break;
            case 3:
                cout << "Scissors";
                break;
        }
        cout << endl;

        // Determine the winner
        if (playerChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((playerChoice == 1 && computerChoice == 3) ||
                   (playerChoice == 2 && computerChoice == 1) ||
                   (playerChoice == 3 && computerChoice == 2)) {
            cout << "You win this round!" << endl;
            playerScore++;
        } else {
            cout << "Computer wins this round." << endl;
            computerScore++;
        }

        // Display the current score
        cout << "Your Score: " << playerScore << "  Computer Score: " << computerScore << endl;

        cout << "Play another round? (Y/N): ";
        char playAgain;
        cin >> playAgain;

        if (playAgain != 'Y' && playAgain != 'y') {
            break;
        }
    }

    clearScreen();
    displayTitle();
    cout << "Final Score:" << endl;
    cout << "Your Score: " << playerScore << "  Computer Score: " << computerScore << endl;
    cout << "Thank you for playing!" << endl;

    return 0;
}
