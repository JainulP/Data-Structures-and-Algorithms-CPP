/*
 * WordVector.h
 *
 *  Created on: Nov 5, 2017
 *      Author: jainulpatel
 */

#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include <vector>
#include "TimedContainer.h"
#include "Word.h"

/***** Modify this file as needed. *****/

using namespace std;

/**
 * A vector implementation for the concordance that inherits a timer.
 */
class WordVector: public TimedContainer {
public:
	/**
	 * Default constructor.
	 */
	WordVector();

	/**
	 * Destructor.
	 */
	virtual ~WordVector();

	/**
	 * Insert a new word into the sorted vector,
	 * or increment the count of an existing word.
	 * @param text the text of the word to insert or increment.
	 * @return a pointer to the word entry.
	 */
	Word *insert(const string text);

	/**
	 * Search the vector for a word entry with the given text.
	 * @param text the text of the word to find.
	 * @return a pointer to the word entry if found, nullptr if not.
	 */
	Word *search(const string text);


	/**
	 * Returns the whole vector
	 * @return a vector of words
	 */
	vector<Word> get_data() const;

	/**
	 * Conts the total elements in the vector.
	 * @return a integer size of the vector.
	 */
	int get_size() const;

private:
	vector<Word> data;
};

#endif /* WORDVECTOR_H_ */

