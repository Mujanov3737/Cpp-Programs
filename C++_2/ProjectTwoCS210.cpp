// Ahmet Mujanovic
#include <iostream>
#include <string>
#include <cstdlib>
#include "UserData.h"
#include "Calculations.h"


int main()
{
    // Creating objects to access class member functions
    auto calcObj = std::make_unique<Calculations>();
    auto dataObj = std::make_unique<UserData>();
    

    // Loop menu/display
    while (true) {
        dataObj->inputUserData();
        dataObj->printUserData();

        calcObj->printHeader(1);
        calcObj->balanceWithoutMonthlyDeposit(dataObj->getInitialInvestment(), dataObj->getAnnualInterest(), dataObj->getYears());

        calcObj->printHeader(2);
        calcObj->balanceWithMonthlyDeposit(dataObj->getInitialInvestment(), dataObj->getMonthlyDeposit(), dataObj->getAnnualInterest(), dataObj->getYears());

        if (Calculations::restart() == true) {
            continue;
        }
        else {
            break;
        }
    }
}

