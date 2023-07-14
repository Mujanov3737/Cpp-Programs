#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

class Calculations {
public:
	static std::string nCharString(size_t t_n, char t_c);
	static bool isNumber(std::string t_userInput);
	static bool restart();

	void balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears);
	void balanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears);

	void printDetails(int t_year, double t_yearEndBalance, double t_interestEarned);
	void printHeader(int t_selection);

};

#endif USER_DATA_H_