/*
 * Calculator.h
 *
 *  Created on: Oct 30, 2017
 *      Author: jainulpatel
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include<string>

using namespace std;

class Calculator {
public:
	Calculator();
	virtual ~Calculator();

	double expression();
	double term();
	double factor();

	int get_error();

	int bracketCount = 0;//number of brackets;
	int errorCode;//stores the code if error generated
};

#endif /* CALCULATOR_H_ */
