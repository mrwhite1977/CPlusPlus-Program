/*
 * Calculation.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: Micheal White (1837887_snhu)
 */

#include <vector>
#include <iostream>
#include "Calculation.h"
#include "InvestmentInfo.h"

using namespace std;

const long MAX_AMOUNT = 9999999999999999;

// Default constructor
Calculation::Calculation() {}

// Take user input to build InvestmentInfo object which contains user balance and interest info
InvestmentInfo Calculation::calculateAnnualInvestment(DataInput& t_userData, bool t_monthlyDep) {
	double openAmt = t_userData.getMInitialInvestAmt();
	double depAmt = t_userData.getMMonthlyDep();
	int initRate = t_userData.getMAnnualInt();
	int numYears = t_userData.getMNumYears();
	vector<int> years;
	vector<vector<double>> yearEndBals;

	// Create an object to store report data
	InvestmentInfo investmentDetails;

	try {
		// Return years in array of integers to display to user
		for (int i = 0; i < numYears; ++i) {
			years.push_back(i+1);
		}

		if (t_monthlyDep == false) {
			// Calculate interest without monthly deposit
			yearEndBals = annualBalWithInt(openAmt, 0, initRate, numYears);
		}
		else {
			//Calculate interest with monthly deposits
			yearEndBals = annualBalWithInt(openAmt, depAmt, initRate, numYears);
		}

		// Populate Investment object details
		investmentDetails.setMYears(years);
		investmentDetails.setMYearEndEarnedInterest(yearEndBals.at(0));
		investmentDetails.setMYearEndBalances(yearEndBals.at(1));

		return investmentDetails;
	}

	catch (runtime_error& except) {
		cout << except.what() << endl;
	}
}

// Calculate annual account balance and earned interest
vector<vector<double>> Calculation::annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years) {
	// Local variables to assure accurate calculations
	vector<vector<double>> balanceAndInts;
	vector<double> annualInterestOnly;
	vector<double> annualBalWithInterest;
	double newBal;
	double yearEndInt;
	double precIntRate = (t_intRate / 100.00) / 12.00;
	double intTracker = 0;
	double intOnly = 0;

	// Loop to cycle over months to calculate annual balance and earned interest over requested time period
	for (int i = 0; i < (t_years * 12); ++i) {
		yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i + 1))) * precIntRate;
		// Calculates earned interest back into principle
		intTracker = yearEndInt;
		if (((i + 1) % 12) == 0) {
			annualInterestOnly.push_back(yearEndInt - intOnly);  // Adds only annual interest to one vector
			intOnly = yearEndInt;
			newBal = t_openAmount + (t_depositAmount * (i + 1)) + yearEndInt; // Adds interest and opening & monthly amounts
			annualBalWithInterest.push_back(newBal);  // Add annual balance with interest to second vector
		}
	}

	if (newBal > MAX_AMOUNT) {
		throw runtime_error("Unable to complete calculations.  Amount too large.");
	}

	balanceAndInts.push_back(annualInterestOnly);		// Vector for tracking interest
	balanceAndInts.push_back(annualBalWithInterest);	// Vector for tracing interest and balance

	return balanceAndInts;
}
