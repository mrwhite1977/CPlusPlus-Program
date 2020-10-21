/*
 * DataInput.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: Micheal White (1837887_snhu)
 */
#include <iostream>
#include <istream>
#include <limits>
#include <vector>
#include "DataInput.h"

using namespace std;

// Default constructor
DataInput::DataInput() {
	DataInput::m_userPrompts = {
		"Initial Investment Amount: ",
			"Monthly Deposit: ",
			"Annual Interest: ",
			"Number of Years: "
	};
};

const vector<string> &DataInput::getMUserPrompts() const {
	return m_userPrompts;
}

// Creating setters and getters
double DataInput::getMInitialInvestAmt() const {
	return m_initialInvestAmt;
}

void DataInput::setMInitialInvestAmt(double t_initialInvestAmt) {
	m_initialInvestAmt = t_initialInvestAmt;
}

double DataInput::getMMonthlyDep() const {
	return m_monthlyDep;
}

void DataInput::setMMonthlyDep(double t_monthlyDep) {
	m_monthlyDep = t_monthlyDep;
}

double DataInput::getMAnnualInt() const {
	return m_annualInt;
}

void DataInput::setMAnnualInt(double t_annualInt) {
	m_annualInt = t_annualInt;
}

double DataInput::getMNumYears() const {
	return m_numYears;
}

void DataInput::setMNumYears(double t_numYears) {
	m_numYears = t_numYears;
}

// Create print header for user input prompts
void DataInput::printHeader() {
	cout << string(36, '*') << endl;
	cout << string(12, '*') << " DataInput " << string(12, '*') << endl;
}

// Capture user input and set class members
void DataInput::promptUser() {
	vector<double> depositDetails;
	char quitCommand = 'a';  // Infinite loop created until user satisfies all input requirements

	while (quitCommand != 'q') {

		try {
			// Clears any prior incomplete collection of user input
			depositDetails.clear();
			printHeader();			// Display interface header
			depositDetails = inputCollect();	// Collects user input

		}
		// Catch any invalid arguments and handle appropriately
		catch (invalid_argument& except) {
			cin.clear();	// Clears errors
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// Clears input buffer
			cout << except.what() << endl;
		}

		// Determines if depositDetails vector is full and decides whether to continue
		if (depositDetails.size() == 4 && enterCheck()) {
			// Set private members of class
			setMInitialInvestAmt(depositDetails.at(0));
			setMMonthlyDep(depositDetails.at(1));
			setMAnnualInt(depositDetails.at(2));
			setMNumYears(depositDetails.at(3));

			// Exit command for class and return to main()
			quitCommand = 'q';
		}
	}
}

// Loop for user prompts and store responses
vector<double>DataInput::inputCollect() {
	vector<double> responses;	// Collect user input in vector
	vector<string> prompts = getMUserPrompts();

	for (int i = 0; i < prompts.size(); ++i) {
		string prompt = prompts.at(i);
		double userInput;
		cout << prompt;
		cin >> userInput;

		// Verify user inputs as valid
		if (!cin || userInput < 0.01) {
			throw invalid_argument("\n\nAlphabetical characters and amounts less than 0.01 not allowed. \n\n"
			"Please try again\n\n");
		}

		// Add vector input to created vector
		responses.push_back(userInput);
	}
	return responses;
}

// Create abstract method to validate specific enter key presses
bool DataInput::enterCheck() {
	cout << "Press enter to continue . . . \n\n\n";
	return cin.get() == '\n';
}
