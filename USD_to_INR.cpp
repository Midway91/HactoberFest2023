#include <iostream>

int main() {
    // Input: Exchange rate from USD to INR
    double exchangeRate;
    std::cout << "Enter the exchange rate (USD to INR): ";
    std::cin >> exchangeRate;

    // Input: Amount in USD
    double usdAmount;
    std::cout << "Enter the amount in USD: ";
    std::cin >> usdAmount;

    // Convert USD to INR
    double inrAmount = usdAmount * exchangeRate;

    // Display the converted amount in INR
    std::cout << "Equivalent amount in INR: " << inrAmount << "\n";

    return 0;
}
