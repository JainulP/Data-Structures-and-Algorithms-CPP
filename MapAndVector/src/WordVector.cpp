/*
 * WordVector.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: jainulpatel
 */

#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

/***** Complete this file. *****/

using namespace std;

WordVector::WordVector() {
	/***** Complete this member function. *****/
}

WordVector::~WordVector() {
	/***** Complete this member function. *****/
}

Word *WordVector::insert(const string text) {

	vector<Word>::const_iterator it = data.begin();
	//calculating the position for insering an element so that vector is sorted
	bool repeat = false;
	while (it != data.end() && (text > it->get_text())) {
		it++;
	}
	for (vector<Word>::const_iterator it = data.begin(); it != data.end();
			it++) {
		if (text == it->get_text()) {
			repeat = true;
			break;
		}
	}
	if (!repeat) {
		//data.push_back(text);
		data.insert(it, Word(text));
		//return &*it;
	} else {
		return nullptr;
	}

}

Word *WordVector::search(const string text) {
	std::vector<Word>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		if (it->get_text() == text) {
			return &*it;
		}

	}
	if (it == data.end()) {
		return nullptr;
	}
}

vector<Word> WordVector::get_data() const {
	return data;
}

int WordVector::get_size() const {
	return data.size();
}
