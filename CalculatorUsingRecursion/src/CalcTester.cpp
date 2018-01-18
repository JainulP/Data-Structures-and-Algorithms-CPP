/*
 * Calc.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: jainulpatel
 */

#include <iostream>
#include <stdlib.h>
#include "Calculator.h"

using namespace std;

int main() {

	Calculator calculator;


	cout << endl << "Expression? ";

			char ch;
			cin >> ws;//terminating white space
			ch = cin.peek();//checking for the next char in stream

			//iterate till user does not press dot '.'
			while (ch != '.'){

				//before checking for the next character terminate spaces in between
				cin >> ws;
				ch = cin.peek();

				//if next char is dot then terminate the loop else call the calculator expression function and print the result if there is no error else print the error
				if (ch != '.') {
					double result = calculator.expression();//expression func calls recursively the term func which calls factor func and which again calls expression func for mutual recursion


					//print the error messages or else if there is no error then print the result
					switch (calculator.get_error())
					{
					case 1:
						cout << "***** Division by zero" << endl;
						break;
					case 2:
						cout << result << endl;
						cout << "***** Unexpected %" << endl;
						break;
					case 3:
						cout << "***** Missing )" << endl;
						break;
					case 4:
						cout << result << endl;
						cout << "***** Unexpected )" << endl;
						break;

					default:
						cout << result << endl;
						break;
					}

					string str; getline(cin, str);//read the pending string in order to read next input

					//ask for the next expression
					cout << endl << "Expression? ";
					cin >> ws;
					ch = cin.peek();

		}
	}

	cout << endl << "Done!" << endl;
	return 0;
}

