/*
 * Word.h
 *
 *  Created on: Nov 5, 2017
 *      Author: jainulpatel
 */

#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

/***** Modify this file as needed. *****/

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word {
public:
	/**
	 * Default constructor.
	 */
	Word();

	/**
	 * Constructor.
	 * Create a word entry with the given text. Initialize the count to 1.
	 * @param text the text of the word.
	 */
	Word(string text);

	/**
	 * Destructor.
	 */
	virtual ~Word();


	/**
	 * returns the count of  a word entry with the given text
	 * @return count of the word.
	 */
	int get_count() const;

	/**
	 * returns the text of  a word entry
	 * @return text of the word.
	 */
	string get_text() const;

	/**
	 * increments the count of word if the repeatative word is found in vector or map
	 */
	void increment_count();

	/**
	 * != operator overloading.
	 * Compares two words' texts and counts
	 * @param two words for which comparision is done
	 * @returns true if both words are not equal and false if they are equal
	 */
	friend bool operator !=(Word word, Word otherword);

private:
	string text;
	int count;
};

#endif /* WORD_H_ */
