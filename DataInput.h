/*
 * DataInput.h
 *
 *  Created on: Oct 4, 2020
 *      Author: Micheal White (1837887_snhu)
 */

#ifndef DATAINPUT_H_
#define DATAINPUT_H_

#include <vector>

using namespace std;

class DataInput {

public:
	DataInput();
	const vector<string> &getMUserPrompts() const;

	double getMInitialInvestAmt() const;
	void setMInitialInvestAmt(double t_initialInvestAmt);

	double getMMonthlyDep() const;
	void setMMonthlyDep(double t_monthlyDep);

	double getMAnnualInt() const;
	void setMAnnualInt(double t_annualInt);

	double getMNumYears() const;
	void setMNumYears(double t_numYears);

	void promptUser();

private:
	vector<string> m_userPrompts;

	double m_initialInvestAmt;
	double m_monthlyDep;
	double m_annualInt;
	double m_numYears;

	void printHeader();
	vector<double> inputCollect();
	bool enterCheck();

};


#endif /* DATAINPUT_H_ */
