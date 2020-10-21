//============================================================================
// Name:       : AirgeadBank.cpp
// Author      : Micheal White
// Date:	   : 10/04/2020
// Description : Interest Calculator
//============================================================================

#include <string>
#include <iostream>
#include "DataInput.h"
#include "Calculation.h"
#include "ReportGenerator.h"
#include "InvestmentInfo.h"

using namespace std;

void startApp() {
	bool restart = true;

	try {
		do {
			// Request input from user and store results
			DataInput userData;
			userData.promptUser();

			// Pass user input to make appropriate calculations
			Calculation calculation;
			InvestmentInfo acctWithNoMonthlyDep = calculation.calculateAnnualInvestment(userData);
			InvestmentInfo acctWithMonthlyDep = calculation.calculateAnnualInvestment(userData, true);

			// Generate reports to present information to user
			ReportGenerator balanceAndInterestReport;
			balanceAndInterestReport.reportGenerator(acctWithNoMonthlyDep, acctWithMonthlyDep);

			// Prompt to ask if user would like to continue or exit program
			restart = balanceAndInterestReport.additionalSessionCheck();
		}

		while (restart);
	}

	catch (runtime_error& except) {
		cout << "Oops! Something went wrong. Exception: " << except.what() << endl;
	}
}

int main() {

	startApp();

	return 0;
}
