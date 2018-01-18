/*
 * RomanNumerals.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: jainulpatel
 */

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

#include "RomanNumeral.h"
using namespace std;

//default constructor
RomanNumeral::RomanNumeral() {
	roman = "";
	decimal = 0;
}

RomanNumeral::RomanNumeral(int decimalVal) :decimal(decimalVal) {
	roman = "";
	to_roman(decimalVal);
}

RomanNumeral::RomanNumeral(string romanVal) : roman(romanVal) {

	decimal = 0;
	to_decimal(romanVal);

}

int RomanNumeral::get_decimalVal() const {
	return decimal;
}
string RomanNumeral::get_romanVal() const {
	return roman;
}

void RomanNumeral::to_decimal(string romanVal) {

	decimal = 0;
	char prev;

	//iterate the loop for reading the char by char
	for (int i = romanVal.length() - 1; i >= 0; i--)
	{

		prev = romanVal[i - 1];

		//assigning the  decimal value per character
		switch (romanVal[i])
		{
		case 'I':
			decimal += 1;
			break;

		case 'V':
			decimal += 5;
			break;

		case 'X':
			decimal += 10;
			break;

		case 'L':
			decimal += 50;
			break;

		case 'C':
			decimal += 100;
			break;

		case 'D':
			decimal += 500;
			break;

		case 'M':
			decimal += 1000;
			break;

		}

		if (romanVal[i] == 'I' && i != romanVal.length() - 1) {
			if (romanVal[i + 1] == 'X') {
				decimal -= 2;
			}
		}

		//If the char is other than I,X or C and check if it is preceded by I,X or C then decrease the value according to the value of the char it is preceded by
		if ((romanVal[i] != 'I' && romanVal[i] != 'X' && romanVal[i] != 'C')) {
			if (romanVal[i] != prev) {

				if (prev == 'I' || 'X' || 'C') {
					if (prev == 'I') {
						decimal -= 1;
						i--;
					} else if (prev == 'X') {
						decimal -= 10;
						i--;
					} else if (prev == 'C') {
						decimal -= 100;
						i--;
					}

				}
			}
		}
	}

}


void RomanNumeral::to_roman(int decimalVal) {
	int tempNum = decimalVal;

	//iterate till number is not zero as we will keep dividing the number to separate the digits
	while (tempNum != 0)
	{
		//case for number greater than 1000
		if (tempNum >= 1000)
		{
			int n = tempNum / 1000;
			//Print M number of n times
			do {
				roman += 'M';
				n--;
			} while (n > 0);

			tempNum = tempNum % 1000;

		}

		//case for number greater than 500
		else if (tempNum >= 500) {

			//case for number greater than 900
			if (tempNum >= 900) {
				roman += 'C';
				roman += 'M';

				tempNum = tempNum % 900;

			}
			//case for number greater than 500 and less than 900
			else {
				roman += 'D';
				tempNum = tempNum % 500;

			}
		}
		//case for number greater than 100
		else if (tempNum >= 100) {
			//case for number greater than 100 and less than 400
			if (tempNum < 400) {
				int n = tempNum / 100;
				do {
					roman += 'C';
					n--;
				} while (n > 0);

				tempNum = tempNum % 100;
			}
			else {
				roman += 'C';
				roman += 'D';
				tempNum = tempNum % 100;

			}

		}

		//case for number greater than 50
		else if (tempNum >= 50) {
			if (tempNum >= 90) {
				roman += 'X';
				roman += 'C';
				tempNum = tempNum % 90;

			}
			//case for number greater than 50 and less than 90
			else {
				roman += 'L';
				tempNum = tempNum % 50;

			}
		}

		//case for number greater than 10
		else if (tempNum >= 10) {
			//case for number less than 40
			if (tempNum < 40) {
				int n = tempNum / 10;
				do {
					roman += 'X';
					n--;
				} while (n > 0);

				tempNum = tempNum % 10;
			} else {
				roman += 'X';
				roman += 'L';
				tempNum = tempNum % 10;
			}

		}

		//case for number greater than 5
		else if (tempNum >= 5) {

			//case for number greater than 9
			if (tempNum >= 9) {
				roman += 'I';
				roman += 'X';
				tempNum = tempNum % 9;

			}
			//case for number greater than 5 and less than 9
			else {
				roman += 'V';
				tempNum = tempNum % 5;

			}
		}

		//case for number greater than 1
		else if (tempNum >= 1) {
			//case for number greater than 1 and less than 4
			if (tempNum < 4) {
				int n = tempNum / 1;
				do {
					roman += 'I';
					n--;
				} while (n > 0);

				tempNum = 0;
			}
			//case for number equals to 4
			else {
				roman += 'I';
				roman += 'V';
				tempNum = 0;

			}

		}
	}

}

ostream& operator <<(ostream& outs, const RomanNumeral& rn) {
//printing number in the required format
	outs << "[" << rn.decimal << ":" << rn.roman << "]";
	return outs;
}

istream& operator >>(istream& ins, RomanNumeral& rn) {
	string romanNum;
	ins >> romanNum;
	rn.roman = romanNum;
	rn.to_decimal(romanNum);

	return ins;
}

//computing addition of roman numbers
int operator +(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	return rn1.get_decimalVal() + rn2.get_decimalVal();
}

//computing division of roman numbers
int operator /(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	return abs(rn1.get_decimalVal() / rn2.get_decimalVal());
}

//computing subtractions of roman numbers
int operator -(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	return (rn1.get_decimalVal() - rn2.get_decimalVal());
}

//computing multiplication of roman numbers
int operator *(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	return (rn1.get_decimalVal() * rn2.get_decimalVal());
}

//computing equal numbers
bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	if (rn1.get_decimalVal() == rn2.get_decimalVal())
		return true;
	else
		return false;

}

//computing if numbers are not equal
bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2) {
	if (rn1.get_decimalVal() != rn2.get_decimalVal())
		return true;
	else
		return false;
}
