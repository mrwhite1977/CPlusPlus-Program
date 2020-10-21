/*
 * ReportGenerator.h
 *
 *  Created on: Oct 4, 2020
 *      Author: Micheal White (1837887_snhu)
 */

#ifndef REPORTGENERATOR_H_
#define REPORTGENERATOR_H_

#include <vector>
#include "DataInput.h"
#include "Calculation.h"
#include "InvestmentInfo.h"

using namespace std;

class ReportGenerator {

public:
	ReportGenerator();

	void reportGenerator(InvestmentInfo &t_dataOne, InvestmentInfo &t_dataTwo);

	bool additionalSessionCheck();

private:
	void printColHeader();

	void annualReport(InvestmentInfo &t_data);
};


#endif /* REPORTGENERATOR_H_ */
