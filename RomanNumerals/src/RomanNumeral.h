/*
 * RomanNumerals.h
 *
 *  Created on: Sep 25, 2017
 *      Author: jainulpatel
 */

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

using namespace std;

class RomanNumeral {

private:
	string roman;
	int decimal;
	void to_roman(int decimal);
	void to_decimal(string roman);
public:
	/**
	 * Default constructor.
	 */
	RomanNumeral();


	/**
	 Constructs a roman numeral.
	 @param int decimalVal
	 */
	RomanNumeral(int decimalVal);

	/**
	 Constructs a roman numeral.
	 @param romanVal
	 */
	RomanNumeral(string romanVal);

	/**

	 @return the roman value
	 */
	string get_romanVal() const;

	/**
	 @return the decimal value
	 */
	int get_decimalVal() const;

	//declaring the friend functions
	friend int operator -(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend int operator +(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend int operator *(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend int operator /(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend ostream& operator <<(ostream& outs, const RomanNumeral& rn);
	friend istream& operator >>(istream& ins, RomanNumeral& rn);

};

#endif /* ROMANNUMERAL_H_ */

