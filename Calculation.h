/*
 * Calculation.h
 *
 *  Created on: Oct 4, 2020
 *      Author: Micheal White (1837887_snhu)
 */

#ifndef CALCULATION_H_
#define CALCULATION_H_

#include <vector>
#include "DataInput.h"
#include "InvestmentInfo.h"

using namespace std;

class Calculation {

	public:

	Calculation();

	InvestmentInfo calculateAnnualInvestment(DataInput& data, bool t_monthlyDep = false);

	private:
		vector<vector<double>> annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years);

};


#endif /* CALCULATION_H_ */
