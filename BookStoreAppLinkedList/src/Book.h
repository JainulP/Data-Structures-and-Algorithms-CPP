#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * The Book class.
 */
class Book {
public:
	/**
	 * Default constructor.
	 */
	Book();

	/**
	 * Constructor.
	 */
	Book(string isbn, string last, string first, string title);

	/**
	 * Destructor.
	 */
	~Book();

	// Declaring Getters.
	string get_isbn() const;
	string get_last() const;
	string get_first() const;
	string get_title() const;

	// stream I/O operators
	friend ostream& operator <<(ostream& outs, const Book& book);
	friend istream& operator >>(istream& ins, Book& book);
	Book& operator =(const Book& book);

private:

	string isbn;  	   // Book isbn number
	string last;    // author's last name
	string first;   // author's first name
	string title;   // Book's title
};

#endif /* BOOK_H_ */
