#include <stdio.h>
#include <time.h>

int main() {
    // Declare variables for birthdate and current date
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;

    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Input birthdate
    printf("Enter your birthdate (YYYY MM DD): ");
    scanf("%d %d %d", &birthYear, &birthMonth, &birthDay);

    // Calculate age
    currentYear = tm.tm_year + 1900;
    currentMonth = tm.tm_mon + 1;
    currentDay = tm.tm_mday;

    int ageYears = currentYear - birthYear;
    int ageMonths = currentMonth - birthMonth;
    int ageDays = currentDay - birthDay;

    // Adjust for negative ageMonths or ageDays
    if (ageDays < 0) {
        ageMonths--;
        ageDays += 30; // Assuming an average of 30 days per month
    }
    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }

    // Print the calculated age
    printf("Your age is: %d years, %d months, %d days\n", ageYears, ageMonths, ageDays);

    return 0;
}
