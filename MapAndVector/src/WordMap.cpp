/*
 * WordMap.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: jainulpatel
 */

#include <iostream>
#include <map>
#include "WordMap.h"
#include <string>


using namespace std;

WordMap::WordMap() {
}

WordMap::~WordMap() {
}

Word *WordMap::insert(const string text) {

	data.insert(std::pair<string, Word>(text, Word(text)));

}

Word *WordMap::search(const string text) {
	std::map<string, Word>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		if (it->second.get_text() == text) {
			return &it->second;
		}
	}
	if (it == data.end()) {
		return nullptr;
	}

}

int WordMap::get_size() const {
	return data.size();
}

map<string, Word>& WordMap::get_data() {
	return data;
}
