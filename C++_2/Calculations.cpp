#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <math.h>
#include "UserData.h"
#include "Calculations.h"

/*
* Prints a particular character a desired number of times
* @param int char
* @param Number of times to print a character
* @param The character desired to be printed
* 
* @returns Formatted string
*/
std::string Calculations::nCharString(size_t t_n, char t_c) {
    std::string formattedCharString(t_n, t_c);

    return formattedCharString;
}


/*
* Parses every element of string to see if they are all numbers.
* Additionally, checks to make sure the number is not negative.
* @param string
* @param String to check if all indexes are numbers
*
* @returns True or False
*/
bool Calculations::isNumber(std::string t_userInput) {
    for (size_t i = 0; i < t_userInput.length(); i++)
    {
        if (isdigit(t_userInput[i]) == false) {
            return false;
        }
    }
    if (stoi(t_userInput) < 0) {
        return false;
    }
    return true;
}


/*
* Prompts user if they want to check another investment estimate or not
* 
* @returns True or False
*/
bool Calculations::restart() {

    char t_userChoice;
    while (true)
    {
        std::cout << "Would you like to enter another set of values? ('y' or 'n'): ";
        std::cin >> t_userChoice;
        if (t_userChoice == 'y' || t_userChoice == 'Y') {
            std::cin.clear();
            std::cin.ignore(999, '\n');
            return true;
        }
        else if (t_userChoice == 'n' || t_userChoice == 'N') {
            std::cin.clear();
            std::cin.ignore(999, '\n');
            return false;
        }
        else {
            std::cout << "Please enter 'y' or 'n'" << std::endl;
            std::cin.clear();
            std::cin.ignore(999, '\n');
            continue;
        }
    }
    return false;
}


/*
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void Calculations::printDetails(int t_year, double t_yearEndBalance, double t_interestEarned) {

    std::cout << std::setw(34) << std::left << t_year;
    std::cout << "$" << std::setw(33) << std::fixed << std::setprecision(2) << t_yearEndBalance;
    std::cout << "$" << std::setw(34) << t_interestEarned;
}

/*
* Prints header for balance and interest charts
* @param 1 to print header WITHOUT additional deposits
* @param 2 to print header WITH additional deposits
*/
void Calculations::printHeader(int t_selection) {

    if (t_selection == 1) {
        std::cout << std::setw(79) << std::right << "Balance and Interest Without Additional Monthly Deposits" << std::endl;
        std::cout << nCharString(102, '=') << std::endl;
        std::cout << std::setw(34) << std::left << "Year";
        std::cout << std::setw(34) << std::left << "Year End Balance";
        std::cout << std::setw(34) << std::left << "Year End Earned Interest" << std::endl;
        std::cout << nCharString(102, '-') << std::endl;

    }
    else if (t_selection == 2) {
        std::cout << std::setw(79) << std::right << "Balance and Interest With Additional Monthly Deposits" << std::endl;
        std::cout << nCharString(102, '=') << std::endl;
        std::cout << std::setw(34) << std::left << "Year";
        std::cout << std::setw(34) << std::left << "Year End Balance";
        std::cout << std::setw(34) << std::left << "Year End Earned Interest" << std::endl;
        std::cout << nCharString(102, '-') << std::endl;
    }
}

/*
 * Calculates and returns an end of year balance for a given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param monthlyDeposit dollar amount added into the investment each month
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 *
 */
void Calculations::balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears) {
    
    double total = t_initialInvestment;
    double gainWithInterestMonthly = 0;
    double gainWithInterest = 0;
    double gainWithInterestTotal = 0;

    // Looping through years
    for (int i = 0; i < t_numberOfYears; i++) {

        gainWithInterest = 0;
        gainWithInterestTotal = 0;

        // Nested loop loops through months
        for (int j = 0; j < 12; j++) {
            gainWithInterest = 0;
            gainWithInterestMonthly = ((t_interestRate / 100) / 12) * (total + t_monthlyDeposit);
            gainWithInterest = gainWithInterest + gainWithInterestMonthly;
            gainWithInterestTotal = gainWithInterestTotal + gainWithInterest;
            total = total + gainWithInterest + t_monthlyDeposit;
            //std::cout << "Monthly INT: " << gainWithInterest << "\tTotal: " << total << std::endl;
        }

        printDetails(i + 1, total, gainWithInterestTotal);
        std::cout << std::endl;
        std::cout << nCharString(102, '-') << std::endl;
    }

    std::cout << std::endl;
}


/*
 * Calculates and returns an end of year balance for given number of years
 *
 * @param initialInvestment dollar amount of initial investment
 * @param interestRate percentage of investment earned each year (annually), so a passed value of 3.5 is a rate of .035
 * @param numberOfYears number of years to calculate balance for
 */
 void Calculations::balanceWithoutMonthlyDeposit(double t_initialInvestment, double t_interestRate, int t_numberOfYears) {

     double total = t_initialInvestment;
     double gainWithInterest;

     for (int i = 0; i < t_numberOfYears; i++) {
         gainWithInterest = (t_interestRate / 100) * total;
         total = total + gainWithInterest;
         printDetails(i + 1, total, gainWithInterest);
         std::cout << std::endl;
         std::cout << nCharString(102, '-') << std::endl;
     }

     std::cout << std::endl;
 }