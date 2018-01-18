/*
 * Calculator.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: jainulpatel
 */

#include "Calculator.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Calculator::Calculator() {
	// TODO Auto-generated constructor stub

}

Calculator::~Calculator() {
	// TODO Auto-generated destructor stub
}


//returns the code for error genearated
int Calculator::get_error() {
	return errorCode;
}

/*
 *Expression function calls for the term function and returns the result
 *if it finds the next char as
 *if + or - then it calls the term function and adds or subtracts the value from the result.
 */
double Calculator::expression() {

	char c;
	cin >> ws;
	c = cin.peek();//terminate the spaces before the next character and check for the next nonwhitespace character
	double result;

	result = term();//calling the term func for mutual recursion

	//again check for the next non-whitespace char
	cin >> ws;
	c = cin.peek();

	//if the char is + or - then call the term func again and add the result
	if (c == '+') {

		cin >> c;
		result += term();
		errorCode = 0;
	} else if (c == '-') {
		cin >> c;
		result -= term();
	} else if (c == '%') {  //if next char is % then give the error mesaage for incorrect input
		cin >> c;
		errorCode = 2;
	}

	return result;
}


/*
 *Term function checks for the factor and return the value to the expression
 *if it finds the next char as * or / then it calls the factor function and multiplies or divides the values with the result.
 */
double Calculator::term() {


	double term = factor();//calling the factor func for mutual recursion


	//check for the next non-whitespace char
	char c;
	cin >> ws;
	c = cin.peek();


	//condition for the multiplication or division
	if (c == '*') {

		cin >> c;
		term *= factor();

	}
	if (c == '/') {
		cin >> c;
		double divisor = factor();
		if (divisor == 0) {
			//condition for divide by zero exception
			errorCode = 1;
			return 0;
		} else {
			term /= divisor;
		}
	}
	if (c == '%') {
		cin >> c;
		errorCode = 2;
	}
	if (c == ')') {
		errorCode = 4;
	}

	return term;
}


/*
 *Factor function checks for the digits and return the operand if its digit.
 *if it finds the next char as bracket then it calls the expression function again
 */
double Calculator::factor() {

	cin >> ws;
	char c;
	double d;

	c = cin.peek();
	// if the next char is digit then return it to calling function
	if (isdigit(c)) {
		cin >> d;
		return d;

	} else {//else check for the next expression
		if (c == '(') {
			bracketCount++;
			cin >> c;
			d = expression();
			c = cin.peek();


			//for each opening bracket there should be one closing bracket
			if (c == ')') {
				errorCode = 0;
				//cout <<endl<< ") read"<<endl;
				cin >> c;
				bracketCount--;
			} else {// if closing bracket is not there then give the error
				errorCode = 3;
			}
		}

		return d;

	}

}

