#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Book.h"

using namespace std;

//Default Constructor
Book::Book()
	:isbn(""),last(""),first(""),category(Category::NONE)
{}

//Constructor
Book::Book(string isbn, string last, string first, string title, Book::Category category):isbn(isbn), last(last),first(first),title(title),category(category)
{}

//Destructor
Book::~Book()
{}

//Getter.
//returns the Book's isbn.
string Book::get_isbn() const   { return isbn; }

//Getter.
//returns the author's last name.
string Book::get_last() const   { return last; }


//Getter.
//returns the author's first name.
string Book::get_first() const  { return first; }


//Getter.
//returns the book's title.
string Book::get_title() const { return title; }

//Getter.
//returns the book's category.
Book::Category Book::get_category() const { return category; }


ostream& operator <<(ostream& outs, const Book& book)
{
	//converting category type object to string type for printing
	string book_category;
	switch(book.category)
	{
	case Book::Category::FICTION:
		book_category = "fiction";
		break;

	case Book::Category::HISTORY:
			book_category = "history";
			break;

	case Book::Category::TECHNICAL:
			book_category = "technical";
			break;

	case Book::Category::NONE:
			book_category = "none";
			break;

	}
string str = book.get_isbn().substr(1,book.get_isbn().length());

    outs << "Book{ISBN=" << str << ", last=" << book.last
         << ", first=" << book.first << ", title=" << book.title <<", category=" << book_category<<"}";
    return outs;
}


istream& operator >>(istream& ins, Book& book)
{

	//reading inputs and using delimiter storing it to variables
    getline(ins, book.isbn, ',');
    getline(ins, book.last, ',');
    getline(ins, book.first, ',');
    getline(ins, book.title, ',');
    string inputStr;
    getline(ins,inputStr);
    if(inputStr == "fiction")
    {
    		book.category = Book::Category::FICTION;
    }
    else if(inputStr == "history")
	{
		book.category = Book::Category::HISTORY;
	}
    else if(inputStr == "technical")
	{
		book.category = Book::Category::TECHNICAL;
	}
    else
	{
		book.category = Book::Category::NONE;
	}

    return ins;
}
