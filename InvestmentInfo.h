/*
 * InvestmentInfo.h
 *
 *  Created on: Oct 4, 2020
 *      Author: Micheal White(1837887_snhu)
 */

#ifndef INVESTMENTINFO_H_
#define INVESTMENTINFO_H_

#include <vector>

using namespace std;

class InvestmentInfo {

public:
	InvestmentInfo();

	const vector<int> &getMYears() const;
	void setMYears(const vector<int> &t_years);

	const vector<double> &getMYearEndBalances() const;
	void setMYearEndBalances(const vector<double> &t_yearEndBalances);

	const vector<double> &getMYearEndEarnedInterest() const;
	void setMYearEndEarnedInterest(const vector<double> &t_yearEndEarnedInterest);

private:
	vector<int> m_years;
	vector<double> m_yearEndBalances;
	vector<double> m_yearEndEarnedInterest;
};



#endif /* INVESTMENTINFO_H_ */
