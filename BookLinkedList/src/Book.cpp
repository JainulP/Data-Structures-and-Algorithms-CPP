/***** Complete this file. *****/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Book.h"

using namespace std;

//Default Constructor
Book::Book() :
		isbn(""), last(""), first(""), title("") {
}

//Constructor
Book::Book(string isbn, string last, string first, string title) :
		isbn(isbn), last(last), first(first), title(title) {
}

//Destructor
Book::~Book() {
}

//Getter.
//returns the Book's isbn.
string Book::get_isbn() const {
	return isbn;
}

//Getter.
//returns the author's last name.
string Book::get_last() const {
	return last;
}

//Getter.
//returns the author's first name.
string Book::get_first() const {
	return first;
}

//Getter.
//returns the book's title.
string Book::get_title() const {
	return title;
}

ostream& operator <<(ostream& outs, const Book& book) {
	outs << "  Book{ISBN=" << book.isbn << ", last=" << book.last << ", first="
			<< book.first << ", title=" << book.title << "}";
	return outs;
}

istream& operator >>(istream& ins, Book& book) {
	//reading inputs and using delimiter storing it to variables
	getline(ins, book.isbn, ',');
	getline(ins, book.last, ',');
	getline(ins, book.first, ',');
	getline(ins, book.title);

	return ins;
}

Book& Book::operator =(const Book& otherbook) {
	isbn = otherbook.isbn;
	last = otherbook.last;
	first = otherbook.first;
	title = otherbook.title;

	return *this;
}

