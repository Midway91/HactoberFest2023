#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void initialMenu();

void clearScreen() {
    system("CLS");
}

void initializeBoard(char board[10][10], char mask[10][10]) {
    int row, column;

    for (row = 0; row < 10; row++) {
        for (column = 0; column < 10; column++) {
            board[row][column] = 'A';
            mask[row][column] = '*';
        }
    }
}

void displayMap() {
    int count;

    for (count = 0; count < 10; count++) {
        if (count == 0) {
            cout << "    ";
        }
        cout << count << " ";
    }
    cout << "\n";
    for (count = 0; count < 10; count++) {
        if (count == 0) {
            cout << "    ";
        }
        cout << "| ";
    }
    cout << "\n";
}

void printBoard(char board[10][10], char mask[10][10], bool showSolution) {

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
    char pink[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    int row, column;

    for (row = 0; row < 10; row++) {
        cout << row << " -";
        for (column = 0; column < 10; column++) {
            switch (mask[row][column]) {
                case 'A':
                    cout << blue << " " << mask[row][column] << normal;
                    break;
                case 'P':
                    cout << green << " " << mask[row][column] << normal;
                    break;
                case 'M':
                    cout << yellow << " " << mask[row][column] << normal;
                    break;
                case 'G':
                    cout << pink << " " << mask[row][column] << normal;
                    break;
                default:
                    cout << " " << mask[row][column];
                    break;
            }
        }
        cout << "\n";
    }
    if (showSolution == true) {
        cout << "\n\n";
        for (row = 0; row < 10; row++) {
            for (column = 0; column < 10; column++) {
                cout << " " << board[row][column];
            }
            cout << "\n";
        }
    }
}

void placeShips(char board[10][10]) {
    int count = 0, quantity = 10;

    while (count < quantity) {
        int shipRow = rand() % 10;
        int shipColumn = rand() % 10;

        if (board[shipRow][shipColumn] == 'A') {
            board[shipRow][shipColumn] = 'P';
            count++;
        }
    }
    count = 0;
    quantity = 5;
    while (count < quantity) {
        int shipRow = rand() % 5;
        int shipColumn = rand() % 5;

        if (board[shipRow][shipColumn] == 'A') {
            board[shipRow][shipColumn] = 'M';
            count++;
        }
    }
    count = 0;
    quantity = 3;
    while (count < quantity) {
        int shipRow = rand() % 3;
        int shipColumn = rand() % 3;

        if (board[shipRow][shipColumn] == 'A') {
            board[shipRow][shipColumn] = 'G';
            count++;
        }
    }
}

int checkShot(char board[10][10], int shotRow, int shotColumn, int *score, string *message) {

    switch (board[shotRow][shotColumn]) {
        case 'P':
            *score += 10;
            *message = "You hit a small boat, +10 points. ";
            break;
        case 'M':
            *score += 15;
            *message = "You hit a medium boat, +15 points. ";
            break;
        case 'G':
            *score += 20;
            *message = "You hit a large boat, +20 points. ";
            break;
        case 'A':
            *message = "You hit the water, try again! ";
            break;
    }
}

void game(string name) {
    char board[10][10], mask[10][10];
    int row, column, shotRow, shotColumn, option;
    int score = 0, attempts = 0, maxAttempts = 25;
    string message = "Make a move, ";

    initializeBoard(board, mask);

    placeShips(board);

    while (attempts < maxAttempts) {
        clearScreen();
        displayMap();
        printBoard(board, mask, false);

        cout << "\n\nScore: " << score << "\n";
        cout << message << name << ", you have: " << maxAttempts - attempts << " attempts left\n";

        while ((shotRow < 0 || shotColumn < 0) || (shotRow > 9 || shotColumn > 9)) {
            cout << "\n" << name << ", enter a row: ";
            cin >> shotRow;
            cout << "\n" << name << ", enter a column: ";
            cin >> shotColumn;
        }

        checkShot(board, shotRow, shotColumn, &score, &message);

        mask[shotRow][shotColumn] = board[shotRow][shotColumn];

        attempts++;
    }
    cout << "\nGame over.\nWhat do you want to do, " << name << "?\n";
    cout << "\n1 - Initial menu.";
    cout << "\n2 - Play again.";
    cout << "\n3 - Exit.";
    cin >> option;

    switch (option) {
        case 1:
            initialMenu();
            break;
        case 2:
            game(name);
            break;
        case 3:
            cout << "\nThank you for playing! :)";
            break;
    }
}

void initialMenu() {
    int option;
    string name;

    while (option <= 0 || option > 3) {
        clearScreen();
        cout << "Welcome to the Game!\nOptions:\n";
        cout << "\n1 - Play.";
        cout << "\n2 - About.";
        cout << "\n3 - Exit.\n";
        cout << "\nChoose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "What is the player's name?\n";
                cin >> name;
                cout << "\nChosen option: 1 - Play.\n\n";
                game(name);
                break;
            case 2:
                cout << "\nChosen option: 2 - About.";
                cout << "\nGame information:\n";
                cout << "Battleship game developed for learning C/C++ programming.";
                cout << "\nMade by Joao Vitor Pitta.\nGitHub: ZPitta";
                cout << "\n\nSelect an option:\n";
                cout << "\n1 - Back.\n2 - Exit.\n\n";
                cin >> option;
                if (option == 1) {
                    initialMenu();
                }
                break;
            case 3:
                cout << "\nChosen option: 3 - Exit.";
                cout << "\nGoodbye.";
                break;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    initialMenu();

    return 0;
}