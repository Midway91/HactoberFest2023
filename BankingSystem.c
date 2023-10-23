#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function declaration

void createAccount();
long long genAcNumber();
void login();
void checkBalance();
void cashDeposit();
void cashWithdrawl();
void onlineTransfer();
void changePassword();
void showDetails();
void logout();
void loanInterestCalculator();
void EMICalculator();

struct user
{
    char userID[10];
    char phone[15];
    char password[10];
    char fname[20];
    char lname[20];
    long long accountNumber;
    float balance;
};
struct user usr, usr1;

FILE *ob;
char filename[50], userID[50], passKey[50];
int option, choice, loantype, duration;
float interestPercentage, loanAmount, totalAmount, totalInterest, amount;
char cont1 = 'a', flg = 'y';

int main()
{
    system("cls");

    while (flg == 'y')
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\t\tWELCOME TO ONLINE BANKING SYSTEM  \n\n\n\n");

        printf("\n\t\t\t\tWhat do you want to do?");
        printf("\n\n\n\n\t\t\t\t1. Create an account");
        printf("\n\n\t\t\t\t2. Login to an account");
        printf("\n\n\t\t\t\t3. Loan enquiry");

        printf("\n\n\n\n\t\t\t\tYour choice:\t");
        scanf("%d", &option);

        // New Account Section

        if (option == 1)
        {
            createAccount();
        }

        // Login Section

        else if (option == 2)
        {
            login();
        }

        else
        {
            printf("\t\t\t\tYou have entered invalid option");
        }

        printf("\n\n\t\t\t\tDo you want to continue Banking?  [y/n]\t");

        char flg1 = 't';
        while (flg1 != 'y' || flg1 != 'n')
        {
            scanf("%s", &flg1);
            if (flg1 == 'y')
            {
                flg = 'y';
                break;
            }
            else if (flg1 == 'n')
            {
                flg = 'n';
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t========   THANK YOU FOR BANKING WITH US    ========");
                printf("\n\n\t\t\t\t\t\t\t================    VISIT AGAIN    =================\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                break;
            }
            else
            {
                printf("\n\n\t\t\t\tYou have choosen INVALID OPTION !! Try again \n");
                printf("\n\t\t\t\tDo you want to continue Banking? [y/n]\t");
            }
        }
    }

    return 0;
}

// Functions for different features

void createAccount()
{
    system("cls");
    printf("\n\n\n\n\t\t\t\t\t\t------    CREATE ACCOUNT    ------ ");
    printf("\n\n\n\n\t\t\t\tEnter a userID \t\t\t: ");
    scanf("%s", usr.userID);
    printf("\n\t\t\t\tEnter your phone number\t\t: ");
    scanf("%s", usr.phone);
    printf("\n\t\t\t\tFirst Name \t\t\t: ");
    scanf("%s", &usr.fname);
    printf("\n\t\t\t\tLast Name \t\t\t: ");
    scanf("%s", &usr.lname);
    printf("\n\t\t\t\tSet your password\t\t: ");
    scanf("%s", usr.password);
    usr.balance = 0;
    strcpy(filename, usr.userID);
    ob = fopen(strcat(filename, ".txt"), "w");
    fwrite(&usr, sizeof(struct user), 1, ob);
    if (fwrite != 0)
    {
        long long acNumber = genAcNumber();
        usr.accountNumber = acNumber;
        printf("\n\n\n\t\t\t\tYour Account Number is : %lld", acNumber);
        printf("\n\n\n\t\t\t\tCongratulations %s %s !! ", usr.fname, usr.lname);
        printf("\n\t\t\t\tYour account has been created succesfully \n\n");
        printf("\n\n\n\n\t\t\t\tDo you want to login to your account? [y/n]\t");

        char flg = 'a';
        while (flg != 'y' || flg != 'n')
        {
            scanf("%s", &flg);
            if (flg == 'y')
            {
                login();
                break;
            }
            else if (flg == 'n')
            {
                break;
            }
            else
            {
                printf("\n\t\t\t\tYou have choosen INVALID OPTION !! Try again \n");
                printf("\n\t\t\t\tDo you want to login to your account? [y/n]\t");
            }
        }
    }
    else
    {
        printf("\n\n\t\t\t\tSomething went wrong!!  Please try again");
    }
    fclose(ob);
}

long long genAcNumber()
{
    long long accountNumber = 0;

    // Using the current time as seed for random number generation
    srand(time(NULL));

    // Generate a 13-digit account number
    for (int i = 0; i < 13; i++)
    {
        accountNumber = accountNumber * 10 + ((rand() % 10) + 1);
    }

    return accountNumber;
}

void login()
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t================   USER LOGIN    ================ \n\n\n\n");
    printf("\n\t\t\t\tEnter your userID :\t");
    scanf("%s", userID);
    printf("\n\t\t\t\tEnter Password    : \t");
    scanf("%s", passKey);
    strcpy(filename, userID);
    ob = fopen(strcat(filename, ".txt"), "r");
    if (ob == NULL)
    {
        printf("\n\t\t\t\tAccount not registered or You have entered Wrong details\n");
        printf("\n\t\t\t\tDo you want to continue login? [y/n]\t");

        char flg = 'a';
        while (flg != 'y' || flg != 'n')
        {
            scanf("%s", &flg);
            if (flg == 'y')
            {
                login();
                break;
            }
            else if (flg == 'n')
            {
                break;
            }
            else
            {
                printf("\n\n\t\t\t\tYou have choosen INVALID OPTION !! Choose 'y' or 'n' :\t");
            }
        }
    }
    else
    {
        fread(&usr, sizeof(struct user), 1, ob);
        fclose(ob);
        if (!strcmp(passKey, usr.password))
        {
            system("cls");
            printf("\n\t\t\t\t\t\t\t\tHELLO... %s %s", usr.fname, usr.lname);

            char cont = 'y';
            while (cont == 'y')
            {

                printf("\n\n\n\n\t\t\t\tPress 1 for balance inquiry");
                printf("\n\n\t\t\t\tPress 2 for depositing cash");
                printf("\n\n\t\t\t\tPress 3 for cash withdrawl");
                printf("\n\n\t\t\t\tPress 4 for online transfer");
                printf("\n\n\t\t\t\tPress 5 for password change");
                printf("\n\n\t\t\t\tPress 6 for User Details");
                printf("\n\n\t\t\t\tPress 7 for LogOut");
                printf("\n\n\n\t\t\t\tYour choice:\t");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    cashDeposit();
                    break;
                case 3:
                    cashWithdrawl();
                    break;

                case 4:
                    onlineTransfer();
                    break;
                case 5:
                    changePassword();
                    break;
                case 6:
                    showDetails();
                    break;
                case 7:
                    cont = 'n';
                    logout();
                    break;

                default:
                    printf("\n\t\t\t\tInvalid option");
                }

                if (choice == 7)
                {
                }
                else
                {
                    printf("\n\t\t\t\tStay Logged in? [y/n] \t");

                    while (cont1 != 'y' || cont1 != 'n')
                    {
                        scanf("%s", &cont1);
                        if (cont1 == 'y')
                        {
                            cont = 'y';
                            system("cls");
                            printf("\n\t\t\t\t\t\t\t\tHELLO... %s %s", usr.fname, usr.lname);
                            break;
                        }
                        else if (cont1 == 'n')
                        {
                            cont = 'n';
                            break;
                        }
                        else
                        {
                            printf("\n\t\t\t\tYou have choosen INVALID OPTION !! Try again \n");
                            printf("\t\t\t\tDo you want to proceed with the transaction? [y/n]\t");
                        }
                    }
                }
            }
        }
        else
        {
            printf("\n\t\t\t\tYou have entered wrong password");
        }
    }
}

void checkBalance()
{
    printf("\n\t\t\t\tYour current balance is Rs.%.2f \n", usr.balance);
}

void cashDeposit()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t\tCASH DEPOSIT  \n\n\n");
    printf("\n\t\t\t\tEnter the amount:\t");
    scanf("%f", &amount);
    usr.balance += amount;
    ob = fopen(filename, "w");
    fwrite(&usr, sizeof(struct user), 1, ob);
    if (fwrite != NULL)
        printf("\n\t\t\t\tRs %0.2f is succesfully deposited to your account", usr.balance);
    fclose(ob);
    printf("\n\n\t\t\t\tYour current balance is Rs.%.2f \n\n", usr.balance);
}

void cashWithdrawl()
{
    printf("\n\t\t\t\t\t\t\t\tCASH WITHDRAWAL  \n\n\n");
    printf("\n\t\t\t\tEnter the amount:\t");
    scanf("%f", &amount);
    usr.balance -= amount;
    ob = fopen(filename, "w");
    fwrite(&usr, sizeof(struct user), 1, ob);
    if (fwrite != NULL)
        printf("\n\t\t\t\tYou have withdrawn Rs.%.2f", amount);
    fclose(ob);
    printf("\n\n\t\t\t\tYour current balance is Rs.%.2f \n\n", usr.balance);
}

void onlineTransfer()
{
    printf("\n\t\t\t\tPlease enter the userID to transfer the balance:  ");
    scanf("%s", userID);
    if (!strcmp(userID, usr.userID))
    {
        printf("\n\t\t\t\tNot possible to transfer in same account ");
    }
    else
    {
        printf("\n\t\t\t\tPlease enter the amount to transfer:\t\t");
        scanf("%f", &amount);
        strcpy(filename, userID);
        ob = fopen(strcat(filename, ".txt"), "r");
        if (ob == NULL)
            printf("\n\t\t\t\tAccount not registered");
        else
        {
            fread(&usr1, sizeof(struct user), 1, ob);
            fclose(ob);

            if (amount > usr.balance)
                printf("\n\t\t\t\tInsufficient balance");
            else
            {

                ob = fopen(filename, "w");
                usr1.balance += amount;
                fwrite(&usr1, sizeof(struct user), 1, ob);

                fclose(ob);
                if (fwrite != NULL)
                {
                    printf("\n\t\t\t\tYou have succesfully transfered Rs.%.2f to %s", amount, userID);
                    strcpy(filename, usr.userID);
                    ob = fopen(strcat(filename, ".txt"), "w");
                    usr.balance -= amount;
                    fwrite(&usr, sizeof(struct user), 1, ob);
                    fclose(ob);
                    printf("\n\n\t\t\t\tYour current balance is Rs.%.2f \n\n", usr.balance);
                }
            }
        }
    }
}

void changePassword()
{
    printf("\n\t\t\t\tPlease enter your new password:\t");
    scanf("%s", passKey);
    ob = fopen(filename, "w");
    strcpy(usr.password, passKey);
    fwrite(&usr, sizeof(struct user), 1, ob);
    if (fwrite != NULL)
        printf("\n\t\t\t\tPassword succesfully changed\n\n");
}

void showDetails()
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t %s -- ACCOUNT DETAILS \n\n\n\n", usr.userID);
    printf("\t\t\t\tFirst Name : %s", usr.fname);
    printf("\n\n\t\t\t\tLast Name : %s", usr.lname);
    printf("\n\n\t\t\t\tUser ID : %s", usr.userID);
    printf("\n\n\t\t\t\tAccount Number : %lld", usr.accountNumber);
    printf("\n\n\t\t\t\tPhone Number : %s", usr.phone);
    printf("\n\n\t\t\t\tCurrent Balance : %0.2f \n\n\n\n\n\n\n\n\n\n", usr.balance);
}

void logout()
{
    int i, j;
    printf("\n\n\n\n\t\t\t\tPlease wait, logging out");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 25000000; j++)
        {
            i++;
            i--;
        }
        printf(".");
    }

    printf("Logged out successfully..\n\n");
}
