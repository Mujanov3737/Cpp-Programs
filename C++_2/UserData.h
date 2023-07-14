//#pragma once
#ifndef USER_DATA_H_
#define USER_DATA_H_

#include <string>

class UserData {
public:
	UserData();
	UserData(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_years);

	// Declaring accessors for user's account
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getAnnualInterest() const;
	int getYears() const;

	// Declaring mutators for user's account
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setAnnualInterest(double t_annualInterest);
	void setYears(int t_years);

	void inputUserData();
	void printUserData();

private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_years;
};



#endif USER_DATA_H_
