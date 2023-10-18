#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    float balance;
};

// Function to display the main menu
void displayMainMenu() {
    printf("\nBank Management System\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to create a new account
void createAccount(struct BankAccount accounts[], int *accountCount) {
    if (*accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    struct BankAccount newAccount;
    newAccount.accountNumber = *accountCount + 1;

    printf("Enter account holder's name: ");
    scanf("%s", newAccount.accountHolder);
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);

    accounts[*accountCount] = newAccount;
    (*accountCount)++;

    printf("Account created successfully with account number %d.\n", newAccount.accountNumber);
}

// Function to deposit money into an account
void deposit(struct BankAccount accounts[], int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw(struct BankAccount accounts[], int accountCount) {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }

    printf("Account not found.\n");
}

// Function to check account balance
void checkBalance(struct BankAccount accounts[], int accountCount) {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account holder: %s\n", accounts[i].accountHolder);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    struct BankAccount accounts[MAX_ACCOUNTS];
    int accountCount = 0;
    int choice;

    while (1) {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2:
                deposit(accounts, accountCount);
                break;
            case 3:
                withdraw(accounts, accountCount);
                break;
            case 4:
                checkBalance(accounts, accountCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
