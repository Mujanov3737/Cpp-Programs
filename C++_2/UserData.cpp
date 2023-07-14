#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "UserData.h"
#include "Calculations.h"

// Default Constructor
UserData::UserData() {};

// Parameterized Constructor
UserData::UserData(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_years) {
	this->m_initialInvestment = t_initialInvestment;
	this->m_monthlyDeposit = t_monthlyDeposit;
	this->m_annualInterest = t_annualInterest;
	this->m_years = t_years;
}

// Defining accessors for user's account
double UserData::getInitialInvestment() const { return m_initialInvestment; }
double UserData::getMonthlyDeposit() const { return m_monthlyDeposit; }
double UserData::getAnnualInterest() const { return m_annualInterest; }
int UserData::getYears() const { return m_years; }

// Defining mutators for user's account
void UserData::setInitialInvestment(double t_initialInvestment) { this->m_initialInvestment = t_initialInvestment; }
void UserData::setMonthlyDeposit(double t_monthlyDeposit) { this->m_monthlyDeposit = t_monthlyDeposit; }
void UserData::setAnnualInterest(double t_annualInterest) { this->m_annualInterest = t_annualInterest; }
void UserData::setYears(int t_years) { this->m_years = t_years; }


/*
* Goes through prompts to collect data for the user's account. Includes a check for only integers and casts to double.
*/
void UserData::inputUserData() {
	std::string userInput;


	std::cout << Calculations::nCharString(64, '=') << std::endl;
	std::cout << Calculations::nCharString(27, '-') << "DATA INPUT" << Calculations::nCharString(27, '-') << std::endl;

	while (true)
	{
		std::cout << "Please enter Initial Investment Amount (as a number): $";
		std::cin >> userInput;
		if (!Calculations::isNumber(userInput)) {
			std::cout << "Error: Please enter a whole number only." << std::endl;
			std::cout << std::endl;
			continue;
		}
		break;
	}

	UserData::setInitialInvestment(std::stod(userInput));
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Please enter Monthly Deposit (as a number): $";
		std::cin >> userInput;
		if (!Calculations::isNumber(userInput)) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << "Error: Please enter a positive whole number only." << std::endl;
			std::cout << std::endl;
			continue;
		}
		break;
	}

	UserData::setMonthlyDeposit(std::stod(userInput));
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Please enter Annual Interest (as a number): %";
		std::cin >> userInput;
		if (!Calculations::isNumber(userInput)) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << "Error: Please enter a positive whole number only." << std::endl;
			std::cout << std::endl;
			continue;
		}
		break;
	}

	UserData::setAnnualInterest(std::stod(userInput));
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Please enter Number of Years (as a number): ";
		std::cin >> userInput;
		if (!Calculations::isNumber(userInput)) {
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << "Error: Please enter a positive whole number only." << std::endl;
			std::cout << std::endl;
			continue;
		}
		break;
	}

	UserData::setYears(stoi(userInput));
	std::cout << Calculations::nCharString(32, '-') << std::endl;

}


/*
* Prints values user entered
*/
void UserData::printUserData() {
	std::cout << Calculations::nCharString(32, '=') << std::endl;
	std::cout << Calculations::nCharString(11, '-') << "DATA INPUT" << Calculations::nCharString(11, '-') << std::endl;
	std::cout << "Initial Investment Amount: $" << getInitialInvestment() << std::endl;
	std::cout << "Monthly Deposit: $" << getMonthlyDeposit() << std::endl;
	std::cout << "Annual Interest: %" << getAnnualInterest() << std::endl;
	std::cout << "Number of Years: " << getYears() << std::endl;
	std::cout << Calculations::nCharString(32, '=') << std::endl;
	// Wait for user input to continue
	system("pause");
}

