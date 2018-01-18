/*
 * Word.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: jainulpatel
 */

#include <string>
#include "Word.h"
using namespace std;


Word::Word() :
		text(""), count(0) {
}
Word::Word(string text) :
		text(text), count(1) {
}

Word::~Word() {
}

int Word::get_count() const {
	return count;
}

string Word::get_text() const {
	return text;
}

bool operator !=(Word word, Word otherword) {

	if (word.text == otherword.text) {
		return false;
	} else {
		return true;
	}
}

void Word::increment_count() {
	count++;
}
