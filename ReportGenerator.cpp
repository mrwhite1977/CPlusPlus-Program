/*
 * ReportGenerator.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: Micheal White (1837887_snhu)
 */
#include <string_view>
#include <iostream>
#include <iomanip>
#include "ReportGenerator.h"
#include "Calculation.h"

using namespace std;

const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

// Constructor
ReportGenerator::ReportGenerator() {}

// Create and print column titles for report
void ReportGenerator::printColHeader() {
	cout << string(66, '=') << endl;
	cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST << endl;
	cout << string(66, '-') << endl;
}

// Print report header
void ReportGenerator::reportGenerator(InvestmentInfo &t_dataOne, InvestmentInfo &t_dataTwo) {
	cout <<"     Balance and Interest Without Additional Monthly Deposits   \n" << endl;
	annualReport(t_dataOne);

	cout <<"     Balance and Interest With Additional Monthly Deposits      \n" << endl;
	annualReport(t_dataTwo);
}

// Print rows of financial information for report
void ReportGenerator::annualReport(InvestmentInfo &t_data) {
	// Create local variables for accurate reporting
	vector<int> years = t_data.getMYears();
	vector<double> yearEndBalances = t_data.getMYearEndBalances();
	vector<double> yearEndEarnedInterest = t_data.getMYearEndEarnedInterest();

	printColHeader();

	// Loop over InvestmentInfo object to populate report
	for (int i = 0; i < years.size(); ++i) {
		cout << setw(9) << years.at(i) << fixed << setprecision(2);
		cout << setw(26) << yearEndBalances.at(i) << fixed << setprecision(2);
		cout << setw(27) << yearEndEarnedInterest.at(i) << fixed << setprecision(2) << endl;
	}
	cout << endl << endl;
}

// Prompt to user for additional session
bool ReportGenerator::additionalSessionCheck() {
	string text;

	cout << "Press enter to input additional values (press 'q' to quit)\n";
	getline(cin, text);

	if (text.empty()) {
		return true;
	}
	else {
		return false;
	}
}
