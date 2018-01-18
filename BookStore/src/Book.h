#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>
#include <string>
using namespace std;


/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

    /**
     * Destructor.
     */
    ~Book();



    // Declaring Getters.
        string get_isbn() const;
        string get_last() const;
        string get_first() const;
        string get_title() const;
        Category get_category() const;

        // stream I/O operators
        friend ostream& operator <<(ostream& outs, const Book& emp);
        friend istream& operator >>(istream& ins, Book& emp);

private:

        	   string isbn;  	   // Book isbn number
           string last;    // author's last name
           string first;   // author's first name
           string title;   // Book's title
           Category category; //Book's category
};

#endif
